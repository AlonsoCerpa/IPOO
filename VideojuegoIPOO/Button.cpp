#include "Button.h"

bool Button::loadButtonOff(const std::string &buttonDir)
{
    return buttonOff.loadFromFile(buttonDir);
}

bool Button::loadButtonOn(const std::string &dir)
{
    return buttonOn.loadFromFile(dir);
}

void Button::setButtonTexture()
{
    buttonSprite.setTexture(buttonOff);
}

void Button::setButtonPosition(const sf::Vector2f &pos)
{
    buttonSprite.setPosition(pos);
}

void Button::setButtonOver(bool isOver)
{
    buttonOver = isOver;
}

bool Button::isButtonOver() const
{
    return buttonOver;
}

void Button::updateButton()
{
    if(buttonOver == false)
        buttonSprite.setTexture(buttonOff);
    else
        buttonSprite.setTexture(buttonOn);
}
