#include "User.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>

#include "Execption.h"

// Function that sets the user's name, validating if it is a valid name
void User::setName() {
    while(true) {
        try {
            std::cout << "Care este numele tau? ";
            std::cout << std::endl;
            std::getline(std::cin, username);  // Reads the name
            std::istringstream iss(username);
            int temp;
            if (iss >> temp) {  // Checks if the name contains only letters
                throw NameException("Numele nu poate fi un numar. Te rog sa introduci un nume valid.");
            }
            break;  // Exits the loop if the name is valid
        } catch (NameException& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears the input buffer
            std::cout << e.what() << std::endl;  // Displays the error message
        }
    }
}

// Function that displays the user's name and asks them to choose a test
void User::printName() const {
    std::cout << "Buna " << username << '\n' << "Ce test ai vrea sa dai?" << std::endl;
}

// Function that adds points to the user's score, calculating a bonus if applicable
void User::addScore(int points, bool isMGame) {
    score += points;  // Adds points to the score

    // If a strategy exists, the bonus is calculated and added to the score
    if (CurrentStrategy) {
        int bonus = CurrentStrategy->calculateBonus(points);
        score += bonus;
        points += bonus;
        if (bonus > 0) {
            std::cout << "bonus:" << bonus << std::endl;  // Displays the bonus
        }
    }

    // Adds the points to the respective history (math or capitals)
    if (isMGame) {
        MHistory.addScore(points);
    } else {
        CHistory.addScore(points);
    }

    std::cout << "Scorul tau total: " << score << std::endl;  // Optional printout
}

// Destructor that frees the memory allocated for the strategy and displays a farewell message
User::~User() {
    delete CurrentStrategy;
    std::cout << "Pa!" << std::endl;
}

// Function that sets the strategy based on the type of game (math or capitals)
void User::setStrategy(bool isMGame) {
    delete CurrentStrategy;  // Frees memory for the previous strategy
    if (isMGame) {
        CurrentStrategy = new MathQuizStrategy;  // Sets the strategy for math
    } else {
        CurrentStrategy = new CapitalsQuizStrategy;  // Sets the strategy for capitals
    }
    CurrentStrategy->displayInstructions();  // Displays the instructions for the selected strategy
}

// Function that displays the score history for the current game (math or capitals)
void User::GameHistory(bool isMGame) {
    if (isMGame) {
        MHistory.displayHistory();  // Displays history for math
    } else {
        CHistory.displayHistory();  // Displays history for capitals
    }
}

// Overloading the << operator to display the user's name and score
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.username << " " << user.score << std::endl;  // Displays the name and score
    return os;
}
