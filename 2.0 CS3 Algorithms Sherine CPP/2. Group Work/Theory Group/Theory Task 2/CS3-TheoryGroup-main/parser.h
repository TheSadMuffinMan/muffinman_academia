#pragma once

#include "stdint.h"
#include <cstring>
#include "vec.h"
#include "map.h"

namespace parser {
    void lower(char* text);
    char* lowered(const char* text);
    void upper(char* text);
    char* uppered(const char* text);

    Vec<char*>* tokenizeWords(const char* text);
    Vec<char*>* tokenizeSentences(const char* text, const Vec<char*>* abbrevs = nullptr); // Abbrevs: If previous word matches word in 'abbrev' Vec, sentence DOESN'T end
    Vec<char*>* tokenizeSections(const char* text);
    char* trim(const char* text, bool all = false); // Remove starting and ending whitespace

    Vec<uint32_t>* rabinKarp(const char* text, const char* pattern);
}
