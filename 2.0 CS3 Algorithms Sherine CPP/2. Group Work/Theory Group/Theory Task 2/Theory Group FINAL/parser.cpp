#include "parser.h"
#include <iostream>

uint32_t tokenizeSentencesHasher(char* const &abbrev);
void tokenizeSentenceDeallocator(char* key, uint32_t i);
inline bool isCharacter(char ch);

constexpr uint32_t HASH_MAGIC_NUMBER = 31;

uint32_t genHash(const char* text, uint32_t &mul, uint8_t limit);
uint32_t rollHash(uint32_t digest, char remove, char add, uint32_t mul);

void parser::lower(char* text) {
    for (uint32_t i = 0; text[i]; i++) {
        
        // Uppercase character detected!
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] += 'a' - 'A'; // Convert from uppercase to lowercase
        }
    }
}

// Return copy of text, which is now lowercase (does NOT modify original)
char* parser::lowered(const char* text) {
    char* buf = new char[strlen(text) + 1]; // Allocate new memory buffer for lowercased text
    strcpy(buf, text);                  // Copy text into buffer
    parser::lower(buf);                 // Perform actual lowercase operation
    return buf;
}

void parser::upper(char* text) {
    for (uint32_t i = 0; text[i]; i++) {
        
        // Lowercase character detected!
        if (text[i] >= 'a' && text[i] <= 'a') {
            text[i] -= 'a' - 'A'; // Convert from lowercase to uppercase
        }
    }
}

// Return copy of text, which is now uppercase (does NOT modify original)
char* parser::uppered(const char* text) {
    char* buf = new char[strlen(text) + 1]; // Allocate new memory buffer for lowercased text
    strcpy(buf, text);                  // Copy text into buffer
    parser::upper(buf);                 // Perform actual uppercase operation
    return buf;
}

Vec<char*>* parser::tokenizeWords(const char* text) {
    uint32_t buffer_start = 0;
    Vec<char*>* tokens = new Vec<char*>();

    // Loop through all characters
    uint32_t i;
    for (i = 0; text[i]; i++) {
        char ch = text[i];
        if (ch == '\r') continue; // Ignore my least favorite character
        
        // Detect "--" sequences
        bool isDoubleDash = i > 0 && (ch == '-' && text[i-1] == '-');
        
        // Create new token
        if (ch == ' ' || ch == '\n' || isDoubleDash) {
            uint32_t buffer_len = i - buffer_start;

            // Non-empty word
            if (buffer_len != 0) {
                char* str = new char[buffer_len + 1]; // Allocate enough space for word
                memcpy(str, text + buffer_start, sizeof(char) * buffer_len);
                str[buffer_len] = 0x00; // Null byte
                tokens->push(str);
            }

            buffer_start = i + 1; // Start new buffer
            continue;
        }
    }

    // Push final token into vector
    if (buffer_start != i) {
        uint32_t buffer_len = i - buffer_start;

        char* str = new char[buffer_len + 1]; // Allocate enough space for word
        memcpy(str, text + buffer_start, sizeof(char) * buffer_len);

        str[buffer_len] = 0x00; // Null byte
        tokens->push(str);
    }

    return tokens;
}

Vec<char*>* parser::tokenizeSentences(const char* text, const Vec<char*>* abbrevs) {
    uint32_t buffer_start = 0;
    uint32_t abbrev_start = 0;

    // Act as a set (value is extraneous); Used to determine if some string is an abbreviation in linear time
    MapLinear<char*, bool> abbrevSet(tokenizeSentencesHasher, abbrevs == nullptr ? 1 : 4 * abbrevs->size()); // Start with good occupancy ratio
    if (abbrevs != nullptr) {
        for (uint32_t i = 0; i < abbrevs->size(); i++) {
            abbrevSet.set(parser::uppered(abbrevs->get(i)), true);
        }
    }


    Vec<char*>* tokens = new Vec<char*>();

    uint32_t i;
    char abbrevBuffer[100]; // Cheap pre-allocated memory block (larger than any word... hopefully)
    for (i = 0; text[i]; i++) {
        
        // New word detected: update abbrev buffer
        if (text[i] == ' ') {
            abbrev_start = i + 1;
            continue;
        }
        
        // Ignore non-sentence ending characters
        if (text[i] != '.' && text[i] != '!' && text[i] != '?') continue;

        // Fill abbrevBuffer so able to hash to check against all other abbreviations
        uint32_t abbrevLen = i - abbrev_start - 1; // -1 to account for trailing '.' (which isn't counted!)
        memcpy(abbrevBuffer, text + abbrev_start, sizeof(char) * abbrevLen);
        abbrevBuffer[abbrevLen] = 0x00; // Null byre
        parser::upper(abbrevBuffer); // Case incensitive conversion

        // Check against abbreviation list
        if (abbrevSet.has(abbrevBuffer)) continue; // Abbreviation detected; Ignore

        // Not abbreviation: Mark as sentence and continue
        uint32_t buffer_len = i - buffer_start;

        // Non-empty word
        if (buffer_len != 0) {
            char* str = new char[buffer_len + 1]; // Allocate enough space for sentence
            memcpy(str, text + buffer_start, sizeof(char) * buffer_len);
            str[buffer_len] = 0x00; // Null byte
            tokens->push(str);
        }

        buffer_start = i + 1; // Start new buffer
    }

    // Add last sentence to tokens

    // Non-empty sentence
    if (buffer_start != i) {
        uint32_t buffer_len = i - buffer_start;

        char* str = new char[buffer_len + 1]; // Allocate enough space for sentence
        memcpy(str, text + buffer_start, sizeof(char) * buffer_len);
        str[buffer_len] = 0x00; // Null byte
        tokens->push(str);
    }

    // Deallocate uppered cstrings
    Vec<char*>* abbrevKeys = abbrevSet.keys();
    abbrevKeys->forEach(tokenizeSentenceDeallocator);
    delete abbrevKeys;

    return tokens;
}

// Stolen wholecloth from Java String hashing
uint32_t tokenizeSentencesHasher(char* const &abbrev) {
    uint32_t digest = 7;
    for (uint32_t i = 0; abbrev[i]; i++) {
        digest = digest * 31 + abbrev[i];
    }
    return digest;
}

// Deallocate keys (allocated with 'new', so deallocated with 'delete')
void tokenizeSentenceDeallocator(char* key, uint32_t _i) {
    delete key;
}

Vec<char*>* parser::tokenizeSections(const char* text) {
    uint32_t buffer_start = 0;
    Vec<char*>* tokens = new Vec<char*>();

    // Loop through all characters
    uint32_t i;
    for (i = 0; text[i]; i++) {
        if (i < 3) continue; // Keep scanning text until 4 characters discovered

        char ch = text[i];
        
        // Ignore non-newline previous characters
        if (ch != '\n') continue;

        // Check if all characters on line are upper case
        uint32_t j = i;
        bool valid = true;
        bool isRoman = true;
        bool hasNumeral = false;
        bool hasFlavor = false;
        while (text[j]) {
            j++; // Check next char

            char ch = text[j];

            // End of line!
            if (ch == '\n') break;

            // Reset Romanness
            if (ch == ' ') {
                isRoman = true;
                continue;
            }

            if (ch == '.' && isRoman) {
                hasNumeral = true;
                continue;
            }

            if (!(ch == 'I' || ch == 'V' || ch == 'X')) {
                isRoman = false;
                hasFlavor = true;
            }

            if (!(
                (ch >= 'A' && ch <= 'Z') // Must be all uppercase
                || (ch == '-' || ch == '\'') // Allowed other characters
            )) {
                valid = false;
                break;
            }
        }

        // Didn't find section header
        if (!valid || !hasNumeral || !hasFlavor) {
            
            // Search for multiple newlines (indicates end of book)
            uint8_t newlines = 0;
            while (text[i + newlines++] == '\n');

            // Only don't count as new section if not enough newlines
            if (newlines < 10) continue;
        }

        // Create new token 
        uint32_t buffer_len = i - buffer_start - 3;

        // Non-empty buffer
        if (buffer_len != 0) {
            char* str = new char[buffer_len + 1]; // Allocate enough space for section
            memcpy(str, text + buffer_start, sizeof(char) * buffer_len);
            str[buffer_len] = 0x00; // Null byte
            tokens->push(str);
        }

        // Scan for next newline (Skip header info)
        i = j;
        while (text[i] && text[i] != '\n') { i++; }
        
        // Start buffer after next newline (once section header has ended)
        buffer_start = i + 2;
    }

    // Add in last section
    if (buffer_start != i) {
        uint32_t buffer_len = i - buffer_start - 3;

        char* str = new char[buffer_len + 1]; // Allocate enough space for section
        memcpy(str, text + buffer_start, sizeof(char) * buffer_len);
        str[buffer_len] = 0x00; // Null byte
        tokens->push(str);
    }

    return tokens;
}

char* parser::trim(const char* text, bool all) {

    uint32_t len = strlen(text);
    char* buffer;

    if (all) {
        uint32_t buffLen = 0;
        buffer = new char[len + 1];
        
        // Remove ANY whitespace/symbolic character
        for (uint32_t i = 0; i < len; i++) {
            
            // Character invalid; ignore
            if (!isCharacter(text[i])) continue;

            // Push character into buffer
            buffer[buffLen++] = text[i];
        }

        // Shrink buffer size to match bufferLen
        char* tempBuf = new char[buffLen + 1];
        memcpy(tempBuf, buffer, buffLen);
        tempBuf[buffLen] = 0x00; // Add in null byte

        // Clear up old buffer, and replace with new buffer
        delete[] buffer;
        buffer = tempBuf;
    }

    // Obly remove whitespace/symbolic characters from start/end
    else {

        uint32_t start;
        uint32_t end;

        // Remove starting whitespace/symbols
        for (start = 0; start < len; start++) {
            
            // Found non-symbol character!
            // Use this to mart the start of the new string
            if (isCharacter(text[start])) break;
        }

        // Remove ending whitespace/symbols
        for (end = len; end > start; end--) {

            // Found non-symbol character!
            // Use this to mart the end of the new string
            if (isCharacter(text[end-1])) break;
        }

        std::cout << text << std::endl;

        // Shrink buffer size to match bufferLen
        uint32_t buffLen = end - start;
        buffer = new char[buffLen + 1];
        memcpy(buffer, text + start, buffLen);
        buffer[buffLen] = 0x00; // Add in null byte
    }
    
    return buffer;
}

bool isCharacter(char ch) {
    return (ch >= 'A' && ch <= 'Z')
        || (ch >= 'a' && ch <= 'z')
        || (ch >= '0' && ch <= '9')
        || ch == '-';
}

Vec<uint32_t>* parser::rabinKarp(const char* text, const char* pattern) {
    Vec<uint32_t>* matches = new Vec<uint32_t>();

    uint8_t patternLen = strlen(pattern);
    if (patternLen == 0) return matches; // Invalid pattern
    
    uint32_t mul;
    uint32_t patternHash = genHash(pattern, mul, 0);
    uint32_t textHash = genHash(text, mul, patternLen);

    for (uint32_t i = patternLen; text[i]; i++) {

        // Hash matches, and word matches
        if (patternHash == textHash && memcmp(pattern, text + i - patternLen, sizeof(char) * patternLen) == 0) {
            matches->push(i - patternLen);
        }

        textHash = rollHash(textHash, text[i - patternLen], text[i], mul);
    }
    return matches;
}

// Generate initial hash
uint32_t genHash(const char* text, uint32_t& mul, uint8_t limit) {
    mul = 1;
    uint32_t digest = 0;

    uint8_t i = 0;
    while (text[i]) {
        digest = rollHash(digest, 0, text[i], 0);
        if (i != 0) mul *= HASH_MAGIC_NUMBER;
        i++;

        if (i == limit) break;
    }

    return digest;
}

// Do simple rolling hash
uint32_t rollHash(uint32_t digest, char remove, char add, uint32_t mul) {
    return (digest - (remove*mul)) * HASH_MAGIC_NUMBER + add;
}
