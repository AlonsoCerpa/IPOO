#include "TopPlayers.h"

void TopPlayers::iniScreen()
{
    setSpritesPosition();
    loadTextures();
    setSpritesTextures();
    setButtonsFalse();
    iniText();
}

int TopPlayers::loadTextures()
{
    if (!topPlayersT.loadFromFile("imagenes/TopPlayers/topPlayersTitle.png"))
        return 0;
    if (!backgroundT.loadFromFile("imagenes/fondoCompleto.png"))
        return 0;
    if (!getBackB.loadButtonOff("imagenes/backMenuOff.png"))
        return 0;
    if (!getBackB.loadButtonOn("imagenes/backMenuOn.png")
        return 0;
    return 1;
}

void TopPlayers::setSpritesTextures()
{
    topPlayerS.setTexture(topPlayersT);
    backgroundS.setTexture(backgroundT);
    getBackB.setButtonTexture();
}

void TopPlayers::setSpritesPosition()
{
    topPlayerS.setPosition(sf::Vector2f{195.f, 0.f});
    backgroundS.setPosition(sf::Vector2f{195.f, 0.f});
    getBackB.setButtonPosition(sf::Vector2f{355.f, 400.f});
}

void TopPlayers::updateScreen()
{
    updateButtonStates();
    setButtonsFalse();
}

void TopPlayers::updateButtonStates()
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
    else
        currentButton = 0;

    getBackB.updateButton();
}

void TopPlayers::setButtonsFalse()
{
    getBackB.setButtonOver(false);
}

void TopPlayers::renderScreen()
{
    ventana.draw(topPlayerS);
    ventana.draw(backgroundS);
    ventana.draw(getBackB.buttonSprite);
}

void TopPlayers::iniText()
{

}
