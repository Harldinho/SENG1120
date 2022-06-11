/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

Card.cpp
*/
#include "Card.h"		

Card::Card(){//Constructor

}

Card::Card(string f, int v, bool d){//constructor
	face = f;
	value = v;
	faceUp = d;
}

Card::~Card(){//destructor
	
}

void Card::setFace(string f){//sets the face of the card
	face = f;
}
void Card::setValue(int v){//set the value associated with card
	value = v;
}
void Card::setFaceUp(bool d){//sets true of false if the face is up
	faceUp = d;
}

string Card::getFace() const{//returns the face string of the card
	return face;
}
int Card::getValue() const{//returns the value associated with card
	return value;
}
bool Card::getFaceUp() const{//returns true or false if the face is up
	return faceUp;
}