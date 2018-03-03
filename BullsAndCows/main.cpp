/*
	This is the console executable, thats makes use of the BullCow class
	This act as the view in a MVC pattern, and is responsible for all user
	interaction. For game logic see the FBullCowGame class.
*/
#include <iostream>;
#include <string>;
#include "FBullCowGame.h";

//using namespace std;

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();
		//submit a valid guess to the game, and receive counts
		FBulllCowCount BulllCowCountBCGame = BCGame.SubmitGuess(Guess);
		// print the number of bulls and cows
		std::cout << "Bulls: " << BulllCowCountBCGame.Bulls;
		std::cout << ". Cows: " << BulllCowCountBCGame.Cows << std::endl;
		
		std::cout << std::endl;
	}

}

FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player	
	std::cout << "Try " << CurrentTry <<  ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
