#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuessAndPrintBack();

// Main driver for the program.
int main()
{
	PrintIntro();

	// Loop for number of turns asking for guesses.
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
	}
	return 0;
}

// Introduction to the game.
void PrintIntro()
{
	using namespace std;
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
}

std::string GetGuessAndPrintBack()
{
	using namespace std;
	// Get a guess from the player.
	cout << "Enter Your Guess: \n";
	string Guess;
	getline(std::cin, Guess);

	// Print the guess out.
	cout << "Your guess was: " << Guess << "\n\n";
	return Guess;
}