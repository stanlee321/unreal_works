#include "FBullCowGame.h"
#include <string>

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTrie;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    MyMaxTrie   = MAX_TRIES;
    MyCurrentTry = 1;
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    return;
}
bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false)// if the guess isn't an isogram
    {
        return EGuessStatus::No_Isogram; // return not isogram error
    }
    else if(false) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if(Guess.length() != GetHiddenWordLenght())     // if the guess length is worng
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}

int32 FBullCowGame::GetHiddenWordLenght() const
{

    return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increase the turn number
    MyCurrentTry++;
    // Setup a return variable
    FBullCowCount BullCowCount;

    // loop through all the letters in the guess
    int32 HiddenWordLenght = MyHiddenWord.length();
    for (int32 i=0; i < HiddenWordLenght; i++){
        // comparte letters against the hidden word
        for (int32 j = 0; j < HiddenWordLenght; j++){
            // if they match then
            if (Guess[i] == MyHiddenWord[i]){
                //if they are in the same place
                if (i==j){
                    BullCowCount.Bulls++;   // incremetn bulls
                }
                    // else
                else {
                    BullCowCount.Cows++;// incremente cows
                }
            }
        }
    }
    return BullCowCount;
}