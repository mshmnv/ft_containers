#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	template <class Type>
	class list {
		private:
			Node<Type> *_head;
			Node<Type> *_tail;
			Node<Type> *_empty;
			int			_size;

		public:
			list();
			list(list const &);
			list(int, Type);	// ? Allocator()

			~list();
	
			list &operator=(list const &list);

			bool empty() const;
			size_t size() const;
			size_t max_size() const;
	
			// const_reference back() const;
			Type &back();
			// const_reference front() const;
			Type &front();
		
			void assign(size_t, Type const &); // -
			template <class InputIterator>
				void assign(InputIterator, InputIterator); // - after iterators

		void push_front (Type const &);	// -
		void pop_front();				// -
		void push_back(Type const &);
		void pop_back();				// -


			void clear();
	};
}

/*
** CONSTRUCTORS
*/

template <class Type>
ft::list<Type>::list() : _size(0) {
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
** DESTRUCTOR
*/

template <class Type>
ft::list<Type>::~list() {
	Node<Type> *tmp;
	for (int i = 0; i < this->_size; i++) {
		tmp = this->_head;
		this->_head = this->_head->next;
		delete tmp;
	}
}

/*
** METHODS
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
Type &ft::list<Type>::back() {
	return this->_tail->getData();
}

template <class Type>
Type &ft::list<Type>::front() {
	return this->_head->getData();
}

template <class Type>
void ft::list<Type>::assign(size_t count, Type const &value) {
	this->clear();
	this->_empty = new Node<Type>;
	this->_head = this->_empty;
	this->_tail = this->_empty;
	for (int i = 0; i < count; i++)
		push_back(value);
}

template <class Type>
template <class InputIterator>
void ft::list<Type>::assign(InputIterator first, InputIterator last) {
	// while (first != last) {

	// }
}

template <class Type>
void ft::list<Type>::clear() {
	this->_size = 0;
	Node<Type> *tmp;
	for (int i = 0; i < this->_size; i++) {
		tmp = this->_head;
		this->_head = this->_head->next;
		delete tmp;
	}
}

template <class Type>
void ft::list<Type>::push_front (Type const &) {

}

template <class Type>
void ft::list<Type>::pop_front() {

}

template <class Type>
void ft::list<Type>::push_back(Type const &data) {
	this->_size++;
	Node<Type> *tmp = new Node<Type>(data);
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

}










/*
** OVERLOADS
*/

template <class Type>
ft::list<Type> &ft::list<Type>::operator=(list const &list) {
	if (*this != list) {
		this->_head = list._head;
		this->_tail = list._tail;
		this->_empty = list._empty;
		this->_size = list._size;
	}
	return *this;
}





#endif