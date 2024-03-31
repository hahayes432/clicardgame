#include <iostream>
#include "Card.h"
#include "Player.h"
#include <string>

using namespace std;

void Hit(Player& player, Deck& deck, __in_opt short s = 1) {
	// optional s so i dont have to make a seperate function for revealing dealers hand
	switch (s)
	{
	case 1:
		player.GiveCards(1, deck);
		cout << "You've decided to hit. The new value of your hand is: " << player.SumOfHand() << endl;
		break;
	case 2:
		Card card = deck.TakeCard();
		cout << "The dealers has pulled a card with the value: " << card.Value() << "\nTheir hand now has a value of " << player.SumOfHand() << endl;
		player.CardtoDealer(card);
		break;
	}
	//shuffle for a little more randomness in the cards
	deck.ShuffleDeck();
}

void Stand(Player& player) {
	cout << "You've decided to stand. Your hand's current value is: " << player.SumOfHand() << endl;
}

Hand Split(Player& player, double& bet, Deck& deck) {
	Hand n = player.SplitHand();
	if (n.Size() == 1) {
		cout << "You must place a bet on the new hand.\nDo you agree to place an extra bet? Y/n (defaults to yes)"<< endl;
		bool agree = true;
		string y;
		cin >> y;
		if (y.at(0) == 'n' || y.at(0) == 'N') {
			agree = false;
		}
		if (agree == true) {
			cout << "How much would you like to bet with the new hand?" << endl;
			double newBet = 0;
			cin >> newBet;
			while (cin.fail() || newBet <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number that is higher than 0" << endl;
				cin >> newBet;
			}
			bet += newBet;
			player.GiveCards(1, deck);
			Card c = deck.TakeCard();
			n.Add(c);
			return n;
		}
	}
}

void DoubleDown() {

}

void Fold(Player& player, double& bet) {
	double amountLost = (bet / 2);
	cout << "amount lost: " << amountLost << "\nbet amount" << bet << endl;
	//add half of original bet back to balance
	player.AddBalance(amountLost);
	cout << "You've folded and lost half your bet amount." << endl;
	player.ViewBalance();
	player.EmptyHand();
}

double CalculateWinnings(double& bet) {
	return (bet * 1.72)*1.02;
}

void blackjack(Player& player) {
	Player Dealer;
	bool gameOver = false;
	cout << "How much do you want to bet on the next game?" << endl;
	player.ViewBalance();
	double bet = 0;
	cin >> bet;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "PLeesea give number :DD" << endl;
		cin >> bet;
	}
	player.TakeBalance(bet);
	Deck deck;
	Deck* ptrDeck = &deck;
	deck.FillDeck();
	Dealer.GiveCards(1,*ptrDeck);
	deck.ShuffleDeck();
	player.GiveCards(2,*ptrDeck);
	cout << "The sum of the players deck is: " << player.SumOfHand() << endl;
	cout << "The sum of the dealers deck is: " << Dealer.SumOfHand() << endl;
	bool HandOver21 = false;
	//game loop
	do {
		cout << "What action do you want to do?\n1: Hit\n2: Stand\n3: Split\n4: DoubleDown\n5: Fold\n6: Done" << endl;
		short choice;
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You input the wrong data type. Please give an integer." << endl;
			cin >> choice;
		}
		//Have to declare outside of switch. Only used with split.
		Hand hand2;
		switch (choice)
		{
		case 1:
			Hit(player, *ptrDeck);
			break;
		case 2:
			Stand(player);
			deck.ShuffleDeck();
			break;
		case 3:
			hand2 = Split(player,bet,deck);
			break;
		case 4:
			DoubleDown();
			break;
		case 5:
			Fold(player, bet);
			gameOver = true;
			break;
		case 6:
			cout << "Revealing dealers hand." << endl;
			gameOver = true;
			break;
		default:
			cout << "Please enter a number from 1 to 6" << endl;
			break;
		}
		//loss check for going above sum of 21
		if (player.SumOfHand() > 21) {
			gameOver = true;
			HandOver21 = true;
			cout << "You lost.\nYou've gone over 21." << endl;
			cout << "\nTotal balance lost: $" << bet << endl;
			player.TakeBalance(bet);
			player.EmptyHand();
			Dealer.EmptyHand();
		}
	} while (!gameOver);

	int playerHandValue = player.SumOfHand();
	Player* ptrDealer = &Dealer;
	
	switch (HandOver21)
	{
		//Here if player didnt lose from going above 21
	case false:
		while (Dealer.SumOfHand() < 17) {
			Hit(*ptrDealer, *ptrDeck, 2);
		}
		cout << "The dealers hand has settled at a value of " << Dealer.SumOfHand() << endl;
		if (playerHandValue > Dealer.SumOfHand() || playerHandValue == 21) {
			cout << "You've won the match!" << endl;
			double Winnings = CalculateWinnings(bet);
			cout << "You've won $" << Winnings << " and your hand's final value was " << playerHandValue << endl;
			player.ViewBalance();
			player.EmptyHand();
			Dealer.EmptyHand();
		}
		else {
			cout << "You've lost the match.\n\nThe dealer has won with the final hand value of " << Dealer.SumOfHand() << " while your hand's value was " << playerHandValue << "." << endl;
			cout << "You've lost your bet amount which was $" << bet << endl;
			player.ViewBalance();
			player.EmptyHand();
			Dealer.EmptyHand();
		}
		break;
		//The player already lost so just break
	case true:
		break;
	}
}

int main() {
	//for use later
	Player player;
	Player* ptrPlayer = &player;
	cout << "What game do you want to play \n";
	cout << "1: Blackjack\n2: todo..." << endl;
	short choice;
	cin >> choice;
	//prevent infinite cin loop and default to 1st option
	if (cin.fail()) {
		cout << "Error getting short integer. Defaulting to 1." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		choice = 1;
	}
	switch (choice)
	{
	case 1:
		blackjack(*ptrPlayer);
		break;
	default:
		break;
	}
}