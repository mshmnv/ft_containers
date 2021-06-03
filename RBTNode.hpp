#ifndef RBTNODE_HPP
#define RBTNODE_HPP

#include <iostream>

#define BLACK 0
#define RED 1

template<class Key, class Value>
class RBTNode {

private:

public:
    int color;
//    Key key;
//    Value value;
    std::pair<const Key, Value> pair;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;

    RBTNode(): color(BLACK), left(NULL), right(NULL), parent(NULL) {}

    RBTNode(int color, std::pair<const Key, Value> pair, RBTNode* left, RBTNode* right, RBTNode* parent)
    : color(color), pair(pair), left(left), right(right), parent(parent) {}

//    RBTNode(): color(BLACK), left(NULL), right(NULL), parent(NULL) {}
//
//    RBTNode(int color, Key key, Value value, RBTNode* left, RBTNode* right, RBTNode* parent)
//            : color(color), key(key), value(value), left(left), right(right), parent(parent) {}
    ~RBTNode() { }

};

#endif
