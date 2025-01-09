#include "question.h"
#include <ostream>

// Constructor of the question class
question::question(std::string text) : QuestionText(std::move(text)) {}

// Overload the << operator for displaying the question text
std::ostream& operator<<(std::ostream& os, const question& q) {
    os << q.QuestionText << std::endl;
    return os;
}
