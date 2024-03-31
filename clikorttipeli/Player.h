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

	void GiveCards(unsigned int Count, Deck& deck);

	void EmptyHand();

	int SumOfHand();
	
	Hand SplitHand();

	void CardtoDealer(Card& c);

private:
	Hand hand;
	double balance;
};

#endif