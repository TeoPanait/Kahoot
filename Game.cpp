#include "Game.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>

Game::Game(User &user) : user(user) {
}

void Game::addQuiz(std::unique_ptr<Quiz> quiz) {
    quizes.push_back(std::move(quiz));
}
Game::~Game() {
    std::cout << "\n";
}
void Game::playGame1() {
    addQuiz(std::make_unique<SingleChoiceQuiz>("Cat fac 3*5?", "15", "3", "10", std::vector<int>{1}));
    addQuiz(std::make_unique<SingleChoiceQuiz>("Cat fac 4*5?", "15", "20", "10", std::vector<int>{2}));
    addQuiz(std::make_unique<SingleChoiceQuiz>("Cat fac 6*8?", "46", "42", "48", std::vector<int>{3}));
    addQuiz(std::make_unique<MultipleChoiceQuiz>("Ce proprietati are un triunghi dreptunghic?",
        "are un unghi de 30 de grade",
        "are un unghi de 90 de grade",
        "ip^2=c1^2+c2^2",
        std::vector<int>{2, 3}));
    addQuiz(std::make_unique<FillBlanksQuiz>("Un triunghi cu doua laturi egale se numeste .....", "isoscel"));
    addQuiz(std::make_unique<MultipleChoiceQuiz>("Care sunt proprietatile unui patrat?",
        "Are 4 laturi egale",
        "Are diagonale congruente si perpendiculare",
        "Are un unghi de 120 de grade",
        std::vector<int>{1, 2}));
    addQuiz(std::make_unique<MultipleChoiceQuiz>("Cum recunosti un trapez dreptunghic?",
        "Are o pereche de laturi paralele",
        "Are doua unghiuri drepte",
        "Are toate unghiurile egale",
        std::vector<int>{1, 2}));
    addQuiz(std::make_unique<FillBlanksQuiz>("Suma unghiurilor intr-un triunghi este ..... grade.", "180"));
    addQuiz(std::make_unique<FillBlanksQuiz>("O dreapta care imparte un cerc in doua parti egale se numeste .....",
        "diametru"));
    for (const auto& quiz : quizes) {
        int correct= quiz->askQuestions();
        quiz->display();
        user.addScore(correct);
    }
    std:: cout<< "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);
    std::transform(ans.begin(), ans.end(), ans.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    if(ans == "da") {
        details();
    }

    quizes.clear();
}

void Game::playGame2() {
    addQuiz(std::make_unique<SingleChoiceQuiz>("Care este capitala Austriei?",
        "Viena", "Venetia", "Germania", std::vector<int>{1}));
    addQuiz(std::make_unique<SingleChoiceQuiz>("Care este capitala Suediei?",
        "Copenhaga", "Stockholm", "Londra", std::vector<int>{2}));
    addQuiz(std::make_unique<SingleChoiceQuiz>("Care este capitala Spaniei?",
        "Barcelona","Valencia","Madrid",std::vector<int>{3}));
    addQuiz(std::make_unique<MultipleChoiceQuiz>(
    "Care dintre urmatoarele orase sunt capitale europene?",
    "Roma", "Berlin", "Lyon", std::vector<int>{1, 2}));
    addQuiz(std::make_unique<MultipleChoiceQuiz>(
        "Ce capitale apartin țarilor nordice?",
        "Oslo", "Stockholm", "Amsterdam", std::vector<int>{1, 2}));
    addQuiz(std::make_unique<FillBlanksQuiz>("Capitala Frantei este .....", "paris"));
    addQuiz(std::make_unique<FillBlanksQuiz>("Capitala Italiei este .....", "roma"));
    for (const auto& quiz : quizes) {
        int correct = quiz->askQuestions();
        quiz->display(); //tip de raspuns
        user.addScore(correct);
    }

    std:: cout<< "Vrei sa vezi detaliile testului? "<< std::endl;
    std::string ans;
    std::getline(std::cin, ans);
    std::transform(ans.begin(), ans.end(), ans.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    if(ans == "da") {
        details();
    }

    quizes.clear();

}

void Game::details() const {
    std::cout<< std::endl<< "Tipurile de intrebari ale acestui test : "<< std::endl;
    for (const auto& const quiz : quizes) {
        if(auto* scq=dynamic_cast<SingleChoiceQuiz*>(quiz.get())) {
            std::cout << "Intrebare cu un singur raspuns id: "<< scq->getDetails() << "\n";
        } else if (auto* const mcq=dynamic_cast<MultipleChoiceQuiz*>(quiz.get())) {
            std::cout << "Intrebare cu raspuns multiplu id:"<< mcq->getDetails() << "\n";
        }else if(auto* const fbq=dynamic_cast<FillBlanksQuiz*>(quiz.get())) {
            std::cout << "Completare propozitii id: " <<  fbq->getDetails() << "\n";
        }

    }
}
