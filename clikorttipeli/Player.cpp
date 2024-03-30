#include "Player.h"
#include <iostream>

//Initialize player
Player::Player() {
	this->balance = 500;
	this->hand = Hand::Hand();
}

//Give balance from winning
void Player::AddBalance(unsigned int Amount) {
	this->balance += Amount;
}

//Take Balance from losing
void Player::TakeBalance(unsigned int Amount) {
	if (Amount > this->balance || (this->balance -= Amount) < 50) {
		this->balance = 50;
	}
	else {
		this->balance -= Amount;
	}
}

//Print balance
void Player::ViewBalance() {
	std::cout << "Your balance is: " << this->balance << "$" << std::endl;
}

//Give player cards from deck
void Player::GiveCards(unsigned int Count, Deck& deck) {
	if (deck.IsEmpty() == false) {
		for (unsigned int i = 0; i < Count; i++) {
			this->hand.Add(deck.TakeCard());
		}
	}
	else {
		std::cout << "The deck is empty." << std::endl;
	}
}

//Make hand empty for next games
void Player::NewHand() {
	this->hand.EmptyHand();
}

int Player::SumOfHand() {
	return this->hand.Sum();
}