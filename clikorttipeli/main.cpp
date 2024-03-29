#include <iostream>
#include "Card.h"

using namespace std;

void blackjack() {
	Hand DealerHand;
	Hand PlayerHand;
	PlayerHand.AddMultiple(2);
	DealerHand.AddMultiple(2);
	cout << "The current value of your hand is: " << PlayerHand.Sum() << "\nThe current value of the dealers hand is: " << DealerHand.Sum() << endl;
	PlayerHand.Add(Card::Card());
	DealerHand.Add(Card::Card());
	cout << "The current value of your hand is: " << PlayerHand.Sum() << "\nThe current value of the dealers hand is: " << DealerHand.Sum() << endl;
}

int main() {
	cout << "What game do you want to play \n";
	cout << "1: Blackjack\n2: todo..." << endl;
	short choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		blackjack();
		break;
	default:
		break;
	}
}