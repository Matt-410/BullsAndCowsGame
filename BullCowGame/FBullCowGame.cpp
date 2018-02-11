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
	const FString HIDDEN_WORD = "planet";
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
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// Increment the try number.
	MyCurrentTry++;
	// Setup a return variable.
	FBullCowCount BullCowCount;
	// Loop through all letters in the guess.
		// Compare letters against the hidden word.

	return BullCowCount;
}
