#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }

void FBullCowGame::Reset(){

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString){
	return false;
}

FBulllCowCount FBullCowGame::SubmitGuess(FString Guess){

	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBulllCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				// if they're in the same place
				if (HWChar == GChar) {
					// increments bulls
					BullCowCount.Bulls++;
				}
				else {
					// increments cows
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
