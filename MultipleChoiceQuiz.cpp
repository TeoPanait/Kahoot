#include "MultipleChoiceQuiz.h"
#include <iostream>
#include <ostream>
#include <sstream>


MultipleChoiceQuiz::MultipleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>& RightAnswer)
    : Quiz(text, a1, a2, a3, RightAnswer) {}

int MultipleChoiceQuiz::askQuestions() const{
    std::cout << std::endl;
    std::cout << Qa << std::endl;
    std::cout<< Aa<< std::endl;
    int guess1=0;
    int guess2=0;
    std::cout << "Care este raspunsul tau?\n" ;
    std::cin>>guess1;
    std::cin>>guess2;

    if (guess1 == Aa.RightAnswer[0] && guess2 == Aa.RightAnswer[1]) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;
    }else{
        std::cout << "Mai incearca"<< std::endl;
        std::cin >> guess1;
        std::cin >> guess2;
        if (guess1 == Aa.RightAnswer[0] && guess2 == Aa.RightAnswer[1]) {

            std::cout << std::endl << "Corect!" << std::endl;
            return Qa.QuestionScore-5;
        }else {
            std::cout << std::endl << "Gresit!" << std::endl;
            std::cout << "Raspuns corect = " << Aa.RightAnswer[0] << "si" << Aa.RightAnswer[1]<< std::endl;
        }

    }


    return 0;
}

int MultipleChoiceQuiz::getDetails() const {
    return 2;
}

void MultipleChoiceQuiz::display() const {
    std:: cout << "Raspuns multiplu" << std::endl;
}
