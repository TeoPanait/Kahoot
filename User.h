#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

#include "ScoreHistory.h"
#include "Strategy.h"

// Class that represents a user of the game
class User {
    std::string username;  // The user's name
    int score;  // The user's score
    ScoreHistory<int> MHistory;  // History of scores for math games
    ScoreHistory<int> CHistory;  // History of scores for capitals games
    QuizStrategy* CurrentStrategy;  // The current game strategy

public:
    // Constructor that initializes variables and displays a greeting message
    User() : score(0), MHistory("Mate"), CHistory("Capitale"), CurrentStrategy(nullptr) {
        std::cout << "Saluatari\n";
    }

    // Destructor
    ~User();

    // Function to set the user's name
    void setName();

    // Function to display the user's name
    void printName() const;

    // Function to add points based on the game type
    void addScore(int points, bool isMGame);

    // Function to set the game strategy based on the game type
    void setStrategy(bool isMGame);

    // Function to display the score history based on the game type
    void GameHistory(bool isMGame);

    // Overloading the << operator to display information about the user
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif //USER_H
