#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RBTnode.hpp"

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

        class value_compare {
        protected:
            friend class map;
            Compare comp;
            value_compare(Compare c = key_compare()) : comp(c){};
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(value_type const& x, value_type const& y) const { return comp(x.first, y.first); }
        };

        size_type _size;
        std::allocator<std::pair<const Key,T> > _pairAllocator;
        allocator_type _allocatorType;
        key_compare _comp;
        value_compare _value_comp;
        Node<Key,T> *_root;
        Node<Key,T> *_leftEmpty;

    public:

        ////////////////////////////
        ////    CONSTRUCTORS    ////
        ////////////////////////////
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _size(0), _comp(comp), _value_comp(comp), _pairAllocator(alloc) {
            this->_root = new Node<Key, T>(NULL, comp, alloc);
            this->_root->right = new Node<Key,T>(this->_root, comp, alloc);
            this->_root->right->color = BLACK;

            this->_root->left = new Node<Key,T>(this->_root, comp, alloc);
            this->_root->left->color = BLACK;
            this->_leftEmpty = this->_root->left;
        }

        template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(),
                typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
                : _size(0), _comp(comp), _value_comp(comp), _pairAllocator(alloc) {
            this->_root = new Node<Key, T>(NULL, comp, alloc);
            this->_root->right = new Node<Key,T>(this->_root, comp, alloc);
            this->_root->right->color = BLACK;
            this->_root->left = new Node<Key,T>(this->_root, comp, alloc);
            this->_root->left->color = BLACK;
            this->_leftEmpty = this->_root->left;
            insert(first, last);
        }

        map(const map& x) : _size(0), _comp(x._comp), _value_comp(x._value_comp), _pairAllocator(x._pairAllocator) {
            this->_root = new Node<Key, T>(NULL, _comp, _pairAllocator);
            this->_root->right = new Node<Key,T>(this->_root, _comp, _pairAllocator);
            this->_root->right->color = BLACK;
            this->_root->left = new Node<Key,T>(this->_root, _comp, _pairAllocator);
            this->_root->left->color = BLACK;
            this->_leftEmpty = this->_root->left;
            insert(x.begin(), x.end());
        }

        map& operator=(map const& x) {
            clear();
            insert(x.begin(), x.end());
            this->_pairAllocator = x._pairAllocator;
            this->_allocatorType = x._allocatorType;
            this->_comp = x.comp;
            this->_value_comp = x._value_comp;
            return *this;
        }

        //////////////////////////
        ////    DESTRUCTOR    ////
        //////////////////////////
        ~map() {
            clear();
            delete this->_root->right;
            delete this->_root->left;
            delete this->_root;
        }

        /////////////////////////
        ////    ITERATORS    ////
        /////////////////////////
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
                if (this->_node->left && !this->_node->left->isEmpty) {
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
            iterator operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            iterator operator--(int) {
                iterator tmp = *this;
                --(*this);
                return tmp;
            }
            bool operator!=(iterator const& other) { return this->_node != other._node; }
            bool operator==(iterator const& other) { return this->_node == other._node; }
            bool operator>(iterator const& other) { return this->_node > other._node; }
            bool operator<(iterator const& other) { return this->_node < other._node; }
            bool operator>=(iterator const& other) { return this->_node >= other._node; }
            bool operator<=(iterator const& other) { return this->_node <= other._node; }
            pointer operator->() { return this->_node->pair; }
            reference operator*() const { return *(this->_node->pair); }
        };

        class const_iterator : public iterator {
        public:
            const_iterator() : iterator() {}
            const_iterator(Node<Key,T> *other) : iterator(other) {}
            const_iterator(iterator const& other) : iterator(other._node) {}
            const_iterator& operator=(iterator &other) { this->_node = other._node; return *this; }
            ~const_iterator() {}
        };

        class reverse_iterator {
        protected:
            Node<Key, T> *_node;
            friend class map;
        public:
            reverse_iterator() : _node(NULL) {}
            reverse_iterator(Node<Key, T> *node) : _node(node) {}
            reverse_iterator(reverse_iterator const& other) : _node(other._node) {}
            ~reverse_iterator() { }
            reverse_iterator& operator++() {
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
            reverse_iterator& operator--() {
                if (this->_node->right && !this->_node->right->isEmpty) {
                    this->_node = this->_node->right;
                    while (this->_node->left)
                        this->_node = this->_node->left;
                } else {
                    while (this->_node->parent && this->_node == this->_node->parent->right)
                        this->_node = this->_node->parent;
                    this->_node = this->_node->parent;
                }
            }
            reverse_iterator operator++(int) {
                reverse_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            reverse_iterator operator--(int) {
                reverse_iterator tmp = *this;
                --(*this);
                return tmp;
            }
            bool operator!=(reverse_iterator const& other) { return this->_node != other._node; }
            bool operator==(reverse_iterator const& other) { return this->_node == other._node; }
            bool operator>(reverse_iterator const& other) { return this->_node > other._node; }
            bool operator<(reverse_iterator const& other) { return this->_node < other._node; }
            bool operator>=(reverse_iterator const& other) { return this->_node >= other._node; }
            bool operator<=(reverse_iterator const& other) { return this->_node <= other._node; }
            pointer operator->() { return this->_node->pair; }
            reference operator*() const { return *(this->_node->pair); }
        };

        class const_reverse_iterator : public reverse_iterator {
        public:
            const_reverse_iterator() : reverse_iterator() {}
            const_reverse_iterator(Node<Key,T> *other) : reverse_iterator(other) {}
            const_reverse_iterator(reverse_iterator const& other) : reverse_iterator(other._node) {}
            const_reverse_iterator& operator=(reverse_iterator &other) { this->_node = other._node; return *this; }
            ~const_reverse_iterator() {}
        };

        iterator begin() {
            if (this->_size == 0)
                return iterator(this->_root->right);
            Node<Key,T> *tmp = this->_root;
            while (tmp) {
                if (tmp->left && !tmp->left->isEmpty)
                    tmp = tmp->left;
                else
                    return iterator(tmp);
            }
            return iterator(tmp);
        }

        const_iterator begin() const {
            if (this->_size == 0)
                return const_iterator(this->_root->right);
            Node<Key,T> *tmp = this->_root;
            while (tmp) {
                if (tmp->left && !tmp->left->isEmpty)
                    tmp = tmp->left;
                else
                    return const_iterator(tmp);
            }
            return const_iterator(tmp);
        }
        iterator end() { return iterator(this->_root->right); }
        const_iterator end() const { return const_iterator(this->_root->right); } ;
        reverse_iterator rbegin() { return reverse_iterator(this->_root); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_root); }
        reverse_iterator rend() { return reverse_iterator(this->_leftEmpty); }
        const_reverse_iterator rend() const { return const_reverse_iterator(this->_leftEmpty); }

        /////////////////////////
        ////     CAPACITY    ////
        /////////////////////////
        bool empty() const { return this->_size == 0; }
        size_type size() const { return this->_size; }
        size_type max_size() const { return std::numeric_limits<size_t>::max() / sizeof(this->_root); }

        ///////////////////////////////
        ////     ELEMENT ACCESS    ////
        //////////////////////////////
        mapped_type& operator[](const key_type& k) {
            iterator tmp = find(k);
            if (tmp == this->end()) {
                insert(std::make_pair(k, mapped_type()));
                tmp = find(k);
            }
            return tmp._node->pair->second;
        }

        //////////////////////////
        ////     MODIFIERS    ////
        //////////////////////////
        std::pair<iterator,bool> insert(const value_type& val) {
            if (this->_size == 0) {
                this->_root->pair = this->_pairAllocator.allocate(1);
                this->_pairAllocator.construct(this->_root->pair, val);
                this->_root->isEmpty = false;
            }
            else {
                iterator tmp;
                if ((tmp = find(val.first)) != this->end())
                    return std::make_pair(tmp, false);
                this->_root = insertNode(this->_root, this->_root->parent, val, _comp, _pairAllocator);
            }
            this->_root->color = BLACK;
            this->_size++;
            return std::make_pair(this->begin(), true);
        }

        iterator insert(iterator position, const value_type& val) {
            (void)position;
            insert(val);
        }

        template <class InputIterator>
            void insert(InputIterator first, InputIterator last,
                        typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
            while (first != last)  {
                insert(*first);
                first++;
            }
        }

        void erase(iterator position) { erase(position._node->pair->first); }

        size_type erase(const key_type& k) {
            iterator tmpNode;
            if ((tmpNode = find(k)) == this->end())
                return 0;
            if (this->_size == 1) {
                this->_pairAllocator.deallocate(this->_root->pair, 1);
                this->_root->pair = NULL;
            }
            else
                deleteNode(tmpNode._node);
            this->_size--;
            return 1;
        }

        void erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
        }

        void swap (map& x) {
            size_type sizeTmp = this->_size;
            std::allocator<std::pair<const Key,T> > allocTmp = this->_pairAllocator;
            allocator_type atTmp = this->_allocatorType;
            key_compare kCompTmp = this->_comp;
            value_compare vCompTmp = this->_value_comp;
            Node<Key,T> *rootTmp = this->_root;
            Node<Key,T> *leftTmp = this->_leftEmpty;

            this->_size = x._size;
            this->_pairAllocator = x._pairAllocator;
            this->_allocatorType = x._allocatorType;
            this->_comp = x._comp;
            this->_value_comp = x._value_comp;
            this->_root = x._root;
            this->_leftEmpty = x._leftEmpty;

            x._size = sizeTmp;
            x._pairAllocator = allocTmp;
            x._allocatorType = atTmp;
            x._comp = kCompTmp;
            x._value_comp = vCompTmp;
            x._root = rootTmp;
            x._leftEmpty = leftTmp;
        }

        void clear() {
            erase(this->begin(), this->end());
        }

        //////////////////////////
        ////     OBSERVERS    ////
        //////////////////////////

        key_compare key_comp() const {
            return this->_comp;
        }
        value_compare value_comp() const {
            return this->_value_comp;
        }

        ///////////////////////////
        ////     OPERATIONS    ////
        ///////////////////////////

        iterator find(const key_type& k) {
            if (this->_size) {
                Node<Key,T> *tmpNode = this->_root;
                while (tmpNode != NULL && !tmpNode->isEmpty) {
                    if (_comp(k, tmpNode->pair->first))
                        tmpNode = tmpNode->left;
                    else if (k == tmpNode->pair->first)
                        return iterator(tmpNode);
                    else
                        tmpNode = tmpNode->right;
                }
            }
            return this->end();
        }

        const_iterator find(const key_type& k) const {
            Node<Key,T> *tmpNode = this->_root;
            while (tmpNode != NULL) {
                if (_comp(k, tmpNode->pair->first))
                    tmpNode = tmpNode->left;
                else if (k == tmpNode->pair->first)
                    return const_iterator(tmpNode);
                else
                    tmpNode = tmpNode->right;
            }
            return this->end();
        }

        size_type count(const key_type& k) const {
            if (find(k) == this->end())
                return 0;
            return 1;
        }

        iterator lower_bound(const key_type& k) {
            iterator it = begin();
            for (iterator it = begin(); it != end(); it++) {
                if (this->_comp(it->first, k) <= 0)
                    return it;
            }
            return end();
        }

        const_iterator lower_bound(const key_type& k) const {
            const_iterator it = begin();
            for (const_iterator it = begin(); it != end(); it++) {
                if (this->_comp(it->first, k) <= 0)
                    return it;
            }
            return end();
        }

        iterator upper_bound(const key_type& k) {
            iterator it = begin();
            for (iterator it = begin(); it != end(); it++) {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    return it;
            }
            return end();
        }

        const_iterator upper_bound(const key_type& k) const {
            const_iterator it = begin();
            for (const_iterator it = begin(); it != end(); it++) {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    return it;
            }
            return end();
        }

        std::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
            return std::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
        }

        std::pair<iterator,iterator> equal_range(const key_type& k) {
            return std::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
        }

        /////////////////////////
        ////    ALLOCATOR    ////
        /////////////////////////

        allocator_type get_allocator() const { return this->_allocatorType; }
    };
}

#endif
