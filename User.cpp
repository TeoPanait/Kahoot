#include "User.h"

#include <iostream>


void User::setName() {
    std::cout << "Care este numele tau? ";
    std::cout<< std::endl;
    std::getline(std::cin, username);
}

void User::printName() const {
    std::cout << "Buna " << username << '\n'<<"Ce test ai vrea sa dai?"<< std::endl;

}

void User::addScore(int points) {
    score += points;
    std::cout << "Scorul tau total: " << score << std::endl;  // Optional printout
}

User::~User() {
    std::cout << "Pa!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.username << " " << user.score << std::endl;
    return os;
}