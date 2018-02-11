#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
}

void PlayGame()
{
	// Loop for number of turns asking for guesses.
	int MaxTries = BCGame.GetMaxTries();
	for (int i = 1; i <= MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << "\n\n";
	}
}

// Get a guess from the player.
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". " << "Enter Your Guess: \n";
	std::string Guess;
	getline(std::cin, Guess);
	return Guess;
}

// Ask if player wants to play again.
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response;
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}