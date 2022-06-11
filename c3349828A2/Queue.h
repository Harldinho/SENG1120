/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

Queue.h 
*/

//Macroguard
#ifndef HARLAN_QUEUE
#define HARLAN_QUEUE

#include <cstdlib>

#include "LinkedList.h"

template <class data_type>
class Queue{
	public:

		Queue(); //constructor
		~Queue(); //destructor

		void enqueue(const data_type& data); //adds a node to the end of the queue
		void dequeue();//removes a node from the front of the queue
		const int length();//returns amount of nodes withing queue
		const data_type front();//returns the head of the queue

	private:
		LinkedList<data_type>* qList;
		int size;
};
#include "Queue.hpp"
#endif