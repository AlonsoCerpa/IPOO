#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Screen.h"

class Menu : public Screen
{
public:
    virtual void iniScreen();
    virtual void updateScreen();
    virtual void renderScreen();
private:
    virtual int loadTextures();
    virtual void setSpritesTextures();
    virtual void setSpritesPosition();
    virtual void updateButtonStates();
    virtual void setButtonsFalse();

    Button newGameB;
    Button optionsB;
    Button topPlayersB;
    Button creditsB;
    Button exitB;
    sf::Texture titleT;
    sf::Sprite titleS;
};

#endif // MENU_H_INCLUDED
