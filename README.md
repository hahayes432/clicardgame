# clicardgame
End project for c++ ohjelmointi course

Blackjack command line game.

## Build
Build the solution from the build button in visual studio

## Short description of the games functions

There are a few functions that i've made in this.

The main prompt of the game is a do while loop that takes input to decide what function gets used
which are listed in the following order

#### 1. Hit
You take a new card to your hand and the new sum of your hand is printed on screen

#### 2. Stand
You take no cards and the deck gets shuffled for a little added randomness

#### 3. Split
If you have 2 of the same card your hand gets split and you have to place a new bet on that hand
Both hands get 1 card added to them so that they both contain 2 cards at the end of the function
also makes you play the 2nd hand seperately

#### 4. DoubleDown
Double your bet and get 1 extra card into your hand

#### 5. Fold
You stop playing and lose half the bet you placed

#### 6. CheckHand
Prints your cards values on screen

#### 7. Done
Stop taking cards and start revealing dealers hand until it is above the value of 17
After the initial game loop you do the same loop a second time if you split your hand at the start of the game

#### Play again
Once you have completed your second hand or if you didnt split you will be prompted on wether you want to play again

This will default to yes if you enter any character that isn't 'n' and only checks the first character of the string
The input is case insensitive as it is made to be lowercase after the input is given
If the character from the input is n the game will close
