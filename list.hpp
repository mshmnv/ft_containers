#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	template <class Type>
	class list {
		private:
			// std::allocator<Type> alloc;
		
			Node<Type>* _head;
			Node<Type>* _tail;
			Node<Type>* _empty;
			size_t		_size;

			template <bool B, class T = void>
				struct enable_if {};
			template <class T>
				struct enable_if <true, T> { typedef T type; };

		public:
// todo w/ allocator
			explicit list(/* const allocator_type& alloc = allocator_type() */);
// todo w/ allocator
			explicit list(int, const Type& /* = value_type(), const allocator_type& alloc = allocator_type() */);
// todo w/ allocator
			template <class InputIterator>
				list (InputIterator first, InputIterator last, /* const allocator_type& alloc = allocator_type(), */
					typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
			explicit list(list const &);
			~list();
	
			list &operator=(list const &);

			/*
			**		ITERATORS
			*/

			class	const_iterator;
			class	iterator {
			protected:
				Node<Type>* _curNode;
				template <class T>
				friend class list;
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
		
			/*
			**		METHODS
			*/

			bool empty() const;
			size_t size() const;
			size_t max_size() const;
			Type& back();
			Type const& back() const;
			Type& front();
			Type const& front() const;
		
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
			void resize(size_t, Type);
			void clear();

			void splice(iterator, list&);
			void splice(iterator, list&, iterator);
			void splice(iterator, list&, iterator, iterator);

			void remove(const Type& val);
			template <class Predicate>
				void remove_if(Predicate pred);
			
//todo
			void unique();
			template <class BinaryPredicate>
				void unique(BinaryPredicate binary_pred);
			
			void merge (list& x);
			template <class Compare>
				void merge(list& x, Compare comp);
			
			void sort();
			template <class Compare>
				void sort(Compare comp);
			
			void reverse();
		
			// allocator_type get_allocator() const;
	};
}

/*
**		CONSTRUCTORS
*/

template <class Type>
ft::list<Type>::list() : _size(0){
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	this->_head->next = this->_empty;
	this->_head->prev = this->_empty;
	this->_tail->prev = this->_empty;
	this->_tail->next = this->_empty;
}

template <class Type>
ft::list<Type>::list(int count, const Type& data) : _size(0) {
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	for (int i = 0; i < count; i++)
		this->push_back(data);
}

template <class Type>
template <class InputIterator>
ft::list<Type>::list (InputIterator first, InputIterator last, /* const allocator_type& alloc = allocator_type(), */
	typename ft::list<Type>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	this->_size = 0;
	this->_empty = new Node<Type>;
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

template <class Type>
ft::list<Type>::list(list const &other) {
	*this = other;
}


/*
**		DESTRUCTOR
*/

template <class Type>
ft::list<Type>::~list() {
	Node<Type>* tmp;
	for (int i = 0; i < this->_size; i++) {
		tmp = this->_head;
		this->_head = this->_head->next;
		delete tmp;
	}
}

/*
**		METHODS
*/

template <class Type>
bool ft::list<Type>::empty() const {
	return this->_size == 0;
}

template <class Type>
size_t ft::list<Type>::size() const {
	return this->_size;
}

template <class Type>
size_t ft::list<Type>::max_size() const {
	return (std::numeric_limits<size_t>::max() / sizeof(this->_head));
}


template <class Type>
Type& ft::list<Type>::back() {
	return this->_tail->getData();
}

template <class Type>
Type const& ft::list<Type>::back() const{
	return this->_tail->getData();
}

template <class Type>
Type& ft::list<Type>::front() {
	return this->_head->getData();
}

template <class Type>
Type  const& ft::list<Type>::front() const{
	return this->_head->getData();
}

template <class Type>
void ft::list<Type>::assign(size_t count, Type const& value) {
	this->clear();
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	for (int i = 0; i < count; i++) {
		push_back(value);
	}
}

template <class Type>
template <class InputIterator>
void ft::list<Type>::assign(InputIterator first, InputIterator last, typename enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	this->clear();
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	while (first != last) {
		push_back(*first);
		first++;
	}
}

template <class Type>
void ft::list<Type>::push_front(Type const &data) {
	this->_size++;
	Node<Type>* tmp = new Node<Type>(data);
	this->_head->prev = tmp;
	tmp->next = this->_head;
	this->_empty->next = tmp;
	tmp->prev = this->_empty;
	this->_head = tmp;
}

template <class Type>
void ft::list<Type>::pop_front() {
	this->_size--;
	Node<Type>* tmp = this->_head->next;

	tmp->prev = this->_empty;
	this->_empty->next = tmp;
	delete this->_head;
	this->_head = tmp;
}

template <class Type>
void ft::list<Type>::push_back(Type const &data) {
	this->_size++;
	Node<Type>* tmp = new Node<Type>(data);
	if (this->_size == 1)
		this->_head = tmp;
	this->_tail->next = tmp;
	tmp->prev = this->_tail;
	this->_empty->prev = tmp;
	tmp->next = this->_empty;

	this->_tail = tmp;
}

template <class Type>
void ft::list<Type>::pop_back() {
	this->_size--;
	Node<Type>* tmp = this->_tail->prev;

	tmp->next = this->_empty;
	this->_empty->prev = tmp;
	delete this->_tail;
	this->_tail = tmp;
}

template <class Type>
typename ft::list<Type>::iterator ft::list<Type>::insert(iterator position, Type const& data) {

	Node<Type> *newNode = new Node<Type>(data);
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

template <class Type>
void	ft::list<Type>::insert(iterator position, size_t n, Type const& data) {

	for (int i = 0; i < n; i++) {
		position = this->insert(position, data);
	}
}

template <class Type>
template <class InputIterator>
void	ft::list<Type>::insert(iterator position, InputIterator first, InputIterator last,
typename ft::list<Type>::enable_if <!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	while (first != last) {
		insert(position, *first);
		first++;
	}
}

template <class Type>
typename ft::list<Type>::iterator ft::list<Type>::erase(iterator position) {

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
	delete position._curNode;
	return iterator(nextNode);
}

template <class Type>
typename ft::list<Type>::iterator ft::list<Type>::erase(iterator first, iterator last) {
	int i = 0;
	iterator tmp;
	while (first != last) {
		first = erase(first);
	}
	return first;
}

template <class Type>
void ft::list<Type>::swap(list& x) {
	Node<Type> *tmpHead = x._head;
	Node<Type> *tmpTail = x._tail;
	Node<Type> *tmpEmpty = x._empty;
	size_t tmpSize = x._size;

	x = *this;
	this->_head = tmpHead;
	this->_tail = tmpTail;
	this->_empty = tmpEmpty;
	this->_size = tmpSize;
}

template <class Type>
void ft::list<Type>::resize(size_t n, Type data) {
	Node<Type> *tmpNode = this->_head;

	for (int i = 0; i < this->_size; i++) {
		if (i == n) {
			Node<Type>* tmp;
			this->_tail = tmpNode->prev;
			this->_tail->next = this->_empty;
			this->_empty->prev = tmpNode->prev;
			for (;this->_size != n; ) {
				this->_size--;
				tmp = tmpNode;
				tmpNode = tmpNode->next;
				delete tmp;
			}
			return ;
		}
		tmpNode = tmpNode->next;
	}
	for (;this->_size < n; )
		push_back(data);
}

template <class Type>
void ft::list<Type>::clear() {
	if (this->_size != 0) {
		this->_size = 0;
		Node<Type>* tmp;
		for (int i = 0; i < this->_size; i++) {
			tmp = this->_head;
			this->_head = this->_head->next;
			delete tmp;
		}
		this->_empty = new Node<Type>;
		this->_head = this->_empty;
		this->_tail = this->_empty;
		this->_head->next = this->_empty;
		this->_head->prev = this->_empty;
		this->_tail->prev = this->_empty;
		this->_tail->next = this->_empty;
	}
}


template <class Type>
void ft::list<Type>::splice(iterator position, list& x) {
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

template <class Type>
void ft::list<Type>::splice(iterator position, list& x, iterator i) {
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

template <class Type>
void ft::list<Type>::splice(iterator position, list& x, iterator first, iterator last) {
	if (first == last)
		return ;
	int len = 0;
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

template <class Type>
void	ft::list<Type>::remove(const Type& val) {
	iterator ite = this->end();
	iterator it = this->begin();
	for (; it != ite; ) {
		if (*it == val)
			it = this->erase(it);
		else
			it++;
	}
}

template <class Type>
template <class Predicate>
void	ft::list<Type>::remove_if(Predicate pred) {
	for (iterator it = this->begin(); it != this->end(); ) {
		if (pred(*it))
			it = erase(it);
		else
			it++;
	}
}

template <class Type>
void	ft::list<Type>::unique() {
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

template <class Type>
template <class BinaryPredicate>
void	ft::list<Type>::unique(BinaryPredicate binary_pred) {
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

template <class Type>
void ft::list<Type>::merge(list& x) {
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

template <class Type>
template <class Compare>
void	ft::list<Type>::merge(list& x, Compare comp) {
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
			
template <class Type>
void	ft::list<Type>::sort() {

}

template <class Type>
template <class Compare>
void	ft::list<Type>::sort(Compare comp) {

}


template <class Type>
void	ft::list<Type>::reverse() {
	Node<Type> *tmpHead = this->_head;
	Node<Type> *tmpTail = this->_tail;
	Node<Type> *tmpNext;
	Node<Type> *tmpPrev;
	this->_head = tmpTail;
	this->_tail = tmpHead;

	for (int i = 0; i < this->_size / 2 - 1; i++) {
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

/*
**		OVERLOADS
*/

template <class Type>
ft::list<Type>& ft::list<Type>::operator=(list const& list) {
	this->_head = list._head;
	this->_tail = list._tail;
	this->_empty = list._empty;
	this->_size = list._size;
	return *this;
}


#endif