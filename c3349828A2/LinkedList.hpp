/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

LinkedList.hpp
*/

#include <cstdlib>
#include "LinkedList.h"
#include "Node.h"

	template <typename data_type>
	LinkedList<data_type>::LinkedList(){ //constructor
		head = NULL;
		tail = NULL;
		current = NULL; 
        length = 0;
	}

	template <typename data_type>
	LinkedList<data_type>::LinkedList(data_type& data){ //constructor
		head = new Node<data_type>(data);
		tail = head;
		current = tail;
		length = 1;
		return;
	}

	template <typename data_type>
	LinkedList<data_type>::~LinkedList(){ //destructor
		while(head != NULL){
			removeHead();
		}
		tail = NULL;
		length = 0;
	}

	template <typename data_type>
    void LinkedList<data_type>::add_to_tail(const data_type& data){
    	if(tail == NULL){

			tail = new Node<data_type>(data); //start from scratch if no nodes exist already

			head = tail;
			current = tail;
			length = 1;
		}
		else{
			Node<data_type>* temp = new Node<data_type>(data); //adding a new node to the tail of the existing tail

			temp->set_prev(tail); // ^^
			tail->set_next(temp);
			tail = temp;
			temp = NULL;
		}
	}

	template <typename data_type>
	void LinkedList<data_type>::add_to_head(const data_type& d){ //adds data to head
		if(head == NULL){

			Node<data_type>* temp = new Node<data_type>(d);

			head = temp;
			tail = temp;
			current = temp;
			temp = NULL;
		}
		else{
			Node<data_type>* temp = new Node<data_type>(d);

			temp->set_next(head);
			head->set_prev(temp);
			head = temp;
			temp = NULL;
		}
	}

	template <typename data_type>
	void LinkedList<data_type>::remove(const data_type& word){
		//find word
		current = head; //initialising to start
		while(current != NULL){
			if(current->get_data().compare(word) == 0){ //if the word is found remove the node where it is found
				if(current == head){
					removeHead();
				}
				else if(current == tail){
					removeTail();
					break;
				}
				else{
					removeCurrent();
				}
			}
			current = current->get_next(); //iterating
		}
	}

	template <typename data_type>
	void LinkedList<data_type>::removeHead(){ //removes the head node
		current = head;	
        Node<data_type>* temp;							
        temp = head;									
        head = head->get_next();								
        if (head != NULL) {head->set_prev(NULL);}		
        else {tail = NULL;} 								
        delete temp; 										
        length --;											
        current = head;
	}

	template <typename data_type>
	void LinkedList<data_type>::removeCurrent(){ //removes the current node
		current->get_prev()->set_next(current->get_next()); //linking the previous node of current to the next node of current
		current->get_next()->set_prev(current->get_prev()); //linking the next node of current to the previous node of current for doubly linked
		delete current;
		current = head;
	}

	template <typename data_type>
	void LinkedList<data_type>::removeTail(){ //removes the tail node
		Node<data_type>* temp;
		temp = tail;
		tail = tail->get_prev(); //assigning tail to the previous node
		tail->set_next(NULL); //assigning the what was tail node to NULL
		delete temp;
	}

	template <typename data_type>
	int LinkedList<data_type>::count(const data_type& word){ //counts and returns the amount of times a specified string appears in all nodes
		current = head;
		int count = 0;
		for(int i=0;i<size();i++){
			if(current->get_data().compare(word) == 0){ 
				count++; //increment count when the specified string is found in a node
			}
			current = current->get_next();
		}
		return count;
	}

	//bubble sort algorithm
	template <typename data_type>
	void LinkedList<data_type>::sort(){ //sorts the nodes into alphabetical order according to the string data inside
		current = head;
		for(int i=0;i<size()-1;i++){
			for(int j=0;j<size()-i-1;j++){ //implementing bubble sort
				if(current->get_next()->get_data() < current->get_data()){ //checks if the data next to current has a lower ASCII value for alphabetical sort

					add_to_tail(current->get_data()); //adding current string to tail as a placeholder for swapping

					current->set_data(current->get_next()->get_data()); //setting the data that was next to current to currents old position

					forward(); //moving current pointer to next in linkedlist
					current->set_data(tail->get_data()); //setting the what was next position to be the old current data. I,e the data swapped
					current = current->get_prev(); //pointing current to previous node to maintain iteration outside if statment
					removeTail(); //removing the temporary placeholder
				}
				current = current->get_next(); //iterating
			}
			current = head; //sort must begin from beginning once a node has bubbled up to the top
		}
	}

	template <typename data_type>
	void LinkedList<data_type>::set_current(Node<data_type>* newCurrent){ //sets the current pointer to point to a different node in the linked list
		current = newCurrent;
	}

	template <typename data_type>
	data_type LinkedList<data_type>::get_current(){ //returning data stored in the node at current pointer
		return current->get_data();
	}

	template <typename data_type>
    data_type LinkedList<data_type>::getHead(){ //returns head data
		current = head;
		return current->get_data();
	}

	template <typename data_type>
	void LinkedList<data_type>::start(){ //setting current pointer to point to head of linked list
		current = head;
	}

	template <typename data_type>
	void LinkedList<data_type>::end(){ //setting current pointer to point to the tail of linked list
		current = tail;
	}

	template <typename data_type>
	void LinkedList<data_type>::forward(){ //moving current to the next node along the linked list
		if(current->get_next() != NULL){ //ensuring the next node is not NULL to stay within limits of list
			current = current->get_next();
		}
	}

	template <typename data_type>
	int LinkedList<data_type>::size(){ //returns the amount of nodes currently within the linked list
		int counter = 0;
		Node<data_type>* temp = head;
		while(temp != NULL){ //signifies end of linked list
			counter++;
			temp = temp->get_next();
		}
		return counter;
	}

	template <typename data_type>
	std::ostream& operator << (std::ostream& out, LinkedList<data_type>& L){ //overloading << operator
		L.start();
		for(int i = 0; i<L.size();i++){
			out << L.get_current() << " "; //returns all data within all nodes of the linked list
			L.forward();
		}
		return out;
	}

	template <typename data_type>
	LinkedList<data_type>& LinkedList<data_type>::operator += (LinkedList<data_type>& list){ //adds a linked list to the end of another linked list maintaining the structure of both lists
		list.start();
		for(int i=0;i<list.size();i++){
			this->add_to_tail(list.get_current()); //adds the given list to the tail of the first list
			list.forward();
		}
		return *this;
	}