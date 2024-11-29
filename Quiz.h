#ifndef QUIZ_H
#define QUIZ_H

#include <memory>
#include <string>

#include "Answer.h"
#include "SingleChoiceQuestion.h"

class Quiz {
    SingleChoiceQuestion Sq;
    Answer Aa;

public:

    Quiz(const std::string &text, const std::string &a1,
         const std::string &a2, const std::string &a3, int RightAnswer);

     [[nodiscard]] int askQuestions() const;
    friend class Game;


    friend std::ostream &operator<<(std::ostream &os, const Quiz &q);
};





#endif //QUIZ_H
