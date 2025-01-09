#ifndef SINGLECHOICEQUIZ_H
#define SINGLECHOICEQUIZ_H

#include "Quiz.h"
#include "Answer.h"

class SingleChoiceQuiz: public Quiz{

public:

    SingleChoiceQuiz(const std::string &text, const std::string &a1,
    const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer);
    [[nodiscard]] int askQuestions() const override;
    void display()const override;
    [[nodiscard]] int getDetails()const override;
    ~SingleChoiceQuiz() override=default;
    friend class Game;


};



#endif //SINGLECHOICEQUIZ_H
