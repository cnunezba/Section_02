#pragma once
#include <string>;

using FString = std::string;
using int32 = int;

// all values initialize to 0
struct FBulllCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: make a more rich return value.
	bool CheckGuessValidity(FString);
	// counts bulls and cows, and increasing try # assuming valid guess
	FBulllCowCount SubmitGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
