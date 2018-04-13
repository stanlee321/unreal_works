#include <string>
using FString = std::string;
using int32 = int;


struct FBullCowCount{
    int32 Bulls = 0;
    int32 Cows = 0;

};


enum class EGuessStatus
{
    OK,
    No_Isogram,
    Wrong_Length,
    Not_Lowercase,
    Invalid
};

class FBullCowGame
{
public:

    FBullCowGame();         // Constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLenght() const;

    void Reset();
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    // Provide a method to count bulls and cows and increase
    FBullCowCount SubmitGuess(FString);

private:

    // see constructor for init 
    int32 MyCurrentTry ;
    int32 MyMaxTrie ;
    FString MyHiddenWord;
};