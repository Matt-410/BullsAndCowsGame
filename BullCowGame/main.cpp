/*This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate the game.

// Main driver for the program.
int main()
{
	bool bPlayAgain = true;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

// Introduction to the game.
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
}

void PlayGame()
{
	// Reset game conditions.
	BCGame.Reset();

	// Loop for number of turns asking for guesses.
	// TODO change from FOR to WHILE loop once we are validating tries.
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO add validation check
		// Submit valid guess to game.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO add a game summary.
}

// Get a guess from the player.
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". " << "Enter Your Guess: ";
	FText Guess;
	getline(std::cin, Guess);
	return Guess;
}

// Ask if player wants to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response;
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}