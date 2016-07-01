#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

class Screen
{
public:
    //bool loadScreenFondo(const std::string &);
    bool loadScreen(const std::string &);
    void setScreenTexture();
    void setScreenPosition(const sf::Vector2f &pos);
    sf::Sprite getScreenSprite() const;
    bool ScreenIsOpen();
    void setScreenOpen(bool state);
private:
    //sf::Texture fondoCompleto;
    sf::Texture ScreenTexture;
    sf::Sprite ScreenSprite;
    bool ScreenOpen{true};
};

#endif // SCREEN_H_INCLUDED
