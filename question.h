#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <utility>

class question {
protected:
    std::string QuestionText;
    int QuestionScore;


public:
    explicit question(std::string question): QuestionText(std::move(question)), QuestionScore(10) {}
    virtual ~question()=default;
    friend class Quiz;

   // friend std::ostream& operator<<(std::ostream& os, const question& q);
};



#endif //QUESTION_H
