#ifndef RBTNODE_HPP
#define RBTNODE_HPP

#include <iostream>
#include "map.hpp"

#define BLACK 0
#define RED 1

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class RBTnode {
private:
    typedef std::pair<const Key,T> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;

public:
    int color;
    std::pair<const Key, T> *pair;
    RBTnode* left;
    RBTnode* right;
    RBTnode* parent;
    key_compare _comp;
    std::allocator<std::pair<const Key,T> > _pairAllocator;
    bool isEmpty;

    RBTnode(const value_type& val, RBTnode<Key,T> *parent, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : color(RED), left(NULL), right(NULL), parent(parent), _comp(comp), _pairAllocator(alloc), isEmpty(false) {
        this->pair = this->_pairAllocator.allocate(1);
        this->_pairAllocator.construct(pair, val);
    }

    RBTnode(RBTnode<Key,T> *parent, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : color(RED), pair(NULL), left(NULL), right(NULL), parent(parent), _comp(comp), _pairAllocator(alloc), isEmpty(true) {
    }
    ~RBTnode() { this->_pairAllocator.deallocate(this->pair, 1); }
};


void swapColors(int& color1, int& color2) {
    int tmp = color2;
    color2 = color1;
    color1 = tmp;
}

template<class Key, class T>
RBTnode<Key,T> *rotateLeft(RBTnode<Key,T> *node) {
    RBTnode<Key,T> *child = node->right;
    RBTnode<Key,T> *childLeft = child->left;
    child->left = node;

    child->parent = node->parent;
    if (node->parent->left == node)
        node->parent->left = child;
    else
        node->parent->right = child;
    node->parent = child;

    node->right = childLeft;
    if (childLeft)
        childLeft->parent = node;
    return child;
}

template<class Key, class T>
RBTnode<Key,T> *rotateRight(RBTnode<Key,T> *node) {
    RBTnode<Key,T> *child = node->left;
    RBTnode<Key,T> *childRight = child->right;
    child->right = node;

    child->parent = node->parent;
    if (node->parent->left == node)
        node->parent->left = child;
    else
        node->parent->right = child;
    node->parent = child;

    node->left = childRight;
    if (childRight)
        childRight->parent = node;
    return child;
}

template<class Key, class T, class Compare, class Alloc>
RBTnode<Key,T> *insertNode(RBTnode<Key,T> *node, RBTnode<Key,T> *parent, const std::pair<const Key,T>& val, Compare comp, Alloc pairAlloc) {
    if (node == NULL)
        return new RBTnode<Key,T>(val, parent, comp, pairAlloc);
    if (comp(val.first, node->pair->first) && (node->left && node->left->isEmpty)) {
        RBTnode<Key,T> *newNode = new RBTnode<Key,T>(val, NULL, comp, pairAlloc);
        newNode->left = node->left;
        node->left->parent = newNode;
        newNode->parent = node;
        node->left = newNode;
        return node;
    }
    else if (comp(val.first, node->pair->first))
        node->left = insertNode(node->left, node, val, comp, pairAlloc);
    // if value is bigger but there is emptyNode on the right
    else if (!comp(val.first, node->pair->first) && (node->right && node->right->isEmpty)) {
        RBTnode<Key,T> *newNode = new RBTnode<Key,T>(val, NULL, comp, pairAlloc);
        newNode->right = node->right;
        node->right->parent = newNode;
        newNode->left = node;
        node->parent = newNode;
        node->right = NULL;
        swapColors(newNode->color, node->color);
        if ((node->left && node->left->color == RED) && ( node->left->left && node->left->left->color == RED)) {
            node = rotateRight(node);
            swapColors(node->color, node->right->color);
        }
        return newNode;
    }
    else if (!comp(val.first, node->pair->first))
        node->right = insertNode(node->right, node, val, comp, pairAlloc);
    else
        return node;

    if ((node->right && node->right->isEmpty) || (node->left && node->left->isEmpty) )
        return node;
    // case 1: right child is RED but left child is BLACK or doesn't exist
    if ((node->right && node->right->color == RED) && (node->left == NULL || node->left->color == BLACK)) {
        node = rotateLeft(node);
        swapColors(node->color, node->left->color);
    }
    // case 2: left child and left grand child are RED
    if ((node->left && node->left->color == RED) && ( node->left->left && node->left->left->color == RED)) {
        node = rotateRight(node);
        swapColors(node->color, node->right->color);
    }
    // case 3: left and right children  are RED
    if ((node->left && node->left->color == RED) && (node->right && node->right->color == RED)) {
        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }
    return node;
}

template<class Key, class T>
void deleteNode(RBTnode<Key,T> *node) {
    RBTnode<Key,T> *parent = node->parent;
    if (!node->left && !node->right) {
        if (parent->right == node)
            parent->right = NULL;
        else
            parent->left = NULL;
    }
    else if (node->right && !node->left) {
        if (parent->right == node)
            parent->right = node->right;
        else
            parent->left = node->right;
        node->right->parent = parent;
    }
    else if (!node->right && node->left) {
        if (parent->right == node)
            parent->right = node->left;
        else
            parent->left = node->left;
        node->left->parent = parent;
    }
    else {
        RBTnode<Key,T> *next = node;
        if (next->right && !next->right->isEmpty) {
            next = next->right;
            while (next->left)
                next = next->left;
        } else {
            while (next->parent && next == next->parent->right)
                next = next->parent;
            next = next->parent;
        }
        if (!next) {
            next = node;
            if (next->left) {
                next = next->left;
                while (next->right)
                    next = next->right;
            } else {
                while (next->parent && next == next->parent->left)
                    next = next->parent;
                next = next->parent;
            }
        }
        std::pair<const Key,T> *tmp = next->pair;
        next->pair = node->pair;
        node->pair = tmp;
        return deleteNode(next);
    }
    delete node;
    return;
}


template<class Key, class T>
void inorderPrinting(RBTnode<Key,T> *node)
{
    if (node == NULL || node->isEmpty)
        return ;
    inorderPrinting(node->left);
    std::cout << node->pair->first << ":" << node->pair->second << " | ";
    inorderPrinting(node->right);
}

#endif
