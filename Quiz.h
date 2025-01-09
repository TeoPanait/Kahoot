#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include "question.h"
#include "Answer.h"

// Base class for a quiz
class Quiz {
protected:
    question Qa;              // Object of type question
    Answer Aa;                // Object of type answer
    static int idgame;        // Unique identifier for each quiz

public:
    // Returns the game identifier
    static int getIdGame();

    // Constructor that initializes questions and answers
    Quiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer);

    virtual ~Quiz() = default;  // Virtual destructor for polymorphism

    // Pure virtual method for quiz details
    [[nodiscard]] virtual int getDetails() const = 0;

    // Pure virtual method for displaying the quiz
    virtual void display() const = 0;

    // Pure virtual method for asking questions to the user
    [[nodiscard]] virtual int askQuestions() const = 0;

    // Friend declaration for derived classes and quiz factories
    friend class SingleChoiceQuiz;
    friend class MultipleChoiceQuiz;
    friend class FillBlanksQuiz;
    friend class QuizFac;
};

#endif //QUIZ_H
