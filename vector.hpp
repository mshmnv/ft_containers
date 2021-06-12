#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft {
    template <class Type, class Alloc = std::allocator<Type> >
    class vector {
    private:
        typedef Alloc   allocator_type;
        typedef Type    value_type;
        typedef size_t  size_type;
		typedef value_type& reference;
        typedef const value_type& const_reference;

        Type		*_arr;
        size_type   _size;
        size_type   _capacity;
        std::allocator<value_type> _allocator;
        allocator_type  _allocatorType;

        template <bool B, class T = void>
        struct enable_if {};
        template <class T>
        struct enable_if <true, T> { typedef T type; };

    public:
        /////////////////////////////
        ////     CONSTRUCTORS    ////
        /////////////////////////////

        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
        vector(const vector& x);
        vector &operator=(vector const &);

        //////////////////////////
        ////    DESTRUCTOR    ////
        //////////////////////////

        ~vector();

        //////////////////////////
        ////     ITERATORS    ////
        //////////////////////////

        class	const_iterator;
        class	iterator {
        protected:
			Type*			_arr;
            friend class	vector;
        public:
            iterator() : _arr(NULL) {}
            iterator(Type *other) : _arr(other) {}
            iterator(iterator  const &other) { this->_arr = other._arr; }
            iterator& operator++() { this->_arr++; return *this; }
            iterator& operator--() { this->_arr--; return *this; }
            iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
            iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
            bool operator!=(iterator const &it) { return this->_arr != it._arr; }
            bool operator==(iterator const &it) { return this->_arr == it._arr; }
            Type operator*() { return *this->_arr; }
			iterator operator-(const iterator other) { this->_arr = this->_arr - other._arr; return *this; }
			iterator operator-(const int& val) {this->_arr = this->_arr - val; return *this; }
			iterator operator+(const iterator other) {this->_arr = this->_arr + other._arr; return *this; }
			iterator operator+(const int& val) {this->_arr = this->_arr + val; return *this; }
		};

        class	const_iterator : public iterator {
        public:
            const_iterator() : iterator() {}
            const_iterator(Type *other) : iterator(other) {}
            const_iterator(iterator const &other) : iterator(other) {}
            const_iterator& operator=(iterator &other) { this->_arr = other._arr; return *this; }
        };

        class	const_reverse_iterator;
        class	reverse_iterator {
        private:
            Type*	_arr;
        public:
            reverse_iterator() : _arr(NULL) {}
            reverse_iterator(Type* other) : _arr(other) {}
            reverse_iterator(reverse_iterator const &other) { this->_arr = other._arr; }
            reverse_iterator& operator++() { this->_arr--; return *this; }
            reverse_iterator& operator--() { this->_arr++; return *this; }
            reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
            reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }
            bool operator!=(reverse_iterator const &it) { return this->_arr != it._arr; }
            Type operator*() { return *this->_arr; }
			iterator operator-(const iterator other) { this->_arr = this->_arr - other._arr; return *this; }
			iterator operator-(const int& val) {this->_arr = this->_arr - val; return *this; }
			iterator operator+(const iterator other) {this->_arr = this->_arr + other._arr; return *this; }
			iterator operator+(const int& val) {this->_arr = this->_arr + val; return *this; }
        };

        class	const_reverse_iterator : public reverse_iterator {
        public:
            const_reverse_iterator() : reverse_iterator() {}
            const_reverse_iterator(Type *other) : reverse_iterator(other) {}
            const_reverse_iterator(reverse_iterator const &other) : reverse_iterator(other) {}
            const_reverse_iterator& operator=(reverse_iterator &other) { this->_arr = other._arr; return *this; }
        };

        iterator begin() { return iterator(this->_arr); }
        const_iterator begin() const { return const_iterator(this->_arr); }
        iterator end() { return iterator(this->_arr + this->_size); }
        const_iterator end() const { return const_iterator(this->_arr + this->_size); }
        reverse_iterator rbegin() { return reverse_iterator(this->_arr + (this->_size - 1)); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_arr + (this->_size - 1)); }
        reverse_iterator rend() { return reverse_iterator(this->_arr - 1); }
        const_reverse_iterator rend() const { return const_reverse_iterator(this->_arr - 1); }

        /////////////////////////
        ////     CAPACITY    ////
        /////////////////////////

        size_type size() const;
        size_type max_size() const;
        void resize(size_type n, value_type val = value_type());
        size_type capacity() const;
        bool empty() const;
        void reserve(size_type n);

        ///////////////////////////////
        ////     ELEMENT ACCESS    ////
        ///////////////////////////////

        reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference back();
		const_reference back() const;
		reference front();
		const_reference front() const;

        //////////////////////////
        ////     MODIFIERS    ////
        //////////////////////////

		template <class InputIterator>
				void assign(InputIterator first, InputIterator last, typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
		void assign(size_type n, const value_type& val);
        void push_back(const value_type& val);
        void pop_back();
		iterator insert(iterator position, const value_type& val);
		void insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last, typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector& x);
		void clear();

        //////////////////////////
        ////     ALLOCATOR    ////
        //////////////////////////
        allocator_type get_allocator() const { return this->_allocatorType; }
	};
    /////////////////////////////////////
    ////     NON-MEMBER FUNCTIONS    ////
    /////////////////////////////////////
    template <class T, class Alloc>
    bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    void swap(ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y);
}

/////////////////////////////
////     CONSTRUCTORS    ////
/////////////////////////////

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(const allocator_type& alloc)
    : _arr(NULL), _size(0), _capacity(0), _allocatorType(alloc) {
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
: _arr(NULL), _size(n), _capacity(n), _allocatorType(alloc)  {
    this->_arr = this->_allocator.allocate(n);
    for (size_type i = 0; i < n; i++)
    	this->_allocator.construct(&this->_arr[i], val);
}

template <class Type, class Alloc>
template <class InputIterator>
ft::vector<Type, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc,
                                typename ft::vector<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*)
                                : _arr(NULL), _size(0), _capacity(0), _allocatorType(alloc) {
	this->insert(this->begin(), first, last);
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>::vector(const vector& x) {
        *this = x;
}

template <class Type, class Alloc>
ft::vector<Type, Alloc>& ft::vector<Type, Alloc>::operator=(vector const& vector) {
    this->clear();
    this->insert(this->begin(), vector.begin(), vector.end());
    this->_allocatorType = vector._allocatorType;
    this->_allocator = vector._allocator;
    return *this;
}

///////////////////////////
////     DESTRUCTOR    ////
///////////////////////////

template <class Type, class Alloc>
ft::vector<Type, Alloc>::~vector() {
    for (size_type i = 0; i < this->_size; i++)
        this->_allocator.destroy(&_arr[i]);
    this->_allocator.deallocate(_arr, this->_capacity);
}

/////////////////////////
////     CAPACITY    ////
/////////////////////////

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::size_type ft::vector<Type, Alloc>::size() const {
    return this->_size;
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::size_type ft::vector<Type, Alloc>::max_size() const {
    return (std::numeric_limits<size_type>::max() / sizeof(this->_arr));
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::resize(size_type n, Type val) {
	if (this->_size < n)
		insert(this->end(), n - this->_size, val);
	else if (this->_size > n)
		erase(this->begin() + n, this->end());
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
void ft::vector<Type, Alloc>::reserve(size_type n) {
	if (n <= this->_capacity)
		return;
	if (n > this->max_size())
		throw std::length_error("vector size limit");
	Type *newArr = this->_allocator.allocate(n);
	for (size_type i = 0; i < this->_size; i++) {
		this->_allocator.construct(&newArr[i], this->_arr[i]);
		this->_allocator.destroy(&this->_arr[i]);
	}
    this->_allocator.deallocate(this->_arr, this->_capacity);
	this->_capacity = n;
	this->_arr = newArr;
}

///////////////////////////////
////     ELEMENT ACCESS    ////
///////////////////////////////

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::reference ft::vector<Type, Alloc>::operator[](size_type n) {
    return this->_arr[n];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::const_reference ft::vector<Type, Alloc>::operator[](size_type n) const {
    return this->_arr[n];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::reference ft::vector<Type, Alloc>::at(size_type n) {
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return this->_arr[n];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::const_reference ft::vector<Type, Alloc>::at(size_type n) const {
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return this->_arr[n];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::reference ft::vector<Type, Alloc>::back() {
	return this->_arr[this->_size - 1];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::const_reference ft::vector<Type, Alloc>::back() const {
	return this->_arr[this->_size - 1];
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::reference ft::vector<Type, Alloc>::front() {
	return this->_arr[0];

}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::const_reference ft::vector<Type, Alloc>::front() const {
	return this->_arr[0];
}

//////////////////////////
////     MODIFIERS    ////
//////////////////////////

template <class Type, class Alloc>
template <class InputIterator>
void ft::vector<Type, Alloc>::assign(InputIterator first, InputIterator last,
                                     typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
    clear();
    insert(this->begin(), first, last);
}
template <class Type, class Alloc>
void ft::vector<Type, Alloc>::assign(size_type n, const value_type& val) {
    clear();
    insert(this->begin(), n, val);
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::push_back(const value_type& val) {
//    if (this->_size == this->_capacity && this->_size > 1)
//        reserve(this->_capacity * 2);
	insert(this->end(), 1, val);
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::pop_back() {
	erase(this->end() - 1);
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::iterator ft::vector<Type, Alloc>::insert(iterator position, const value_type& val) {
	insert(position, 1, val);
	return --position;
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::insert(iterator position, size_type n, const value_type& val) {
	if (n == 0)
		return;
	size_type index = position._arr - this->_arr;
    if (this->_size + n > this->_capacity && this->_size > 1)
        while (this->_capacity < this->_size + n)
            reserve(this->_capacity * 2);
    else
        reserve(this->_size + n);
    for (size_type j = this->_size + n - 1; j > index; j--) {
		this->_allocator.construct(&this->_arr[j], this->_arr[j - n]);
		this->_allocator.destroy(&this->_arr[j - n]);
	}
	for (size_type i = index; i < index + n; i++)
		this->_allocator.construct(&this->_arr[i], val);
	this->_size += n;
}

template <class Type, class Alloc>
template <class InputIterator>
void ft::vector<Type, Alloc>::insert(iterator position, InputIterator first, InputIterator last,
									 typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
    size_type n = 0;
	for (iterator tmp = first; tmp != last; tmp++)
		n++;
	size_type index = position._arr - _arr;
    if (this->_size + n > this->_capacity && this->_size > 1)
        while (this->_capacity < this->_size + n)
            reserve(this->_capacity * 2);
    else
	    reserve(this->_size + n);
	for (size_type j = this->_size + n - 1; j > index; j--) {
		this->_allocator.construct(&this->_arr[j], this->_arr[j - n]);
		this->_allocator.destroy(&this->_arr[j - n]);
	}
	for (size_type i = index; first != last; first++, i++)
		this->_allocator.construct(&this->_arr[i], *first);
	this->_size += n;
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::iterator ft::vector<Type, Alloc>::erase(iterator position) {
    return erase(position, position + 1);
}

template <class Type, class Alloc>
typename ft::vector<Type, Alloc>::iterator ft::vector<Type, Alloc>::erase(iterator first, iterator last){
    size_t ind = first._arr - _arr;
    size_t last_ind = last._arr - _arr;
    size_t n = last_ind - ind;
    if (n < 1)
        return last;
    for (; ind < last_ind; ind++) {
        this->_allocator.destroy(&this->_arr[ind]);
    }
    for (ind = last_ind; ind < this->_size; ind++) {
        this->_allocator.construct(&this->_arr[ind - n], this->_arr[ind]);
        this->_allocator.destroy(&this->_arr[ind]);
    }
    this->_size -= n;
    return last;
}

template <class Type, class Alloc>
void ft::vector<Type, Alloc>::swap(vector& x) {
    Type* tmpArr = x._arr;
    size_type tmpSize = x._size;
    size_type tmpCap = x._capacity;
    allocator_type tmpAT = x._allocatorType;
    std::allocator<value_type> tmpAlloc = x._allocator;

    x._arr = this->_arr;
    x._size = this->_size;
    x._capacity = this->_capacity;
    x._allocatorType = this->_allocatorType;
    x._allocator = this->_allocator;

    this->_arr = tmpArr;
    this->_size = tmpSize;
    this->_capacity = tmpCap;
    this->_allocatorType = tmpAT;
    this->_allocator = tmpAlloc;
}



template <class Type, class Alloc>
void ft::vector<Type, Alloc>::clear() {
	erase(this->begin(), this->end());
}

/////////////////////////////////////
////     NON-MEMBER FUNCTIONS    ////
/////////////////////////////////////

template <class T, class Alloc>
bool ft::operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    typename ft::vector<T, Alloc>::iterator lit = lhs.begin();
    typename ft::vector<T, Alloc>::iterator lite = lhs.end();
    typename ft::vector<T, Alloc>::iterator rit = rhs.begin();
    typename ft::vector<T, Alloc>::iterator rite = rhs.end();
    for (; lit != lite; lit++, rit++)
        if (*lit != *rit)
            return false;
    return true;
}

template <class T, class Alloc>
bool ft::operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool ft::operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    typename ft::vector<T, Alloc>::iterator lit = lhs.begin();
    typename ft::vector<T, Alloc>::iterator lite = lhs.end();
    typename ft::vector<T, Alloc>::iterator rit = rhs.begin();
    typename ft::vector<T, Alloc>::iterator rite = rhs.end();
    for (; lit != lite; lit++, rit++)
        if (*lit > *rit)
            return false;
    return true;
}

template <class T, class Alloc>
bool ft::operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs<rhs);
}

template <class T, class Alloc>
bool ft::operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs<rhs);

}

template <class T, class Alloc>
bool ft::operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs>rhs);
}

template <class T, class Alloc>
void ft::swap(ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
    x.swap(y);
}

#endif