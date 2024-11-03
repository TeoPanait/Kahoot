//
// Created by LauraP on 10/29/2024.
//

#include "Answer.h"

Answer::Answer(std::string a1, std::string a2, std::string a3, const int rightAnswer)
    : Answer1(std::move(a1)), Answer2(std::move(a2)), Answer3(std::move(a3)), RightAnswer(rightAnswer) {
}