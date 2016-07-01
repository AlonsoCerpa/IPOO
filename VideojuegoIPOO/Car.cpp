#include "Car.h"

//Car class

bool Car::loadCar(const string &dir)
{
    return carTexture.loadFromFile(dir);
}

void Car::setCarTexture(){
    carSprite.setTexture(carTexture);
}

void Car::setCarPosition(const sf::Vector2f &vec)
{
    carSprite.setPosition(vec);
}

sf::FloatRect Car::getCarBounds() const
{
    return carSprite.getGlobalBounds();
}

sf::Sprite Car::getCarSprite() const
{
    return carSprite;
}

//CarPlayer class

void CarPlayer::movement(const int &dir)
{
    position = {0.f, 0.f};
    if (dir == 1){
        position.y -= 1.f * speedCar;
    }
    else if (dir == 2){
        position.y += 1.f * speedCar;
    }
    else if (dir == 3){
        position.x -= 1.f * speedCar;
    }
    else if (dir == 4){
        position.x += 1.f * speedCar;
    }

    carSprite.move(position);
}

//CarObstacle class

void CarObstacle::movement(const int &dir)
{
}


