#ifndef QUIZFAC_H
#define QUIZFAC_H
#include <memory>
#include "Quiz.h"

// Factory class for creating Quiz objects
class QuizFac {
public:
    // Virtual destructor
    virtual ~QuizFac() = default;

    // Static function to create a Single Choice Quiz
    static std::shared_ptr<Quiz> createSingleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>& RightAnswer);

    // Static function to create a Multiple Choice Quiz
    static std::shared_ptr<Quiz> createMultipleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>& RightAnswer);

    // Static function to create a Fill in the Blanks Quiz
    static std::shared_ptr<Quiz> createFillBlanksQuiz(const std::string &text, const std::string &correct);

    // Friend declaration for the Game class
    friend class Game;
};

#endif //QUIZFAC_H
