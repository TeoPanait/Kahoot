#include "Game.h"
#include "User.h"

int main() {
    User myUser;  // Create a User object

    myUser.setName();  // Set the user's name
    myUser.printName();  // Display the user's name
    int gameChoice;  // Variable for selecting the game type
    std::cout << "Optiuni de joc: "<< std::endl;
    std::cout << "1. Mate" << std::endl;  // Option for the math game
    std::cout << "2. Capitale Europene" << std::endl;  // Option for the capitals game

    std::cin >> gameChoice;  // Read the user's choice

    Game newGame(myUser);  // Create a Game object, linked to the user

    if (gameChoice == 1) {  // If the user chose math
        newGame.playGame1();  // Start the math game
    } else if (gameChoice == 2) {  // If the user chose capitals
        newGame.playGame2();  // Start the capitals game
    } else {  // If the choice is invalid
        std::cout << "Raspuns invalid. Te rog introdu 1 sau 2\n";  // Error message
        std::cout << "Mai alege o data:\n";  // Prompt for a new choice
        std::cin >> gameChoice;  // Read the choice again
        if (gameChoice == 1) {  // If the choice is 1
            newGame.playGame1();  // Start the math game
        } else if (gameChoice == 2) {  // If the choice is 2
            newGame.playGame2();  // Start the capitals game
        }
    }

    std::cout << myUser;  // Display the final score of the user

    return 0;  // End the program
}
