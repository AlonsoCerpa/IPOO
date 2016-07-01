#include "Game.h"
#include <iostream>
#include <random>
#include <SFML/Audio.hpp>

Game *Game::uniqueGame = nullptr;

///////////////////////////////////////////////////////////////////////////////

Game *Game::getInstance()
{
    if (uniqueGame == nullptr)
        uniqueGame = new Game();
    return uniqueGame;
}

Game::Game() : ventana{sf::VideoMode{800, 600}, "Videojuego de carros"},
    arrObstacle{{&redCar, &policeCar, &truck1, &blackCar,
                 &taxi, &truck2, &motorcycle, &bicycle}},
    arrCarPlayer{{&mainCar}},
    obs{{&obs1, &obs2, &obs3}}
    {

    }

///////////////////////////////////////////////////////////////////////////////

int Game::inicializar(){

    topPlayersFile.open("topPlayers.txt");
    for (int i = 0; i <= 4; ++i)
    {
        topPlayersFile.getline(arrChar, 24);
        inputAux = string{arrChar};

        posRead = static_cast<int>(inputAux[0]) - 48;
        nameRead = inputAux.substr(2, 16);
        scoreRead = std::stoi(inputAux.substr(19, 4));

        arrPly.arrPtrPlayers.push_back(new PlayerScore{posRead, nameRead, scoreRead});
        std::cout << arrPly.arrPtrPlayers[i]->getInfo();
    }


    score = 0;
    ventana.setFramerateLimit(60);
    ventana.setVerticalSyncEnabled(false);

    timeFloat = clock.getElapsedTime().asSeconds();
    timeInt = static_cast<int>(timeFloat);

    localPosition = sf::Mouse::getPosition(ventana);

    /*
    text.setFont(font);
    text.setString("exitB");
    text.setCharacterSize(150);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f{70.f, 20.f});
*/
    namePlayerT.setFont(font);
    namePlayerT.setCharacterSize(40);
    namePlayerT.setColor(sf::Color::Red);
    namePlayerT.setStyle(sf::Text::Bold);
    namePlayerT.setPosition(sf::Vector2f{240.f, 20.f});

    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setColor(sf::Color::Red);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(sf::Vector2f{610.f, 20.f});

    std::srand(std::time(0));

    if(!loadSounds())
        return 1;
    if(!loadImages())
        return 1;

    setSounds();
    setTextures();
    iniMusicNoEnd.play();

    menu.setScreenPosition(sf::Vector2f{195.f, 0.f});
    fondoMenu.setScreenPosition(sf::Vector2f{195.f, 102.f});
    options.setScreenPosition(sf::Vector2f(195.f, 0.f));
    topPlayers.setScreenPosition(sf::Vector2f(195.f, 0.f));
    credits.setScreenPosition(sf::Vector2f(195.f, 0.f));

    newGameB.setScreenPosition(sf::Vector2f{195.f, 200.f});
    optionsB.setScreenPosition(sf::Vector2f{195.f, 280.f});
    topPlayersB.setScreenPosition(sf::Vector2f{195.f, 360.f});
    creditsB.setScreenPosition(sf::Vector2f{195.f, 440.f});
    exitB.setScreenPosition(sf::Vector2f{195.f, 520.f});

    pista.setFondoPosition(sf::Vector2f{118.f, 0.f});
    treesL.setFondoPosition(sf::Vector2f{0.f, 0.f});
    treesR.setFondoPosition(sf::Vector2f{681.f, 0.f});

    mainCar.setVehiclePosition(sf::Vector2f(365.f, 463.f));

    return 0;
}

/////////////////////////////////////////////////////////////////////////////

void Game::eventos(){

    while (ventana.pollEvent(miEvento)){
        switch (miEvento.type)
        {
        case sf::Event::Closed:
            isPlaying = false;
            break;

        case sf::Event::KeyPressed:
            switchKeyPressed();
            break;

        case sf::Event::KeyReleased:
            switchKeyReleased();
            break;

        case sf::Event::TextEntered:
            if (topPlayersB.buttonPressed())
            {
                if (miEvento.text.unicode >= 32 && miEvento.text.unicode <= 126 && numCharEnter <= 15)
                {
                    namePlayerS.insert(namePlayerS.getSize(),
                                       miEvento.text.unicode);
                    ++numCharEnter;
                }
                else if (miEvento.text.unicode == 8)
                {
                    namePlayerS = namePlayerS.substring(0, namePlayerS.getSize() - 1);
                    --numCharEnter;
                }
            }
            break;

        default:
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////

void Game::update(){

    if (enterReleased)
    {
        //topPlayersFile.open("topPlayers.txt");

        aux = namePlayerS.toAnsiString();
        int sizeAux = aux.size();
        for (int i = 0; i < 16 - sizeAux; ++i)
            aux.push_back(' ');
        arrPly.insertPlayer(new PlayerScore{aux, score});
        for (unsigned i = 0; i <= 4; ++i)
        {
            std::cout << (arrPly.getPlayer(i))->getInfo();
            topPlayersFile << (arrPly.getPlayer(i))->getInfo();
        }
        //topPlayersFile.close();
    }

    localPosition = sf::Mouse::getPosition(ventana);
    posX = static_cast<float>(localPosition.x);
    posY = static_cast<float>(localPosition.y);

    timeFloat = clock.getElapsedTime().asSeconds();
    timeInt = static_cast<int>(timeFloat);
    //std::cout << timeFloat << std::endl;

    if(menu.ScreenIsOpen())
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
        ++score;
        scoreString = std::to_string(score/20);
        scoreText.setString(scoreString);
        if(numPitch < 1)
            numPitch += 0.0002;
        //std::cout << numPitch << std::endl;

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

        Obstacle::setVehicleSpeed(0.003f);

        pista.moveFondo(1);
        treesL.moveFondo(2);
        treesR.moveFondo(2);

        //Movement
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

        if (mainCar.getVehicleBounds().intersects(obs1.getVehicleBounds()))
            isPlaying = false;
        if (mainCar.getVehicleBounds().intersects(obs2.getVehicleBounds()))
            isPlaying = false;
        if (mainCar.getVehicleBounds().intersects(obs3.getVehicleBounds()))
            isPlaying = false;
    }

    else if(topPlayersB.buttonPressed())
    {
        namePlayerT.setString(namePlayerS);
    }
    updateKeyStates();
}

/////////////////////////////////////////////////////////////////////////////

void Game::render(){
    ventana.clear();
    if(menu.ScreenIsOpen()){

        //ventana.draw(text);
        ventana.draw(fondoMenu.getScreenSprite());
        ventana.draw(menu.getScreenSprite());

        ventana.draw(newGameB.ScreenSprite);
        ventana.draw(optionsB.ScreenSprite);
        ventana.draw(topPlayersB.ScreenSprite);
        ventana.draw(creditsB.ScreenSprite);
        ventana.draw(exitB.ScreenSprite);
    }

    else if(optionsB.buttonPressed())
        ventana.draw(options.getScreenSprite());

    else if(topPlayersB.buttonPressed()){
        ventana.draw(topPlayers.getScreenSprite());
        ventana.draw(namePlayerT);
    }

    else if(creditsB.buttonPressed())
        ventana.draw(credits.getScreenSprite());

    else if (newGameB.buttonPressed()){
        ventana.draw(treesL.getFondoSprite());
        ventana.draw(treesR.getFondoSprite());
        ventana.draw(pista.getFondoSprite());
        ventana.draw(scoreText);

        ventana.draw(mainCar.getVehicleSprite());
        if (!finishMove)
            obstacleRender();
    }
    ventana.display();
}

/////////////////////////////////////////////////////////////////////////////

void Game::cleared(){
    ventana.close();
}

/////////////////////////////////////////////////////////////////////////////

void Game::run(){
    inicializar();
    while(isPlaying){
        eventos();
        update();
        render();
    }
    topPlayersFile.close();
    cleared();
}







