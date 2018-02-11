#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// Receives a VALID guess, increments tries, and returns counts.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the try number.
	MyCurrentTry++;

	// Setup a return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// Compare each guess letter against all letters in the hidden word.
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[j]) // If the letters match.
			{
				if (i == j) // If they are in the same position.
				{
					BullCowCount.Bulls++; // Increment Bulls.
				}
				else
				{
					BullCowCount.Cows++; // Increment Cows.
				}
			}
		}
	}
	return BullCowCount;
}
