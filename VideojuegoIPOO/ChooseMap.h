#ifndef CHOOSEMAP_H_INCLUDED
#define CHOOSEMAP_H_INCLUDED

class ChooseMap : public Screen
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

#endif // CHOOSEMAP_H_INCLUDED
