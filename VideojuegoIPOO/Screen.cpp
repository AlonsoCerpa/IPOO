#include "Screen.h"

sf::RenderWindow Screen::ventana{sf::VideoMode{800, 600}, "Dodge Cars"};

Input *Screen::input = Input::getInstance();

int Screen::currentScreen = 0;

bool Screen::sound = true;

int Screen::difficulty = 1;

bool Screen::pause = false;

int Screen::loadSounds()
{
    if(!buttonBuff.loadFromFile("sounds/button.wav"))
        return 0;
    return 1;
}

void Screen::setSounds()
{
    buttonSound.setBuffer(buttonBuff);
}
