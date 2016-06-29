#include "Vehicle.h"
#include <stdexcept>

//Vehicle, abstract class

bool Vehicle::loadVehicle(const string &dir)
{
    return vehicleTexture.loadFromFile(dir);
}

void Vehicle::setVehicleTexture(){
    width = vehicleTexture.getSize().x;
    height = vehicleTexture.getSize().y;
    vehicleSprite.setTexture(vehicleTexture);
}

void Vehicle::setVehiclePosition(const sf::Vector2f &vec)
{
    vehicleSprite.setPosition(vec);
}

sf::FloatRect Vehicle::getVehicleBounds() const
{
    return vehicleSprite.getGlobalBounds();
}

sf::Sprite Vehicle::getVehicleSprite() const
{
    return vehicleSprite;
}

////////////////////////////////////////////////////////////////////////////////////
//CarPlayer class

void CarPlayer::movement(const int &dir)
{
    position = {0.f, 0.f};
    if (dir == 1){
        position.y -= 1.f * speedVehicle;
    }
    else if (dir == 2){
        position.y += 1.f * speedVehicle;
    }
    else if (dir == 3){
        position.x -= 1.f * speedVehicle;
    }
    else if (dir == 4){
        position.x += 1.f * speedVehicle;
    }

    vehicleSprite.move(position);
    if(vehicleSprite.getPosition().y > 599.f - height)
        vehicleSprite.setPosition({vehicleSprite.getPosition().x, 599.f - height});
}

////////////////////////////////////////////////////////////////////////////////////
//Obstacle class

Obstacle &Obstacle::operator=(const Obstacle &obs)
{
    this->vehicleTexture = obs.vehicleTexture;
    this->vehicleSprite = obs.vehicleSprite;
    this->position = obs.position;
    this->width = obs.width;
    this->height = obs.height;
    return *this;
}

float Obstacle::speedVehicle = 3.f;

void Obstacle::movement(const int &dir)
{
    position = {0.f, 0.f};
    if(dir == 1){
        position.y += 1.f * speedVehicle;
    }
    vehicleSprite.move(position);
}

void Obstacle::setVehicleSpeed(const float &addSpeed)
{
    speedVehicle += addSpeed;
}

float Obstacle::getSpeedVehicle()
{
    return speedVehicle;
}
