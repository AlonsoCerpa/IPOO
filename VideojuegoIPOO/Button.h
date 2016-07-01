#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(const int &nItem);
    bool loadScreen(const std::string &);
    void setScreenTexture();
    void setScreenPosition(const sf::Vector2f &pos);
    bool ScreenIsOpen();
    void setScreenOpen(bool state);
    bool loadScreenOn(const std::string &);
    void setMouseOver(bool);
    bool isMouseOver();
    void setButtonPressed(bool);
    bool buttonPressed() const;
    void updateButton();
    sf::Sprite ScreenSprite;
private:
    sf::Texture ScreenTexture;
    bool ScreenOpen{true};
    sf::Texture buttonOn;
    bool mouseOver{false};
    bool pressed{false};
    int numItem;
};

#endif // BUTTON_H_INCLUDED
