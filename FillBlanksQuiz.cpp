#include "FillBlanksQuiz.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

FillBlanksQuiz::FillBlanksQuiz(const std::string& text, const std::string&  correct) :
    Quiz( text,"", "","", {}), correct(correct) {}

int FillBlanksQuiz::askQuestions() const {
    std::cout << std::endl;
    std::cout << Qa << std::endl;

    std::cout << "Care este raspunsul tau?" << std::endl;
    std::string guess;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//pt a scapa de un endline ramas
    getline(std::cin, guess);
    std::ranges::transform(guess, guess.begin(),
                           [](unsigned char c){ return std::tolower(c); });//transforma string ul citit in lower pt a nu fi key-sensitive

    if (guess == correct ) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;
    }else{
        std::cout << "Mai incearca"<< std::endl;
        getline(std::cin, guess);
        std::ranges::transform(guess, guess.begin(),
                               [](unsigned char c){ return std::tolower(c); });
        if (guess == correct) {

            std::cout << std::endl << "Corect!" << std::endl;
            return Qa.QuestionScore-5;
        }else {
            std::cout << std::endl << "Gresit!" << std::endl;
            std::cout << "Raspuns corect = " << correct << "." << std::endl;
        }

    }


    return 0;
}

void FillBlanksQuiz::display() const {
    std::cout<< "Completare" << std::endl;
}

int FillBlanksQuiz::getDetails() const {
    return 3;
}
