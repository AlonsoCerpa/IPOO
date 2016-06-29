#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
    bool loadButtonOff(const std::string &);
    bool loadButtonOn(const std::string &);
    void setButtonTexture();
    void setButtonPosition(const sf::Vector2f &pos);
    void setButtonOver(bool);
    bool isButtonOver() const;
    void updateButton();

    sf::Sprite buttonSprite;
private:
    sf::Texture buttonOff;
    sf::Texture buttonOn;
    bool buttonOver{false};
    int numItem;
};

#endif // BUTTON_H_INCLUDED
