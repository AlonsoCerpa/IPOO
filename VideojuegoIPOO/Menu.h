#ifndef Screen_H_INCLUDED
#define Screen_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
/*
class Screen
{
public:
    bool loadScreen(const std::string &);
    void setScreenTexture();
    void setScreenPosition(const sf::Vector2f &pos);
    sf::Sprite getScreenSprite() const;
    bool ScreenIsOpen();
    void setScreenOpen(bool state);
protected:
    sf::Texture ScreenTexture;
    sf::Sprite ScreenSprite;
    bool ScreenOpen{true};
};

class ScreenButton : public Screen
{
public:
    ScreenButton(const int &nItem);
    bool loadScreenOn(const std::string &);
    void setMouseOver(bool);
    bool isMouseOver();
    void setButtonPressed(bool);
    bool buttonPressed() const;
    void updateButton();
private:
    sf::Texture buttonOn;
    bool mouseOver{false};
    bool pressed{false};
    int numItem;
};
*/
#endif // Screen_H_INCLUDED
