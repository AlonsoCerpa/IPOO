#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vehicle.h"
#include "Fondo.h"
#include "Menu.h"
#include "Screen.h"
#include "Button.h"
#include <queue>
#include <SFML/Audio.hpp>

#include "PlayerScore.h"
#include <fstream>

class Game
{
public:
    static Game *getInstance();

    bool isPlaying{true};
    std::fstream topPlayersFile;
    void run();

private:
    Game();
    static Game *uniqueGame;

    std::string aux;
    int posScore{1};
    ArrPlayers arrPly;

    sf::String namePlayerS;
    sf::Text namePlayerT;

    int numCharEnter{0};

    int posRead;
    std::string nameRead;
    int scoreRead;

    char arrChar[25];
    std::string inputAux;

    int score{15};

    std::string scoreString;
    sf::Text scoreText;
    //Atributos
    float posX, posY;

    sf::RenderWindow ventana;
    sf::Event miEvento;
    sf::Clock clock;
    sf::Vector2i localPosition;
    sf::Font font;
    sf::Text text;

    sf::SoundBuffer buttonBuff;
    sf::Sound buttonSound;
    sf::Music musicGame;
    //sf::Music iniMusic;
    sf::Music iniMusicNoEnd;
    sf::Music bodyMusic;
    sf::Music endMusic;

    Screen menu;
    Screen fondoMenu;
    Screen options;
    Screen topPlayers;
    Screen credits;
    Screen askScore;

    Button newGameB{1};
    Button optionsB{2};
    Button topPlayersB{3};
    Button creditsB{4};
    Button exitB{5};

    Fondo pista;
    Fondo treesL;
    Fondo treesR;

    CarPlayer mainCar;

    Obstacle redCar;
    Obstacle policeCar;
    Obstacle truck1;
    Obstacle blackCar;
    Obstacle taxi;
    Obstacle truck2;
    Obstacle motorcycle;
    Obstacle bicycle;

    //VehicleArray<Obstacle> arrObstacle;
    //VehicleArray<CarPlayer> arrCarPlayer;
    vector<Obstacle *> arrObstacle;
    vector<CarPlayer *> arrCarPlayer;

    bool UP{false}, DOWN{false}, LEFT{false}, RIGHT{false};
    bool BACKSPACE{false}, SPACE{false}, ESCAPE{false};
    bool ENTER{false};

    bool upReleased{false}, downReleased{false};
    bool leftReleased{false}, rightReleased{false};
    bool backReleased{false}, spaceReleased{false};
    bool escapeReleased{false}, enterReleased{false};

    bool upDone{false}, downDone{false}, leftDone{false};
    bool rightDone{false};

    bool bodyMusicStart{false};
    bool newGameBMusicStart{false};

    //bool isPlaying{true};
    bool presionar{false};
    bool liberar{false};
    bool clicIzq{false};
    bool upSpeed{true};
    bool finishMove{true};
    bool newMovement{true};
    bool iniMov;
    bool changePitch{true};
    int currentButton{0};
    int mouseX, mouseY;
    float timeFloat;
    float numPitch{0.5};
    int timeInt, timeAux;
    int key, rand1, rand2, rand3;
    int minInt{1}, maxInt{18};
    int minPos{0}, maxPos{7};
    Obstacle obs1, obs2, obs3;
    vector<Obstacle *> obs;
    Obstacle *firstObs{nullptr}, *secondObs{nullptr};
    unsigned firstPos, secondPos;

    //Auxiliary functions:
    int loadSounds();
    int loadImages();
    void setSounds();
    void setTextures();
    void setPositions();
    void switchKeyPressed();
    void switchKeyReleased();
    void checkMenu();
    void setNewMove();
    void iniMovement(vector<int>);
    void makeMovement(vector<int>);
    void movementSchemeUpdate();
    void obstacleRender();
    void updateKeyStates();

    //Main functions
    int inicializar();
    void eventos();
    void update();
    void render();
    void cleared();
};

#endif // GAME_H_INCLUDED
