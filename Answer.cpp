#include "Answer.h"

#include <iostream>
#include <utility>

Answer::Answer(std::string a1, std::string a2, std::string a3,  std::vector<int> RightAnswer) :
Answer1(std::move(a1)), Answer2(std::move(a2)), Answer3(std::move(a3)), RightAnswer(std::move(RightAnswer)) {}

std::ostream& operator<<(std::ostream& os, const Answer& answer) {
    os << "1. " << answer.Answer1 << "\n";
    os << "2. " << answer.Answer2 << "\n";
    os << "3. " << answer.Answer3 << "\n";
    return os;
}



