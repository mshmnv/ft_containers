#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Node.hpp"

// todo capacity in push_back

namespace ft {
    template <class Type, class Alloc = std::allocator<Type> >
    class vector {
    private:
        typedef Alloc   allocator_type;
        typedef Type    value_type;
        typedef size_t  size_type;
        std::allocator<Node<value_type> > _nodeAllocator;
        allocator_type  _allocatorType;

        Node<Type>* _head;
        Node<Type>* _tail;
        Node<Type>* _empty;
        size_type   _size;
        size_type   _capacity;

        template <bool B, class T = void>
        struct enable_if {};
        template <class T>
        struct enable_if <true, T> { typedef T type; };

    public:
        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
        vector(const vector& x);
        ~vector();

        vector &operator=(vector const &);
        allocator_type get_allocator() const { return this->_allocatorType; }

        ////    ITERATORS    ////

        class	const_iterator;
        class	iterator {
        protected:
            Node<Type>* _curNode;
            friend class vector;
        public:
            iterator() : _curNode(NULL) {}
            iterator(Node<Type> *other) : _curNode(other) {}
            iterator(iterator  const &other) { this->_curNode = other._curNode; }
            Type& getData() const { return _curNode->getData(); }
            iterator& operator++() { this->_curNode = this->_curNode->next; return *this; }
            iterator& operator--() { this->_curNode = this->_curNode->prev; return *this; }
            iterator& operator++(int) { ++(*this); return *this; }
            iterator& operator--(int) { --(*this); return *this; }
            bool operator!=(iterator const &it) { return this->_curNode != it._curNode; }
            bool operator==(iterator const &it) { return this->_curNode == it._curNode; }
            Type operator*() { return this->_curNode->getData(); }
        };

        class	const_iterator : public iterator {
        public:
            const_iterator() : iterator() {}
            const_iterator(Node<Type> *other) : iterator(other) {}
            const_iterator(iterator const &other) : iterator(other) {}
            const_iterator& operator=(iterator &other) { this->_curNode = other._curNode; return *this; }
        };

        class	const_reverse_iterator;
        class	reverse_iterator {
        private:
            Node<Type>* _curNode;
        public:
            reverse_iterator() : _curNode(NULL) {}
            reverse_iterator(Node<Type> *other) : _curNode(other) {}
            reverse_iterator(reverse_iterator const &other) { this->_curNode = other._curNode; }
            Type& getData() const { return _curNode->getData(); }
            reverse_iterator& operator++() { this->_curNode = this->_curNode->prev; return *this; }
            reverse_iterator& operator--() { this->_curNode = this->_curNode->next; return *this; }
            reverse_iterator& operator++(int) { ++(*this); return *this; }
            reverse_iterator& operator--(int) { --(*this); return *this; }
            bool operator!=(reverse_iterator const &it) { return this->_curNode != it._curNode; }
            Type operator*() { return this->_curNode->getData(); }
        };

        class	const_reverse_iterator : public reverse_iterator {
        public:
            const_reverse_iterator() : reverse_iterator() {}
            const_reverse_iterator(Node<Type> *other) : reverse_iterator(other) {}
            const_reverse_iterator(reverse_iterator const &other) : reverse_iterator(other) {}
            const_reverse_iterator& operator=(reverse_iterator &other) { this->_curNode = other._curNode; return *this; }
        };

        iterator begin() { return iterator(this->_head); }
        const_iterator begin() const { return const_iterator(this->_head); }
        iterator end() { return iterator(this->_tail->next); }
        const_iterator end() const { return const_iterator(this->_tail->next); }
        reverse_iterator rbegin() { return reverse_iterator(this->_tail); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_tail); }
        reverse_iterator rend() { return reverse_iterator(this->_head->prev); }
        const_reverse_iterator rend() const { return const_reverse_iterator(this->_head->prev); }

        ////    METHODS    ////

        size_type size() const;
        size_type max_size() const;
        void resize(size_type n, value_type val = value_type());
        size_type capacity() const;
        bool empty() const;
        void reserve(size_type n);

        // operator[]
        // at[]
//        Type& back();
//        Type const& back() const;
//        Type& front();
//        Type const& front() const;

        void push_back (const value_type& val);
        void pop_back();

    };
}

////    CONSTRUCTORS    ////

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(const allocator_type& alloc) :
    _allocatorType(alloc), _size(0), _capacity(0) {
    this->_empty = this->_nodeAllocator.allocate(1);
//    this->_nodeAllocator.construct(this->_empty, 0);
    this->_head = this->_empty;
    this->_tail = this->_empty;
    this->_head->next = this->_empty;
    this->_head->prev = this->_empty;
    this->_tail->prev = this->_empty;
    this->_tail->next = this->_empty;
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) :
    _allocatorType(alloc), _size(0), _capacity(0) {
    this->_empty = this->_nodeAllocator.allocate(1);
//    this->_nodeAllocator.construct(this->_empty, 0);
    this->_head = this->_empty;
    this->_tail = this->_empty;
    for (int i = 0; i < n; i++)
        this->push_back(val);
}

template <class Type, class Alloc>
template <class InputIterator>
ft::vector<Type, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc,
    typename ft::vector<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) :
    _size(0), _capacity(0) {
    this->_empty = this->_nodeAllocator.allocate(1);
//    this->_nodeAllocator.construct(this->_empty, 0);
    this->_head = this->_empty;
        this->_tail = this->_empty;
        this->_head->next = this->_empty;
        this->_head->prev = this->_empty;
        this->_tail->prev = this->_empty;
        this->_tail->next = this->_empty;
        for (; first != last; first++) {
            this->push_back(*first);
        }
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(const vector& x) {
        *this = x;
}

////    DESTRUCTOR    ////

template <class Type, class Alloc>
ft::vector<Type, Alloc>::~vector() {
    Node<Type>* tmp;
    for (int i = 0; i < this->_size; i++) {
        tmp = this->_head;
        this->_head = this->_head->next;
        this->_nodeAllocator.deallocate(tmp, 1);
    }
    if (this->_empty)
        this->_nodeAllocator.deallocate(this->_empty, 1);
}

////    METHODS    ////

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::size_type ft::vector<Type, Alloc>::size() const {
    return this->_size;
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::size_type ft::vector<Type, Alloc>::max_size() const {
    return (std::numeric_limits<size_type>::max() / sizeof(this->_head));
}


template <class Type, class Alloc>
void ft::vector<Type, Alloc>::resize(size_type n, Type val) {
    Node<Type> *tmpNode = this->_head;

    for (int i = 0; i < this->_size; i++) {
        if (i == n) {
            Node<Type>* tmp;
            this->_tail = tmpNode->prev;
            this->_tail->next = this->_empty;
            this->_empty->prev = tmpNode->prev;
            for (;this->_size != n; ) {
                this->_size--;
                this->_capacity--;
                tmp = tmpNode;
                tmpNode = tmpNode->next;
                this->_nodeAllocator.deallocate(tmp, 1);
            }
            return ;
        }
        tmpNode = tmpNode->next;
    }
    for (;this->_size < n; )
        push_back(val);
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::size_type ft::vector<Type, Alloc>::capacity() const {
    return this->_capacity;
}

template <class Type, class Alloc>
bool ft::vector<Type, Alloc>::empty() const {
    return this->_size == 0;
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::push_back(const value_type& val) {
    this->_size++;
    this->_capacity++;
    Node<Type>* tmp = this->_nodeAllocator.allocate(1);
    this->_nodeAllocator.construct(tmp, val);
    if (this->_size == 1)
        this->_head = tmp;
    this->_tail->next = tmp;
    tmp->prev = this->_tail;
    this->_empty->prev = tmp;
    tmp->next = this->_empty;

    this->_tail = tmp;
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::pop_back() {
    this->_size--;
    this->_capacity--;
    Node<Type>* tmp = this->_tail->prev;

    tmp->next = this->_empty;
    this->_empty->prev = tmp;
    this->_nodeAllocator.deallocate(this->_tail, 1);
    this->_tail = tmp;
}

// Requests that the vector capacity be at least enough to contain n elements.
template <class Type, class Alloc>
void ft::vector<Type, Alloc>::reserve(size_type n) {
    if (n <= this->_capacity)
        return ;
    if (n > this->max_size())
        throw std::length_error("vector size limit");
    // do reservation

}

////     OVERLOADS    ////

template <class Type, class Alloc>
ft::vector<Type, Alloc>& ft::vector<Type, Alloc>::operator=(vector const& vector) {
//    this->clear();
//    this->insert(this->begin(), list.begin(), list.end());
//    this->_allocatorType = list._allocatorType;
//    this->_nodeAllocator = list._nodeAllocator;
    return *this;
}

#endif