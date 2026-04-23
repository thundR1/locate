#ifndef UNICODE_UTIL
#define UNICODE_UTIL

#include <unicode/brkiter.h>
#include <unicode/unistr.h>

#include <vector>
#include <string>

std::vector<std::string> split_graphemes(const std::string& text);

#endif
