#ifndef SINGLECHOICEQUIZ_H
#define SINGLECHOICEQUIZ_H

#include "Quiz.h"
#include "Answer.h"

// Class for single-choice quiz (simple choice)
class SingleChoiceQuiz : public Quiz {
public:
    // Constructor to initialize the questions and answers
    SingleChoiceQuiz(const std::string &text, const std::string &a1,
                     const std::string &a2, const std::string &a3,
                     const std::vector<int>& RightAnswer);

    // Method to ask the question and receive the user's answer
    [[nodiscard]] int askQuestions() const override;

    // Method to display the content of the quiz
    void display() const override;

    // Method to return details about the quiz
    [[nodiscard]] int getDetails() const override;

    ~SingleChoiceQuiz() override = default;  // Virtual destructor for the derived class

    friend class Game;  // Friend class for accessing private/protected members
};

#endif //SINGLECHOICEQUIZ_H
