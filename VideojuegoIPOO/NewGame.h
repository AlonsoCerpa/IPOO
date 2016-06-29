#ifndef NEWGAME_H_INCLUDED
#define NEWGAME_H_INCLUDED

#include <random>

#include "Vehicle.h"
#include "Fondo.h"
#include "Button.h"

class NewGame : public Screen
{
public:
    NewGame();
    virtual void iniScreen();
    virtual void updateScreen();
    virtual void renderScreen();
    void setNewMove();
    void iniMovement(std::vector<int>);
    void makeMovement(std::vector<int>);
    void movementSchemeUpdate();
    void obstacleRender();

private:
    virtual int loadTextures();
    virtual void setSpritesTextures();
    virtual void setSpritesPosition();
    virtual void updateButtonStates();
    virtual void setButtonsFalse();

    PauseMenu pauseMenuScreen;
    bool pauseMenu;
    Button pauseMenuB;

    LoseGame loseGameScreen;
    bool loseGame;

    std::vector<Obstacle *> arrObstacle;
    std::vector<CarPlayer *> arrCarPlayer;
    std::vector<Obstacle *> obs;
    Obstacle obs1, obs2, obs3;
    Obstacle *firstObs, *secondObs;
    unsigned firstPos, secondPos;

    bool finishMove;
    bool newMovement;
    bool iniMov;

    int key, rand1, rand2, rand3;
    const int minInt{1}, maxInt{18};
    const int minPos{0}, maxPos{7};

    Button soundOnB;
    Button soundOffB;
    Button pauseB;
    Button playB;

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
};

#endif // NEWGAME_H_INCLUDED
