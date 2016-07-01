#include "Button.h"

bool Button::loadScreen (const std::string &ScreenDir)
{
    return ScreenTexture.loadFromFile(ScreenDir);
}

void Button::setScreenTexture()
{
    ScreenSprite.setTexture(ScreenTexture);
}

void Button::setScreenPosition(const sf::Vector2f &pos)
{
    ScreenSprite.setPosition(pos);
}

bool Button::ScreenIsOpen()
{
    return ScreenOpen;
}

void Button::setScreenOpen(bool state)
{
    ScreenOpen = state;
}

////////////////////////////////////////////////////

Button::Button(const int &nItem)
{
    numItem = nItem;
}

bool Button::loadScreenOn(const std::string &dir)
{
    return buttonOn.loadFromFile(dir);
}

void Button::setMouseOver(bool isOver)
{
    mouseOver = isOver;
}

bool Button::isMouseOver()
{
    return mouseOver;
}

void Button::setButtonPressed(bool buPressed)
{
    this->pressed = buPressed;
}

bool Button::buttonPressed() const
{
    return pressed;
}

void Button::updateButton()
{
    if(mouseOver == false)
        ScreenSprite.setTexture(ScreenTexture);
    else
        ScreenSprite.setTexture(buttonOn);
}
