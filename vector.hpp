#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
    template <class Type, class Alloc = std::allocator<Type>>
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
        size_t      _size;

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
        /*
        **		ITERATORS
        */

        /*
        **		METHODS
        */
        allocator_type get_allocator() const { return this->_allocatorType; }

    };
}

/*
**		CONSTRUCTORS
*/

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(const allocator_type& alloc) {
    this->_empty = this->_nodeAllocator.allocate(1);
    this->_head = this->_empty;
    this->_tail = this->_empty;
    this->_head->next = this->_empty;
    this->_head->prev = this->_empty;
    this->_tail->prev = this->_empty;
    this->_tail->next = this->_empty;
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) {
    this->_empty = this->_nodeAllocator.allocate(1);
    this->_head = this->_empty;
    this->_tail = this->_empty;
    for (int i = 0; i < n; i++)
        this->push_back(val);
}

template <class Type, class Alloc>
template <class InputIterator>
ft::vector<Type, Alloc>::vector (InputIterator first, InputIterator last, const allocato r_type& alloc,
    typename ft::vector<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
        this->_size = 0;
        this->_empty = this->_nodeAllocator.allocate(1);
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

/*
**		DESTRUCTOR
*/

template <class Type, class Alloc>
ft::vector<Type, Alloc>::~vector() {
    Node<Type>* tmp;
    for (int i = 0; i < this->_size; i++) {
        tmp = this->_head;
        this->_head = this->_head->next;
        this->_nodeAllocator.deallocate(tmp, 1);
    }
}

/*
**		METHODS
*/


/*
**		OVERLOADS
*/


template <class Type, class Alloc>
ft::vector<Type, Alloc>& ft::vector<Type, Alloc>::operator=(vector const& vector) {
    this->_head = vector._head;
    this->_tail = vector._tail;
    this->_empty = vector._empty;
    this->_size = vector._size;
    this->_allocatorType = vector._allocatorType;
    this->_nodeAllocator = vector._nodeAllocator;
    return *this;
}

#endif