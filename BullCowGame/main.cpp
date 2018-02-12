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
void PrintGameSummary();

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
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop asking for guesses while the game is NOT won, and there are still tries remaining.
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		// Submit valid guess to game.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();

	// TODO add a game summary.
}

// Loop continually until player enters a valid guess.
FText GetValidGuess()
{
	FText Guess;
	EGuessStatus Status = EGuessStatus::Invalid;
	do
	{
		// Get a guess from the player.
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". " << "Enter Your Guess: ";
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
			// Assuming the guess is valid.
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

// Ask if player wants to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word (y/n)? ";
	FText Response;
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

// Print message based on whether player won or not.
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations you won the game!!!\n\n";
	}
	else
	{
		std::cout << "Better luck next time...\n\n";
	}
}