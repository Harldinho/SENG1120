/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

Node.hpp
*/

#include "node.h"
#include <string>
#include <iostream>

	template <class data_type>
	//constructors
	Node<data_type>::Node(){ 
		next = NULL; //setting pointers to NULL
		previous = NULL;
	}

	template <class data_type>
	Node<data_type>::Node(const data_type& d){ //only when data is given
		data = d;
		next = NULL;
		previous = NULL;
	}
	template <class data_type>
	Node<data_type>::Node(const data_type& d, Node* p, Node* n){ //when everything is given
		data = d;
		next = n;
		previous = p;
	}
	//destructor
	template <class data_type>
	Node<data_type>::~Node(){
		next = NULL; //removing all connections I.e NULL 
		previous = NULL;
	}

	template <class data_type>
	void Node<data_type>::set_data(const data_type& d){ //setting data stored inside a node
		data = d;
	}

	template <class data_type>
	void Node<data_type>::set_next(Node* n){ //setting the next nodes pointer reference
		next = n;
	}

	template <class data_type>
	void Node<data_type>::set_prev(Node* p){ //setting the previous nodes pointer reference
		previous = p;
	}

	template <class data_type>
	data_type Node<data_type>::get_data() const{ //getting the data from the node
		return data;
	}

	template <class data_type>
	const Node<data_type>* Node<data_type>::get_next() const{ //gets the pointer held in 'next', the next node
		return next;
	}

	template <class data_type>
	const Node<data_type>* Node<data_type>::get_prev() const{ //gets the pointer held in 'previous', the previous node
		return previous;
	}

	template <class data_type>
	Node<data_type>* Node<data_type>::get_next(){ //gets the pointer held in 'next', the next node
		return next;
	}

	template <class data_type>
	Node<data_type>* Node<data_type>::get_prev(){ //gets the pointer held in 'previous', the previous node
		return previous;
	}
