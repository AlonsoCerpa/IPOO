#ifndef CREDITS_H_INCLUDED
#define CREDITS_H_INCLUDED

#include "Screen.h"

class Credits : public Screen
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
    void iniText();

    Button getBackB;
    sf::Texture backgroundT;
    sf::Sprite backgroundS;
    sf::Text textCredits;
    sf::Text name;
};

#endif // CREDITS_H_INCLUDED
