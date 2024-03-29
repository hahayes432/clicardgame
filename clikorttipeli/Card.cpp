#include "Card.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <iostream>

Card::Card() {
	//random value between 0 and n-1
	short n = 12; 
	this->value = rand() % n;
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
		Card newCard = Card::Card();
		this->cards.push_back(newCard);
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

void Hand::Shuffle() {
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
}

void Hand::PrintCards() {
	for (int i = 0; i < this->cards.size(); i++) {
		std::cout << "Card value at index " << i << " is: " << this->cards[i].Value() << std::endl;
	}
}