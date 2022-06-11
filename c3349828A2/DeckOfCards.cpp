/*
Name: Harlan De Jong
Student Number: c3349828
Course: SENG1120
Date Due: 21/10/20

DeckOfCards.cpp
*/
#include "DeckOfCards.h"
#include "Queue.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

DeckOfCards::DeckOfCards(){//constructor
	finalList = new Queue<Card>();
		
    initialise(*finalList, "S"); //initialising finallist queue
    initialise(*finalList, "H");
    initialise(*finalList, "C");
    initialise(*finalList, "D");
}
DeckOfCards::~DeckOfCards(){//destructor
	delete finalList;
}

string DeckOfCards::allCards(){//returns all the card faces of the queue
	Queue<Card>* temp = new Queue<Card>();
	Card* card = new Card();
	string cardInfo; 

	for(int i=0; i<52; i++){
	    cardInfo += finalList->front().getFace();    
	    cardInfo += " ";
	    card->setFace(finalList->front().getFace());
		card->setValue(finalList->front().getValue());
		card->setFaceUp(finalList->front().getFaceUp());    //storing card values to put back into finalList               
	    temp->enqueue(*card);
	    finalList->dequeue();
    }
    for(int i=0;i<52;i++){
    	card->setFace(temp->front().getFace());
		card->setValue(temp->front().getValue());
		card->setFaceUp(temp->front().getFaceUp()); //putting card values back into finalList
		finalList->enqueue(*card);
		temp->dequeue();
    }
    delete card;
    return cardInfo;                       
}

void DeckOfCards::shuffle(){//shuffles cards in queue by separating queue into 4 and randomly putting the top card of a queue to the bottom of another
	Queue<Card>* temp = new Queue<Card>[4];
	Card* card = new Card();
	for(int i=1;i<=52;i++){
		card->setFace(finalList->front().getFace());
		card->setValue(finalList->front().getValue());
		card->setFaceUp(finalList->front().getFaceUp());//storing card values to put into 4 different queues
		if(i>39){
			temp[3].enqueue(*card); //putting 39-52 cards in a queue 
		}
		else if(i>26){
			temp[2].enqueue(*card); //putting 26-39 cards in a queue
		}
		else if(i>13){
			temp[1].enqueue(*card); //putting 13-26 cards in a queue
		}
		else if(i>0){
			temp[0].enqueue(*card); //putting 1-13 cards in a queue
		}
		finalList->dequeue();

	}

	int randNum1;
	int randNum2;

	srand(time(NULL)); //RNG
	for(int i=1;i<=1000;i++){
		randNum1 = rand() % 4 + 0; //RNG 0-3
		do{
			randNum2 = rand() % 4 + 0; //RNG 0-3
		}
		while(randNum2 == randNum1); //repeat if random numbers are the same
		if(temp[randNum1].length()>0){ //ensuring we dont try to access null
			card->setFace(temp[randNum1].front().getFace());
			card->setValue(temp[randNum1].front().getValue());
			card->setFaceUp(temp[randNum1].front().getFaceUp());//storing card values of a random queue to put into another random queue

			temp[randNum2].enqueue(*card);
			temp[randNum1].dequeue();
		}
	}
	
	for(int i=0;i<=3;i++){
		while(temp[i].length()>0){
			card->setFace(temp[i].front().getFace());
			card->setValue(temp[i].front().getValue());
			card->setFaceUp(temp[i].front().getFaceUp());//putting card values back into finalList
			finalList->enqueue(*card);
			temp[i].dequeue();
		}
	}
	
	delete card;
}

void DeckOfCards::initialise(Queue<Card>& list, string suit){//gives finallist 13 playing cards in a queue of a given suit
	string cardNum [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};  // Card number
    Card* card = new Card();  // Creates a new card

	for (int j = 0; j < 13; j ++){
		card->setFace (cardNum[j] + "-" + suit); //applying face of card i,e K-S
		if (cardNum[j] == "A"){
			card->setValue(11); //Aces value = 11
		}
		else if (cardNum[j] == "J" || cardNum[j] == "K" || cardNum[j] == "Q"){ //jack, queen and king value = 10
			card->setValue(10);
		}
		else{
			card->setValue(j+2); //numbered cards are the value that their number is
		}
		card->setFaceUp(false);
		
        list.enqueue(*card);
    }
    delete card;
}

size_t DeckOfCards::length() const{ //returns the amount of cards in the deck
	return finalList->length();
}

Card DeckOfCards::draw(){//gets value of card at front of queue and returns it
	Card* drawnCard = new Card();
	drawnCard->setValue(finalList->front().getValue()); //gets value of card at front of queue and returns it
	drawnCard->setFace(finalList->front().getFace());
	drawnCard->setFaceUp(finalList->front().getFaceUp());
	finalList->dequeue();
	return *drawnCard;
}

ostream& operator << (ostream& out, DeckOfCards& cards){ //overloaded << operator
	out << cards.allCards();
	return out;
}