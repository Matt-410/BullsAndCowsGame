#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; // TODO make actual error.
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
