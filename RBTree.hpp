#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>

#define BLACK 0
#define RED 1

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class Node {
private:
    typedef std::pair<const Key,T> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;

    std::allocator<std::pair<const Key,T> > _pairAllocator;
    key_compare _comp;
public:
    int color;
    std::pair<const Key, T> *pair;
    Node* left;
    Node* right;

    Node(const value_type& val, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : color(RED), left(NULL), right(NULL), _comp(comp), _pairAllocator(alloc) {
//        this->pair = this->_pairAllocator.allocate(1);
//        this->_pairAllocator.construct(pair, val);
    }

    Node(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : color(RED), left(NULL), right(NULL), _comp(comp), _pairAllocator(alloc) {
    }
    ~Node() { }


};



void swapColors(int& color1, int& color2) {
    int tmp = color2;
    color2 = color1;
    color1 = tmp;
}

template<class Key, class T>
Node<Key,T> *rotateLeft(Node<Key,T> *node) {
    Node<Key,T> *child = node->right;
    Node<Key,T> *childLeft = child->left;
    child->left = node;
    node->right = childLeft;
    return child;
}

template<class Key, class T>
Node<Key,T> *rotateRight(Node<Key,T> *node) {
    Node<Key,T> *child = node->left;
    Node<Key,T> *childRight = child->right;
    child->right = node;
    node->left = childRight;
    return child;
}

template<class Key, class T, class Compare>
Node<Key,T> *insertNode(Node<Key,T> *node, const std::pair<const Key,T>& val, Compare comp) {
    if (node == NULL)
        return new Node<Key,T>(val, comp);
    if (comp(val.first, node->pair->first))
        node->left = insertNode(node->left, val, comp);
    else if (!comp(val.first, node->pair->first))
        node->right = insertNode(node->right, val, comp);
    else
        return node;
    // case 1: right child is RED but left child is BLACK or doesn't exist
    if (node->right->color == RED && (node->left == NULL || node->left->color == BLACK)) {
        node = rotateLeft(node);
        swapColors(node->color, node->left->color);
    }
    // case 2: left child and left grand child are RED
    if (node->left->color == RED && node->left->left->color == RED) {
        node = rotateRight(node);
        swapColors(node->color, node->right->color);
    }
    // case 3: left and right children  are RED
    if (node->left->color == RED && node->right->color == RED) {
        node->color = !node->color;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }
}



template<class Key, class T>
void inorderPrinting(Node<Key,T> *node)
{
    if (node)
    {
        inorderPrinting(node->left);
        std::cout << node->pair->first << ":" << node->pair->second << " | ";
        inorderPrinting(node->right);
    }
}










#include <queue>

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class RBTree {
private:
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<const key_type,mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef size_t size_type;

public:
    Node<Key,T>* _root;

    std::allocator<std::pair<const Key,T> > _pairAllocator;
    allocator_type _allocatorType;
    key_compare _comp;


    RBTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
    _root(NULL), _comp(comp) {}
    ~RBTree() {}

    void inorder() { orderPrinting(this->_root); }
    void levelOrder() { levelOrderPrinting(this->_root); }

    void insert(const value_type& val) {
        Node<Key, T> *tmp = new Node<Key,T>(val);
        this->_root = BSTinsert(this->_root, tmp, this->_comp);
        balance(tmp);
    }

    void balance(Node<Key,T> *newNode) {
        Node<Key,T> *parentTmp = NULL;
        Node<Key,T> *grandParentTmp = NULL;
        while (newNode != this->_root && newNode->color != BLACK && newNode->parent->color == RED) {
            parentTmp = newNode->parent;
            grandParentTmp = newNode->parent->parent;
            // case A: parent of newNode is left child of grand-parent of newNode
            if (parentTmp == grandParentTmp->left) {
                Node<Key,T>* uncleTmp = grandParentTmp->right;
                // case 1: uncle of newNode is also red. Recoloring required
                if (uncleTmp != NULL && uncleTmp->color == RED) {
                    grandParentTmp->color = RED;
                    parentTmp->color = BLACK;
                    uncleTmp->color = BLACK;
                    newNode = grandParentTmp;
                } else {
                    //case 2: newNode is right child of its parent. Left-rotation required
                    if (newNode == parentTmp->right) {
                        leftRotation(parentTmp);
                        newNode = parentTmp;
                        parentTmp = newNode->parent;
                    }
                    //case 3: newNode is left child of its parent. Right-rotation required
                    rightRotation(grandParentTmp);
                    swapColor(parentTmp->color, grandParentTmp->color);
                    newNode = parentTmp;
                }
            }
            // case B: parent of newNode is right child of grand-parent of newNode
            else {
                Node<Key,T>*  uncleTmp = grandParentTmp->left;
                // case 1: uncle of newNode is also red. Recoloring required
                if (uncleTmp != NULL && uncleTmp->color == RED) {
                    grandParentTmp->color = RED;
                    parentTmp->color = BLACK;
                    uncleTmp->color = BLACK;
                    newNode = grandParentTmp;
                } else {
                    // case 2: newNode is left child of its parent. Right-rotation required
                    if (newNode == parentTmp->left) {
                        rightRotation(parentTmp);
                        newNode = parentTmp;
                        parentTmp = newNode->parent;
                    }
                    // case 3: newNode is right child of its parent. Left-rotation required
                    leftRotation(grandParentTmp);
                    swapColor(parentTmp->color, grandParentTmp->color);
                    newNode = parentTmp;
                }
            }
        }
        this->_root->color = BLACK;
    }

    void leftRotation(Node<Key,T>* node) {
        Node<Key,T> *rightNode = node->right;
        node->right = rightNode->left;

        if (node->right != NULL)
            node->right->parent = node;
        rightNode->parent = node->parent;

        if (node->parent == NULL)
            this->_root = rightNode;
        else if (node == node->parent->left)
            node->parent->left = rightNode;
        else
            node->parent->right = rightNode;
        rightNode->left = node;
        node->parent = rightNode;
    }

    void rightRotation(Node<Key,T>* node) {
        Node<Key,T> *leftNode = node->left;
        node->left = leftNode->right;

        if (node->left != NULL)
            node->left->parent = node;
        leftNode->parent = node->parent;

        if (node->parent == NULL)
            this->_root = leftNode;
        else if (node == node->parent->left)
            node->parent->left = leftNode;
        else
            node->parent->right = leftNode;
        leftNode->right = node;
        node->parent = leftNode;
    }

    void swapColor(int& color1, int& color2) {
        int tmp = color2;
        color2 = color1;
        color1 = tmp;
    }

};

template<class Key, class T, class Compare>
Node<Key,T>* BSTinsert(Node<Key,T> *root, Node<Key,T> *newNode, Compare comp) {
    if (root == NULL)
        return newNode;
    if (comp(newNode->pair.first, root->pair.first)) {
        root->left = BSTinsert(root->left, newNode, comp);
        root->left->parent = root;
    }
    else if (!comp(newNode->pair.first, root->pair.first)) {
        root->right = BSTinsert(root->right, newNode, comp);
        root->right->parent = root;
    }
    return root;
}

template<class Key, class T>
void orderPrinting(Node<Key,T> *root) {
    if (root == NULL)
        return ;
    orderPrinting(root->left);
    std::cout << root->pair.first << ":" << root->pair.second << " | ";
    orderPrinting(root->right);
}

template<class Key, class T>
void levelOrderPrinting(Node<Key,T> *root) {
    if (root == NULL)
        return ;
    std::queue<Node<Key,T>* > q;
    q.push(root);
    while (!q.empty()) {
        Node<Key,T> *tmp = q.front();
        std::cout << tmp->pair.first << ":" << tmp->pair.second << " | ";
        q.pop();
        if (tmp->left != NULL)
            q.push(tmp->left);
        if (tmp->right != NULL)
            q.push(tmp->right);
    }
}

#endif
