/*
	This is the console executable, thats makes use of the BullCow class
	This act as the view in a MVC pattern, and is responsible for all user
	interaction. For game logic see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//using namespace std;

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValildGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new game

//the entry point for our application
int32 main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	


	system("pause");
	return 0; // exit the application
}

void PrintIntro() {
	//introduce the game
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValildGuess();

		//submit a valid guess to the game, and receive counts
		FBulllCowCount BulllCowCountBCGame = BCGame.SubmitValidGuess(Guess);

		// print the number of bulls and cows
		std::cout << "Bulls: " << BulllCowCountBCGame.Bulls;
		std::cout << ". Cows: " << BulllCowCountBCGame.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// loop continually until the user give a valid guess
FText GetValildGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Status; FText Guess = "";
	do {
		//get a guess from the player	
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep loopping until we get no error

	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again with the same hidden word? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() {

	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!";
	}
	else {
		std::cout << "Better luck next time!";
	}

	std::cout << std::endl;
}