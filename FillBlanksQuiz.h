#ifndef FILLBLANKSQUIZ_H
#define FILLBLANKSQUIZ_H
#include "Quiz.h"

// Class representing a quiz with fill-in-the-blank questions
class FillBlanksQuiz : public Quiz {
    std::string correct;  // Correct answer to the question
public:
    // Constructor: initializes a quiz with the question text and the correct answer
    FillBlanksQuiz(const std::string& text, std::string correct);

    // Destructor
    ~FillBlanksQuiz() override= default;

    // Function that asks the question and checks the answer
    [[nodiscard]] int askQuestions() const override;

    // Function that displays the quiz
    void display() const override;

    // Function that returns details about the quiz
    [[nodiscard]] int getDetails() const override;

    // Friend declaration for the Game class
    friend class Game;
};

#endif //FILLBLANKSQUIZ_H
