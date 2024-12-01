#include "SingleChoiceQuiz.h"
#include <iostream>

SingleChoiceQuiz::SingleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const std::vector<int>& RightAnswer)
    : Quiz(text,a1, a2, a3, RightAnswer)  {}

int SingleChoiceQuiz::askQuestions() const {
    std::cout << std::endl;
    std::cout << Qa << std::endl;
    std::cout<< Aa<< std::endl;

    std::cout << "Care este raspunsul tau?" << std::endl;
    int guess=-1;
    std::cin >> guess;


    if (guess == Aa.RightAnswer[0]) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;
    }else{
        std::cout << "Mai incearca"<< std::endl;
        std::cin >> guess;
        if (guess == Aa.RightAnswer[0]) {

                std::cout << std::endl << "Corect!" << std::endl;
                return Qa.QuestionScore-5;
            }else {
                std::cout << std::endl << "Gresit!" << std::endl;
                std::cout << "Raspuns corect = " << Aa.RightAnswer[0] << "." << std::endl;
            }

        }


    return 0;
}

void SingleChoiceQuiz::display() const {
    std::cout<< "Raspuns simplu" << std::endl;
}

int SingleChoiceQuiz::getDetails() const {
    return 1;
}