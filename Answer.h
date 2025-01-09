#ifndef ANSWER_H
#define ANSWER_H

#include <string>
#include <vector>

// Class for answers
class Answer {
    std::string Answer1;           // Answer 1
    std::string Answer2;           // Answer 2
    std::string Answer3;           // Answer 3
    std::vector<int> RightAnswer;  // Indices of correct answers

public:
    Answer(std::string a1, std::string a2, std::string a3, std::vector<int> RightAnswer);

    friend class Quiz;
    friend class SingleChoiceQuiz;
    friend class MultipleChoiceQuiz;
    friend class FillBlanksQuiz;

    friend std::ostream& operator<<(std::ostream& os, const Answer& answer);
};

#endif // ANSWER_H
