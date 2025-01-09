
#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

class QuizStrategy {
    public:
    virtual ~QuizStrategy() = default;
    virtual void displayInstructions() const =0;
    [[nodiscard]] virtual int calculateBonus(int baseScore) const=0;
};

class MathQuizStrategy : public QuizStrategy {
public:
    void displayInstructions() const override {
        std::cout<< "\n Instructiuni pentru testul de matematica: \n";
        std::cout<< "\n 1. Vei primi intrebari din geometrie si calcule simple \n";
        std::cout <<"\n 2. Pentru fiecare raspuns corect primesti 10 pct\n";
        std::cout <<"\n 3. La a doua incercare primesti jumatate din punctaj\n";
    }
    [[nodiscard]] int calculateBonus(int baseScore) const override {
        if (baseScore >= 9) {
            return baseScore +2;
        } else return 0;
    }
};

class CapitalsQuizStrategy : public QuizStrategy {
public:
    void displayInstructions() const override {
        std::cout<< "\n Instructiuni pentru testul de capitale: \n";
        std::cout<< "\n 1. Vei primi intrebari despre capitalele Europei \n";
        std::cout <<"\n 2. Pentru fiecare raspuns corect primesti 10 pct\n";
        std::cout <<"\n 3. La a doua incercare primesti jumatate din punctaj\n";
    }
    [[nodiscard]] int calculateBonus(int baseScore) const override {
        if (baseScore >=10) {
            return baseScore + 4;
        }else return 0;
    }
};

#endif //STRATEGY_H
