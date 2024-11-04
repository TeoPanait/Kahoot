//
// Created by LauraP on 10/29/2024.
//

#include "Answer.h"

#include <iostream>

Answer::Answer(std::string a1, std::string a2, std::string a3, const int rightAnswer)
    : Answer1(std::move(a1)), Answer2(std::move(a2)), Answer3(std::move(a3)), RightAnswer(rightAnswer) {
}

std::ostream &operator<<(std::ostream &os, const Answer &a) {
    os<< "Answer1: " << a.Answer1 << std::endl << "Answer2: " << a.Answer2 << std::endl << "Answer3: " << a.Answer3 << std::endl;
    return os;
}


