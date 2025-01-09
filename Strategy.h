#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

// Abstract class for the strategy of quizzes
class QuizStrategy {
public:
    virtual ~QuizStrategy() = default;  // Virtual destructor
    virtual void displayInstructions() const = 0;  // Pure virtual function for displaying instructions
    [[nodiscard]] virtual int calculateBonus(int baseScore) const = 0;  // Pure virtual function for calculating the bonus
};

// Strategy class for math quizzes
class MathQuizStrategy : public QuizStrategy {
public:
    // Displays the instructions for the math test
    void displayInstructions() const override {
        std::cout << "\n Instructiuni pentru testul de matematica: \n";
        std::cout << "\n 1. Vei primi intrebari din geometrie si calcule simple \n";
        std::cout << "\n 2. Pentru fiecare raspuns corect primesti 10 pct\n";
        std::cout << "\n 3. La a doua incercare primesti jumatate din punctaj\n";
    }

    // Calculates the bonus for the base score, depending on performance
    [[nodiscard]] int calculateBonus(int baseScore) const override {
        if (baseScore >= 9) {
            return baseScore + 2;  // Adds a bonus of 2 if the score is greater than or equal to 9
        } else return 0;  // No bonus is given if the score is less than 9
    }
};

// Strategy class for capitals quizzes
class CapitalsQuizStrategy : public QuizStrategy {
public:
    // Displays the instructions for the capitals test
    void displayInstructions() const override {
        std::cout << "\n Instructiuni pentru testul de capitale: \n";
        std::cout << "\n 1. Vei primi intrebari despre capitalele Europei \n";
        std::cout << "\n 2. Pentru fiecare raspuns corect primesti 10 pct\n";
        std::cout << "\n 3. La a doua incercare primesti jumatate din punctaj\n";
    }

    // Calculates the bonus for the base score, depending on performance
    [[nodiscard]] int calculateBonus(int baseScore) const override {
        if (baseScore >= 10) {
            return baseScore + 4;  // Adds a bonus of 4 if the score is greater than or equal to 10
        } else return 0;  // No bonus is given if the score is less than 10
    }
};

#endif //STRATEGY_H
