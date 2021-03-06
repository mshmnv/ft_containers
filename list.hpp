#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	template <class Type, class Alloc = std::allocator<Type> >
	class list {
		private:
		    typedef Alloc allocator_type;
			typedef Type value_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef size_t size_type;
            std::allocator<Node<value_type> > _nodeAllocator;
            allocator_type _allocatorType;

			Node<Type>* _head;
			Node<Type>* _tail;
			Node<Type>* _empty;
            size_t      _size;

			template <bool B, class T = void>
				struct enable_if {};
			template <class T>
				struct enable_if <true, T> { typedef T type; };

		public:
            /////////////////////////////
            ////     CONSTRUCTORS    ////
            /////////////////////////////
			explicit list(const allocator_type& = allocator_type());
			explicit list(size_type, const value_type& = value_type(), const allocator_type& = allocator_type());
			template <class InputIterator>
				list(InputIterator first, InputIterator last, const allocator_type& = allocator_type(),
                     typename ft::list<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
			explicit list(list const &);
            list &operator=(list const &);

            //////////////////////////
            ////    DESTRUCTOR    ////
            //////////////////////////

            ~list();

            //////////////////////////
            ////     ITERATORS    ////
            //////////////////////////
			class	const_iterator;
			class	iterator {
			protected:
				Node<Type>* _curNode;
				friend class list;
			public:
				iterator() : _curNode(NULL) {}
				iterator(Node<Type> *other) : _curNode(other) {}
				iterator(iterator const &other) { this->_curNode = other._curNode; }
				iterator& operator++() { this->_curNode = this->_curNode->next; return *this; }
				iterator& operator--() { this->_curNode = this->_curNode->prev; return *this; }
                iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
                iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
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
				reverse_iterator& operator++() { this->_curNode = this->_curNode->prev; return *this; }
				reverse_iterator& operator--() { this->_curNode = this->_curNode->next; return *this; }
                reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
                reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }
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

            /////////////////////////
            ////     CAPACITY    ////
            /////////////////////////

			bool empty() const;
			size_t size() const;
            size_t max_size() const;

            ///////////////////////////////
            ////     ELEMENT ACCESS    ////
            ///////////////////////////////

			reference back();
            const_reference back() const;
			reference front();
            const_reference front() const;

            //////////////////////////
            ////     MODIFIERS    ////
            //////////////////////////

			void assign(size_t, Type const&);
			template <class InputIterator>
				void assign(InputIterator, InputIterator, typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
			void push_front (Type const&);
			void pop_front();
			void push_back(Type const&);
			void pop_back();
			iterator insert(iterator, Type const&);
    		void insert(iterator, size_t, Type const&);
			template <class InputIterator>
    			void insert(iterator, InputIterator, InputIterator, typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
			iterator erase(iterator);
			iterator erase(iterator, iterator);
			void swap(list&);
			void resize(size_t, Type = value_type());
			void clear();

            ///////////////////////////
            ////     OPERATIONS    ////
            ///////////////////////////

			void splice(iterator, list&);
			void splice(iterator, list&, iterator);
			void splice(iterator, list&, iterator, iterator);
			void remove(const Type& val);
			template <class Predicate>
				void remove_if(Predicate pred);
			void unique();
			template <class BinaryPredicate>
				void unique(BinaryPredicate binary_pred);
			void merge (list& x);
			template <class Compare>
				void merge(list& x, Compare comp);
            void reverse();
            void sort();
			template <class Compare>
				void sort(Compare comp);

            //////////////////////////
            ////     ALLOCATOR    ////
            //////////////////////////

            allocator_type get_allocator() const { return this->_allocatorType; }
    };
    /////////////////////////////////////
    ////     NON-MEMBER FUNCTIONS    ////
    /////////////////////////////////////
	template <class Type, class Alloc>
    void swap(ft::list<Type,Alloc>& x, ft::list<Type,Alloc>& y);
    template <class Type, class Alloc>
    bool operator==(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
    template <class Type, class Alloc>
    bool operator!=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
    template <class Type, class Alloc>
    bool operator<(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
    template <class Type, class Alloc>
    bool operator>(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
    template <class Type, class Alloc>
    bool operator<=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
    template <class Type, class Alloc>
    bool operator>=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs);
}

/////////////////////////////
////     CONSTRUCTORS    ////
/////////////////////////////

template <class Type, class Alloc>
ft::list<Type, Alloc>::list(const allocator_type& alloc) : _allocatorType(alloc), _size(0){
	this->_empty = this->_nodeAllocator.allocate(1);
    this->_nodeAllocator.construct(this->_empty, value_type());
    this->_head = this->_empty;
	this->_tail = this->_empty;
	this->_head->next = this->_empty;
	this->_head->prev = this->_empty;
	this->_tail->prev = this->_empty;
	this->_tail->next = this->_empty;
	this->_empty->prev = this->_tail;
    this->_empty->next = this->_head;
}

template <class Type, class Alloc>
ft::list<Type, Alloc>::list(size_type count, const Type& data, const allocator_type& alloc) : _allocatorType(alloc), _size(0) {
	this->_empty = this->_nodeAllocator.allocate(1);
    this->_nodeAllocator.construct(this->_empty, value_type());
    this->_head = this->_empty;
	this->_tail = this->_empty;
    this->_head->next = this->_empty;
    this->_head->prev = this->_empty;
    this->_tail->prev = this->_empty;
    this->_tail->next = this->_empty;
    this->_empty->prev = this->_tail;
    this->_empty->next = this->_head;
	for (size_type i = 0; i < count; i++)
		this->push_back(data);
}

template <class Type, class Alloc>
template <class InputIterator>
ft::list<Type, Alloc>::list(InputIterator first, InputIterator last, const allocator_type& alloc,
	typename ft::list<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*)
	: _allocatorType(alloc), _size(0) {
	this->_empty = this->_nodeAllocator.allocate(1);
    this->_nodeAllocator.construct(this->_empty, value_type());
    this->_head = this->_empty;
	this->_tail = this->_empty;
	this->_head->next = this->_empty;
	this->_head->prev = this->_empty;
	this->_tail->prev = this->_empty;
	this->_tail->next = this->_empty;
    this->_empty->prev = this->_tail;
    this->_empty->next = this->_head;
	for (; first != last; first++) {
		this->push_back(*first);
	}
}

template <class Type, class Alloc>
ft::list<Type, Alloc>::list(list const &other) {
	*this = other;
}

template <class Type, class Alloc>
ft::list<Type, Alloc>& ft::list<Type, Alloc>::operator=(list const& list) {
    this->clear();
    this->insert(this->begin(), list.begin(), list.end());
    this->_allocatorType = list._allocatorType;
    this->_nodeAllocator = list._nodeAllocator;
    return *this;
}

///////////////////////////
////     DESTRUCTOR    ////
///////////////////////////

template <class Type, class Alloc>
ft::list<Type, Alloc>::~list() {
    clear();
	this->_nodeAllocator.deallocate(this->_empty, 1);
}

/////////////////////////
////     CAPACITY    ////
/////////////////////////

template <class Type, class Alloc>
bool ft::list<Type, Alloc>::empty() const {
	return this->_size == 0;
}

template <class Type, class Alloc>
size_t ft::list<Type, Alloc>::size() const {
	return this->_size;
}

template <class Type, class Alloc>
size_t ft::list<Type, Alloc>::max_size() const {
	return (std::numeric_limits<size_t>::max() / sizeof(this->_head));
}

///////////////////////////////
////     ELEMENT ACCESS    ////
///////////////////////////////

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::reference ft::list<Type, Alloc>::back() {
	return this->_tail->getData();
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::const_reference ft::list<Type, Alloc>::back() const{
	return this->_tail->getData();
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::reference ft::list<Type, Alloc>::front() {
	return this->_head->getData();
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::const_reference ft::list<Type, Alloc>::front() const{
	return this->_head->getData();
}

//////////////////////////
////     MODIFIERS    ////
//////////////////////////

template <class Type, class Alloc>
void ft::list<Type, Alloc>::assign(size_type count, Type const& value) {
	this->clear();
	for (size_type i = 0; i < count; i++) {
		push_back(value);
	}
}

template <class Type, class Alloc>
template <class InputIterator>
void ft::list<Type, Alloc>::assign(InputIterator first, InputIterator last,
                                   typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	this->clear();
	while (first != last) {
		push_back(*first);
		first++;
	}
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::push_front(Type const &data) {
    insert(this->begin(), data);
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::pop_front() {
	this->_size--;
	Node<Type>* tmp = this->_head->next;

	tmp->prev = this->_empty;
	this->_empty->next = tmp;
    this->_nodeAllocator.deallocate(this->_head, 1);
	this->_head = tmp;
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::push_back(Type const &data) {
    insert(this->end(), data);
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::pop_back() {
	this->_size--;
	Node<Type>* tmp = this->_tail->prev;

	tmp->next = this->_empty;
	this->_empty->prev = tmp;
	this->_nodeAllocator.deallocate(this->_tail, 1);
	this->_tail = tmp;
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::iterator ft::list<Type, Alloc>::insert(iterator position, Type const& data) {
    Node<Type>* newNode = this->_nodeAllocator.allocate(1);
    this->_nodeAllocator.construct(newNode, data);
	this->_size++;
	if (position == this->begin())
		this->_head = newNode;
	if (position == this->end())
		this->_tail = newNode;
	position._curNode->prev->next = newNode;
	newNode->prev = position._curNode->prev;
	position._curNode->prev = newNode;
	newNode->next = position._curNode;
	return iterator(newNode);
}

template <class Type, class Alloc>
void	ft::list<Type, Alloc>::insert(iterator position, size_type n, Type const& data) {
	for (size_type i = 0; i < n; i++) {
		position = this->insert(position, data);
	}
}

template <class Type, class Alloc>
template <class InputIterator>
void	ft::list<Type, Alloc>::insert(iterator position, InputIterator first, InputIterator last,
typename ft::list<Type, Alloc>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	while (first != last) {
		insert(position, *first);
		first++;
	}
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::iterator ft::list<Type, Alloc>::erase(iterator position) {
	if (position == this->end())
		return this->end();
	this->_size--;
	Node<Type> *nextNode = position._curNode->next;
	if (position == this->begin())
		this->_head = nextNode;
	if (position == --this->end())
		this->_tail = position._curNode->prev;
	position._curNode->prev->next = nextNode;
	nextNode->prev = position._curNode->prev;
    this->_nodeAllocator.deallocate(position._curNode, 1);
	return iterator(nextNode);
}

template <class Type, class Alloc>
typename ft::list<Type, Alloc>::iterator ft::list<Type, Alloc>::erase(iterator first, iterator last) {
	iterator tmp;
	while (first != last) {
		first = erase(first);
	}
	return first;
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::swap(list& x) {
    Node<Type> *tmpHead = x._head;
    Node<Type> *tmpTail = x._tail;
    Node<Type> *tmpEmpty = x._empty;
    size_type tmpSize = x._size;
    allocator_type tmpAT = x._allocatorType;
    std::allocator<Node<value_type> > tmpAlloc = x._nodeAllocator;

    x._head = this->_head;
    x._tail = this->_tail;
    x._empty = this->_empty;
    x._size = this->_size;
    x._allocatorType = this->_allocatorType;
    x._nodeAllocator = this->_nodeAllocator;

    this->_head = tmpHead;
    this->_tail = tmpTail;
    this->_empty = tmpEmpty;
    this->_size = tmpSize;
    this->_allocatorType = tmpAT;
    this->_nodeAllocator = tmpAlloc;
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::resize(size_t n, Type data) {
	Node<Type> *tmpNode = this->_head;

	for (size_type i = 0; i < this->_size; i++) {
		if (i == n) {
			Node<Type>* tmp;
			this->_tail = tmpNode->prev;
			this->_tail->next = this->_empty;
			this->_empty->prev = tmpNode->prev;
			for (;this->_size != n; ) {
				this->_size--;
				tmp = tmpNode;
				tmpNode = tmpNode->next;
                this->_nodeAllocator.deallocate(tmp, 1);
			}
			return ;
		}
		tmpNode = tmpNode->next;
	}
	for (;this->_size < n; )
		push_back(data);
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::clear() {
    erase(this->begin(), this->end());
}

///////////////////////////
////     OPERATIONS    ////
///////////////////////////

template <class Type, class Alloc>
void ft::list<Type, Alloc>::splice(iterator position, list& x) {
    if (x._size == 0)
        return;
	this->_size += x._size;
	x._size = 0;
	
	if (position == this->begin())
		this->_head = x._head;
	if (position == this->end())
		this->_tail = x._tail;
	x._head->prev = position._curNode->prev;
	position._curNode->prev->next = x._head;
	x._tail->next = position._curNode;
	position._curNode->prev = x._tail;
	x._head = x._empty;
	x._tail = x._empty;
	x._head->next = x._empty;
	x._head->prev = x._empty;
	x._tail->next = x._empty;
	x._tail->prev = x._empty;	
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::splice(iterator position, list& x, iterator i) {
    if (x._size == 0)
        return;
	this->_size++;
	x._size--;
	if (position == this->begin())
		this->_head = i._curNode;
	if (position == this->end())
		this->_tail = i._curNode;
	if (i == --x.end())
		x._tail = i._curNode->prev;
	if (i == x._head)
		x._head = i._curNode->next;

	i._curNode->prev->next = i._curNode->next;
	i._curNode->next->prev = i._curNode->prev;

	i._curNode->prev = position._curNode->prev;
	position._curNode->prev->next = i._curNode;
	i._curNode->next = position._curNode;
	position._curNode->prev = i._curNode;
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::splice(iterator position, list& x, iterator first, iterator last) {
	if (first == last)
		return ;
	size_t len = 0;
	for (iterator tmpFirst = first; tmpFirst != last; tmpFirst++)
		len++;
	if (position == this->begin())
		this->_head = first._curNode;
	if (position == this->end())
		this->_tail = last._curNode->prev;
	if (last == x.end())
		x._tail = first._curNode->prev;
	if (first == x._head)
		x._head = last._curNode;
	Node<Type> *prevNode = last._curNode->prev;
	first._curNode->prev->next = last._curNode;
	last._curNode->prev = first._curNode->prev;
	
	position._curNode->prev->next = first._curNode;
	first._curNode->prev = position._curNode->prev;
	position._curNode->prev = prevNode;
	prevNode->next = position._curNode;
	
	if (len > x._size)
		x._size = 0;
	else
		x._size -= len;
	this->_size += len;
}

template <class Type, class Alloc>
void	ft::list<Type, Alloc>::remove(const Type& val) {
	iterator ite = this->end();
	iterator it = this->begin();
	for (; it != ite; ) {
		if (*it == val)
			it = this->erase(it);
		else
			it++;
	}
}

template <class Type, class Alloc>
template <class Predicate>
void	ft::list<Type, Alloc>::remove_if(Predicate pred) {
	for (iterator it = this->begin(); it != this->end(); ) {
		if (pred(*it))
			it = erase(it);
		else
			it++;
	}
}

template <class Type, class Alloc>
void	ft::list<Type, Alloc>::unique() {
	iterator prev = this->begin();
	for (iterator it = ++this->begin(); it != this->end();) {
		if (*it == *prev)
			it = this->erase(it);
		else {
			it++;
			prev++;
		}
	}
}

template <class Type, class Alloc>
template <class BinaryPredicate>
void	ft::list<Type, Alloc>::unique(BinaryPredicate binary_pred) {
	iterator prev = this->begin();
	for (iterator it = ++this->begin(); it != this->end();) {
		if (binary_pred(*prev, *it))
			it = this->erase(it);
		else {
			it++;
			prev++;
		}
	}
}

template <class Type, class Alloc>
void ft::list<Type, Alloc>::merge(list& x) {
	iterator it = this->begin();
	if (x.empty())
		return ;
	if (this->empty()) {
		splice(this->begin(), x);
		return ;
	}
	int n = this->_size;
	for (int i = 0; i < n; i++) {
		if (it._curNode->getData() > x._head->getData())
			this->splice(it, x, x.begin());
		else
			it++;
	}
	if (!x.empty())
		this->splice(++it, x);
}

template <class Type, class Alloc>
template <class Compare>
void	ft::list<Type, Alloc>::merge(list& x, Compare comp) {
	iterator it = this->begin();
	if (x.empty())
		return ;
	if (this->empty()) {
		splice(this->begin(), x);
		return ;
	}
	int n = this->_size;
	for (int i = 0; i < n; i++) {
		if (comp(x._head->getData(), it._curNode->getData()))
			this->splice(it, x, x.begin());
		else
			it++;
	}
	if (!x.empty())
		this->splice(++it, x);
}

template <class Type, class Alloc>
void	ft::list<Type, Alloc>::sort() {
    if (this->_size > 1) {
        ft::list<Type> *less = new ft::list<Type>;
        ft::list<Type> *more = new ft::list<Type>;
        Node<Type> *base = this->_head;

        Node<Type> *right = this->_head->next;
        for (Node<Type> *left = this->_tail->next; right != left;) {
            Node<Type> *tmp = right->next;
            if (right->getData() <= base->getData())
                less->splice(less->end(), *this, iterator(right));
            else
                more->splice(more->end(), *this, iterator(right));
            right = tmp;
        }
        less->sort();
        more->sort();
        this->splice(this->begin(), *less);
        this->splice(this->end(), *more);
        delete less;
        delete more;
    }
}

template <class Type, class Alloc>
template <class Compare>
void	ft::list<Type, Alloc>::sort(Compare comp) {
    if (this->_size > 1) {
        ft::list<Type> *less = new ft::list<Type>;
        ft::list<Type> *more = new ft::list<Type>;
        Node<Type> *base = this->_head;

        Node<Type> *right = this->_head->next;
        for (Node<Type> *left = this->_tail->next; right != left;) {
            Node<Type> *tmp = right->next;
            if (comp(right->getData(), base->getData()))
                less->splice(less->end(), *this, iterator(right));
            else
                more->splice(more->end(), *this, iterator(right));
            right = tmp;
        }
        less->sort();
        more->sort();
        this->splice(this->begin(), *less);
        this->splice(this->end(), *more);
        delete less;
        delete more;
    }
}


template <class Type, class Alloc>
void	ft::list<Type, Alloc>::reverse() {
	Node<Type> *tmpHead = this->_head;
	Node<Type> *tmpTail = this->_tail;
	Node<Type> *tmpNext;
	Node<Type> *tmpPrev;
	this->_head = tmpTail;
	this->_tail = tmpHead;

	for (size_t i = 0; i < this->_size / 2 - 1; i++) {
		tmpHead->next->prev = tmpTail;
		tmpTail->prev->next = tmpHead;
		tmpNext = tmpHead->next;
		tmpHead->next = tmpTail->next;
		tmpHead->next->prev = tmpHead;
		tmpTail->next = tmpNext;
		tmpNext->prev = tmpTail;
		tmpPrev = tmpHead->prev;
		tmpHead->prev = tmpTail->prev; 
		tmpTail->prev = tmpPrev;
		tmpPrev->next = tmpTail;
		tmpNext = tmpHead;
		tmpHead = tmpTail->next;
		tmpTail = tmpNext->prev;
	}
	tmpHead->next = tmpTail->next;
	tmpHead->next->prev = tmpHead;
	tmpTail->prev = tmpHead->prev;
	tmpHead->prev->next = tmpTail;
	tmpTail->next = tmpHead;
	tmpHead->prev = tmpTail;
}

/////////////////////////////////////
////     NON-MEMBER FUNCTIONS    ////
/////////////////////////////////////

template <class Type, class Alloc>
bool ft::operator==(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    typename ft::list<Type,Alloc>::iterator lit = lhs.begin();
    typename ft::list<Type,Alloc>:: iterator lite = lhs.end();
    typename ft::list<Type,Alloc>::iterator rit = rhs.begin();
    for (; lit != lite; lit++, rit++) {
        if (*lit != *rit)
            return false;
    }
    return true;
}

template <class Type, class Alloc>
bool ft::operator!=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    return !(lhs==rhs);
}

template <class Type, class Alloc>
bool ft::operator<(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    typename ft::list<Type,Alloc>::iterator lit = lhs.begin();
    typename ft::list<Type,Alloc>::iterator lite = lhs.end();
    typename ft::list<Type,Alloc>::iterator rit = rhs.begin();
    typename ft::list<Type,Alloc>::iterator rite = rhs.end();
    for (; lit != lite; lit++, rit++) {
        if (*lit > *rit)
            return false;
    }
    return true;
}

template <class Type, class Alloc>
bool ft::operator>(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    return !(lhs<rhs);
}

template <class Type, class Alloc>
bool ft::operator<=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    return !(lhs>rhs);
}

template <class Type, class Alloc>
bool ft::operator>=(const ft::list<Type,Alloc>& lhs, const ft::list<Type,Alloc>& rhs) {
    return !(lhs<rhs);
}

template <class Type, class Alloc>
void ft::swap(ft::list<Type,Alloc>& x, ft::list<Type,Alloc>& y) {
    x.swap(y);
}

#endif