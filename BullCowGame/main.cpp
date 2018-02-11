#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuessAndPrintBack();

// Main driver for the program.
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();

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

// Get a guess from the player.
std::string GetGuessAndPrintBack()
{
	using namespace std;
	cout << "Enter Your Guess: \n";
	string Guess;
	getline(std::cin, Guess);
	cout << "Your guess was: " << Guess << "\n\n";
	return Guess;
}