#include "Fondo.h"
#include "Vehicle.h"

bool Fondo::loadFondo(const std::string &dir)
{
    return fondoTexture.loadFromFile(dir);
}

void Fondo::setFondoTexture()
{
    fondoSprite.setTexture(fondoTexture);
}

void Fondo::setFondoPosition(const sf::Vector2f &vec)
{
    fondoSprite.setPosition(vec);
}

void Fondo::moveFondo(const int &pos)
{
    if (pos == 1){
        if (cont < 0)
            cont = 600;
        fondoSprite.setTextureRect(sf::IntRect{0, cont, 565, 600});
        cont -= Obstacle::speedVehicle;
    }
    else if (pos == 2){
        if (cont < 0)
            cont = 600;
        fondoSprite.setTextureRect(sf::IntRect{0, cont, 118, 600});
        cont -= Obstacle::speedVehicle;
    }
}

sf::Sprite& Fondo::getFondoSprite()
{
    return fondoSprite;
}
