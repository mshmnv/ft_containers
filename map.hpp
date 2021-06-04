#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RBTree.hpp"

//todo
// iterators
// []
// insert

namespace ft {
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map {
    private:
        template <bool B, class Type = void>
        struct enable_if {};
        template <class Type>
        struct enable_if <true, Type> { typedef Type type; };

        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type,mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef size_t size_type;


        size_type _size;

        std::allocator<std::pair<const Key,T> > _pairAllocator;
        allocator_type _allocatorType;
        key_compare _comp;

    public:
        Node<Key,T> *_root;
//        RBTree<Key, T> *_tree;

        ////    CONSTRUCTORS    ////

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _size(0), _comp(comp) {
//            this->_tree = new RBTree<Key,T>(comp, alloc);
            this->_root = new Node<Key, T>(comp, alloc);
        }

        template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(),
                typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
                : _size(0), _comp(comp) {
//            this->_tree = new RBTree<Key,T>(comp, alloc);
            this->_root = new Node<Key, T>(comp, alloc);


        }

        map(const map& x) {
            *this = x;
        }

        ////    DESTRUCTOR    ////
        ~map() {
//            iterator it = this->_root->begin();
//            iterator ite = this->_root->end();
//            for (; it != ite; it++) {
//                this->_pairAllocator.destroy(it._node->pair);
//            }
        }

        ////    ITERATORS    ////
        class iterator {
        protected:
            Node<Key, T> *_node;
            friend class map;
        public:
            iterator() : _node(NULL) {}
            iterator(Node<Key, T> *node) : _node(node) {}
            iterator(iterator const& other) : _node(other._node) {}
            ~iterator() { }
            iterator& operator++() {
                if (this->_node->right) {
                    this->_node = this->_node->right;
                    while (this->_node->left)
                        this->_node = this->_node->left;
                } else
                    this->_node = this->_node->parent;
                return *this;
            }
            iterator& operator--() {
                if (this->_node->left) {
                    this->_node = this->_node->left;
                    while (this->_node->right)
                        this->_node = this->_node->right;
                } else
                    this->_node = this->_node->parent;
                return *this;
            }
            iterator& operator++(int) { ++(*this); return *this; }
            iterator& operator--(int) { --(*this); return *this; }
            bool operator!=(iterator const& other) { return this->_node != other._node; }
            bool operator==(iterator const& other) { return this->_node == other._node; }
            pointer operator->() { return &this->_node->pair; }
            reference operator*() { return this->_node->pair; }
        };

        iterator begin() { return iterator(this->_root); }
//        const_iterator begin() const;
        iterator end() { return iterator(this->_root->right); }
//        const_iterator end() const;
//        reverse_iterator rbegin();
//        const_reverse_iterator rbegin() const;
//        reverse_iterator rend();
//        const_reverse_iterator rend() const;

        ////    METHODS    ////
        bool empty() const { return this->_size == 0; }
        size_type size() const { return this->_size; }
        size_type max_size() const { return std::numeric_limits<size_t>::max() / sizeof(this->_root); }



        std::pair<iterator,bool> insert(const value_type& val) {
//            iterator tmp = find(val.first);
//            if (tmp != this->end())
//                return std::make_pair(tmp, false);
//            this->_tree->insert(val);

            insertNode(this->_root, val, _comp);
            this->_size++;
            return std::make_pair(this->begin(), true);
        }

//        iterator insert(iterator position, const value_type& val);
//
//        template <class InputIterator>
//            void insert(InputIterator first, InputIterator last);


        iterator find(const key_type& k) {
            iterator it = this->begin();
            iterator ite = this->end();
            for (; it != ite; it++) {
                if (it->first == k)
                    return it;
            }
            return this->end();
        }

//        const_iterator find(const key_type& k) const {
//        }

//        void clear();
        allocator_type get_allocator() const { return this->_allocatorType; }

        ////     OVERLOADS    ////
        mapped_type& operator[](const key_type& k) {
            // find(k)
            // if find(k) == _root->end() -> create node and return its value
        }
//        map& operator=(const map& x) {
//            this->clear();
//            this->insert(x.begin(), x.end());
//            this->_pairAllocator = x._pairAllocator;
//            this->_allocatorType = x._allocatorType;
//        }
    };
}



#endif
