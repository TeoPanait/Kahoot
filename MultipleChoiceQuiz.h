#ifndef MULTIPLECHOICEQUIZ_H
#define MULTIPLECHOICEQUIZ_H
#include "Quiz.h"
#include "Answer.h"
#include "question.h"

class MultipleChoiceQuiz: public Quiz {
public:
    MultipleChoiceQuiz(const std::string &text, const std::string &a1,
    const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer);
    [[nodiscard]] int askQuestions() const override;
    [[nodiscard]] int getDetails() const override;
    void display()const override;
    ~MultipleChoiceQuiz() override=default;
    friend class Game;

};



#endif //MULTIPLECHOICEQUIZ_H
