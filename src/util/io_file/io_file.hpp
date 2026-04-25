#ifndef LOCATE_IO_FILE_HPP
#define LOCATE_IO_FILE_HPP

#include <string>
#include <vector>

class IOFile final {
public:
    static std::vector<std::string> readPatternsFromFile(const std::string& filename);
    static std::string readTextFromFile(const std::string& filename);
};

#endif
