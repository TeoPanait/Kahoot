#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include "User.h"
#include "SingleChoiceQuiz.h"
#include "MultipleChoiceQuiz.h"
#include "FillBlanksQuiz.h"

class Game {
    std::vector<std::unique_ptr<Quiz>> quizes;
    User &user;
    // MultipleChoiceQuiz MCQ;
    // Quiz* q=dynamic_cast<Quiz*>(&MCQ);

public:
    explicit Game(User &user);
    ~Game();
    void addQuiz(std::unique_ptr<Quiz>quiz);
    void playGame1();
    void playGame2();
    void details() const;

};



#endif //GAME_H
