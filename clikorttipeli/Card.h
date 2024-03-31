#pragma once

#ifndef CARD
#define CARD
#include <vector>

//mostly here as new types for use with player class and some functions that might not get used idk yet
class Card {
public:
	Card();

	short Value();

private:
	short value;
};

class Hand {
public:
	Hand();

	void Add(Card c);

	void AddMultiple(int Count);

	int Sum();

	void Shuffle();

	Card TakeFromHand();

	size_t Size();

	void EmptyHand();

	void PrintCards();

	bool SameValue();

private:
	std::vector<Card> cards;
};

class Deck : public Hand {
public:
	Deck();

	void FillDeck();

	void ShuffleDeck();

	bool IsEmpty();

	Card TakeCard();

	size_t SizeofDeck();
private:
	Hand deck;
};

#endif