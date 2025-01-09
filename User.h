#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

#include "ScoreHistory.h"
#include "Strategy.h"


class User {
    std::string username;
    int score;
    ScoreHistory<int> MHistory;
    ScoreHistory<int> CHistory;
    QuizStrategy* CurrentStrategy;

public:

    User() : score(0), MHistory("Mate"), CHistory("Capitale"), CurrentStrategy(nullptr) {
        std::cout<< "Saluatari\n";
    }
    ~User();

    void setName();
    void printName() const;
    void addScore(int points, bool isMGame);
    void setStrategy(bool isMGame);
    void GameHistory(bool isMGame);
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};



#endif //USER_H
