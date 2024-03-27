#include "Card.h"
#include <cstdlib>
#include <vector>
#include <ctime>


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

//Add to existing hand
void Hand::Add(Card C) {
	this->cards.push_back(C);
}

//Count sum of hand
int Hand::Sum() {
	int total{};
	for (int i = 0; i < this->cards.size(); i++) {
		total += this->cards[i].Value();
	}
	return total;
}