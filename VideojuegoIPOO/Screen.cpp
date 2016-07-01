#include "Screen.h"

bool Screen::loadScreen (const std::string &ScreenDir)
{
    return ScreenTexture.loadFromFile(ScreenDir);
}

void Screen::setScreenTexture()
{
    ScreenSprite.setTexture(ScreenTexture);
}

void Screen::setScreenPosition(const sf::Vector2f &pos)
{
    ScreenSprite.setPosition(pos);
}

sf::Sprite Screen::getScreenSprite() const
{
    return ScreenSprite;
}

bool Screen::ScreenIsOpen()
{
    return ScreenOpen;
}

void Screen::setScreenOpen(bool state)
{
    ScreenOpen = state;
}
