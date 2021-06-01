#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <deque>

//todo
// non-member functions - comparisons, swap

namespace ft {
    template <class Type, class Container = std::deque<Type> >
    class stack {
    private:
        Container _cont;
        typedef Type    value_type;
        typedef size_t  size_type;
        typedef Container container_type;

    public:
        explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}
        ~stack() {}

        bool empty() const { return _cont.empty(); }
        size_type size() const { return _cont.size(); }
        value_type& top() { return _cont.back(); }
        const value_type& top() const { return _cont.back(); }
        void push(const value_type& val) { return _cont.push_back(val); }
        void pop() { _cont.pop_back(); }
    };
}

////     NON-MEMBER FUNCTIONS    ////

template <class T, class Container>
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

}

template <class T, class Container>
void swap (ft::stack<T,Container>& x, ft::stack<T,Container>& y) noexcept(noexcept(x.swap(y))) {

}

#endif
