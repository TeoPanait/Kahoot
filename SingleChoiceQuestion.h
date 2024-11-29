

#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H
#include "question.h"
#include "Answer.h"

class SingleChoiceQuestion final : public question{
    std::string sq;
public:
    explicit SingleChoiceQuestion(const std::string& text);
    void setQuestion( std::string& text);
    friend class Quiz;

    friend std::ostream& operator<<(std::ostream& os, const SingleChoiceQuestion& scq);
};



#endif //SINGLECHOICEQUESTION_H
