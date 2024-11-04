#include "Game.h"

#include <iostream>
#include <string>

Game::Game(User &user) : user(user) {
}
Game::Game(const Game& other)
    : quizes(other.quizes),user(other.user), total(other.total) {
    std::cout << "Constructorul de copiere al lui Game.\n";
}

Game::~Game() {
    std::cout << "Destructorul Game apelat.\n";
}
void Game::playGame1() {
    Quiz quiz1("Care este capitala Frantei?", "Paris", "Berlin", "Roma", 1);
    quizes.push_back(quiz1);

    Quiz quiz2("Cat face 2 + 2?", "3", "4", "5", 2);
    quizes.push_back(quiz2);

    Quiz quiz3("Ce planeta este cunoscuta drept Planeta Rosie?", "Pamant", "Marte", "Jupiter", 2);
    quizes.push_back(quiz3);

    for (const Quiz& quiz : quizes) {
        int correct=quiz.askQuestions();
        user.addScore(correct);
    }
    quizes.pop_back();
    quizes.pop_back();
    quizes.pop_back();

}

void Game::playGame2() {
    Quiz quiz1("Care este capitala Germaniei?", "Paris", "Berlin", "Roma", 2);
    quizes.push_back(quiz1);

    Quiz quiz2("Cat face 2 + 3?", "3", "4", "5", 3);
    quizes.push_back(quiz2);

    Quiz quiz3("Pe ce planeta suntem?", "Pamant", "Marte", "Jupiter", 1);
    quizes.push_back(quiz3);

    for (const Quiz& quiz : quizes) {
        int correct=quiz.askQuestions();
        user.addScore(correct);
    }

}

std::ostream & operator<<(std::ostream &os, const Game &game) {
    os << game.user << "\n";
    return os;
}
