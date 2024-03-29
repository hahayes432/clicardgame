#include <iostream>
#include "Card.h"
#include "Player.h"

using namespace std;

void blackjack(Player player) {
	bool gameOver = false;
	cout << "How much do you want to bet on the next game?" << endl;
	player.ViewBalance();
	unsigned long long bet;
	cin >> bet;
	//game loop
	do {
		short choice;
		cin >> choice;
		switch (choice)
		{
		case 1: 
			
			break;
		default:
			gameOver = true;
			break;
		}
	} while (!gameOver);
}

int main() {
	//for use later
	Player player;
	cout << "What game do you want to play \n";
	cout << "1: Blackjack\n2: todo..." << endl;
	short choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		blackjack(player);
		break;
	default:
		break;
	}
}