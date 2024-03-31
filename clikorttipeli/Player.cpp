#include "Player.h"
#include <iostream>

//Initialize player
Player::Player() {
	this->balance = 500;
	this->hand = Hand::Hand();
}

//Give balance from winning
void Player::AddBalance(double Amount) {
	this->balance += Amount;
}

//Take Balance from losing
void Player::TakeBalance(double Amount) {
	if (Amount > this->balance || (this->balance - Amount) < 50) {
		this->balance = 50;
	}
	else {
		this->balance -= Amount;
	}
}

//Print balance
void Player::ViewBalance() {
	std::wcout << "Your balance is: $" << this->balance << std::endl;
}

//Give player cards from deck
void Player::GiveCards(unsigned int Count, Deck& deck, int WhichHand) {
	if (deck.IsEmpty() == false) {
		switch (WhichHand) {
		case 1:
			for (unsigned int i = 0; i < Count; i++) {
				this->hand.Add(deck.TakeCard());
			}
			break;
		case 2:
			for (unsigned int i = 0; i < Count; i++) {
				this->hand2.Add(deck.TakeCard());
			}
			break;
		}
	}
	else {
		std::cout << "The deck is empty." << std::endl;
	}
}

//Make hand empty for next games
void Player::EmptyHand(int WhichHand) {
	switch (WhichHand) {
	case 1:
		this->hand.EmptyHand();
		break;
	case 2:
		this->hand2.EmptyHand();
		break;
	}
}

int Player::SumOfHand(int WhichHand) {
	switch (WhichHand) {
	case 1:
		return this->hand.Sum();
		break;
	case 2:
		return this->hand2.Sum();
		break;
	}
}

void Player::SplitHand() {
	if (this->hand.Size() == 2 && this->hand.SameValue() == true && this->hand2.Size() == 0) {
		this->hand2.Add(this->hand.TakeFromHand());
	}
	else {
		std::cout << "Your hand cannot be split." << std::endl;
	}
}

void Player::CardtoDealer(Card& c) {
	this->hand.Add(c);
}

bool Player::isHandEmpty(int WhichHand) {
	switch (WhichHand) {
	case 1:
		if (this->hand.Size() == 0) {
			return true;
		}
		else {
			return false;
		}
		break;
	case 2:
		if (this->hand2.Size() == 0) {
			return true;
		}
		else {
			return false;
		}
		break;
	}
}

void Player::CheckCardsInHand(int whichHand) {
	switch (whichHand) {
	case 1:
		this->hand.PrintCards();
		break;
	case 2:
		this->hand2.PrintCards();
		break;
	}
}

double Player::CurrentBalance() {
	return this->balance;
}