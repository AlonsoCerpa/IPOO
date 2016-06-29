#include "Game.h"

int main()
{
    Game *myGame = Game::getInstance();
    myGame -> run();

    return 0;
}
