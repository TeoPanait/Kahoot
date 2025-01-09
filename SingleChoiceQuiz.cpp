#include "SingleChoiceQuiz.h"
#include <iostream>
#include <limits>
#include "Execption.h"

// Constructor that initializes the base class Quiz with the question text and answers
SingleChoiceQuiz::SingleChoiceQuiz(const std::string &text, const std::string &a1,
                                   const std::string &a2, const std::string &a3,
                                   const std::vector<int>& RightAnswer)
    : Quiz(text, a1, a2, a3, RightAnswer) {}

// Method to ask questions and receive the user's answer
int SingleChoiceQuiz::askQuestions() const {
    std::cout << std::endl;
    std::cout << Qa << std::endl; // Displays the question
    std::cout << Aa << std::endl; // Displays the answer options

    int guess; // User's answer
    while (true) {
        try {
            std::cout << "Care este raspunsul tau?\n";
            std::cin >> guess;

            // Checks if the input is valid
            if (std::cin.fail()) {
                throw AnswerException("Input invalid. Te rog sa introduci un numar.");
            }
            break; // Exits the loop if the input is valid
        } catch (const AnswerException &e) {
            // Clears the stream in case of invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }

    // Checks if the answer is correct
    if (guess == Aa.RightAnswer[0]) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore; // Returns the full score
    } else {
        std::cout << "Mai incearca" << std::endl;
        std::cin >> guess;

        if (guess == Aa.RightAnswer[0]) {
            std::cout << std::endl << "Corect!" << std::endl;
            return Qa.QuestionScore - 5; // Penalty for correct answer on the second try
        } else {
            std::cout << std::endl << "Gresit!" << std::endl;
            std::cout << "Raspuns corect = " << Aa.RightAnswer[0] << "." << std::endl;
        }
    }

    return 0; // Returns 0 points if the answer is incorrect
}
