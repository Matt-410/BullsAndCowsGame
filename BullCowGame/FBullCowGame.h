// This is the game's logic and processing center.
// No output code, no user interaction.
// Checking of guess validity and processing the guess
// to obtain the number of Bulls and Cows occurs here.
// This is a guess the word game based on the board game Mastermind.

#pragma once
#include <string>

// To make syntax Unreal friendly.
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EGuessStatus CheckGuessValidity(FString) const;
	void Reset();

	// Count bulls and cows and incrementing try number, assuming valid guess.
	FBullCowCount SubmitValidGuess(FString);

private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};