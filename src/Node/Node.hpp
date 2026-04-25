#ifndef FINDER_NODE_HPP
#define FINDER_NODE_HPP

#include <map>
#include <set>
#include <string>

class Node final {
private:
    Node* failureLink;
public:
    std::map<std::string, Node*> children;
    std::set<std::pair<std::string, size_t>> outputs;
    Node();
    ~Node();
    [[nodiscard]] bool hasChild(const std::string& key) const;
    Node* getChild(const std::string& key);
    void setChild(const std::string& key, Node* node);
    void addOutputLink(const std::string& node, size_t len);
    void copyOutputs(Node* node);
    void setFailureLink(Node* node);
    Node* getFailureLink();
};


#endif //FINDER_NODE_HPP

