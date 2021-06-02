#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RBTNode.hpp"
//#include "mapIterator.hpp"

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
        RBTNode<Key, T>* _root;
        std::allocator<std::pair<const Key,T> > _nodeAllocator;
        allocator_type _allocatorType;

    public:

        ////    CONSTRUCTORS    ////

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
        _size(0), _root(NULL) {
//            this->_nodeAllocator.allocate(this->_root, 1);
//            this->_root->color = "black";
//            right null ?
//            left null ?
        }

        template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type(),
                 typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {

        }

        map(const map& x) {
            *this = x;
        }

        ////    DESTRUCTOR    ////
        ~map() { }

        ////    ITERATORS    ////
//        class iterator {
//        private:
//            RBTNode<Key, T> *_node;
//
//        public:
//            iterator();
//
//            iterator(iterator &other);
//
//            ~iterator();
//        };

//        iterator begin();
//        const_iterator begin() const;
//        iterator end();
//        const_iterator end() const;
//        reverse_iterator rbegin();
//        const_reverse_iterator rbegin() const;
//        reverse_iterator rend();
//        const_reverse_iterator rend() const;

        ////    METHODS    ////
        bool empty() const { return this->_size == 0; }
        size_type size() const { return this->_size; }
        size_type max_size() const { return std::numeric_limits<size_t>::max() / sizeof(this->_tree); }



//        std::pair<iterator,bool> insert(const value_type& val);
//
//        iterator insert(iterator position, const value_type& val);
//
//        template <class InputIterator>
//            void insert(InputIterator first, InputIterator last);

        ////     OVERLOADS    ////
        mapped_type& operator[](const key_type& k) {

        }
        map& operator= (const map& x);
    };
}



#endif
