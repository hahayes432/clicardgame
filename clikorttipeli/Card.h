#pragma once

#ifndef CARD
#define CARD
#include <vector>

class Card {
public:
	Card();

	Card(short value);

	short Value();

private:
	short value;
};

class Hand {
public:
	Hand();

	Hand(Card C);

	void Add(Card c);

	void AddMultiple(int Count);

	int Sum();

	void Shuffle();

	//this is only here for testing remove later
	void PrintCards();

private:
	std::vector<Card> cards;
};

#endif