#ifndef SINGLECHOICEQUIZ_H
#define SINGLECHOICEQUIZ_H
#include <memory>

#include "Quiz.h"
#include "Answer.h"
#include "question.h"


class SingleChoiceQuiz: public Quiz{
    question Sq;
    Answer Aa;
public:
    SingleChoiceQuiz(const std::string &text, const std::string &a1,
    const std::string &a2, const std::string &a3, int RightAnswer);
    int askQuestions() const override;
    friend class Game;

};



#endif //SINGLECHOICEQUIZ_H
