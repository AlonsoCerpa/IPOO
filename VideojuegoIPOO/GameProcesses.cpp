#include "Game.h"

int Game::loadSounds()
{
    if(!buttonBuff.loadFromFile("sounds/button.wav"))
        return 0;
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

int Game::loadImages()
{
    if(!font.loadFromFile("fonts/SimsLLHP.ttf"))
        return 0;

    if(!menu.loadScreen("imagenes/Menu/title.png"))
        return 0;
    if(!fondoMenu.loadScreen("imagenes/Menu/fondoMenu.png"))
        return 0;
    if(!options.loadScreen("imagenes/Menu/fondoCompleto.png"))
        return 0;
    if(!topPlayers.loadScreen("imagenes/Menu/fondoCompleto.png"))
        return 0;
    if(!credits.loadScreen("imagenes/Menu/fondoCompleto.png"))
        return 0;

    if(!newGameB.loadScreen("imagenes/Menu/newGameOff.png"))
        return 0;
    if(!newGameB.loadScreenOn("imagenes/Menu/newGameOn.png"))
        return 0;
    if(!optionsB.loadScreen("imagenes/Menu/optionsOff.png"))
        return 0;
    if(!optionsB.loadScreenOn("imagenes/Menu/optionsOn.png"))
        return 0;
    if(!topPlayersB.loadScreen("imagenes/Menu/topPlayersOff.png"))
        return 0;
    if(!topPlayersB.loadScreenOn("imagenes/Menu/topPlayersOn.png"))
        return 0;
    if(!creditsB.loadScreen("imagenes/Menu/creditsOff.png"))
        return 0;
    if(!creditsB.loadScreenOn("imagenes/Menu/creditsOn.png"))
        return 0;
    if(!exitB.loadScreen("imagenes/Menu/exitOff.png"))
        return 0;
    if(!exitB.loadScreenOn("imagenes/Menu/exitOn.png"))
        return 0;

    if(!pista.loadFondo("imagenes/Fondo/pista.png"))
        return 0;
    if(!treesL.loadFondo("imagenes/Fondo/trees.png"))
        return 0;
    if(!treesR.loadFondo("imagenes/Fondo/trees.png"))
        return 0;

    if(!mainCar.loadVehicle("imagenes/VehiclePlayer/lamborghiniCar.png"))
        return 0;

    if(!redCar.loadVehicle("imagenes/VehicleObstacle/redCar.png"))
        return 0;
    if(!policeCar.loadVehicle("imagenes/VehicleObstacle/policeCar.png"))
        return 0;
    if(!truck1.loadVehicle("imagenes/VehicleObstacle/truck1.png"))
        return 0;
    if(!blackCar.loadVehicle("imagenes/VehicleObstacle/blackCar.png"))
        return 0;
    if(!taxi.loadVehicle("imagenes/VehicleObstacle/taxi.png"))
        return 0;
    if(!truck2.loadVehicle("imagenes/VehicleObstacle/truck2.png"))
        return 0;
    if(!motorcycle.loadVehicle("imagenes/VehicleObstacle/motorcycle.png"))
        return 0;
    if(!bicycle.loadVehicle("imagenes/VehicleObstacle/bicycle.png"))
        return 0;
    return 1;
}

/////////////////////////////////////////////////////////////////////////////

void Game::setSounds()
{
    buttonSound.setBuffer(buttonBuff);
}

/////////////////////////////////////////////////////////////////////////////

void Game::setTextures()
{
    menu.setScreenTexture();
    fondoMenu.setScreenTexture();
    options.setScreenTexture();
    topPlayers.setScreenTexture();
    credits.setScreenTexture();

    pista.setFondoTexture();
    treesL.setFondoTexture();
    treesR.setFondoTexture();

    mainCar.setVehicleTexture();

    redCar.setVehicleTexture();
    policeCar.setVehicleTexture();
    truck1.setVehicleTexture();
    blackCar.setVehicleTexture();
    taxi.setVehicleTexture();
    truck2.setVehicleTexture();
    motorcycle.setVehicleTexture();
    bicycle.setVehicleTexture();
}

/////////////////////////////////////////////////////////////

void Game::switchKeyPressed()
{
    switch (miEvento.key.code)
    {
    case sf::Keyboard::W:
        UP = true;
        break;

    case sf::Keyboard::Up:
        UP = true;
        break;

    case sf::Keyboard::S:
        DOWN = true;
        break;

    case sf::Keyboard::Down:
        DOWN = true;
        break;

    case sf::Keyboard::A:
        LEFT  = true;
        break;

    case sf::Keyboard::Left:
        LEFT = true;
        break;

    case sf::Keyboard::D:
        RIGHT = true;
        break;

    case sf::Keyboard::Right:
        RIGHT = true;
        break;

    case sf::Keyboard::Space:
        SPACE = true;
        break;

    case sf::Keyboard::Escape:
        ESCAPE = true;
        break;

    case sf::Keyboard::Return:
        ENTER = true;
        break;

    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////

void Game::switchKeyReleased()
{
    switch (miEvento.key.code)
    {
    case sf::Keyboard::W:
        upReleased = true;
        break;

    case sf::Keyboard::Up:
        upReleased = true;
        break;

    case sf::Keyboard::S:
        downReleased = true;
        break;

    case sf::Keyboard::Down:
        downReleased = true;
        break;

    case sf::Keyboard::A:
        leftReleased = true;
        break;

    case sf::Keyboard::Left:
        leftReleased = true;
        break;

    case sf::Keyboard::D:
        rightReleased = true;
        break;

    case sf::Keyboard::Right:
        rightReleased = true;
        break;

    case sf::Keyboard::Space:
        spaceReleased = true;
        break;

    case sf::Keyboard::Escape:
        escapeReleased = true;
        break;

    case sf::Keyboard::Return:
        enterReleased = true;
        break;

    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////

void Game::checkMenu()
{
    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 200 &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
        menu.setScreenOpen(false);

    else if (localPosition.x < 195 || localPosition.x >= 605 ||
             localPosition.y < 200)
        currentButton = 0;

    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 200 && localPosition.y < 280){

        if(currentButton != 1){
            currentButton = 1;
            buttonSound.play();
        }

        newGameB.setMouseOver(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            newGameB.setButtonPressed(true);
    }
    else
        newGameB.setMouseOver(false);

    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 280 && localPosition.y < 360){

        if(currentButton != 2){
            currentButton = 2;
            buttonSound.play();
        }

        optionsB.setMouseOver(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            optionsB.setButtonPressed(true);
    }
    else
        optionsB.setMouseOver(false);

    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 360 && localPosition.y < 440){

        if(currentButton != 3){
            currentButton = 3;
            buttonSound.play();
        }

        topPlayersB.setMouseOver(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            topPlayersB.setButtonPressed(true);
    }
    else
        topPlayersB.setMouseOver(false);

    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 440 && localPosition.y < 520){

        if(currentButton != 4){
            currentButton = 4;
            buttonSound.play();
        }

        creditsB.setMouseOver(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            creditsB.setButtonPressed(true);
    }
    else
        creditsB.setMouseOver(false);

    if (localPosition.x >= 195 && localPosition.x < 605 &&
        localPosition.y >= 520){

        if(currentButton != 5){
            currentButton = 5;
            buttonSound.play();
        }

        exitB.setMouseOver(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            isPlaying = false;
    }
    else
        exitB.setMouseOver(false);

}

/////////////////////////////////////////////////////////////////////////////

void Game::setNewMove()
{
    obs1 = *(arrObstacle[rand1]);
    obs2 = *(arrObstacle[rand2]);
    obs3 = *(arrObstacle[rand3]);

    obs1.setVehiclePosition(sf::Vector2f(265.f, -160.f));
    obs2.setVehiclePosition(sf::Vector2f(365.f, -160.f));
    obs3.setVehiclePosition(sf::Vector2f(465.f, -160.f));

    iniMov = false;
    newMovement = false;
}

void Game::iniMovement(vector<int> mov)
{
    firstObs = nullptr;
    secondObs = nullptr;

    firstPos = mov.size();
    secondPos = mov.size();

    for (unsigned i = 0; i < mov.size() && (firstPos == mov.size() ||
                                            secondPos == mov.size()); i++){
        if (firstPos == mov.size() && mov[i] == 1)
            firstPos = i;
        else if (secondPos == mov.size() && mov[i] == 2)
            secondPos = i;
    }
    firstObs = obs[firstPos];
    if (secondPos != mov.size())
        secondObs = obs[secondPos];
    iniMov = true;
}

void Game::makeMovement(vector<int> mov)
{
    if(!iniMov)
        iniMovement(mov);

    if ((secondObs == nullptr && firstObs->getVehicleSprite().getPosition().y >= 600.f) ||
        (secondObs != nullptr && secondObs->getVehicleSprite().getPosition().y >= 600.f))
        finishMove = true;

    for (unsigned i = 0; i < mov.size(); i++){
        if (mov[i] == 1 && obs[i]->getVehicleSprite().getPosition().y < 600.f)
            obs[i]->movement(1);
        else if (mov[i] == 2 && firstObs->getVehicleSprite().getPosition().y >= 280.f &&
                 obs[i]->getVehicleSprite().getPosition().y < 600.f)
            obs[i]->movement(1);
    }
}

void Game::updateKeyStates()
{
    UP = false;
    DOWN = false;
    LEFT = false;
    RIGHT = false;
    BACKSPACE = false;
    SPACE = false;
    ESCAPE = false;
    ENTER = false;

    upReleased = false;
    downReleased = false;
    leftReleased = false;
    rightReleased = false;
    backReleased = false;
    spaceReleased = false;
    escapeReleased = false;
    enterReleased = false;
}

void Game::movementSchemeUpdate()
{
    if(newMovement)
        setNewMove();
    switch(key){
    case 1:
        makeMovement({1, 1, 2});
        break;
    case 2:
        makeMovement({1, 2, 1});
        break;
    case 3:
        makeMovement({1, 2, 2});
        break;
    case 4:
        makeMovement({1, 2, 0});
        break;
    case 5:
        makeMovement({1, 0, 2});
        break;
    case 6:
        makeMovement({1, 0, 0});
        break;
    case 7:
        makeMovement({1, 0, 1});
        break;
    case 8:
        makeMovement({1, 1, 0});
        break;
    case 9:
        makeMovement({2, 1, 0});
        break;
    case 10:
        makeMovement({2, 0, 1});
        break;
    case 11:
        makeMovement({2, 1, 1});
        break;
    case 12:
        makeMovement({2, 2, 1});
        break;
    case 13:
        makeMovement({2, 1, 2});
        break;
    case 14:
        makeMovement({0, 1, 0});
        break;
    case 15:
        makeMovement({0, 0, 1});
        break;
    case 16:
        makeMovement({0, 1, 1});
        break;
    case 17:
        makeMovement({0, 1, 2});
        break;
    case 18:
        makeMovement({0, 2, 1});
        break;
    default:
        std::cout << "Error, bad number of movement" << std::endl;
        break;
    }
}

////////////////////////////////////////////////////////////////////////////

void Game::obstacleRender()
{
    ventana.draw(obs1.getVehicleSprite());
    ventana.draw(obs2.getVehicleSprite());
    ventana.draw(obs3.getVehicleSprite());
}
