#include "User.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

#include "Execption.h"


void User::setName() {
    while(true) {
        try {
            std::cout << "Care este numele tau? ";
            std::cout<< std::endl;
            std::getline(std::cin, username);
            std::istringstream iss(username);
            int temp;
            if (iss >> temp) {
                throw NameException("Numele nu poate fi un numar. Te rog sa introduci un nume valid.");
            }
            break;
        }catch (NameException& e){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }
}

void User::printName() const {
    std::cout << "Buna " << username << '\n'<<"Ce test ai vrea sa dai?"<< std::endl;

}

void User::addScore(int points, bool isMGame) {
    score += points;

    if(CurrentStrategy) {
        int bonus= CurrentStrategy->calculateBonus(points);
        score += bonus;
        points += bonus;
        if(bonus >0 ) {
            std:: cout <<"bonus:"<< bonus << std::endl;
        }
    }
    if(isMGame) {
        MHistory.addScore(points);
    }else {
        CHistory.addScore(points);
    }
    std::cout << "Scorul tau total: " << score << std::endl;  // Optional printout
}

User::~User() {
    delete CurrentStrategy;
    std::cout << "Pa!" << std::endl;
}

void User::setStrategy(bool isMGame) {
    delete CurrentStrategy;
    if(isMGame) {
        CurrentStrategy= new MathQuizStrategy;
    }else {
        CurrentStrategy= new CapitalsQuizStrategy;
    }
    CurrentStrategy-> displayInstructions();
}

void User::GameHistory(bool isMGame) {
    if(isMGame) {
        MHistory.displayHistory();

    }else { CHistory.displayHistory(); }
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.username << " " << user.score << std::endl;
    return os;
}