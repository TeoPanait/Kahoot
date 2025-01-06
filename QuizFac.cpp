#include "QuizFac.h"

#include "FillBlanksQuiz.h"
#include "MultipleChoiceQuiz.h"
#include "SingleChoiceQuiz.h"

std::shared_ptr<Quiz> QuizFac::createSingleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>&  RightAnswer) {
    return std::make_shared<SingleChoiceQuiz>(text, a1, a2, a3, RightAnswer);
}
std::shared_ptr<Quiz> QuizFac::createMultipleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>&  RightAnswer) {
    return std::make_shared<MultipleChoiceQuiz>(text, a1, a2, a3, RightAnswer);
}
std::shared_ptr<Quiz> QuizFac::createFillBlanksQuiz(const std::string &text,const std::string &correct) {
    return std::make_shared<FillBlanksQuiz>(text,std::move(correct));
}