#ifndef GAME_H
#define GAME_H
#include<iostream>
#include <vector>
#include "User.h"
#include "Quiz.h"

class Game {
    //SingleChoiceQuestion Sq;
    std::vector<std::unique_ptr<Quiz>> quizes;
    User &user;

public:
    explicit Game(User &user);
    ~Game();
    void addQuiz(std::unique_ptr<Quiz>quiz);
    void playGame1();
    void playGame2();

};



#endif //GAME_H
