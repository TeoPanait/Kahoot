#ifndef MULTIPLECHOICEQUIZ_H
#define MULTIPLECHOICEQUIZ_H
#include "Quiz.h"
#include "Answer.h"
#include "question.h"

// Class representing a quiz with multiple-choice questions
class MultipleChoiceQuiz: public Quiz {
public:
    // Constructor: initializes a quiz with the question text and possible answers
    MultipleChoiceQuiz(const std::string &text, const std::string &a1,
    const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer);

    // Function that asks the questions and returns the score
    [[nodiscard]] int askQuestions() const override;

    // Function that returns the quiz details
    [[nodiscard]] int getDetails() const override;

    // Function that displays the quiz
    void display() const override;

    // Destructor
    ~MultipleChoiceQuiz() override = default;

    // Friend class declaration for the Game class
    friend class Game;
};

#endif //MULTIPLECHOICEQUIZ_H
