#include <iostream>
#include "fstream"
#include <sstream>
#include "map.h"
#include "vec.h"
#include "parser.h"
#include "logger.h"

uint32_t hasher(char* const &);
bool equals(char* const &, char* const &);

void countWords(Vec<char*>* sections, uint8_t start, uint8_t end, MapChain<char*, uint16_t> &chain);
void countWords(Vec<char*>* sections, uint8_t start, uint8_t end, MapLinear<char*, uint16_t> &linear);
uint16_t countSentences(Vec<char*>* sections, uint8_t start, uint8_t end);
int8_t entryCmp(const KeyPair<char*, uint16_t>& a, const KeyPair<char*, uint16_t>& b);
void logEntries(const Vec<KeyPair<char*, uint16_t>>* entries, Logger& cs);

const char* abbrevList[] = {
    "mr",
    "mrs",
    "ms",
    "dr",
    "esq",
    "hon",
    "jr",
    "prof",
    "rev",
    "sr",
    "st"
};
const uint32_t abbrevListLen = sizeof(abbrevList) / sizeof(abbrevList[0]);

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Please supply filename to analize." << std::endl;
        return 0;
    }

    Logger console = Logger();
    Logger minicon = Logger();

    console.time("Total Runtime");

    console.time("File Read");
    std::ifstream fin = std::ifstream(argv[1]);
    fin.seekg(0, std::ios_base::end);

    uint32_t size = fin.tellg();
    fin.seekg(0); // Move back to start
    console.timeEnd("File Read");
    console.log("");

    char* text = new char[size];
    fin.read(text, size);

    // Tokenize into sections
    Vec<char*>* sections = parser::tokenizeSections(text);
    Vec<KeyPair<char*, uint16_t>>* slice, *entries;
    std::stringstream ss;

    std::cout << "--- Options ---" << std::endl
              << "(l)inear probing" << std::endl
              << "open (c)haining" << std::endl
              << "read (a)ll" << std::endl
              << "find (p)attern" << std::endl
              << "read (s)entences" << std::endl
              << "(%) Occupancy Ratio" << std::endl
              << "($) Chain length" << std::endl
              << "(q)uit" << std::endl;

    char opt;
    bool run = true;
    while (run) {
        std::cin >> opt;

        switch (opt) {
            
            // (L)inear Probing
            case 'l': {
                std::cout << "Counting words... ";

                // Process sections 1-6 using chain map
                console.log("Counting words in sections I - VI using OPEN CHAINING");
                console.time("Open Chain");
                minicon.time("Processing");
                MapChain<char*, uint16_t> chain(hasher, 256, equals);
                countWords(sections, 0,6, chain);
                console.timeEnd("Open Chain");
                minicon.timeEnd("Processing");

                entries = chain.entries()->sort(entryCmp);

                minicon.log("Section I - VI word frequencies using Linear Probing");
                minicon.log("50 words of the lowest frequency");
                slice = entries->slice(0,50);
                logEntries(slice, minicon);
                delete slice;

                minicon.log("\n50 words of the highest frequency");
                slice = entries->slice(-50,50);
                logEntries(slice, minicon);
                delete slice;
                delete entries;

                minicon.save("./output/log_1-6.txt");
                minicon.clear();

                std::cout << "Finished!" << std::endl;
                break;
            }

            // Open (C)haining
            case 'c': {
                std::cout << "Counting words... ";

                // Process sections 7-12 using linear map
                console.log("Counting words in sections VII - XII using LINEAR PROBING");
                console.time("Linear Probing");
                minicon.time("Processing");
                MapLinear<char*, uint16_t> linear(hasher, 1024, equals);
                countWords(sections, 6,12, linear);
                console.timeEnd("Linear Probing");
                minicon.timeEnd("Processing");

                entries = linear.entries()->sort(entryCmp);

                minicon.log("Section VII - XII word frequencies using Linear Probing");
                minicon.log("50 words of the lowest frequency");
                slice = entries->slice(0,50);
                logEntries(slice, minicon);
                delete slice;

                minicon.log("\n50 words of the highest frequency");
                slice = entries->slice(-50,50);
                logEntries(slice, minicon);
                delete slice;
                delete entries;

                minicon.save("./output/log_7-12.txt");
                minicon.clear();

                std::cout << "Finished!" << std::endl;
                break;
            }

            // Read (A)ll
            case 'a': {
                std::cout << "Counting words... ";

                // Process all sections using chain map
                // Need this to get actual final tally of most/least common words
                console.log("Counting words in all sections using OPEN CHAINING");
                console.time("All Sections");
                minicon.time("Processing");
                MapChain<char*, uint16_t> allWords(hasher, 256, equals);
                countWords(sections, 0,12, allWords);
                console.timeEnd("All Sections");
                minicon.timeEnd("Processing");
                console.log("");

                entries = allWords.entries()->sort(entryCmp);

                minicon.log("Section I - XII word frequencies using Linear Probing");
                minicon.log("50 words of the lowest frequency");
                slice = entries->slice(0,50);
                logEntries(slice, minicon);
                delete slice;

                minicon.log("\n50 words of the highest frequency");
                slice = entries->slice(-50,50);
                logEntries(slice, minicon);
                delete slice;
                delete entries;

                minicon.save("./output/log_1-12.txt");
                minicon.clear();

                std::cout << "Finished!" << std::endl;
                break;
            }

            // Find (P)attern in section 8
            case 'p': {

                // Get pattern to search for
                std::cout << "Enter in a pattern to search for: ";
                char pattern[100];
                std::cin >> pattern;

                ss << "Searching for the pattern \"" << pattern << "\"";
                console.log(ss.str().c_str());
                ss.clear();

                console.time("Search");
                char* s9Lower = parser::lowered(sections->get(8));
                Vec<uint32_t>* thes = parser::rabinKarp(s9Lower, pattern);

                ss << "Found " << thes->size() << " matches!";
                console.log(ss.str().c_str());
                ss.clear();

                uint32_t s9Len = strlen(s9Lower);

                const uint8_t searchPadding = 10;
                std::cout << "Found " << thes->size() << " matches!" << std::endl;
                char line[100];
                for (uint32_t i = 0; i < thes->size(); i++) {
                    uint32_t index = thes->get(i);

                    uint32_t start = (index >= searchPadding ? index - searchPadding : 0);
                    uint32_t end = (index + searchPadding < s9Len ? index + searchPadding : s9Len - 1);

                    // Print out line
                    uint32_t len = end - start;
                    // std::cout << start << " " << len << std::endl;
                    memcpy(line, s9Lower + start, sizeof(char) * len);

                    // Replace all '\n' with '\\'
                    for (uint8_t j = 0; j < len; j++) {
                        if (line[j] == '\n') line[j] = '\\';
                    }

                    line[len] = 0x00;
                    std::cout << i + 1 << ": " << line << std::endl;
                }
                delete s9Lower;
                break;
            }

            // Read (S)entences
            case 's': {

                // Get number of sentences from sections
                console.log("Counting sentences...");
                console.time("Count");
                uint16_t sentences = countSentences(sections, 0,12);
                console.timeEnd("Count");

                ss << "Found " << sentences << " sentences\n";
                console.log(ss.str().c_str());
                ss.clear();

                std::cout << sentences << " sentences." << std::endl;
                break;
            }

            // % Occupancy ex
            case '%': {
                float ratio;
                std::cout << "Enter in occupancy ratio: ";
                std::cin >> ratio;

                if (ratio < 0 || ratio > 1) {
                    std::cout << "Invalid ratio!" << std::endl;
                    break;
                }

                // Use section 1 for words
                Vec<char*>* words = parser::tokenizeWords(sections->get(0));

                // Process section 1 using Linear map
                console.log("Counting words in section I using LINEAR PROBING");

                ss << "Occupancy ratio set to " << ratio;
                console.log(ss.str().c_str());
                ss.clear();

                console.time("Linear Probing");
                MapLinear<char*, uint16_t> linear(hasher, (uint32_t) (words->size() / ratio), equals);

                minicon.time("Hash Time");
                countWords(sections, 0,1, linear);
                console.timeEnd("Linear Probing");
                minicon.timeEnd("Hash Time");

                std::cout << minicon << std::endl;

                minicon.clear();

                delete words;
                break;
            }

            // Chain length
            case '$': {
                uint32_t len;
                std::cout << "Enter in desired chain length: ";
                std::cin >> len;

                // Use section 1 for words
                Vec<char*>* words = parser::tokenizeWords(sections->get(0));

                // Process section 1 using Linear map
                console.log("Counting words in section I using OPEN CHAINING");

                ss << "Chain length set to " << len;
                console.log(ss.str().c_str());
                ss.clear();

                console.time("Linear Probing");
                MapChain<char*, uint16_t> chain(hasher, (uint32_t) (words->size() / len), equals);

                minicon.time("Hash Time");
                countWords(sections, 0,1, chain);
                console.timeEnd("Open Chaining");
                minicon.timeEnd("Hash Time");

                std::cout << minicon << std::endl;

                minicon.clear();

                delete words;
                break;
            }

            case 'q':
                run = false;
                break;

            default:
                std::cout << "Invalild key \"" << opt << "\"" << std::endl;
                break;

        }

    }

    console.timeEnd("Total Runtime");
    console.save("./output/log.txt");
}

uint32_t hasher(char* const &str) {
    uint32_t digest = 7;
    for (uint32_t i = 0; str[i]; i++) {
        digest = digest * 31 + str[i];
    }
    return digest;
}

bool equals(char* const &a, char* const &b) {
    return strcmp(a, b) == 0;
}

void countWords(Vec<char*>* sections, uint8_t start, uint8_t end, MapChain<char*, uint16_t> &chain) {
    for (uint8_t i = start; i < end; i++) {
        
        // Split into words
        Vec<char*>* words = parser::tokenizeWords(sections->get(i));
        
        // Loop through all words, and add to map
        for (uint32_t j = 0; j < words->size(); j++) {
            char* word = parser::trim(words->get(j), true);
            parser::lower(word); // Case incensitive conversion

            if (chain.has(word)) {
                chain.set(word, *chain.get(word) + 1); // Found in map, increment
                delete word; // Remove copy, to prevent memory leak
            }
            else chain.set(word, 1);                   // Not in map, add
        }
    }
}

void countWords(Vec<char*>* sections, uint8_t start, uint8_t end, MapLinear<char*, uint16_t> &linear) {
    for (uint8_t i = start; i < end; i++) {
        
        // Split into words
        Vec<char*>* words = parser::tokenizeWords(sections->get(i));
        
        // Loop through all words, and add to map
        for (uint32_t j = 0; j < words->size(); j++) {
            char* word = parser::trim(words->get(j), true);
            parser::lower(word); // Case incensitive conversion

            if (linear.has(word)) {
                linear.set(word, *linear.get(word) + 1); // Found in map, increment
                delete word; // Remove copy, to prevent memory leak
            }
            else linear.set(word, 1);                   // Not in map, add
        }
    }
}

uint16_t countSentences(Vec<char*>* sections, uint8_t start, uint8_t end) {

    // Build abbreviation list
    char* abbrevListCpy[abbrevListLen];
    for (uint32_t i = 0; i < abbrevListLen; i++) {
        uint32_t len = strlen(abbrevList[i]);
        char* buf = new char[len + 1];
        strcpy(buf, abbrevList[i]);

        abbrevListCpy[i] = buf;
    }
    Vec<char*>* abbrevs = new Vec<char*>(abbrevListCpy, abbrevListLen);

    uint16_t sentenceCt = 0;
    for (uint8_t i = start; i < end; i++) {
        
        // Split into sentences
        Vec<char*>* sentences = parser::tokenizeSentences(sections->get(i), abbrevs);

        // Count number of sentences
        sentenceCt += sentences->size();

        // No longer need sentences
        delete sentences;
    }

    // Free abbreviation list
    for (uint32_t i = 0; i < abbrevListLen; i++) {
        delete abbrevListCpy[i];
    }

    return sentenceCt;
}

int8_t entryCmp(const KeyPair<char*, uint16_t>& a, const KeyPair<char*, uint16_t>& b) {
    if (a.val < b.val) return -1;
    if (a.val > b.val) return 1;
    return 0;
}

void logEntries(const Vec<KeyPair<char*, uint16_t>>* entries, Logger& cs) {
    if (entries->size() == 0) {
        cs.log("[]");
        return;
    }
    std::stringstream ss;
    if (entries->size() == 1) { // Single entry has special formatting
        ss << "[ " << entries->get(0) << "]";
    }
    
    // Generic n-count formatting
    else {
        ss << "[" << std::endl;
        for (uint32_t i = 0; i < entries->size(); i++) {
            ss << "  " << entries->get(i).val << ": " << entries->get(i).key << std::endl;
        }
        ss << "]";
    }

    cs.log(ss.str().c_str());
}