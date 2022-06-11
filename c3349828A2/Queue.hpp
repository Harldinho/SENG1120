/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

Queue.hpp
*/

#include <cstdlib>
#include "LinkedList.h"
#include "Node.h"
#include "Queue.h"
using namespace std;

	template <typename data_type>
		Queue<data_type>::Queue(){ //constructor
			qList = new LinkedList<data_type>();
			size = 0;
		}

	template <typename data_type>
		Queue<data_type>::~Queue(){ //destructor
			delete qList;
			size = 0;
		}

	template <typename data_type>
		void Queue<data_type>::enqueue(const data_type& data){ //adds a node to the end of the queue
			qList->add_to_tail(data);
			size++;
		}

	template <typename data_type>
		void Queue<data_type>::dequeue(){ //removes a node from the front of the queue
			qList->removeHead();
			size--;
		}

	template <typename data_type>
		const int Queue<data_type>::length(){ //returns amount of nodes withing queue
			return size;
		}

	template <typename data_type>
		const data_type Queue<data_type>::front(){ //returns the head of the queue
			data_type front = qList->getHead();
			return front;
		}

