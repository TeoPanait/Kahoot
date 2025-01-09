
#ifndef SCOREHISTORY_H
#define SCOREHISTORY_H


#include <utility>
#include <vector>
#include <iostream>

template<typename T>
class ScoreHistory {
private:
    std::vector<T> scores;
    std::string gameType;

public:
    explicit ScoreHistory(std::string  type) : gameType(std::move(type)) {}

    void addScore(T score) {
        scores.push_back(score);
    }

    T getBestScore() const {
        if(scores.empty()) return T();
        T best = scores[0];
        for(const auto& score : scores) {
            if(score > best) best = score;
        }
        return best;
    }

    void displayHistory() const {
        std::cout << "\nIstoric scoruri pentru " << gameType << ":\n";
        for(size_t i = 0; i < scores.size(); ++i) {
            std::cout << "Jocul " << i + 1 << ": " << scores[i] << std::endl;
        }
        std::cout << "Cel mai bun scor: " << getBestScore() << std::endl;
    }


};



#endif //SCOREHISTORY_H
