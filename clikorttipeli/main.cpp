#include <iostream>
#include "Card.h"
#include "Player.h"
#include <string>
#include <algorithm>

using namespace std;

void Hit(Player& player, Deck& deck, short whatHand = 1) {
	// case 3 made so i dont have to make a seperate function for revealing dealers 
	/*
				What hand used to be able to play hand 2 if split was successfull
	*/
	switch (whatHand)
	{
	case 1:
		player.GiveCards(1, deck, whatHand);
		cout << "You've decided to hit. The new value of your hand is: " << player.SumOfHand(whatHand) << endl;
		break;
	case 2:
		player.GiveCards(1, deck, whatHand);
		cout << "You've decided to hit. The new value of your hand is: " << player.SumOfHand(whatHand) << endl;
		break;
	case 3:
		Card card = deck.TakeCard();
		cout << "The dealers has pulled a card with the value: " << card.Value() << "\nTheir hand now has a value of " << player.SumOfHand(1) << endl;
		player.CardtoDealer(card);
		break;
	}
	//shuffle for a little more randomness in the cards
	deck.ShuffleDeck();
}


void Split(Player& player, double& bet, Deck& deck, bool& hasSplit) {
	if (hasSplit == false)	{
		player.SplitHand();
		if (player.isHandEmpty(2) == false) {
			cout << "You must place a bet with the new hand. How much would you like to bet?" << endl;
			double newBet;
			cin >> newBet;
			while (cin.fail() || newBet <= 0 || newBet > player.CurrentBalance()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number that is higher than 0." << endl;
				cin >> newBet;
			}
			player.TakeBalance(newBet);
			bet += newBet;
			cout << "You've placed a new bet worth $" << newBet << ". Which brings the new total bet to $" << bet << endl;
			player.GiveCards(1, deck, 1);
			player.GiveCards(1, deck, 2);
			hasSplit = true;
		}
	}
}

void DoubleDown(Player& player, double& bet, Deck& deck, short whatHand = 1) {
	/*
				What hand used to be able to play hand 2 if split was successfull
	*/
	player.TakeBalance(bet);
	bet *= 2;
	player.GiveCards(1, deck, whatHand);
	cout << "Your bet has been doubled and you've been given a new card.\nThe bet now stands at $" << bet << ".\nThe sum of your hand has increased to " << player.SumOfHand(whatHand) << endl;
}

void Fold(Player& player, double& bet) {
	double amountLost = (bet / 2);
	cout << "amount lost: " << amountLost << "\nbet amount" << bet << endl;
	//add half of original bet back to balance
	player.AddBalance(amountLost);
	cout << "You've folded and lost half your bet amount." << endl;
	player.ViewBalance();
}

double CalculateWinnings(double& bet) {
	return (bet * 1.72)*1.02;
}

//move game loop here
void gameLoop(Player& player, Deck& deck, double& bet, Player& Dealer, bool& hasSplit, int whatHand = 1)  {
	/*
				What hand used to be able to play hand 2 if split was successfull
	*/
	bool gameOver = false;
	bool HandOver21 = false;
	player.GiveCards(2, deck, whatHand);
	//make sure player cant auto lose and that the starting hand isnt too high
	if (player.SumOfHand(whatHand) >= 17) {
		player.EmptyHand();
		deck.ShuffleDeck();
		player.GiveCards(2, deck, whatHand);
	}
	Dealer.GiveCards(1, deck, whatHand);
	cout << "The sum of the players deck is: " << player.SumOfHand(whatHand) << endl;
	cout << "The sum of the dealers deck is: " << Dealer.SumOfHand(whatHand) << endl;

	do {
		cout << "What action do you want to do?\n1: Hit\n2: Stand\n3: Split\n4: DoubleDown\n5: Fold\n6: Check the values of your cards\n7: Done" << endl;
		short choice;
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You input the wrong data type. Please give an integer." << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			Hit(player, deck, whatHand);
			break;
		case 2:
			cout << "You've decided to stand.\nYour hand is valued at " << player.SumOfHand(whatHand) << endl;
			deck.ShuffleDeck();
			break;
		case 3:
			Split(player, bet, deck, hasSplit);
			break;
		case 4:
			DoubleDown(player, bet, deck, whatHand);
			break;
		case 5:
			Fold(player, bet);
			gameOver = true;
			break;
		case 6:
			player.CheckCardsInHand(whatHand);
			break;
		case 7:
			cout << "Revealing dealers hand." << endl;
			gameOver = true;
			break;
		default:
			cout << "Please enter a number from 1 to 6" << endl;
			break;
		}
		//loss check for going above sum of 21
		if (player.SumOfHand(whatHand) > 21) {
			gameOver = true;
			HandOver21 = true;
			cout << "You lost.\nYou've gone over 21." << endl;
			cout << "\nTotal balance lost: $" << bet << endl;
			player.TakeBalance(bet);
			player.EmptyHand();
			Dealer.EmptyHand();
		}
	} while (!gameOver);

	int playerHandValue = player.SumOfHand(whatHand);

	switch (HandOver21)
	{
		//Here if player didnt lose from going above 21
	case false:
		while (Dealer.SumOfHand(1) < 17) {
			Hit(Dealer, deck, 3);
		}
		cout << "The dealers hand has settled at a value of " << Dealer.SumOfHand(whatHand) << endl;
		if (playerHandValue > Dealer.SumOfHand(whatHand) || playerHandValue == 21) {
			cout << "You've won the match!" << endl;
			double Winnings = CalculateWinnings(bet);
			cout << "You've won $" << Winnings << " and your hand's final value was " << playerHandValue << endl;
			player.AddBalance(Winnings);
			player.ViewBalance();
		}
		else {
			cout << "You've lost the match.\n\nThe dealer has won with the final hand value of " << Dealer.SumOfHand(whatHand) << " while your hand's value was " << playerHandValue << "." << endl;
			cout << "You've lost your bet amount which was $" << bet << endl;
			player.ViewBalance();
		}
		break;
		//The player already lost so just break
	case true:
		break;
	}
}

void blackjack(Player& player) {
	Player Dealer;
	Player* ptrDealer = &Dealer;
	cout << "How much do you want to bet on the next game?" << endl;
	player.ViewBalance();
	double bet = 0;
	cin >> bet;
	while (cin.fail() || bet > player.CurrentBalance()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please give a number above 0." << endl;
		cin >> bet;
	}
	player.TakeBalance(bet);
	Deck deck;
	Deck* ptrDeck = &deck;
	deck.FillDeck();
	deck.ShuffleDeck();
	bool hasSplit = false;
	//game loop
	gameLoop(player, *ptrDeck, bet, *ptrDealer, hasSplit);
	if (hasSplit == true) {
		gameLoop(player, *ptrDeck, bet, *ptrDealer, hasSplit, 2);
	}
	player.EmptyHand();
	Dealer.EmptyHand();
}

int main() {
	//for use later
	Player player;
	Player* ptrPlayer = &player;
	blackjack(*ptrPlayer);
	bool playAgain = true;
	do {
		cout << "Do you want to play again? Y/n" << endl;
		string choice;
		cin >> choice;
		//make everything lowercase in the string
		transform(choice.begin(), choice.end(), choice.begin(), std::tolower);
		switch (choice.at(0)) 
		{
		case 'y':
			blackjack(*ptrPlayer);
			break;
		case 'n':
			playAgain = false;
			break;
		default:
			blackjack(*ptrPlayer);
			break;
		}

	} while (playAgain == true);
}