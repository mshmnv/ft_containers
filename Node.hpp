#ifndef NODE_HPP
#define NODE_HPP

template <class Type>
class Node {
private:
	Type	_data;
public:
	Node	*next;
	Node	*prev;
	Node();
	Node(Node const &);
	Node(Type const &);
	~Node();

	Type	&getData();
	void	setData(Type const&);
	Node	&operator=(Node const &);
};

template <class Type>
Node<Type>::Node() : _data(), next(NULL), prev(NULL) {}

template <class Type>
Node<Type>::Node(Node const &other) {
	*this = other;
}

template <class Type>
Node<Type>::Node(Type const &data) : _data(data), next(NULL), prev(NULL) {}

template <class Type>
Node<Type>::~Node() {}

template <class Type>
Type	&Node<Type>::getData() {
	return this->_data;
}

template <class Type>
void	Node<Type>::setData(Type const &data) {
	this->_data = data;
}

template <class Type>
Node<Type>	&Node<Type>::operator=(Node const &node) {
	this->_data = node._data;
	this->next = node.next;
	return *this;
}


#endif
