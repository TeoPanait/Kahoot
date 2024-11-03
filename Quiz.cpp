#include "Quiz.h"
#include <iostream>

Quiz::Quiz(const std::string &q, const std::string &a1, const std::string &a2, const std::string &a3, int RightAnswer)
    : Qa(q), Aa(a1, a2, a3, RightAnswer) {
}


int Quiz::askQuestions() const {
    std::cout << std::endl;

    std::cout << Qa.QuestionText << std::endl;
    std::cout << "1. " << Aa.Answer1 << std::endl;
    std::cout << "2. " << Aa.Answer2 << std::endl;
    std::cout << "3. " << Aa.Answer3 << std::endl;
    std::cout << std::endl;


    std::cout << "Care este raspunsul tau?" << std::endl;
    int guess=-1;
    std::cin >> guess;


    if (guess == Aa.RightAnswer) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;
    }
    std::cout << std::endl << "Gresit!" << std::endl;
    std::cout << "Raspuns corect = " << Aa.RightAnswer << "." << std::endl;
    return 0;
}
