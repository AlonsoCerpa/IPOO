#include "Credits.h"

void Credits::iniScreen()
{
    setSpritesPosition();
    loadTextures();
    setSpritesTextures();
    setButtonsFalse();
    iniText();
}

int Credits::loadTextures()
{
    if (!backgroundT.loadFromFile("imagenes/fondoCompleto.png"))
        return 0;
    if (!getBackB.loadButtonOff("imagenes/backMenuOff.png"))
        return 0;
    if (!getBackB.loadButtonOn("imagenes/backMenuOn.png")
        return 0;
    return 1;
}

void Credits::setSpritesTextures()
{
    backgroundS.setTexture(backgroundT);
    getBackB.setButtonTexture();
}

void Credits::setSpritesPosition()
{
    backgroundS.setPosition(sf::Vector2f{195.f, 0.f});
    getBackB.setButtonPosition(sf::Vector2f{355.f, 400.f});
}

void Credits::updateScreen()
{
    updateButtonStates();
    setButtonsFalse();
}

void Credits::updateButtonStates()
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

void Credits::setButtonsFalse()
{
    getBackB.setButtonOver(false);
}

void Credits::renderScreen()
{
    ventana.draw(backgroundS);
    ventana.draw(textCredits);
    ventana.draw(name);
    ventana.draw(getBackB.buttonSprite);
}

void Credits::iniText()
{
    textCredits.setFont(font);
    textCredits.setString("Videojuego hecho por:");
    textCredits.setCharacterSize(40);
    textCredits.setColor(sf::Color::Red);
    textCredits.setStyle(sf::Text::Bold);
    textCredits.setPosition(sf::Vector2f{210.f, 20.f});

    name.setFont(font);
    name.setString("Alonso Jesus Cerpa Salas\n\nSe utilizo la biblioteca grafica\nSFML y el IDE Code Blocks.");
    name.setCharacterSize(30);
    name.setColor(sf::Color::Red);
    name.setStyle(sf::Text::Bold);
    name.setPosition(sf::Vector2f{210.f, 80.f});
}
