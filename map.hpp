#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RBTnode.hpp"

//todo
// iterator end()
// []
// erase

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

        ////    CONSTRUCTORS    ////

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _size(0), _comp(comp), _root(NULL) {
            this->_root = new Node<Key, T>(comp, alloc);
//            this->_root->right = new Node<Key, T>(comp, alloc);
        }

        template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(),
                typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
                : _size(0), _comp(comp), _root(NULL) {
            this->_root = new Node<Key, T>(comp, alloc);
//            this->_root->right = new Node<Key, T>(comp, alloc);
        }

        map(const map& x) {
            *this = x;
        }

        ////    DESTRUCTOR    ////
        ~map() {
//            iterator it = this->begin();
//            iterator ite = this->end();
//            for (; it != ite; it++) {
//                this->_pairAllocator.destroy(it._node->pair);
//                // + delete node
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
                } else {
                    while (this->_node->parent && this->_node == this->_node->parent->right)
                        this->_node = this->_node->parent;
                    this->_node = this->_node->parent;
                }
                return *this;
            }
            iterator& operator--() {
                if (this->_node->left) {
                    this->_node = this->_node->left;
                    while (this->_node->right)
                        this->_node = this->_node->right;
                } else {
                    while (this->_node->parent && this->_node == this->_node->parent->left)
                        this->_node = this->_node->parent;
                    this->_node = this->_node->parent;
                }
                return *this;
            }
            iterator& operator++(int) { ++(*this); return *this; }
            iterator& operator--(int) { --(*this); return *this; }
            bool operator!=(iterator const& other) { return this->_node != other._node; }
            bool operator==(iterator const& other) { return this->_node == other._node; }
            bool operator>(iterator const& other) { return this->_node > other._node; }
            bool operator<(iterator const& other) { return this->_node < other._node; }
            bool operator>=(iterator const& other) { return this->_node >= other._node; }
            bool operator<=(iterator const& other) { return this->_node <= other._node; }
            pointer operator->() { return this->_node->pair; }
            reference operator*() { return this->_node->pair; }
        };

        iterator begin() {
            Node<Key,T> *tmp = this->_root;
            while (tmp) {
                if (tmp->left)
                    tmp = tmp->left;
                else
                    return iterator(tmp);
            }
            return iterator(tmp);
        }

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
            if (this->_size == 0) {
                this->_root->pair = this->_pairAllocator.allocate(1);
                this->_pairAllocator.construct(this->_root->pair, val);
            }
            else {
                iterator tmp;
                if ((tmp = find(val.first)) != this->end())
                    return std::make_pair(tmp, false);
                this->_root = insertNode(this->_root, this->_root->right, val, _comp, _pairAllocator);
            }
            this->_size++;
            return std::make_pair(this->begin(), true);
        }

//        iterator insert(iterator position, const value_type& val) {
//            insertNode(position._node, position._node->parent, val, _comp, _pairAllocator);
//        }

//        template <class InputIterator>
//            void insert(InputIterator first, InputIterator last,
//                        typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
//            while (first != last)  {
//                insert(*first);
//                first++;
//            }
//        }

        iterator find(const key_type& k) {
            Node<Key,T> *tmpNode = this->_root;
            while (tmpNode != NULL) {
                if (_comp(k, tmpNode->pair->first))
                    tmpNode = tmpNode->left;
                else if (k == tmpNode->pair->first)
                    return iterator(tmpNode);
                else
                    tmpNode = tmpNode->right;
            }
            return this->end();
        }

//        const_iterator find(const key_type& k) const {
//            Node<Key,T> *tmpNode = this->_root;
//            while (tmpNode != NULL) {
//                if (_comp(k, tmpNode->pair->first))
//                    tmpNode = tmpNode->left;
//                else if (k == tmpNode->pair->first)
//                    return iterator(tmpNode);
//                else
//                    tmpNode = tmpNode->right;
//            }
//            return this->end();
//        }

        void erase(iterator position) {
            deleteNode(position._node);
            this->_size--;
        }

//        size_type erase(const key_type& k) {
//            iterator tmp = find(k);
//            erase(tmp);
//            return 1;
//        }

//        void erase(iterator first, iterator last) {
//            while (first != last) {
//                iterator tmp = first + 1;
//                erase(first);
//            }
//        }

//        void clear() { erase(this->begin(), this->end()); }

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
