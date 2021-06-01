#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

namespace ft {
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map {
    private:
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
        size_type _capacity;
    public:
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
        map (const map& x);
    };
}

#endif
