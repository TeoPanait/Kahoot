//
// Created by LauraP on 10/29/2024.
//

#ifndef ANSWER_H
#define ANSWER_H
#include <string>

class Answer {
    std::string Answer1;
    std::string Answer2;
    std::string Answer3;
    int Guess{};
    int RightAnswer;

public:
    Answer(std::string a1, std::string a2, std::string a3, int rightAnswer);

    friend class Quiz;

    friend std::ostream& operator<<(std::ostream& os, const Answer& answer);
};



#endif //ANSWER_H
