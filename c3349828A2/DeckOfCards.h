/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

DeckOfCards.h
*/
#ifndef DECK
#define DECK

#include <cstdlib>
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Card.h"
#include "Queue.h"
using namespace std;

class DeckOfCards{
	public:
		DeckOfCards(); //constructor
		~DeckOfCards(); //destructor

		void shuffle(); //shuffles cards in queue by separating queue into 4 and randomly putting the top card of a queue to the bottom of another
		string allCards(); //returns all the card faces of the queue
		size_t length() const; //returns the amount of cards in the deck
		void initialise(Queue<Card>& list, string suit); //gives finallist 13 playing cards in a queue of a given suit
		Card draw(); //gets value of card at front of queue and returns it

	private:
		Queue<Card>* finalList;
};

ostream& operator << (ostream& out, DeckOfCards& cards); //overloaded << operator

#endif