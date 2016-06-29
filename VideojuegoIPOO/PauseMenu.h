#ifndef PAUSEMENU_H_INCLUDED
#define PAUSEMENU_H_INCLUDED

class PauseMenu : public Screen
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

    Button resumeB;
    Button restartB;
    Button goToMenuB;
    Button exitB;
};

#endif // PAUSEMENU_H_INCLUDED
