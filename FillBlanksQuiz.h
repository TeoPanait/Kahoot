#ifndef FILLBLANKSQUIZ_H
#define FILLBLANKSQUIZ_H
#include "Quiz.h"


class FillBlanksQuiz : public Quiz {
    std::string correct;
public:
    FillBlanksQuiz(const std::string& text, const std::string&  correct);
    ~FillBlanksQuiz() override= default;
    [[nodiscard]] int askQuestions() const override;
    void display()const override;
    [[nodiscard]] int getDetails()const override;
    friend class Game;
};



#endif //FILLBLANKSQUIZ_H
