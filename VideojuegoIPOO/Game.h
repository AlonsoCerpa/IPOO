//Crear un archivo readme (guia de usuario)

//Presentar hasta el dia viernes 1 de julio

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Input.h"
#include "Menu.h"
#include "NewGame.h"
#include "Options.h"
#include "TopPlayers.h"
#include "Credits.h"

class Game
{
public:
    static Game *getInstance();
    static bool isPlaying;
    void run();

private:
    //Attributes
    Game();
    static Game *uniqueGame;

    Menu menuScreen;
    NewGame newGameScreen;
    Options optionsScreen;
    TopPlayers topPlayersScreen;
    Credits creditsScreen;
    ChooseMap chooseMapScreen;
    ChooseCar chooseCarScreen;

    sf::Clock clock;

    sf::Font font;
    sf::Text text;
    sf::Text textCredits;
    sf::Text name;

    sf::Music musicGame;
    sf::Music iniMusicNoEnd;
    sf::Music bodyMusic;
    sf::Music endMusic;

    sf::String namePlayerS;
    sf::Text namePlayerT;

    bool bodyMusicStart{false};
    bool newGameBMusicStart{false};

    bool changePitch{true};

    float timeFloat;
    float numPitch{0.5};
    int timeInt, timeAux;

    //Methods:
    void setCurrentScreen();
    int loadSounds();
    int loadImages();
    void setSounds();
    void setTextures();
    void setPositions();
    void updateCurrentScreen();
    void renderCurrentScreen();

    int initialize();
    void events();
    void update();
    void render();
    void closeWindow();
};

#endif // GAME_H_INCLUDED
