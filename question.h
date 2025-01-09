#ifndef QUESTION_H
#define QUESTION_H

#include <string>

// Base class for a question
class question {
    std::string QuestionText;         // The text of the question
    const int QuestionScore = 10;     // Default score for the question

public:
    explicit question(std::string text); // Constructor
    virtual ~question() = default;       // Virtual destructor for polymorphism

    // Friend class declarations for other classes
    friend class Quiz;
    friend class SingleChoiceQuiz;
    friend class MultipleChoiceQuiz;
    friend class FillBlanksQuiz;

    // Overload the << operator for displaying the question
    friend std::ostream& operator<<(std::ostream& os, const question& q);
};

#endif //QUESTION_H
