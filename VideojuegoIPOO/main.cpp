#include "Game.h"
#include <memory>

std::shared_ptr<Game> myGame{Game::getInstance()};

int main()
{
    myGame -> run();

    return 0;
}
