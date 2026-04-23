//
// Created by NEXT STORE on 4/22/2026.
//

#include "Node.hpp"
#include <iostream>

Node::Node() {
    this->failureLink = nullptr;
}

Node::~Node() {
    for (auto& [c, child] : children) {
        delete child;
    }
}

bool Node::hasChild(const std::string& key) const {
    return this->children.contains(key);
}

Node* Node::getChild(const std::string& key) {
    auto it = this->children.find(key);
    if (it == this->children.end()) return nullptr;
    return it->second;
}

void Node::setChild(const std::string& key, Node* node) {
    this->children[key] = node;
}

void Node::addOutputLink(const std::string& node, size_t len) {
    this->outputs.insert(make_pair(node, len));
}

void Node::copyOutputs(Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("null pointer error, at copyOutputss");
    }
    for (const auto& output : node->outputs) {
        this->outputs.insert(output);
    }
}

void Node::setFailureLink(Node* node) {
    this->failureLink = node;
}

Node* Node::getFailureLink() {
    return this->failureLink;
}
