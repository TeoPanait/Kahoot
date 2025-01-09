#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>

#include "Quiz.h"
#include "User.h"

class Game {
    std::vector<std::shared_ptr<Quiz>> quizes;  // List of quizzes in the game
    User &user;  // Reference to the user playing the game

public:
    // Constructor that associates a user with the game
    explicit Game(User &user);

    // Destructor
    ~Game();

    // Function to add a quiz to the list of quizzes
    void addQuiz(const std::shared_ptr<Quiz> &quiz);

    // Function to start and play the first game (Math)
    void playGame1();

    // Function to start and play the second game (Capitals)
    void playGame2();

    // Function to display the details of the quiz
    void details() const;
};

#endif //GAME_H
