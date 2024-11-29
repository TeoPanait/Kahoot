#include "Quiz.h"
#include <iostream>

Quiz::Quiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, int RightAnswer)
    : Sq(text), Aa(a1, a2, a3, RightAnswer) {
}


int Quiz::askQuestions() const {
    std::cout << std::endl;

    std::cout << Sq << std::endl;
    std::cout<< Aa<< std::endl;


    std::cout << "Care este raspunsul tau?" << std::endl;
    int guess=-1;
    std::cin >> guess;


    if (guess == Aa.RightAnswer) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Sq.QuestionScore;
    }
     if(guess != Aa.RightAnswer) {
        std::cout << "Mai incearca"<< std::endl;
        std::cin >> guess;
        if (guess == Aa.RightAnswer) {
            std::cout << std::endl << "Corect!" << std::endl;
            return Sq.QuestionScore-5;

        }

    } else {
        std::cout << std::endl << "Gresit!" << std::endl;
        std::cout << "Raspuns corect = " << Aa.RightAnswer << "." << std::endl;
    }
    return 0;
}

