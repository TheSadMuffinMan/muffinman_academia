#pragma once
#include <chrono>
#include "vec.h"
#include "cstring"
#include "cstdio"
#include "fstream"

enum LoggerSectTypes {
    LOGGER_SECT_LOG     = 0b00001,
    LOGGER_SECT_DEBUG   = 0b00010,
    LOGGER_SECT_TIME    = 0b00100,
    LOGGER_SECT_WARN    = 0b01000,
    LOGGER_SECT_ERROR   = 0b10000
};

struct LoggerSect {
    uint32_t length;
    LoggerSectTypes type;
};

struct LoggerTimer {
    char* name;
    std::chrono::time_point<std::chrono::high_resolution_clock> timer;
};

class Logger {
    Vec<char>* m_log;
    Vec<LoggerSect>* m_sections;
    Vec<LoggerTimer>* m_timers;
    uint8_t m_outputTypes;

    std::time_t m_start;

    void _raw(char* text, bool newline, enum LoggerSectTypes type);

    public:
    Logger();
    ~Logger();

    // Different levels of logging
    Logger& log(char* text);
    Logger& debug(char* text);
    Logger& error(char* text);
    Logger& time(char* timer);
    Logger& timeEnd(char* timer);
    Logger& clear();

    Logger& log(const char* text) { return log((char*) text); }
    Logger& debug(const char* text) { return debug((char*) text); }
    Logger& error(const char* text) { return error((char*) text); }
    Logger& time(const char* text) { return time((char*) text); }
    Logger& timeEnd(const char* text) { return timeEnd((char*) text); }

    Logger& save(const char* text);

    void setOutputType(uint8_t outputTypes);

    friend std::ostream& operator<<(std::ostream& os, const Logger& logger) {

        // Print out start time
        os << "TACuOS Startup " << std::ctime(&logger.m_start) << std::endl;

        uint32_t i = 0;
        for (uint32_t j = 0; j < logger.m_sections->size(); j++) {
            LoggerSect section = logger.m_sections->get(j);

            // Do output
            if (section.type & logger.m_outputTypes) {
                for (uint32_t k = 0; k < section.length; k++) {
                    os << logger.m_log->get(i + k);
                }
            }

            i += logger.m_sections->get(j).length;
        }

        return os;
    }
};