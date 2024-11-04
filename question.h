#ifndef QUESTION_H
#define QUESTION_H



#include <string>

class question {
    std::string QuestionText;
    const int QuestionScore = 10;

public:
    question()=default;
    explicit question(std::string question);
    friend class Quiz;
};


#endif //QUESTION_H