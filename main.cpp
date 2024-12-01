#include "Game.h"
#include "User.h"


int main() {
    User myUser;

    myUser.setName();
    myUser.printName();
    int gameChoice;
    std::cout << "Variante de joc : "<< std::endl;
    std::cout<< "1. Matematica"<< std::endl;
    std::cout<< "2. Capitalele europei"<<std::endl;

    std::cin >> gameChoice;

    Game newGame(myUser);

    if (gameChoice == 1) {
        newGame.playGame1();
    } else if (gameChoice == 2) {
        newGame.playGame2();
    } else {
        std::cout << "Alegere invalida. Introduceti 1 sau 2.\n";
        std::cout << "Alegere iar:\n";
        std::cin >> gameChoice;
        if (gameChoice == 1) {
            newGame.playGame1();
        } else if (gameChoice == 2) {
            newGame.playGame2();
        }
    }

    std::cout << myUser;

    return 0;
}
