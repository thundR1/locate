#include <iostream>

#include "./AhoCorasick/AhoCorasick.hpp"
#include "./util/io_file/io_file.hpp"

int main(int argc, char* argv[]) {
    
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <patterns_file> <text_file>\n";
        return 1;
    }

    std::string patternsPath = argv[1];
    std::string textPath = argv[2];

    try {
        auto patterns = IOFile::readPatternsFromFile(patternsPath);
        auto text = IOFile::readTextFromFile(textPath);

        AhoCorasick machine(patterns);
        auto ans = machine.search(text);

        for (const auto& el : ans) {
            std::cout << el.first << "   " << el.second << '\n';
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}

