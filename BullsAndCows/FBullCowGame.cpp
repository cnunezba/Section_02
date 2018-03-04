#include "FBullCowGame.h"
#include <map>
#define TMap std::map // it is a simple alternative to using

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset(){

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
	
	if (!isIsogram(Guess)) {
		// if the guess isn't an isogram
		return EGuessStatus::Not_Isogram;
	}else if (!isLowercase(Guess)) {
		// if the guess isn't all lowercase
		return EGuessStatus::Not_Lowercase;
	}else if (Guess.length() != GetHiddenWordLength()) {
		// if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}

	// otherwise
	return EGuessStatus::OK;
}

FBulllCowCount FBullCowGame::SubmitValidGuess(FString Guess){
	MyCurrentTry++;
	FBulllCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming samen length as guess

	// loop through all letters in the hidden word
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::isIsogram(FString Word) const{
	// treat 0 and 1 letter words as isogram
	if (Word.length() <= 1) { return true; }

	// setup our map
	TMap<char, bool> LetterSeen;

	// loop throught all the letters of the word
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::isLowercase(FString Word) const{

	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
