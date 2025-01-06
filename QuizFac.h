#ifndef QUIZFAC_H
#define QUIZFAC_H
#include <memory>

#include "Quiz.h"

class QuizFac {
    public:
    virtual ~QuizFac() = default;


    static std::shared_ptr<Quiz> createSingleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>&  RightAnswer);
    static std::shared_ptr<Quiz> createMultipleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>&  RightAnswer);
    static std::shared_ptr<Quiz> createFillBlanksQuiz(const std::string &text, const std::string &correct);

    friend class Game;
};

#endif //QUIZFAC_H
