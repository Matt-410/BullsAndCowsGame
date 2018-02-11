#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.

	// Provide a function for counting bulls and cows and incrementing try number.

private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
};