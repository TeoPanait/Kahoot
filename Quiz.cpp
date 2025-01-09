#include "Quiz.h"

// Returns the unique identifier of the quiz
int Quiz::getIdGame() {
    return idgame;
}

// Constructor for initializing questions and answers
Quiz::Quiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer)
    : Qa(text), Aa(a1, a2, a3, RightAnswer) {
    idgame++;  // Increment the unique identifier
}

// Static variable initialization for the game ID
int Quiz::idgame = 0;
