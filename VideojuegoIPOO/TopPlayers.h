#ifndef TOPPLAYERS_H_INCLUDED
#define TOPPLAYERS_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Button.h"

class TopPlayers : public Screen
{
public:
    virtual void iniScreen();
    virtual void updateScreen();
    virtual void renderScreen();

private:
    virtual void setSpritesPosition();
    virtual void setSpritesTextures();
    virtual int loadTextures();
    virtual void updateButtonStates();
    virtual void setButtonsFalse();
    void iniText();

    Button getBackB;
    sf::Texture topPlayersT;
    sf::Sprite topPlayerS;
    sf::Texture backgroundT;
    sf::Sprite backgroundS;
};

#endif // TOPPLAYERS_H_INCLUDED
