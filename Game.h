#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include "User.h"
#include "SingleChoiceQuiz.h"

class Game {
    std::vector<std::unique_ptr<SingleChoiceQuiz>> quizes;
    User &user;

public:
    explicit Game(User &user);
    ~Game();
    void addQuiz(std::unique_ptr<SingleChoiceQuiz>quiz);
    void playGame1();
    void playGame2();

};



#endif //GAME_H
