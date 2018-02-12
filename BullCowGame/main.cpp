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
FText GetValidGuess();
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
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 i = 1; i <= MaxTries; i++) // TODO change from FOR to WHILE loop once we are validating tries.
	{
		FText Guess = GetValidGuess();
		// Submit valid guess to game.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO add a game summary.
}

// Loop continually until player enters a valid guess.
// TODO change to get valid guess.
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		// Get a guess from the player.
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". " << "Enter Your Guess: ";
		FText Guess;
		getline(std::cin, Guess);

		// Check validity of guess.
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram. (Word where any letter is used only once in the word.\n)";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter the word in only lowercase letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

// Ask if player wants to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response;
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}