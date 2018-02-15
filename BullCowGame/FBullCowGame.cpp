#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // Check if guess is an isogram.
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) // Check if guess is in lowercase. TODO write function
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // Check if guess is the correct length.
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// Receives a VALID guess, increments tries, and returns counts.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // Assuming the same length as guess.
	bGameIsWon = false;

	// Loop through all letters in the guess.
	for (int32 i = 0; i < WordLength; i++)
	{
		// Compare each guess letter against all letters in the hidden word.
		for (int32 j = 0; j < WordLength; j++)
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
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Treat 0 and 1 letter words as isograms.
	if (Guess.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen;
	for (auto Letter : Guess) // For all letters in the guess.
	{
		Letter = tolower(Letter); // Handle mixed case.
		if (LetterSeen[Letter]) // If letter is in the map.
		{
			return false; // We do not have an isogram.
		}
		else
		{
			LetterSeen[Letter] = true; // Add the letter to the map.
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	for (auto Letter : Guess) // For all letters in the guess.
	{
		if (!islower(Letter)) { return false; } // If letter is not lower return false.
	}
	return true;
}
