#ifndef RBTNODE_HPP
#define RBTNODE_HPP

#include <iostream>

template<class Key, class Value>
class RBTNode {

private:

public:
    std::string color;
    Key key;
    Value value;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;

    RBTNode(): color(""), left(NULL), right(NULL), parent(NULL) {}

    RBTNode(std::string color, Key key, Value value, RBTNode* left, RBTNode* right, RBTNode* parent)
    : color(color), key(key), value(value), left(left), right(right), parent(parent) {}

    ~RBTNode() { }

};

#endif
