#include "Input.h"
#include "Game.h"

Input::Input() {}

Input *Input::uniqueInput = nullptr;

/////////////////////////////////////////////////////////////////////////////

Input *Input::getInstance()
{
    if (uniqueInput == nullptr)
        uniqueInput = new Input();
    return uniqueInput;
}

/////////////////////////////////////////////////////////////////////////////

void Input::pollEvent()
{
    while (ventana.pollEvent(miEvento)){
        switch (miEvento.type)
        {
        case sf::Event::Closed:
            Game::isPlaying = false;
            break;

        case sf::Event::KeyPressed:
            switchKeysPressed();
            break;

        case sf::Event::KeyReleased:
            switchKeysReleased();
            break;

        case sf::Event::MouseButtonEvent:
            if (miEvento::MouseButtonPressed == sf::Mouse::Left)
                CLICLEFT = true;
            else if (miEvento::MouseButtonReleased == sf::Mouse::Left)
                clicLeftReleased = true;
            break;

        case sf::Event::TextEntered:
            if (miEvento.text.unicode >= 32 && miEvento.text.unicode <= 126)
                namePlayerS.insert(namePlayerS.getSize(),
                                   miEvento.text.unicode);
            else if (miEvento.text.unicode == 8)
                namePlayerS = namePlayerS.substring(0, namePlayerS.getSize() - 1);
            break;

        default:
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////

void Input::switchKeysPressed()
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

    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////

void Input::switchKeysReleased()
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

    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////

void Input::updateMousePosition()
{
    localPosition = sf::Mouse::getPosition(Game::ventana);

    mousePosX = static_cast<float>(localPosition.x);
    mousePosX = static_cast<float>(localPosition.y);
}

/////////////////////////////////////////////////////////////////////////////

void Input::setKeysFalse()
{
    CLICLEFT = false;
    UP = false;
    DOWN = false;
    LEFT = false;
    RIGHT = false;
    BACKSPACE = false;
    SPACE = false;
    ESCAPE = false;

    clicReleased = false;
    upReleased = false;
    downReleased = false;
    leftReleased = false;
    rightReleased = false;
    backReleased = false;
    spaceReleased = false;
    escapeReleased = false;
}
