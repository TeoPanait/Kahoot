#ifndef QUIZ_H
#define QUIZ_H

class Quiz {
public:

    Quiz()=default;
    virtual ~Quiz() = default;
    virtual int askQuestions() const=0;
};





#endif //QUIZ_H
