#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include "Answer.h"
#include "question.h"

class Quiz {
    question Qa;
    Answer Aa;

public:

    Quiz(const std::string &q, const std::string &a1,
         const std::string &a2, const std::string &a3, int RightAnswer);

    [[nodiscard]] int askQuestions() const;

    friend class Game;
    friend class Answer;
    friend class question;
};



#endif //QUIZ_H
