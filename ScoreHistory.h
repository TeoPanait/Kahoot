#ifndef SCOREHISTORY_H
#define SCOREHISTORY_H

#include <utility>
#include <vector>
#include <iostream>

// Template class for score history
template<typename T>
class ScoreHistory {
private:
    std::vector<T> scores;  // Vector that stores the scores
    std::string gameType;   // The type of game (e.g., "Math" or "Capitals")

public:
    // Constructor that initializes the game type
    explicit ScoreHistory(std::string type) : gameType(std::move(type)) {}

    // Adds a score to the history
    void addScore(T score) {
        scores.push_back(score);  // Adds the score to the vector
    }

    // Returns the best score from the history
    T getBestScore() const {
        if(scores.empty()) return T();  // If there are no scores, return the default value
        T best = scores[0];  // Start with the first score as the best
        for(const auto& score : scores) {  // Compare each score with the best
            if(score > best) best = score;  // Update the best score if a higher score is found
        }
        return best;  // Return the best score
    }

    // Displays the score history
    void displayHistory() const {
        std::cout << "\nIstoricul scorului pentru " << gameType << ":\n";  // Displays the game type
        for(size_t i = 0; i < scores.size(); ++i) {  // Iterates through the vector of scores
            std::cout << "Joc " << i + 1 << ": " << scores[i] << std::endl;  // Displays each game's score
        }
        std::cout << "Cel mai bun scor: " << getBestScore() << std::endl;  // Displays the best score
    }
};

#endif //SCOREHISTORY_H
