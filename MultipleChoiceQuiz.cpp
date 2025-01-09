#include "MultipleChoiceQuiz.h"
#include <iostream>
#include <ostream>
#include <sstream>

// Constructor for the MultipleChoiceQuiz class
MultipleChoiceQuiz::MultipleChoiceQuiz(const std::string &text, const std::string &a1, const std::string &a2, const std::string &a3, const  std::vector<int>& RightAnswer)
    : Quiz(text, a1, a2, a3, RightAnswer) {}

// Function that asks the questions and verifies the answers
int MultipleChoiceQuiz::askQuestions() const{
    std::cout << std::endl;
    std::cout << Qa << std::endl; // Display the question
    std::cout << Aa << std::endl; // Display the possible answers
    int guess1=0, guess2=0;
    std::cout << "Care este raspunsul tau?\n" ;
    std::cin >> guess1;  // Receive answer 1
    std::cin >> guess2;  // Receive answer 2

    // Verify if the answers are correct
    if (guess1 == Aa.RightAnswer[0] && guess2 == Aa.RightAnswer[1]) {
        std::cout << std::endl << "Corect!" << std::endl;
        return Qa.QuestionScore;  // Return the score for the correct answer
    } else {
        std::cout << "Mai incearca o data" << std::endl;
        std::cin >> guess1;  // Allow a new attempt
        std::cin >> guess2;

        // Check the answers again
        if (guess1 == Aa.RightAnswer[0] && guess2 == Aa.RightAnswer[1]) {
            std::cout << std::endl << "Corect!" << std::endl;
            return Qa.QuestionScore - 5;  // If the second attempt is correct, the score is reduced by 5
        } else {
            std::cout << std::endl << "Gresit!" << std::endl;
            std::cout << "Raspuns corect = " << Aa.RightAnswer[0] << " si " << Aa.RightAnswer[1] << std::endl;
        }
    }

    return 0;  // Return 0 if the answer is incorrect even after the second attempt
}

// Function that returns the quiz details
int MultipleChoiceQuiz::getDetails() const {
    return 2;  // Specific details for the multiple-choice quiz
}

// Function that displays the type of quiz
void MultipleChoiceQuiz::display() const {
    std::cout << "Raspuns multiplu" << std::endl;  // Display message for the multiple-choice quiz
}
