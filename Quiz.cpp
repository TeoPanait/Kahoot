#include "Quiz.h"


Quiz::Quiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>& RightAnswer) :
    Qa(text), Aa(a1, a2, a3, RightAnswer){}


