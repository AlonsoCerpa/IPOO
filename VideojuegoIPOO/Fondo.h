#ifndef FONDO_H_INCLUDED
#define FONDO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Fondo
{
public:
    bool loadFondo(const std::string &);
    void setFondoTexture();
    void setFondoPosition(const sf::Vector2f &);
    void moveFondo(const int &);
    sf::Sprite& getFondoSprite();
private:
    int cont{600};
    sf::Sprite fondoSprite;
    sf::Texture fondoTexture;
};


#endif // FONDO_H_INCLUDED
