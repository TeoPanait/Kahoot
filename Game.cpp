#include "Game.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>

#include "Execption.h"

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
        addQuiz(std::make_shared<SingleChoiceQuiz>("Cat fac 3*5?", "15", "3", "10", std::vector<int>{1}));
        addQuiz(std::make_shared<SingleChoiceQuiz>("Cat fac 4*5?", "15", "20", "10", std::vector<int>{2}));
        addQuiz(std::make_shared<SingleChoiceQuiz>("Cat fac 6*8?", "46", "42", "48", std::vector<int>{3}));
    } catch (const AnswerException &e) {
        std::cout << e.what() << "\n";
    }
    addQuiz(std::make_shared<MultipleChoiceQuiz>("Ce proprietati are un triunghi dreptunghic?",
        "are un unghi de 30 de grade",
        "are un unghi de 90 de grade",
        "ip^2=c1^2+c2^2",
        std::vector<int>{2, 3}));
    addQuiz(std::make_shared<FillBlanksQuiz>("Un triunghi cu doua laturi egale se numeste .....", "isoscel"));
    addQuiz(std::make_shared<MultipleChoiceQuiz>("Care sunt proprietatile unui patrat?",
        "Are 4 laturi egale",
        "Are diagonale congruente si perpendiculare",
        "Are un unghi de 120 de grade",
        std::vector<int>{1, 2}));
    addQuiz(std::make_shared<MultipleChoiceQuiz>("Cum recunosti un trapez dreptunghic?",
        "Are o pereche de laturi paralele",
        "Are doua unghiuri drepte",
        "Are toate unghiurile egale",
        std::vector<int>{1, 2}));
    addQuiz(std::make_shared<FillBlanksQuiz>("Suma unghiurilor intr-un triunghi este ..... grade.", "180"));
    addQuiz(std::make_shared<FillBlanksQuiz>("O dreapta care imparte un cerc in doua parti egale se numeste .....",
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
    addQuiz(std::make_shared<SingleChoiceQuiz>("Care este capitala Austriei?",
        "Viena", "Venetia", "Germania", std::vector<int>{1}));
    addQuiz(std::make_shared<SingleChoiceQuiz>("Care este capitala Suediei?",
        "Copenhaga", "Stockholm", "Londra", std::vector<int>{2}));
    addQuiz(std::make_shared<SingleChoiceQuiz>("Care este capitala Spaniei?",
        "Barcelona","Valencia","Madrid",std::vector<int>{3}));
    addQuiz(std::make_shared<MultipleChoiceQuiz>(
    "Care dintre urmatoarele orase sunt capitale europene?",
    "Roma", "Berlin", "Lyon", std::vector<int>{1, 2}));
    addQuiz(std::make_shared<MultipleChoiceQuiz>(
        "Ce capitale apartin țarilor nordice?",
        "Oslo", "Stockholm", "Amsterdam", std::vector<int>{1, 2}));
    addQuiz(std::make_shared<FillBlanksQuiz>("Capitala Frantei este .....", "paris"));
    addQuiz(std::make_shared<FillBlanksQuiz>("Capitala Italiei este .....", "roma"));
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
            if(!q)throw AplException("Nu stiu ce tip de quiz este.");
        }
    }catch ( const AplException &e) {
        std::cout << e.what() << std::endl;
    }
}


