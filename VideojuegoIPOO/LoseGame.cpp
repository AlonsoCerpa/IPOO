#include "LoseGame.h"

LoseGame::LoseGame()
    : textBox{sf::Vector2f{350.f, 50.f}} {}

void LoseGame::iniScreen()
{
    enterScore = false;
    setSpritesPosition();
    loadTextures();
    setSpritesTextures();
    setButtonsFalse();
}

void LoseGame::updateScreen()
{
    updateButtonStates();
    setButtonsFalse();
}

void LoseGame::renderScreen()
{
    ventana.draw(submitScoreTitleS);
    if (!enterScore)
    {
        ventana.draw(enterName);
        ventana.draw(textBox);
        ventana.draw(enterB.buttonSprite);
    }
    ventana.draw(topPlayersB.buttonSprite);
    ventana.draw(newGameB.buttonSprite);
    ventana.draw(backToMenuB.buttonSprite);
}

int LoseGame::loadTextures()
{
    if (!submitScoreTitleT.loadFromFile("imagenes/LoseGame/submitScoreTitle"))
        return 0;
    if (!enterB.loadButtonOff("imagenes/LoseGame/enterOff"))
        return 0;
    if (!enterB.loadButtonOn("imagenes/LoseGame/enterOn"))
        return 0;
    if (!topPlayersB.loadButtonOff("imagenes/LoseGame/topPlayersOff"))
        return 0;
    if (!topPlayersB.loadButtonOn("imagenes/LoseGame/topPlayersOn"))
        return 0;
    if (!newGameB.loadButtonOff("imagenes/LoseGame/newGameOff"))
        return 0;
    if (!newGameB.loadButtonOn("imagenes/LoseGame/newGameOn"))
        return 0;
    if (!backToMenuB.loadButtonOff("imagenes/LoseGame/backToMenuOff"))
        return 0;
    if (!backToMenuB.loadButtonOn("imagenes/LoseGame/backToMenuOn"))
        return 0;
}

void LoseGame::setSpritesTextures()
{
    textBox.setFillColor(sf::Color::White);

    submitScoreTitleS.setTexture(submitScoreTitleT);
    enterB.setButtonTexture();
    topPlayersB.setButtonTexture();
    newGameB.setButtonTexture();
    backToMenuB.setButtonTexture();
}

void LoseGame::setSpritesPosition()
{
    submitScoreTitleS.setPosition(sf::Vector2f{195.f, 0.f});
    textBox.setPosition(sf::Vector2f{225.f, 240.f})
    enterB.setButtonPosition(sf::Vector2f{325.f, 300.f});
    topPlayersB.setButtonPosition(sf::Vector2f{195.f, 360.f});
    newGameB.setButtonPosition(sf::Vector2f{195.f, 440.f});
    backToMenuB.setButtonPosition(sf::Vector2f{195.f, 520.f});
}

void LoseGame::updateButtonStates()
{
    if (!enterScore)
    {
        if (enterB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 1){
                currentButton = 1;
                buttonSound.play();
            }
            enterB.setButtonOver(true);
            if (Game::input->CLICLEFT)
            {
                enterScore = true;
                currentButton = 0;
                topPlayersB.setButtonPosition(sf::Vector2f{195.f, 200.f});
                newGameB.setButtonPosition(sf::Vector2f{195.f, 280.f});
                backToMenuB.setButtonPosition(sf::Vector2f{195.f, 360.f});
            }
        }

        else if (topPlayersB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 2){
                currentButton = 2;
                buttonSound.play();
            }
            topPlayersB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 3;
        }

        else if (newGameB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 3){
                currentButton = 3;
                buttonSound.play();
            }
            enterB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 1;
        }

        else if (backToMenuB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 4){
                currentButton = 4;
                buttonSound.play();
            }
            backToMenuB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 0;
        }

        else
            currentButton = 0;
    }

    else
    {
        if (topPlayersB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 1){
                currentButton = 1;
                buttonSound.play();
            }
            topPlayersB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 3;
        }

        else if (newGameB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 2){
                currentButton = 2;
                buttonSound.play();
            }
            enterB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 1;
        }

        else if (backToMenuB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if(currentButton != 3){
                currentButton = 3;
                buttonSound.play();
            }
            backToMenuB.setButtonOver(true);
            if (Game::input->CLICLEFT)
                currentScreen = 0;
        }

        else
            currentButton = 0;
    }

    if (!enterScore)
        enterB.updateButton();
    topPlayersB.updateButton();
    newGameB.updateButton();
    backToMenuB.updateButton();
}

void LoseGame::setButtonsFalse()
{
    if(!enterScore)
        enterB.setButtonOver(false);
    topPlayersB.setButtonOver(false);
    newGameB.setButtonOver(false);
    backToMenuB.setButtonOver(false);
}

void LoseGame::iniText()
{
    enterName.setFont(font);
    enterName.setString("Enter your name:");
    enterName.setCharacterSize(20);
    enterName.setColor(sf::Color::Red);
    enterName.setStyle(sf::Text::Bold);
    enterName.setPosition(sf::Vector2f{210.f, 220.f});
}
