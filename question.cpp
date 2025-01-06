#include "question.h"

#include <ostream>

question::question(std::string text): QuestionText(std::move(text)) {
}



std::ostream& operator<<(std::ostream& os, const question& q) {
    os << q.QuestionText<< std::endl;
    return os;
}




