/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

node.h 
*/

//Macroguard
#ifndef HARLAN_NODE
#define HARLAN_NODE

#include <cstdlib>
#include <iostream>
#include <string>

template <class data_type>
class Node{

	public:
		//constructors
		Node(); //default
		Node(const data_type& a); //when a string is inputted
		Node(const data_type& a, Node<data_type>* p, Node<data_type>* n); //when everything about the node is inputted
		//destructor
		~Node();

		/*
		Member function: sets the data stored inside a node
		Precondition: a valid node must exist, inputted argument must be a valid string
		Postcondition: the string from the argument is stored inside the node
		*/
		void set_data(const data_type& a);

		/*
		Member function: sets the next nodes pointer
		Precondition: inputted argument is a valid node, a valid node exists
		Postcondition: the node pointer next is changed to point to the next node
		*/
		void set_next(Node<data_type>* n);

		/*
		Member function: sets the previous nodes pointer
		Precondition: inputted argument is a valid node, a valid node exists
		Postcondition: the node pointer previous is changed to point to the previous node
		*/
		void set_prev(Node<data_type>* p);

		/*
		Member function: gets and returns the data stored in a node
		Precondition: a valid node exists, 'data' is storing valid data
		Postcondition: returns the data in 'data' as a string
		*/
		data_type get_data() const;

		/*
		Member function: gets the pointer held in 'next', the next node
		Precondition: next can be NULL or a valid pointer to another node
		Postcondition: the 'next' pointer is returned
		*/
		const Node<data_type>* get_next() const;

		/*
		Member function: gets the pointer held in 'previous', the previous node
		Precondition: 'previous' can be NULL or a valid pointer to another node
		Postcondition: the 'previous' pointer is returned
		*/
		const Node<data_type>* get_prev() const;

		/*
		Member function: gets the pointer held in 'next', the next node
		Precondition: next can be NULL or a valid pointer to another node
		Postcondition: the 'next' pointer is returned
		*/
		Node<data_type>* get_next();

		/*
		Member function: gets the pointer held in 'previous', the previous node
		Precondition: 'previous' can be NULL or a valid pointer to another node
		Postcondition: the 'previous' pointer is returned
		*/
		Node<data_type>* get_prev();

	private:
		data_type data; //variable for string storage within nodes
		Node<data_type>* next; //variable for storing address of next node
		Node<data_type>* previous; //variable for storing address of previous node

};
#include "Node.hpp"
#endif