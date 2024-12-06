#include "logger.h"

Logger::Logger() {
    m_log = new Vec<char>();
    m_sections = new Vec<LoggerSect>();
    m_timers = new Vec<LoggerTimer>();
    m_outputTypes = 0b11101; // Default: all but debug

    // Record when logging started
    m_start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

Logger::~Logger() {
    delete m_log;
    delete m_sections;
    delete m_timers;
}

void Logger::_raw(char* text, bool newline, enum LoggerSectTypes type) {
    uint32_t i = 0; // Length stored in here
    bool addedPreNewLine = false;

    if (newline) {
        if (m_log->size() != 0 && m_log->get(m_log->size() - 1) != '\n') {
            m_log->push('\n');
            addedPreNewLine = true;
        }
    }

    while (text[i]) { m_log->push(text[i++]); } // Copy text into log

    if (newline) {
        m_log->push('\n');
        i++;

        if (addedPreNewLine) i++;
    }

    // Update end of previous section
    if (m_sections->size() > 0 && m_sections->get(m_sections->size() - 1).type == type) {
        LoggerSect section = m_sections->pop();
        section.length += i;
        m_sections->push(section);
    }
    else m_sections->push({ i, type }); // Create new section
}

Logger& Logger::log(char* text) {
    this->_raw(text, true, LoggerSectTypes::LOGGER_SECT_LOG);
    return *this;
}

Logger& Logger::debug(char* text) {
    this->_raw(text, true, LoggerSectTypes::LOGGER_SECT_DEBUG);
    return *this;
}

Logger& Logger::error(char* text) {
    this->_raw(text, true, LoggerSectTypes::LOGGER_SECT_ERROR);
    return *this;
}

Logger& Logger::time(char* timer) {
    
    // Search for timer (do nothing if already exists)
    for (uint32_t i = 0; i < m_timers->size(); i++) {
        if (std::strcmp(timer, m_timers->get(i).name) == 0) {
            uint32_t len = strlen(timer) + 23;
            char* buf = (char*) malloc(sizeof(char) * len);
            snprintf(buf, len, "Timer %s already exists!", timer);

            this->_raw(buf, true, LOGGER_SECT_TIME);
            free(buf);
            return *this;
        }
    }

    // Initialize new timer
    m_timers->push({
        timer,
        std::chrono::high_resolution_clock::now()
    });

    return *this;
}

Logger& Logger::timeEnd(char* timer) {

    // Search for timer (stop if exists)
    for (uint32_t i = 0; i < m_timers->size(); i++) {
        if (std::strcmp(timer, m_timers->get(i).name) == 0) {
            double delta = ((std::chrono::duration<double>) (std::chrono::high_resolution_clock::now() - m_timers->get(i).timer)).count();
            
            uint32_t len = strlen(timer) + 20;
            char* buf = (char*) malloc(sizeof(char) * len);
            
            if (delta < 1e-6) snprintf(buf, len, "%s: %7.4fns", timer, delta * 1e9);
            else if (delta < 1e-3) snprintf(buf, len, "%s: %7.4fus", timer, delta * 1e6);
            else if (delta < 1) snprintf(buf, len, "%s: %7.4fms", timer, delta * 1e3);
            else snprintf(buf, len, "%s: %8.4fs", timer, delta);

            this->_raw(buf, true, LOGGER_SECT_TIME);
            m_timers->splice(i, 1);
            free(buf);
            return *this;
        }
    }

    // Print out warning message
    uint32_t len = strlen(timer) + 24;
    char* buf = (char*) malloc(sizeof(char) * len);
    snprintf(buf, len, "Timer %s not yet started!", timer);

    this->_raw(buf, true, LOGGER_SECT_TIME);
    free(buf);
    return *this;
}

Logger& Logger::clear() {

    delete m_log;
    delete m_sections;
    delete m_timers;

    m_log = new Vec<char>();
    m_sections = new Vec<LoggerSect>();
    m_timers = new Vec<LoggerTimer>();
    return *this;
}

void Logger::setOutputType(uint8_t outputTypes) {
    m_outputTypes = outputTypes;
}

Logger& Logger::save(const char* text) {
    std::ofstream fout(text);
    fout << *this;
    fout.close();
    return *this;
}
