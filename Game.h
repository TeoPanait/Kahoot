#ifndef GAME_H
#define GAME_H

#include <vector>
#include "User.h"
#include "Quiz.h"

class Game {
    question Q;
    std::vector<Quiz> quizes;
   // int gameId{};
    User &user;
    int total{};

public:
    explicit Game(User &user);
    Game(const Game& other);
    ~Game();

    void playGame1();
    void playGame2();

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};



#endif //GAME_H
