/*
    This is the console executable
*/

// Tthis is my first project

#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText  = std::string;
using int32  = int;
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; // Instantiate a new Game

// Intro point for the app
int main(){

    std::cout << BCGame.GetCurrentTry();

    bool bPlayAgain = false;

    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();

    }
    while(bPlayAgain == true);
    return 0;
}




// Print intro for the game
void PrintIntro()
{
    constexpr int32 WORD_LENGHT = 9;
    std::cout << "Wellcome to Bulls and COws\n";
    std::cout << "Can you guess the " << WORD_LENGHT;
    std::cout << " letter isogram I'm thinking of \n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    for (int32 count=1; count <= MaxTries; count++){

        FText Guess = GetValidGuess();

        // Submit a valid guess to the game, and resive counts
        FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);

        // print number of bulls and cows
        std::cout << "BUlls =  " << BullCowCount.Bulls;
        std::cout << ". Cows  =  " << BullCowCount.Cows;
        //std::cout << "Your guess was " << Guess;
        std::cout << std::endl;

    }
    return ;
}

std::string GetValidGuess() // TODO  change to get valid guess
{
    EGuessStatus Status = EGuessStatus::Invalid;
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter Your Guess:";
        FString Guess = "";
        getline(std::cin, Guess);
          
        // Check guess validity
        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
        switch (Status){
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word. \n";
            break;
        case EGuessStatus::No_Isogram:
            std::cout << "Please enter a word without repeating letters. \n";
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter all lowercase letters. \n";
        default:
            return Guess;
        }
        std::cout << std::endl;

    } while(Status != EGuessStatus::OK); // Keep looping until no erros

}

bool AskToPlayAgain()
{
    std::cout << "Do your want to play again (y/m) ? ";
    FString Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0]=='Y');
}