#include "FillBlanksQuiz.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

// Constructor for the FillBlanksQuiz class
FillBlanksQuiz::FillBlanksQuiz(const std::string& text, std::string correct) :
    Quiz( text,"", "","", {}), correct(std::move(correct)) {}

// Function that asks the question and checks the user's answer
int FillBlanksQuiz::askQuestions() const {
    std::cout << std::endl;
    std::cout << Qa << std::endl;  // Display the question

    std::cout << "Care este raspunsul tau?" << std::endl;
    std::string guess;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer to avoid reading issues
    getline(std::cin, guess);  // Read the user's answer
    std::ranges::transform(guess, guess.begin(),
                           [](unsigned char c){ return std::tolower(c); }); // Convert the answer to lowercase to avoid case sensitivity

    // Check if the answer is correct
    if (guess == correct ) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;  // Return the score for the correct answer
    } else {
        std::cout << "Mai incearca o data" << std::endl;  // Allow another attempt
        getline(std::cin, guess);  // Read the answer again
        std::ranges::transform(guess, guess.begin(),
                               [](unsigned char c){ return std::tolower(c); });  // Convert the answer to lowercase
        if (guess == correct) {
            std::cout << std::endl << "Corect!" << std::endl;
            return Qa.QuestionScore - 5;  // Reduced score by 5 if the answer is correct on the second try
        } else {
            std::cout << std::endl << "Incorect!" << std::endl;
            std::cout << "Raspuns corect = " << correct << "." << std::endl;  // Display the correct answer
        }
    }

    return 0;  // Return 0 if the answer is incorrect
}

// Function that displays the quiz type
void FillBlanksQuiz::display() const {
    std::cout << "Completare" << std::endl;  // Display the quiz type
}

// Function that returns details about the quiz
int FillBlanksQuiz::getDetails() const {
    return 3;  // Specific details for the fill-in-the-blank quiz
}
