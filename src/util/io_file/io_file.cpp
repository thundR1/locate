#include "io_file.hpp"
#include <fstream>

std::vector<std::string> IOFile::readPatternsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open patterns file");
    }

    std::vector<std::string> patterns;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty())
            patterns.push_back(line);
    }

    return patterns;
}

std::string IOFile::readTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open text file");
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    return content;
}
