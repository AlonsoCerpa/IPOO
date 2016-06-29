#include "Menu.h"
#include "Input.h"
#include "Game.h"

void Menu::iniScreen()
{
    setSpritesPosition();
    loadTextures();
    setSpritesTextures();
    setButtonsFalse();
}

int Menu::loadTextures()
{
    if(!titleT.loadFromFile("imagenes/Menu/title.png"))
        return 0:
    if(!newGameB.loadButtonOff("imagenes/Menu/newGameOff.png"))
        return 0;
    if(!newGameB.loadButtonOn("imagenes/Menu/newGameOn.png"))
        return 0;
    if(!optionsB.loadButtonOff("imagenes/Menu/optionsOff.png"))
        return 0;
    if(!optionsB.loadButtonOn("imagenes/Menu/optionsOn.png"))
        return 0;
    if(!topPlayersB.loadButtonOff("imagenes/Menu/topPlayersOff.png"))
        return 0;
    if(!topPlayersB.loadButtonOn("imagenes/Menu/topPlayersOn.png"))
        return 0;
    if(!creditsB.loadButtonOff("imagenes/Menu/creditsOff.png"))
        return 0;
    if(!creditsB.loadButtonOn("imagenes/Menu/creditsOn.png"))
        return 0;
    if(!exitB.loadButtonOff("imagenes/Menu/exitOff.png"))
        return 0;
    if(!exitB.loadButtonOn("imagenes/Menu/exitOn.png"))
        return 0;

    return 1;
}

void Menu::setSpritesTextures()
{
    titleS.setTexture(titleT);
    newGameB.setButtonTexture();
    optionsB.setButtonTexture();
    topPlayersB.setButtonTexture();
    creditsB.setButtonTexture();
    exitB.setButtonTexture();
}

void Menu::setSpritesPosition()
{
    titleS.setPosition(sf::Vector2f{195.f, 0.f});
    newGameB.setButtonPosition(sf::Vector2f{195.f, 200.f});
    optionsB.setButtonPosition(sf::Vector2f{195.f, 280.f});
    topPlayersB.setButtonPosition(sf::Vector2f{195.f, 360.f});
    creditsB.setButtonPosition(sf::Vector2f{195.f, 440.f});
    exitB.setButtonPosition(sf::Vector2f{195.f, 520.f});
}

void Menu::updateScreen()
{
    updateButtonStates();
    setButtonsFalse();
}

void Menu::updateButtonStates()
{
    if (newGameB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY)){
        if(currentButton != 1){
            currentButton = 1;
            buttonSound.play();
        }
        newGameB.setButtonOver(true);
        if (Game::input->CLICLEFT)
            Game::currentScreen = 1;
    }

    else if (optionsB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY)){
        if(currentButton != 2){
            currentButton = 2;
            buttonSound.play();
        }
        optionsB.setButtonOver(true);
        if (input->CLICLEFT)
            currentScreen = 2;
    }

    else if (topPlayersB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY)){
        if(currentButton != 3){
            currentButton = 3;
            buttonSound.play();
        }
        topPlayersB.setButtonOver(true);
        if (input->CLICLEFT)
            currentScreen = 3;
    }

    else if (creditsB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY)){
        if(currentButton != 4){
            currentButton = 4;
            buttonSound.play();
        }
        creditsB.setButtonOver(true);
        if (input->CLICLEFT)
            currentScreen = 4;
    }

    else if (exitB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY)){
        if(currentButton != 5){
            currentButton = 5;
            buttonSound.play();
        }
        exitB.setButtonOver(true);
        if (input->CLICLEFT)
            isPlaying = false;
    }

    else
        currentButton = 0;

    newGameB.updateButton();
    optionsB.updateButton();
    topPlayersB.updateButton();
    creditsB.updateButton();
    exitB.updateButton();
}

void Menu::setButtonsFalse()
{
    newGameB.setButtonOver(false);
    optionsB.setButtonOver(false);
    topPlayersB.setButtonOver(false);
    creditsB.setButtonOver(false);
    exitB.setButtonOver(false);
}

void Menu::renderScreen()
{
    ventana.draw(titleS);
    ventana.draw(newGameB.buttonSprite);
    ventana.draw(optionsB.buttonSprite);
    ventana.draw(topPlayersB.buttonSprite);
    ventana.draw(creditsB.buttonSprite);
    ventana.draw(exitB.buttonSprite);
}
