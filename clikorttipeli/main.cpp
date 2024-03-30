#include <iostream>
#include "Card.h"
#include "Player.h"

using namespace std;

void Hit(Player& player, Deck& deck) {
	player.GiveCards(1, deck);
	cout << "You've decided to hit. The new value of your hand is: " << player.SumOfHand() << endl;
}

void Stand() {

}

void Split() {

}

void DoubleDown() {

}

void Fold() {

}

void blackjack(Player& player) {
	Player Dealer;
	bool gameOver = false;
	cout << "How much do you want to bet on the next game?" << endl;
	player.ViewBalance();
	int bet = 0;
	cin >> bet;
	//game loop
	Deck deck;
	Deck* ptrDeck = &deck;
	deck.FillDeck();
	cout << "deck size" << deck.SizeofDeck() << endl;
	Dealer.GiveCards(1,*ptrDeck);
	player.GiveCards(2,*ptrDeck);
	deck.ShuffleDeck();
	cout << deck.SizeofDeck() << endl;
	cout << "The sum of the players deck is: " << player.SumOfHand() << endl;
	cout << "The sum of the dealers deck is: " << Dealer.SumOfHand() << endl;
	do {
		cout << "What action do you want to do?\n1: Hit\n2: Stand\n3: Split\n4: DoubleDown\n5: Fold" << endl;
		short choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Hit(player, *ptrDeck);
			break;
		case 2:
			Stand();
			break;
		case 3:
			Split();
			break;
		case 4:
			DoubleDown();
			break;
		case 5:
			Fold();
			gameOver = true;
		default:
			cout << "Please enter a number from 1 to 5" << endl;
			break;
		}
	} while (!gameOver);
}

int main() {
	//for use later
	Player player;
	Player* ptrPlayer = &player;
	cout << "What game do you want to play \n";
	cout << "1: Blackjack\n2: todo..." << endl;
	short choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		blackjack(*ptrPlayer);
		break;
	default:
		break;
	}
	cout << player.SumOfHand() << endl;
}