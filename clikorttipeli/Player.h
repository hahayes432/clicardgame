#pragma once

#ifndef PLAYER
#define PLAYER
#include "Card.h"

class Player {
public:
	Player();
	
	void AddBalance(double Amount);

	void TakeBalance(double Amount);

	void ViewBalance();

	void GiveCards(unsigned int Count, Deck& deck, int whichHand);

	void EmptyHand(int whichHand);

	int SumOfHand(int whichHand);
	
	void SplitHand();

	void CardtoDealer(Card& c);

	void CheckCardsInHand(int whichHand);

	bool isHandEmpty(int whichHand);
	
	double CurrentBalance();

private:
	Hand hand;
	//used if split
	Hand hand2;
	double balance;
};

#endif