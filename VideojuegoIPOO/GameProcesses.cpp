#include "Game.h"

void Game::iniNewGame()
{

}

void Game::iniTopPlayers()
{
    topPlayers.setScreenPosition(sf::Vector2f(195.f, 0.f));

    namePlayerT.setFont(font);
    namePlayerT.setCharacterSize(150);
    namePlayerT.setColor(sf::Color::Red);
    namePlayerT.setStyle(sf::Text::Bold);
    namePlayerT.setPosition(sf::Vector2f{70.f, 20.f});
}

int Game::loadSounds()
{
    if (!musicGame.openFromFile("sounds/musicGame.flac"))
        return 0;
    if (!iniMusicNoEnd.openFromFile("sounds/iniMusicNoEnd.flac"))
        return 0;
    if (!bodyMusic.openFromFile("sounds/musicBody.flac"))
        return 0;
    if (!endMusic.openFromFile("sounds/endMusic.flac"))
        return 0;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////

void Game::updateCurrentScreen()
{
    switch(currentScreen)
    {
    case 0:
        menuScreen.updateScreen();
        break;
    case 1:
        newGameScreen.updateScreen();
        break;
    case 2:
        optionsScreen.updateScreen();
        break;
    case 3:
        topPlayersScreen.updateScreen();
        break;
    case 4:
        creditsScreen.updateScreen();
        break;
    case 5:
        chooseMapScreen.updateScreen();
        break;
    case 6:
        chooseCarScreen.updateScreen();
        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////

void Game::renderCurrentScreen()
{
    switch (currentScreen)
    {
    case 0:
        menuScreen.renderScreen();
        break;
    case 1:
        newGameScreen.renderScreen();
        break;
    case 2:
        optionsScreen.renderScreen();
        break;
    case 3:
        topPlayersScreen.renderScreen();
        break;
    case 4:
        creditsScreen.renderScreen();
        break;
    case 5:
        chooseMapScreen.renderScreen();
        break;
    case 6:
        chooseCarScreen.renderScreen();
        break;
    default:
        break;
    }
}
