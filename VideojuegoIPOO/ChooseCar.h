#ifndef CHOOSECAR_H_INCLUDED
#define CHOOSECAR_H_INCLUDED

class ChooseCar : public Screen
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
};

#endif // CHOOSECAR_H_INCLUDED
