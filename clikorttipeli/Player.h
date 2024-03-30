#pragma once

#ifndef PLAYER
#define PLAYER
#include "Card.h"

class Player {
public:
	Player();
	
	void AddBalance(unsigned int Amount);

	void TakeBalance(unsigned int Amount);

	void ViewBalance();

	void GiveCards(unsigned int Count, Deck& deck);

	void NewHand();

	int SumOfHand();

private:
	Hand hand;
	unsigned int balance;
};

#endif