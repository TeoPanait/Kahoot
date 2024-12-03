#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>


class User {
    std::string username;
    int score;

public:

    User() : score(0) {
        std::cout<< "Saluatari\n";
    }
    ~User();

    void setName();
    void printName() const;
    void addScore(int points);

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};



#endif //USER_H
