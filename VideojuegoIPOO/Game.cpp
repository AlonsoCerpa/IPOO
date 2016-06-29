#include "Game.h"
#include <iostream>

bool Game::isPlaying = true;

Game *Game::uniqueGame = nullptr;

///////////////////////////////////////////////////////////////////////////////

Game *Game::getInstance()
{
    if (uniqueGame == nullptr)
        uniqueGame = new Game();
    return uniqueGame;
}

///////////////////////////////////////////////////////////////////////////////

int Game::initialize(){
    isPlaying = true;
    uniqueGame = nullptr;

    newGameScreen.iniScreen();

    menuScreen.iniScreen();
    newGameScreen.iniScreen();
    optionsScreen.iniScreen();
    topPlayersScreen.iniScreen();
    creditsScreen.iniScreen();

    ventana.setFramerateLimit(60);
    ventana.setKeyRepeatEnabled(false);
    ventana.setVerticalSyncEnabled(false);

    timeFloat = clock.getElapsedTime().asSeconds();
    timeInt = static_cast<int>(timeFloat);

    localPosition = sf::Mouse::getPosition(ventana);

    iniMenu();
    iniOptions();
    iniTopPlayers();
    iniCredits();

    if(!font.loadFromFile("fonts/SimsLLHP.ttf"))
        return 0;

    /*
    text.setFont(font);
    text.setString("exitB");
    text.setCharacterSize(150);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f{70.f, 20.f});
*/
    std::srand(std::time(0));

    if(!loadSounds())
        return 1;
    if(!loadImages())
        return 1;

    setTextures();
    iniMusicNoEnd.play();

    return 0;
}

/////////////////////////////////////////////////////////////////////////////

void Game::eventos(){

    input->pollEvent();
}

/////////////////////////////////////////////////////////////////////////////

void Game::update(){

    input->updateMousePosition();

    timeFloat = clock.getElapsedTime().asSeconds();
    timeInt = static_cast<int>(timeFloat);
    //cout << timeFloat << endl;

    updateCurrentScreen();

    if(menuScreen.)
    {
        checkMenu();

        if(!bodyMusicStart && iniMusicNoEnd.getStatus() == 0){
            bodyMusicStart = true;
            iniMusicNoEnd.stop();
            bodyMusic.play();
            bodyMusic.setLoop(true);
        }

        newGameB.updateButton();
        optionsB.updateButton();
        topPlayersB.updateButton();
        creditsB.updateButton();
        exitB.updateButton();
    }

    else if(newGameB.buttonPressed())
    {
            /*
        if(changePitch && timeInt % 10 == 0){
            timeAux = timeInt;
            changePitch = false;
            numPitch += 0.1;
        }
        else if (!changePitch && timeInt == timeAux + 1)
            changePitch = true;
*/
        numPitch += 0.0002;
        std::cout << numPitch << std::endl;

        if (!newGameBMusicStart){
            newGameBMusicStart = true;
            if(!bodyMusicStart)
                iniMusicNoEnd.stop();
            else{
                bodyMusic.stop();
                bodyMusicStart = false;
            }
            iniMusicNoEnd.play();
        }
        iniMusicNoEnd.setPitch(numPitch);

/*
        if(SPACE == true)
            Obstacle::speedVehicle = 7.0f;
*/
        if (!bodyMusicStart && iniMusicNoEnd.getStatus() == 0)
        {
            bodyMusicStart = true;
            bodyMusic.play();
            bodyMusic.setLoop(true);
        }
        if(bodyMusicStart)
            bodyMusic.setPitch(numPitch);

        if (upReleased)
            upDone = false;
        if (downReleased)
            downDone = false;
        if (leftReleased)
            leftDone = false;
        if (rightReleased)
            rightDone = false;

        if (UP && !upDone)
        {
            mainCar.movement(1);
            upDone = true;
        }
        else if (DOWN && !downDone)
        {
            mainCar.movement(2);
            downDone = true;
        }
        else if (LEFT && !leftDone)
        {
            mainCar.movement(3);
            leftDone = true;
        }
        else if (RIGHT && !rightDone)
        {
            mainCar.movement(4);
            rightDone = true;
        }

        newGameScreen.updateScreen();

        soundB.updateButton();
        menuB.updateButton();
    }

    else if(optionsB.buttonPressed())
    {
        menuB.updateButton();
    }

    else if(topPlayersB.buttonPressed())
    {
        namePlayerT.setString(namePlayerS);
        menuB.updateButton();
    }
    else if(creditsB.buttonPressed())
    {
        menuB.updateButton();
    }

    input->setKeysFalse();
}

/////////////////////////////////////////////////////////////////////////////

void Game::render(){
    ventana.clear();
    renderCurrentScreen();
    ventana.display();
}

/////////////////////////////////////////////////////////////////////////////

void Game::closeWindow(){
    ventana.close();
}

/////////////////////////////////////////////////////////////////////////////

void Game::run(){
    initialize();
    while (isPlaying)
    {
        events();
        update();
        render();
    }
    closeWindow();
}







