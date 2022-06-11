/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

HandOfCards.h
*/
#ifndef HAND
#define HAND

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Card.h"
#include "Queue.h"
using namespace std;

class HandOfCards{
	public:
		HandOfCards(); //constructor
		~HandOfCards(); //destructor

		void add(Card card, const bool faceIsUp); //adds a card to the hand queue
		int count(); //counts the value of the hand stored in the list (only facing up)
		int countAll(); //counts the value of the hand stored in the list
		string value(); //returns a string of the sequences of cards in the list
		void faceUp(); //makes all cards in the hand face up

	private:
		Queue<Card>* handList;
};

ostream& operator << (ostream& out, HandOfCards& cards); //overloading << operator

#endif