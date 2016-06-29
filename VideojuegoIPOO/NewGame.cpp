#include "NewGame.h"

NewGame::NewGame()
    : arrObstacle{{&redCar, &policeCar, &truck1, &blackCar,
                   &taxi, &truck2, &motorcycle, &bicycle}},
    arrCarPlayer{{&mainCar}},
    obs{{&obs1, &obs2, &obs3}} {}

/////////////////////////////////////////////////////////////////////////////

void NewGame::iniScreen()
{
    currentButton = 0;
    loseGame = false;
    pauseMenu = false;
    finishMove = true;
    newMovement = true;
    firstObs = nullptr;
    secondObs = nullptr;
    pause = false;

    loadTextures();
    setSpritesTextures();
    setSpritesPosition();
    setButtonsFalse();
}

/////////////////////////////////////////////////////////////////////////////

int NewGame::loadTextures()
{
    if(!soundOnB.loadButtonOff("imagenes/NewGame/soundOnOff.png"))
        return 0;
    if(!soundOnB.loadButtonOn("imagenes/NewGame/soundOnOn.png"))
        return 0;
    if(!soundOffB.loadButtonOff("imagenes/NewGame/soundOffOff.png"))
        return 0;
    if(!soundOffB.loadButtonOn("imagenes/NewGame/soundOffOn.png"))
        return 0;
    if(!pauseB.loadButtonOff("imagenes/NewGame/pauseOff.png"))
        return 0;
    if(!pauseB.loadButtonOn("imagenes/NewGame/pauseOn.png"))
        return 0;
    if(!pauseMenuB.loadButtonOff("imagenes/NewGame/pauseMenuOff.png"))
        return 0;
    if(!pauseMenuB.loadButtonOn("imagenes/NewGame/pauseMenuOn.png"))
        return 0;
    if(!playB.loadButtonOff("imagenes/NewGame/playOff.png"))
        return 0;
    if(!playB.loadButtonOn("imagenes/NewGame/playOn.png"))
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

void NewGame::setSpritesTextures()
{
    pista.setFondoTexture();
    treesL.setFondoTexture();
    treesR.setFondoTexture();

    soundOnB.setButtonTexture();
    soundOffB.setButtonTexture();
    pauseMenuB.setButtonTexture();
    pauseB.setButtonTexture();
    playB.setButtonTexture();

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

/////////////////////////////////////////////////////////////////////////////

void NewGame::setSpritesPosition()
{
    soundOnB.setButtonPosition(sf::Vector2f{610.f, 20.f});
    soundOffB.setButtonPosition(sf::Vector2f{610.f, 20.f});
    pauseMenuB.setButtonPosition(sf::Vector2f{700.f, 20.f});

    pista.setFondoPosition(sf::Vector2f{118.f, 0.f});
    treesL.setFondoPosition(sf::Vector2f{0.f, 0.f});
    treesR.setFondoPosition(sf::Vector2f{681.f, 0.f});

    mainCar.setVehiclePosition(sf::Vector2f(365.f, 460.f));
}

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

void NewGame::updateScreen()
{
    if (pauseMenu)
    {
        pauseMenuScreen.updateButtonStates();
        pauseMenuScreen.setButtonsFalse();
    }

    else if (loseGame)
    {
        loseGameScreen.updateButtonStates();
        loseGameScreen.setButtonsFalse();
    }

    else
    {
        updateButtonStates();

        Obstacle::setVehicleSpeed(0.003f);

        pista.moveFondo(1);
        treesL.moveFondo(2);
        treesR.moveFondo(2);

        if (finishMove){
            key = minInt + (rand() % (int)(maxInt - minInt + 1));
            rand1 = minPos + (rand() % (int)(maxPos - minPos + 1));
            rand2 = minPos + (rand() % (int)(maxPos - minPos + 1));
            rand3 = minPos + (rand() % (int)(maxPos - minPos + 1));
            finishMove = false;
            newMovement = true;
        }
        else
            movementSchemeUpdate();

        if (mainCar.getVehicleBounds().intersects(obs1.getVehicleBounds()) ||
            mainCar.getVehicleBounds().intersects(obs2.getVehicleBounds()) ||
            mainCar.getVehicleBounds().intersects(obs3.getVehicleBounds()))
            loseGame = true;

        setButtonsFalse();
    }
}

/////////////////////////////////////////////////////////////////////////////

void NewGame::renderScreen()
{
    ventana.draw(treesL.getFondoSprite());
    ventana.draw(treesR.getFondoSprite());
    ventana.draw(pista.getFondoSprite());
    ventana.draw(menuB.getButtonSprite());

    if (sound = true)
        ventana.draw(soundOnB.getButtonSprite());
    else
        ventana.draw(soundOffB.getButtonSprite());


    ventana.draw(mainCar.getVehicleSprite());
    if (!finishMove)
        obstacleRender();

    if (pauseMenu)
        pauseMenuScreen.renderScreen();
    else if(loseGame)
        loseGameScreen.renderScreen();
}

/////////////////////////////////////////////////////////////////////////////

void NewGame::updateButtonStates()
{
    if (soundOnB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
    {
        if (sound)
        {
            if (currentButton != 1){
                currentButton = 1;
                buttonSound.play();
            }
            soundOnB.setButtonOver(true);
            if (input->CLICLEFT)
                sound = false;
        }

        else
        {
            if (currentButton != 1){
                currentButton = 1;
                buttonSound.play();
            }
            soundOffB.setButtonOver(true);
            if (input->CLICLEFT)
                sound = true;
        }
    }

    else if (pauseMenuB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
    {
        if (currentButton != 2){
            currentButton = 2;
            buttonSound.play();
        }
        pauseMenuB.setButtonOver(true);
        if (input->CLICLEFT)
            pauseMenu = true;
    }

    else if (pauseB.buttonSprite.getLocalBounds().contains(input->mousePosX, input->mousePosY))
    {
        if (currentButton != 3){
            currentButton = 3;
            buttonSound.play();
        }
        pauseB.setButtonOver(true);
        if (input->CLICLEFT)
            pause = true;
    }

    else
        currentButton = 0;

    soundOnB.updateButton();
    soundOffB.updateButton();
    pauseMenuB.updateButton();
}

/////////////////////////////////////////////////////////////////////////////

void NewGame::setButtonsFalse()
{
    soundOnB.setButtonOver(false);
    soundOffB.setButtonOver(false);
    pauseMenuB.setButtonOver(false);
}

/////////////////////////////////////////////////////////////////////////////

void NewGame::obstacleRender()
{
    ventana.draw(obs1.getVehicleSprite());
    ventana.draw(obs2.getVehicleSprite());
    ventana.draw(obs3.getVehicleSprite());
}

