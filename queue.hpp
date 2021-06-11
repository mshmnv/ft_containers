#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <deque>

namespace ft {
    template <class Type, class Container = std::deque<Type> >
    class queue {
    private:
        Container _cont;
        typedef Type    value_type;
        typedef size_t  size_type;
        typedef Container container_type;

    public:
        explicit queue (const container_type& ctnr = container_type()) : _cont(ctnr) {}
        ~queue() {}

        bool empty() const { return _cont.empty(); }
        size_type size() const { return _cont.size(); }
        value_type& front() { return _cont.front(); }
        const value_type& front() const { return _cont.front(); }
        value_type& back() { return _cont.back(); }
        const value_type& back() const { return _cont.back(); }
        void push(const value_type& val) { return _cont.push_back(val); }
        void pop() { _cont.pop_front(); }

        void swap (queue& x) { _cont.swap(x._cont); }
        friend bool operator>(queue const &lhs, queue const &rhs) { return lhs._cont > rhs._cont; }
        friend bool operator==(queue const &lhs, queue const &rhs) { return lhs._cont == rhs._cont; }
        friend bool operator!=(queue const &lhs, queue const &rhs) { return lhs._cont != rhs._cont; }
        friend bool operator<=(queue const &lhs, queue const &rhs) { return lhs._cont <= rhs._cont; }
        friend bool operator>=(queue const &lhs, queue const &rhs) { return lhs._cont >= rhs._cont; }
    };
}

/////////////////////////////////////
////     NON-MEMBER FUNCTIONS    ////
/////////////////////////////////////

template <class T, class Container>
bool operator==(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs == rhs;
}

template <class T, class Container>
bool operator!=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs != rhs;
}

template <class T, class Container>
bool operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs < rhs;
}

template <class T, class Container>
bool operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs <= rhs;
}

template <class T, class Container>
bool operator>(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs > rhs;
}

template <class T, class Container>
bool operator>=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
    return lhs >= rhs;
}

template <class T, class Container>
void swap(ft::queue<T,Container>& x, ft::queue<T,Container>& y) noexcept(noexcept(x.swap(y))) {
    x.swap(y);
}

#endif
