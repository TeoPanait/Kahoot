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

Game::Game(User &user) : user(user) {
}

void Game::addQuiz(const std::shared_ptr<Quiz> &quiz) {
    quizes.push_back(quiz);
}
Game::~Game() {
    std::cout << "\n";
}
void Game::playGame1() {
    try {
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 3*5?", "15", "3", "10", std::vector<int>{1}));
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 4*5?", "15", "20", "10", std::vector<int>{2}));
        addQuiz(QuizFac::createSingleChoiceQuiz("Cat fac 6*8?", "46", "42", "48", std::vector<int>{3}));
    } catch (const AnswerException &e) {
        std::cout << e.what() << "\n";
    }
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
    addQuiz(QuizFac::createFillBlanksQuiz("O dreapta care imparte un cerc in doua parti egale se numeste .....",
        "diametru"));
    for (const auto& quiz : quizes) {
        int correct= quiz->askQuestions();
        quiz->display();
        user.addScore(correct);
    }
    std:: cout<< "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);
    std::ranges::transform(ans, ans.begin(),
                           [](unsigned char c) { return std::tolower(c); });
    if(ans == "da") {
        try {
            details();
        }catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout<< Quiz::getIdGame() << std::endl;
    quizes.clear();
}

void Game::playGame2() {
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Austriei?",
        "Viena", "Venetia", "Germania", std::vector<int>{1}));
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Suediei?",
        "Copenhaga", "Stockholm", "Londra", std::vector<int>{2}));
    addQuiz(QuizFac::createSingleChoiceQuiz("Care este capitala Spaniei?",
        "Barcelona","Valencia","Madrid",std::vector<int>{3}));
    addQuiz(QuizFac::createMultipleChoiceQuiz(
    "Care dintre urmatoarele orase sunt capitale europene?",
    "Roma", "Berlin", "Lyon", std::vector<int>{1, 2}));
    addQuiz(QuizFac::createMultipleChoiceQuiz(
        "Ce capitale apartin tarilor nordice?",
        "Oslo", "Stockholm", "Amsterdam", std::vector<int>{1, 2}));
    addQuiz(QuizFac::createFillBlanksQuiz("Capitala Frantei este .....", "paris"));
    addQuiz(QuizFac::createFillBlanksQuiz("Capitala Italiei este .....", "roma"));
    for (const auto& quiz : quizes) {
        int correct = quiz->askQuestions();
        quiz->display();
        user.addScore(correct);
    }

    std:: cout<< "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);
    std::ranges::transform(ans, ans.begin(),
                           [](unsigned char c) { return std::tolower(c); });
    if(ans == "da") {
        details();
    }
    std::cout<< Quiz::getIdGame() << std::endl;
    quizes.clear();

}

void Game::details() const {
    try{
        bool q=false;
        std::cout<< std::endl<< "Tipurile de intrebari ale acestui test : "<< std::endl;
        for (const auto& quiz : quizes) {
            if(dynamic_pointer_cast<SingleChoiceQuiz>(quiz)) {
                std::cout << "Intrebare cu un singur raspuns id: "<< quiz->getDetails() << "\n";
                q=true;
            } else if (dynamic_pointer_cast<MultipleChoiceQuiz>(quiz)) {
                std::cout << "Intrebare cu raspuns multiplu id:"<< quiz->getDetails() << "\n";
                q=true;
            }else if(dynamic_pointer_cast<FillBlanksQuiz>(quiz)) {
                std::cout << "Completare propozitii id: " <<  quiz->getDetails() << "\n";
                q=true;
            }
            if(!q)throw QuizException("Nu stiu ce tip de quiz este.");
        }
    }catch ( const QuizException &e) {
        std::cout << e.what() << std::endl;
    }
}


