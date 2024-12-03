#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include "question.h"
#include "Answer.h"

class Quiz {
protected:
    question Qa;
    Answer Aa;
    static int idgame;
public:
    static int getIdGame();
    Quiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>&  RightAnswer);
    virtual ~Quiz() = default;
    virtual int getDetails() const = 0;
    virtual void display() const =0 ;
    [[nodiscard]] virtual int askQuestions() const=0;

    friend class SingleChoiceQuiz;
    friend class MultipleChoiceQuiz;
    friend class FillBlanksQuiz;
};





#endif //QUIZ_H
