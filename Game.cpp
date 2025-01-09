#include "Game.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include "SingleChoiceQuiz.h"
#include "MultipleChoiceQuiz.h"
#include "FillBlanksQuiz.h"
#include "Execption.h"
#include "QuizFac.h"

Game::Game(User &user) : user(user) {}  // Constructor that associates a user with the game

void Game::addQuiz(const std::shared_ptr<Quiz> &quiz) {  // Adds a quiz to the list of quizzes
    quizes.push_back(quiz);
}

Game::~Game() {  // Destructor
    std::cout << "\n";  // Termination message
}

void Game::playGame1() {  // Function for the math game
    user.setStrategy(true);  // Sets the strategy for the math game
    try {
        // Creates and adds SingleChoiceQuiz questions
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 3*5?", "15", "3", "10", std::vector<int>{1}));
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 4*5?", "15", "20", "10", std::vector<int>{2}));
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 6*8?", "46", "42", "48", std::vector<int>{3}));
    } catch (const AnswerException &e) {
        std::cout << e.what() << "\n";  // Displays the error if one occurs
    }

    // Creates and adds MultipleChoiceQuiz and FillBlanksQuiz questions
    addQuiz(QuizFac::createMultipleChoiceQuiz("Ce proprietati are un triunghi dreptunghic?",
        "are un unghi de 30 de grade",
        "are un unghi de 90 de grade",
        "ip^2=c1^2+c2^2",
        std::vector<int>{2, 3}));
    addQuiz(QuizFac::createFillBlanksQuiz("Un triunghi cu doua laturi egale se numeste .....", "isoscel"));
    addQuiz(QuizFac::createMultipleChoiceQuiz("Care sunt proprietatile unui patrat?",
        "Are 4 laturi egale",
        "Are diagonale congruente si perpendiculare",
        "Are un unghi de 120 de grade",
        std::vector<int>{1, 2}));
    addQuiz(QuizFac::createMultipleChoiceQuiz("Cum recunosti un trapez dreptunghic?",
        "Are o pereche de laturi paralele",
        "Are doua unghiuri drepte",
        "Are toate unghiurile egale",
        std::vector<int>{1, 2}));
    addQuiz(QuizFac::createFillBlanksQuiz("Suma unghiurilor intr-un triunghi este ..... grade.", "180"));
    addQuiz(QuizFac::createFillBlanksQuiz("O dreapta care imparte un cerc in doua parti egale se numeste .....", "diametru"));

    // Answer each question and add the score
    for (const auto& quiz : quizes) {
        int correct = quiz->askQuestions();  // Answer the question
        quiz->display();  // Display the type of quiz
        user.addScore(correct, false);  // Add the score to the user
    }

    std::cout << "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);  // Reads the user's answer
    std::ranges::transform(ans, ans.begin(),
                           [](unsigned char c) { return std::tolower(c); });  // Normalize the answer to lowercase

    if(ans == "da") {  // If the user wants to see the details
        try {
            details();  // Displays the details of the game
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;  // Displays the error if one occurs
        }
    }

    std::cout << Quiz::getIdGame() << std::endl;  // Displays the game ID
    user.GameHistory(false);  // Displays the game history
    quizes.clear();  // Clears the list of quizzes
}

void Game::playGame2() {  // Function for the capitals game
    user.setStrategy(false);  // Sets the strategy for the capitals game
    // Creates and adds capital quizzes
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Austriei?", "Viena", "Venetia", "Germania", std::vector<int>{1}));
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Suediei?", "Copenhaga", "Stockholm", "Londra", std::vector<int>{2}));
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Spaniei?", "Barcelona","Valencia","Madrid",std::vector<int>{3}));
    addQuiz(QuizFac::createMultipleChoiceQuiz("Care dintre urmatoarele orase sunt capitale europene?", "Roma", "Berlin", "Lyon", std::vector<int>{1, 2}));
    addQuiz(QuizFac::createMultipleChoiceQuiz("Ce capitale apartin tarilor nordice?", "Oslo", "Stockholm", "Amsterdam", std::vector<int>{1, 2}));
    addQuiz(QuizFac::createFillBlanksQuiz("Capitala Frantei este .....", "paris"));
    addQuiz(QuizFac::createFillBlanksQuiz("Capitala Italiei este .....", "roma"));

    // Answer each question and add the score
    for (const auto& quiz : quizes) {
        int correct = quiz->askQuestions();  // Answer the question
        quiz->display();  // Display the type of quiz
        user.addScore(correct, false);  // Add the score to the user
    }

    std::cout << "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);  // Reads the user's answer
    std::ranges::transform(ans, ans.begin(),
                           [](unsigned char c) { return std::tolower(c); });

    if(ans == "da") {  // If the user wants to see the details
        details();  // Displays the details of the game
    }

    std::cout << Quiz::getIdGame() << std::endl;  // Displays the game ID
    user.GameHistory(false);  // Displays the game history
    quizes.clear();  // Clears the list of quizzes
}

void Game::details() const {  // Function to display details about quizzes
    try {
        bool q = false;
        std::cout << "\nTipurile de intrebari ale acestui test : "<< std::endl;
        for (const auto& quiz : quizes) {  // Iterates through all the quizzes
            if(dynamic_pointer_cast<SingleChoiceQuiz>(quiz)) {
                std::cout << "Intrebare cu un singur raspuns id: "<< quiz->getDetails() << "\n";
                q = true;
            } else if (dynamic_pointer_cast<MultipleChoiceQuiz>(quiz)) {
                std::cout << "Intrebare cu raspuns multiplu id:" << quiz->getDetails() << "\n";
                q = true;
            } else if(dynamic_pointer_cast<FillBlanksQuiz>(quiz)) {
                std::cout << "Completare propozitii id: " <<  quiz->getDetails() << "\n";
                q = true;
            }
            if(!q) throw QuizException("Nu stiu ce tip de quiz este.");  // If the quiz type is unrecognized
        }
    } catch (const QuizException &e) {
        std::cout << e.what() << std::endl;  // Displays the error
    }
}
