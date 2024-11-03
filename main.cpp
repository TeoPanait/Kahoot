#include "Game.h"
#include "User.h"


int main() {
    User myUser;

    myUser.setName();
    myUser.printName();
    Game newGame(myUser);
    newGame.playGame1();
    Game copiedGame = newGame;
    copiedGame.playGame2();


    return 0;
}
