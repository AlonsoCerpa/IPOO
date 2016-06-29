#include "Options.h"

void Options::iniScreen()
{
    showDifficulties = false;
    panelDifficulties = false;
    setSpritesPosition();
    loadTextures();
    setSpritesTextures();
    setButtonsFalse();
    iniText();
}

int Options::loadTextures()
{
    if (!titleOptionsT.loadFromFile("imagenes/Options/optionsTitle.png"))
        return 0;
    if (!backgroundT.loadFromFile("imagenes/fondoCompleto.png"))
        return 0;
    if (!getBackB.loadButtonOff("imagenes/backMenuOff.png"))
        return 0;
    if (!getBackB.loadButtonOn("imagenes/backMenuOn.png")
        return 0;
    if (!setDifficultyB.loadButtonOff("imagenes/Options/difficultiesOff.png"))
        return 0;
    if (!setDifficultyB.loadButtonOn("imagenes/Options/difficultiesOn.png")
        return 0;
    if (!chooseMapB.loadButtonOff("imagenes/Options/chooseMapOff.png"))
        return 0;
    if (!chooseMapB.loadButtonOn("imagenes/Options/chooseMapOn.png")
        return 0;
    if (!chooseCarB.loadButtonOff("imagenes/Options/chooseCarOff.png"))
        return 0;
    if (!chooseCarB.loadButtonOn("imagenes/Options/chooseCarOn.png")
        return 0;
    if (!easyB.loadButtonOff("imagenes/Options/easyOff.png"))
        return 0;
    if (!easyB.loadButtonOn("imagenes/Options/easynOn.png")
        return 0;
    if (!mediumB.loadButtonOff("imagenes/Options/mediumOff.png"))
        return 0;
    if (!mediumB.loadButtonOn("imagenes/Options/mediumnOn.png")
        return 0;
    if (!hardB.loadButtonOff("imagenes/Options/hardOff.png"))
        return 0;
    if (!hardB.loadButtonOn("imagenes/Options/hardOn.png")
        return 0;
    return 1;
}

void Options::setSpritesTextures()
{
    titleOptionsS.setTexture(titleOptionsT);
    backgroundS.setTexture(backgroundT);
    getBackB.setButtonTexture();
    setDifficultyB.setButtonTexture();
    chooseMapB.setButtonTexture();
    chooseCarB.setButtonTexture();
    easyB.setButtonTexture();
    mediumB.setButtonTexture();
    hardB.setButtonTexture();
}

void Options::setSpritesPosition()
    titleOptionsS.setPosition(sf::Vector2f{195.f, 0.f});
    backgroundS.setPosition(sf::Vector2f{195.f, 0.f});
    setDifficultyB.setButtonPosition(sf:
{:Vector2f{195.f, 200.f});
    chooseMapB.setButtonPosition(sf::Vector2f{195.f, 280.f});
    chooseCarB.setButtonPosition(sf::Vector2f{195.f, 360.f});
    easyB.setButtonPosition(sf::Vector2f{195.f, 280.f});
    mediumB.setButtonPosition(sf::Vector2f{195.f, 330.f});
    hardB.setButtonPosition(sf::Vector2f{195.f, 380.f});

    getBackB.setButtonPosition(sf::Vector2f{355.f, 470.f});
}

void Options::updateScreen()
{
    updateButtonStates();
    setButtonsFalse();
}

void Options::updateButtonStates()
{
    if (showDifficulties)
    {
        if (easyB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 1)
            {
                currentButton = 1;
                buttonSound.play();
            }
            easyB.setButtonOver(true);
            if (input->CLICLEFT)
                difficulty = 0;
        }

        else if (mediumB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 2)
            {
                currentButton = 2;
                buttonSound.play();
            }
            mediumB.setButtonOver(true);
            if (input->CLICLEFT)
                difficulty = 1;
        }

        else if (hardB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 3)
            {
                currentButton = 3;
                buttonSound.play();
            }
            hardB.setButtonOver(true);
            if (input->CLICLEFT)
                difficulty = 2;
        }

        else
        {
            currentButton = 0;
            if (input->CLICLEFT)
                showDifficulties = false;
        }

        easyB.updateButton();
        mediumB.updateButton();
        hardB.updateButton();
    }

    else
    {
        if (getBackB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 1)
            {
                currentButton = 1;
                buttonSound.play();
            }
            getBackB.setButtonOver(true);
            if (input->CLICLEFT)
                currentScreen = 0;
        }

        else if (setDifficultyB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 2)
            {
                currentButton = 2;
                buttonSound.play();
            }
            setDifficultyB.setButtonOver(true);
            if (input->CLICLEFT)
                showDifficulties = true;
        }

        else if (chooseMapB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 3)
            {
                currentButton = 3;
                buttonSound.play();
            }
            chooseMapB.setButtonOver(true);
            if (input->CLICLEFT)
                currentScreen = 5;
        }

        else if (chooseCarB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
        {
            if (currentButton != 4)
            {
                currentButton = 4;
                buttonSound.play();
            }
            chooseCarB.setButtonOver(true);
            if (input->CLICLEFT)
                currentScreen = 6;
        }
        else
            currentButton = 0;

        setDifficultyB.updateButton();
        chooseMapB.updateButton();
        chooseCarB.updateButton();
        getBackB.updateButton();
    }
}

void Options::setButtonsFalse()
{
    setDifficultyB.setButtonOver(false);
    chooseMapB.setButtonOver(false);
    chooseCarB.setButtonOver(false);
    getBackB.setButtonOver(false);
}

void Options::renderScreen()
{
    ventana.draw(titleOptionsS);
    ventana.draw(backgroundS);
    ventana.draw(setDifficultyB.buttonSprite);
    ventana.draw(chooseMapB.buttonSprite);
    ventana.draw(chooseCarB.buttonSprite);
    ventana.draw(getBackB.buttonSprite);
    if (showDifficulties)
    {
        ventana.draw(easyB.buttonSprite);
        ventana.draw(mediumB.buttonSprite);
        ventana.draw(hardB.buttonSprite);
    }
}

void Options::iniText()
{

}

