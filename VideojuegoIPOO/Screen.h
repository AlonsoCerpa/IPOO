#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <vector>

#include "Button.h"
#include "Input.h"

class Screen
{
public:
    virtual void iniScreen() = 0;
    virtual void updateScreen() = 0;
    virtual void renderScreen() = 0;
    static int loadSounds();
    static void setSounds();

protected:
    virtual int loadTextures() = 0;
    virtual void setSpritesTextures() = 0;
    virtual void setSpritesPosition() = 0;
    virtual void updateButtonStates() = 0;
    virtual void setButtonsFalse() = 0;

    static int difficulty;
    static sf::RenderWindow ventana;
    static Input *input;
    static int currentScreen;
    static bool sound;
    static bool pause;
    static sf::Font font;
    static sf::SoundBuffer buttonBuff;
    static sf::Sound buttonSound;

    int currentButton;
};

#endif // SCREEN_H_INCLUDED
