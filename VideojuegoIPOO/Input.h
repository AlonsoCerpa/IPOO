#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <SFML/Graphics.hpp>

//Singleton, design pattern

class Input
{
public:
    static Input *getInstance();

    void pollEvent();
    void switchKeysPressed();
    void switchKeysReleased();
    void updateMousePosition();
    void setKeysFalse();

    sf::Event miEvento;
    sf::Vector2i localPosition;
    float mousePosX, mousePosY;

    bool CLICLEFT{false};
    bool UP{false}, DOWN{false}, LEFT{false}, RIGHT{false};
    bool BACKSPACE{false}, SPACE{false}, ESCAPE{false};

    bool clicLeftReleased{false};
    bool upReleased{false}, downReleased{false};
    bool leftReleased{false}, rightReleased{false};
    bool backReleased{false}, spaceReleased{false};
    bool escapeReleased{false};

    bool upDone{false}, downDone{false}, leftDone{false};
    bool rightDone{false};

    bool press{false};
    bool release{false};

private:
    Input();
    static Input *uniqueInput;
};

#endif // INPUT_H_INCLUDED
