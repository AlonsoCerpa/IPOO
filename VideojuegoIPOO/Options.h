#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

class Options : public Screen
{
public:
    virtual void iniScreen();
    virtual void updateScreen();
    virtual void renderScreen();

private:
    virtual int loadTextures();
    virtual void setSpritesTextures();
    virtual void setSpritesPosition();
    virtual void updateButtonStates();
    virtual void setButtonsFalse();
    void iniText();

    Button setDifficultyB;
    Button chooseMapB;
    Button chooseCarB;
    Button getBackB;
    Button easyB;
    Button mediumB;
    Button hardB;
    bool showDifficulties;
    sf::Texture titleOptionsT;
    sf::Sprite titleOptionsS;
    sf::Texture backgroundT;
    sf::Sprite backgroundS;
};

#endif // OPTIONS_H_INCLUDED
