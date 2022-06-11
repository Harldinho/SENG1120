/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

HandOfCards.cpp
*/
#include "HandOfCards.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <sstream> //for conversion of int to string
using namespace std;

HandOfCards::HandOfCards(){//constructor
	handList = new Queue<Card>();
}
HandOfCards::~HandOfCards(){//destructor
	delete handList;
}

int HandOfCards::count(){//counts the value of the hand stored in the list (only facing up)
	Card* card = new Card();
	Queue<Card>* temp = new Queue<Card>();
	int cardValue = 0;

	for(int i=0;i<=handList->length();i++){//iterates through queue
		if(handList->front().getFaceUp()){
			cardValue = cardValue + handList->front().getValue(); //stores card details
		}
		card->setFace(handList->front().getFace());
		card->setValue(handList->front().getValue());
		card->setFaceUp(handList->front().getFaceUp());	//storing card values to put back into handlist
		temp->enqueue(*card);
		handList->dequeue();
	}
	for(int i=0;i<=temp->length();i++){
    	card->setFace(temp->front().getFace());
		card->setValue(temp->front().getValue());
		card->setFaceUp(temp->front().getFaceUp()); //putting card values back into handlist
		handList->enqueue(*card);
		temp->dequeue();
    }

    delete card; //avoid memory leak
	return cardValue;
}

int HandOfCards::countAll(){//counts the value of the hand stored in the list
	Card* card = new Card();
	Queue<Card>* temp = new Queue<Card>();
	int allCardValue = 0;
	for(int i=0;i<=handList->length();i++){
		allCardValue = allCardValue + handList->front().getValue();
		card->setFace(handList->front().getFace());
		card->setValue(handList->front().getValue());
		card->setFaceUp(handList->front().getFaceUp()); //storing card values to put back into handlist
		temp->enqueue(*card);
		handList->dequeue();
	}
	for(int i=0;i<=temp->length();i++){
    	card->setFace(temp->front().getFace());
		card->setValue(temp->front().getValue());
		card->setFaceUp(temp->front().getFaceUp()); //putting card values back into handlist
		handList->enqueue(*card);
		temp->dequeue();
    }
    delete card;
	return allCardValue;
}

string HandOfCards::value(){//returns a string of the sequences of cards in the list
	Card* card = new Card();
	Queue<Card>* temp = new Queue<Card>();
	string cardString;

	for(int i=0;i<=handList->length();i++){
		if(handList->front().getFaceUp() == true){
			cardString += handList->front().getFace() + " ";
		}
		else{
			cardString += "?-? ";
		}
		card->setFace(handList->front().getFace());
		card->setValue(handList->front().getValue());
		card->setFaceUp(handList->front().getFaceUp()); //storing card values to put back into handlist
		temp->enqueue(*card);
		handList->dequeue();
	}

	for(int i=0;i<=temp->length();i++){
    	card->setFace(temp->front().getFace());
		card->setValue(temp->front().getValue());
		card->setFaceUp(temp->front().getFaceUp()); //putting card values back into handlist
		handList->enqueue(*card);
		temp->dequeue();
    }

	int handValue = count();
	stringstream ss;
	ss << handValue; //converting int to string
	cardString = cardString + "(" + ss.str() +" points)";

    delete card;
	return cardString;
}

void HandOfCards::faceUp(){//makes all cards in the hand face up
	Card* card = new Card();
	Queue<Card>* temp = new Queue<Card>();

	for(int i=0;i<=handList->length();i++){
		card->setFace(handList->front().getFace());
		card->setValue(handList->front().getValue()); //storing card values to put back into handlist
		card->setFaceUp(true);
		temp->enqueue(*card);
		handList->dequeue();
	}

	for(int i=0;i<=temp->length();i++){
    	card->setFace(temp->front().getFace());
		card->setValue(temp->front().getValue());//putting card values back into handlist
		card->setFaceUp(true); 
		handList->enqueue(*card);
		temp->dequeue();
    }
    delete card;
}

void HandOfCards::add(Card card, const bool faceIsUp){//adds a card to the hand queue
	card.setFaceUp(faceIsUp);
	handList->enqueue(card);
}

ostream& operator << (ostream& out, HandOfCards& cards){//overloading << operator
	out << cards.value();
	return out;
}