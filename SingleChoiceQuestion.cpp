
#include "SingleChoiceQuestion.h"
#include <iostream>

SingleChoiceQuestion::SingleChoiceQuestion(const std::string &text) : question(text), sq(text){}

void SingleChoiceQuestion::setQuestion( std::string &text) {
    sq=std::move(text);
}


std::ostream& operator<<(std::ostream& os, const SingleChoiceQuestion& scq) {
    os << scq.sq << "\n";
    return os;
}



