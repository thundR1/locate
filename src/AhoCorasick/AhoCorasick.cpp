//
// Created by NEXT STORE on 4/22/2026.
//

#include "AhoCorasick.hpp"
#include "../util/unicode_util.hpp"
#include <queue>

AhoCorasick::AhoCorasick(const std::vector<std::string>& patterns) {
    this->root = new Node();
    Node* currNode = root;
    for (const auto& pattern : patterns) {
        auto tokens = split_graphemes(pattern);
        
        for (const std::string& t : tokens) {
            if (!currNode->hasChild(t)) {
                currNode->setChild(t, new Node());
            }
            currNode = currNode->getChild(t);
        }

        currNode->addOutputLink(pattern, tokens.size());
        currNode = root;
    }
    root->setFailureLink(root);

    std::queue<Node*> queue;

    for (auto& child : root->children) {
        child.second->setFailureLink(root);
        queue.emplace(child.second);
    }

    while (!queue.empty()) {
        Node* curr = queue.front();
        queue.pop();
        for (const auto& [ch, child] : curr->children) {
            queue.emplace(child);
            Node* fl = curr->getFailureLink();
            while (fl != root && !fl->hasChild(ch)) {
                fl = fl->getFailureLink();
            }
            Node* next = fl->getChild(ch);
            if (!next) next = root;
            child->setFailureLink(next);
            child->copyOutputs(child->getFailureLink());
        }
    }
}

AhoCorasick::~AhoCorasick() {
    delete root;
}

std::vector<std::pair<size_t, std::string>> AhoCorasick::search(const std::string& text) {
    std::vector<std::pair<size_t, std::string>> found;
    
    Node* curr = this->root;
    auto tokens = split_graphemes(text);
    
    for (size_t i = 0; i < tokens.size(); i++) {
        const std::string& t = tokens[i];
        while (curr != root && !curr->hasChild(t)) {
            curr = curr->getFailureLink();
        }
        if (curr->hasChild(t)) {
            curr = curr->getChild(t);
        }
        for (const auto& [pat, len] : curr->outputs) {
            //auto len = split_graphemes(pat).size();
            found.emplace_back(i + 1 - len, pat);
        }
    }

    return found;
}

