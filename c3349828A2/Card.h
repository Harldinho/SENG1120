/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

Card.h
*/
#ifndef CARD
#define CARD
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Card{
	public:
		Card(); //Constructor
		Card(string f, int v, bool d = false); //constructor
		~Card(); //destructor

		void setFace(string f); //sets the face of the card
		void setValue(int v); //set the value associated with card
		void setFaceUp(bool d); //sets true of false if the face is up

		string getFace() const; //returns the face string of the card
		int getValue() const; //returns the value associated with card
		bool getFaceUp() const; //returns true or false if the face is up

	private:
		string face;
		int value;
		bool faceUp;

};

#endif