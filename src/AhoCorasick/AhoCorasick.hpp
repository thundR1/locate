//
// Created by NEXT STORE on 4/22/2026.
//

#ifndef FINDER_AHOCORASICK_HPP
#define FINDER_AHOCORASICK_HPP

#include "../Node/Node.hpp"

#include <vector>
#include <string>

class AhoCorasick final {
private:
    Node* root;
public:
    explicit AhoCorasick(const std::vector<std::string>& patterns);
    ~AhoCorasick();
    std::vector<std::pair<size_t, std::string>> search(const std::string& text);
};


#endif //FINDER_AHOCORASICK_HPP

