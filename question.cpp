#include "question.h"

question::question(std::string question): QuestionText(std::move(question)) {
};


std::ostream& operator<<(std::ostream& os, const question& q) {
    os << q.QuestionText;
    return os;
}