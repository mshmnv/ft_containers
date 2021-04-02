#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	template <class Type>
	class list {
		private:
			Node<Type>* _head;
			Node<Type>* _tail;
			Node<Type>* _empty;
			size_t		_size;

		public:
			list();
			list(list const &);
			list(int, Type);	// ? Allocator()
			~list();
	
			list &operator=(list const &list);

			

			/*
			**		ITERATORS
			*/

			class	iterator {
			private:
				Node<Type>* _curNode;
			public:
				iterator() : _curNode(NULL) {}
				iterator(Node<Type> *other) : _curNode(other) {}
				Type& getData() const { return _curNode->getData(); }
				iterator& operator++() { this->_curNode = this->_curNode->next; return *this; }	// prefix
				iterator& operator++(int) {++(*this); return *this;}			// postfix
				bool operator!=(iterator const &it) { return this->_curNode->getData() != it.getData(); }
				int operator*() { return this->_curNode->getData(); }
			};

			class	const_iterator {
			private:
				Node<Type>* _curNode;
			public:
				const_iterator() : _curNode(NULL) {}
				const_iterator(Node<Type> *other) : _curNode(other) {}
				Type& getData() const { return _curNode->getData(); }
				const_iterator& operator++() { this->_curNode = this->_curNode->next; return *this; }
				const_iterator& operator++(int) { ++(*this); return *this; }
				bool operator!=(const_iterator const &it) { return this->_curNode->getData() != it.getData(); }
				int operator*() { return this->_curNode->getData(); }
				const_iterator& operator=(const_iterator &other) { this->_curNode = other._curNode; return *this; } // ????? maybe teplate <class Iterator>

			};

			class	reverse_iterator {
			private:
				Node<Type>* _curNode;
			public:
				reverse_iterator() : _curNode(NULL) {}
				reverse_iterator(Node<Type> *other) : _curNode(other) {}
				Type& getData() const { return _curNode->getData(); }
				reverse_iterator& operator++() { this->_curNode = this->_curNode->prev; return *this; }
				reverse_iterator& operator++(int) {++(*this); return *this;}
				bool operator!=(reverse_iterator const &it) { return this->_curNode->getData() != it.getData(); }
				int operator*() { return this->_curNode->getData(); }
			};
			
			class	const_reverse_iterator {
			private:
				Node<Type>* _curNode;
			public:
				const_reverse_iterator() : _curNode(NULL) {}
				const_reverse_iterator(Node<Type> *other) : _curNode(other) {}
				Type& getData() const { return _curNode->getData(); }
				const_reverse_iterator& operator++() { this->_curNode = this->_curNode->prev; return *this; }
				const_reverse_iterator& operator++(int) { ++(*this); return *this; }
				bool operator!=(const_reverse_iterator const &it) { return this->_curNode->getData() != it.getData(); }
				int operator*() { return this->_curNode->getData(); }
			};

			iterator begin() { return iterator(this->_head); }
			const_iterator begin() const { return const_iterator(this->_head); }
			iterator end() { return iterator(this->_tail->next); }
			const_iterator end() const { return const_iterator(this->_tail->next); }
			reverse_iterator rbegin() { return this->_tail; }
			const_reverse_iterator rbegin() const { return this->_tail; }
			reverse_iterator rend() { return this->_head->prev; }
			const_reverse_iterator rend() const { return this->_head->prev; }

			bool empty() const;
			size_t size() const;
			size_t max_size() const;
			Type& back();
			Type const& back() const;
			Type& front();
			Type const& front() const;
		
			void assign(size_t, Type const&);
			// template <class InputIterator>
			// 	void assign(InputIterator, InputIterator); // - after iterators

			void push_front (Type const&);
			void pop_front();
			void push_back(Type const&);
			void pop_back();

			iterator insert(iterator, Type const&);
    		void insert(iterator, size_t, Type const&);
			// template <class InputIterator>
    		// 	void insert(iterator position, InputIterator first, InputIterator last); // previous insert goes here
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);


			// swap();
			// resize();
			void clear();

			// splice();
			// remove();
			// remove_if();
			// unique();
			// merge();
			// sort();
			// reverse();
			// get_allocator(); // ?????


			// getter for node
			Node<Type>* getNode() const;
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
}

template <class Type>
ft::list<Type>::list(int count, Type data) : _size(0) {
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	for (int i = 0; i < count; i++)
		push_back(data);
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

// template <class Type>
// template <class InputIterator>
// void ft::list<Type>::assign(InputIterator first, InputIterator last) {

// 	while (first != last) {

// 	}
// }

template <class Type>
void ft::list<Type>::clear() {
	this->_size = 0;
	Node<Type>* tmp;
	for (int i = 0; i < this->_size; i++) {
		tmp = this->_head;
		this->_head = this->_head->next;
		delete tmp;
	}
}

template <class Type>
void ft::list<Type>::push_front (Type const &data) {
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
typename ft::list<Type>::iterator	ft::list<Type>::insert(iterator position, Type const& data) {
	Node<Type> *tmp = this->_head;
	Node<Type> *newNode = new Node<Type>(data);
	Node<Type> *nextNode;

	for (int i = 0; i < this->_size; i++) {
		if (tmp->getData() == *position) {
			this->_size++;
			if (i == 0)
				this->_head = newNode;
			nextNode = tmp->next;
			tmp->prev->next = newNode;
			newNode->prev = tmp->prev;
			tmp->prev = newNode;
			newNode->next = tmp;
			return position;
		}
		tmp = tmp->next;
	}
	delete newNode;
	push_back(data);
	return iterator(this->_tail);
}

template <class Type>
void	ft::list<Type>::insert(iterator position, size_t n, Type const& data) {
	int flag = 0;
	Node<Type> *tmp = this->_head;

	for (int i = 0; i < this->_size; i++) {
		if (tmp->getData() == *position) {
			flag = 1;
			this->_size += n;
			for (int j = 0; j < n; j++) {
				Node<Type> *newNode = new Node<Type>(data);
				if (i == 0 && j == 0)
					this->_head = newNode;
				tmp->prev->next = newNode;
				newNode->prev = tmp->prev->next;
				newNode->next = tmp;
				tmp->prev = newNode;
			}
			break;
		}
		tmp = tmp->next;
	}
	if (!flag)
		for (int i = 0; i < n; i++)
			push_back(data);
}

// template <class Type>
// template <class InputIterator>
// void	ft::list<Type>::insert(iterator position, InputIterator first, InputIterator last) {

// }


template <class Type>
typename ft::list<Type>::iterator ft::list<Type>::erase(iterator position) {

}

template <class Type>
typename ft::list<Type>::iterator ft::list<Type>::erase(iterator first, iterator last) {

}

template <class Type>
Node<Type>* ft::list<Type>::getNode() const {
	return this->_head;
}

/*
**		OVERLOADS
*/

template <class Type>
ft::list<Type>& ft::list<Type>::operator=(list const& list) {
	if (*this != list) {
		this->_head = list._head;
		this->_tail = list._tail;
		this->_empty = list._empty;
		this->_size = list._size;
	}
	return *this;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, ft::list<Type> const& list) {
	Node<Type>* tmp = list.getNode();
	for (int i = 0; i < list.size(); i++) {
		out << tmp->getData() << " ";
		tmp = tmp->next;
	}
	out << std::endl;
	return out;
}

#endif