#include "Game.h"

#include <iostream>


Game::Game(User &user) : user(user) {
}


void Game::addQuiz(std::unique_ptr<Quiz> quiz) {
    quizes.push_back(std::move(quiz));
}

Game::~Game() {
    std::cout << "\n";
}
void Game::playGame1() {
    addQuiz(std::make_unique<Quiz>("Cat fac 3*5", "15", "3", "10", 1));
    addQuiz(std::make_unique<Quiz>("Cat fac 4*5", "15", "20", "10", 2));
    addQuiz(std::make_unique<Quiz>("Cat fac 6*8", "46", "42", "48", 3));
    for (const auto& quiz : quizes) {
        int correct= quiz->askQuestions();
        user.addScore(correct);
    }
    quizes.clear();

}

void Game::playGame2() {
    addQuiz(std::make_unique<Quiz>("Care este capitala Austriei?", "Viena", "Venetia", "Germania", 1));
    addQuiz(std::make_unique<Quiz>("Care este capitala Suediei?", "Copenhaga", "Stockholm", "Londra", 2));
    addQuiz(std::make_unique<Quiz>("Care este capitala Spaniei?", "Barcelona", "Valencia", "Madrid", 3));
    for (const auto& quiz : quizes) {
        int correct = quiz->askQuestions();
        user.addScore(correct);
    }
    quizes.clear();

}

