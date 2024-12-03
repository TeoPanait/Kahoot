#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>

#include "Quiz.h"
#include "User.h"

class Game {
    std::vector<std::shared_ptr<Quiz>> quizes;
    User &user;

public:
    explicit Game(User &user);
    ~Game();
    void addQuiz(const std::shared_ptr<Quiz> &quiz);
    void playGame1();
    void playGame2();
    void details() const;

};



#endif //GAME_H
