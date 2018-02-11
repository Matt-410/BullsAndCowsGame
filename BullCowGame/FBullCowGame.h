#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const; 
	int GetCurrentTry() const;
	bool IsGameWon() const;
	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(std::string); // TODO make a more rich return value.

	// Provide a function for counting bulls and cows and incrementing try number.

private:
	// See constructor for initialization.
	int MyCurrentTry;
	int MyMaxTries;
};