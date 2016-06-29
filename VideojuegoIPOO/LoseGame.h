#ifndef LOSEGAME_H_INCLUDED
#define LOSEGAME_H_INCLUDED

class LoseGame : public Screen
{
public:
    LoseGame();
    virtual void iniScreen();
    virtual void updateScreen();
    virtual void renderScreen();

    bool enterScore;
private:
    virtual int loadTextures();
    virtual void setSpritesTextures();
    virtual void setSpritesPosition();
    virtual void updateButtonStates();
    virtual void setButtonsFalse();

    void iniText();

    sf::Text enterName;
    sf::Texture submitScoreTitleT;
    sf::Sprite submitScoreTitleS;
    Button enterB;
    Button topPlayersB;
    Button newGameB;
    Button backToMenuB;
    sf::RectangleShape textBox;
};

#endif // LOSEGAME_H_INCLUDED
