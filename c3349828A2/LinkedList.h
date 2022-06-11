/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

LinkedList.h
*/

//Macroguard
#ifndef LINKED
#define LINKED
#include "Node.h"
#include <iostream>

template<class data_type>

class LinkedList{
	
	public:
		//constructor
		LinkedList(); //0 parameters
		LinkedList(data_type& data);
		//destructor
		~LinkedList();

		/*
		Member function: Removes all nodes from the linkedlist
		Precondition: A valid linked list exists
		Postcondition: all nodes are deleted from linkedlist, NULL
		*/
		void listClear();

		/*
		Member function: adds a string to new nodes delimited by every space in the given string
		Precondition: inputted data must be a valid string
		Postcondition: a linked list of nodes is created with strings stored in each node
		*/
		void add(data_type& str);

		/*
		Member function: adds data into a new node at the end of the linked list
		Precondition: inputted data must be a vaild string
		Postcondition: a node is created and appended to end of linked list, works if no linked list existing also
		*/
		void add_to_tail(const data_type& d);

		void add_to_head(const data_type& d);

		/*
		Member function: removes a selected string from any node with an instance of it stored
		Precondition: inputted data must be a vaild string, a valid linked list must exist
		Postcondition: removes a node within the linked list with the specified string stored in it
		*/
		void remove(const data_type& word);

		/*
		Member function: removes the node at the front of the linked list
		Precondition: a valid linked list must exist, the head pointer must be pointing to a valid node
		Postcondition: the head of the linked list is removed setting it to NULL
		*/
		void removeHead();

		/*
		Member function: removes the node that the current pointer is pointing to
		Precondition: a valid linked list must exist, current pointer must be pointing to a vaild node
		Postcondition: the node at current pointer is removed and the nodes left and right are joined
		*/
		void removeCurrent();

		/*
		Member function: removes the node at the end of the linked list
		Precondition: a valid linked list must exist, tail pointer must be pointing to a vaild node
		Postcondition: the tail of the linked list is removed setting it to NULL
		*/
		void removeTail();

		/*
		Member function: sorts the nodes into alphabetical order according to the string data inside each node (Bubble sort)
		Precondition: a valid linked list must exist, stored data in nodes must be string
		Postcondition: rearranges the nodes by changing links with each node into alphabetical order
		*/
		void sort();

		/*
		Member function: sets the current pointer to point to a different node in the linked list
		Precondition: a valid linked list must exist, the argument must be a valid node
		Postcondition: the current pointer is set to a different node in the linked list
		*/
		void set_current(Node<data_type>* newCurrent);

		/*
		Member function: returning data stored in the node at current pointer
		Precondition: a valid linked list must exist, current must be pointing to a valid node
		Postcondition: the data stored in the node at the current pointer is returned
		*/
		data_type get_current();

		data_type getHead();

		/*
		Member function: sets the current pointer to point to head of linked list
		Precondition: a valid linked list must exist, the head pointer must be pointing to a valid node
		Postcondition: the current pointer is pointing to the node where head is pointing to
		*/
		void start();

		/*
		Member function: sets the current pointer to point to the tail of linked list
		Precondition: a valid linked list must exist, the tail pointer must be pointing to a valid node
		Postcondition: the current pointer is pointing to the node where tail is pointing to
		*/
		void end();

		/*
		Member function: moves the current pointer to point to the next node along the linked list in reference to currents location
		Precondition: a valid linked list must exist
		Postcondition: the current pointer is pointing to the next node in the linked list in reference to currents location
		*/
		void forward();

		/*
		Member function: finds and returns the amount of nodes currently within a linked list
		Precondition: a valid linked list must exist
		Postcondition: returns an integer of the amounts of nodes currently in the list
		*/
		int size();

		/*
		Member function: counts and returns the amount of times a specified string appears in all nodes of a linked list
		Precondition: a valid linked list must exist, inputted argument must be a valid string
		Postcondition: returns an integer of the amount of times a string appears in all nodes of the linked list
		*/
		int count(const data_type& word);

		/*
		Operator overloading: adds a linked list to the end of another linked list maintaining the structure of both lists
		Precondition: a valid linked list must exist, inputted argument must be a valid linked list, tail pointer of first linked list must be pointing to a valid node
		Postcondition: a concatenated linked list pointer is created and returned
		*/
		LinkedList<data_type>& operator += (LinkedList<data_type>& list);
		
	private:
		Node<data_type>* head; //pointer variable pointing to the head node of the linked list
		Node<data_type>* tail; //pointer variable pointing to the tail node of the linked list
		Node<data_type>* current; //pointer variable pointing to the current node of the linked list
		int length;
};

		template <class data_type>

/*
Operator overloading: returns all data within all nodes of the linked list
Precondition: a valid linked list must exist
Postcondition: all the data inside every node of the linked list is returned
*/
		std::ostream& operator << (std::ostream& out, LinkedList<data_type>& L);
		#include "LinkedList.hpp"
#endif