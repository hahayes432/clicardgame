#include "Card.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <iostream>

Card::Card() {
	//random value between 1 and n
	short n = 11; 
	this->value = (rand() % n)+1;
}

Card::Card(short value) {
	this->value = value;

}

short Card::Value() {
	return value;
}

//Initialize empty hand
Hand::Hand() {

}
//initialize new hand with a card
Hand::Hand(Card C) {
	this->cards.push_back(C);
}

//Add a card to existing hand
void Hand::Add(Card C) {

	this->cards.push_back(C);
}

//Add more than one generated cards to hand
void Hand::AddMultiple(int Count) {
	for (int i = 0; i < Count; i++) {
		this->cards.push_back(Card::Card());
	}
}

//Count sum of hand
int Hand::Sum() {
	int total{};
	for (int i = 0; i < this->cards.size(); i++) {
		total += this->cards[i].Value();
	}
	return total;
}

//Shuffle cards in deck.
void Hand::Shuffle() {
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
}


size_t Hand::Size() {
	return this->cards.size();
}

Card Hand::TakeFromHand() {
	Card C = this->cards.at(this->cards.size() - 1);
	this->cards.pop_back();
	return C;
}

void Hand::EmptyHand() {
	this->cards.erase(this->cards.begin(),this->cards.end());
}

//Debug thing to see how random shuffle id / how random generated cards are. Remove later.
void Hand::PrintCards() {
	for (int i = 0; i < this->cards.size(); i++) {
		std::cout << "Card value at index " << i << " is: " << this->cards[i].Value() << std::endl;
	}
}

//Initialize empty deck
Deck::Deck() {

}

//Fill deck with cards and shuffle
void Deck::FillDeck() {
	this->deck.AddMultiple(52);
	this->deck.Shuffle();
}

//Shuffle the cards in the deck again
void Deck::ShuffleDeck() {
	this->deck.Shuffle();
}

size_t Deck::SizeofDeck() {
	return this->deck.Size();
}

bool Deck::IsEmpty() {
	if (this->deck.Size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

Card Deck::TakeCard() {
	return this->deck.TakeFromHand();
}