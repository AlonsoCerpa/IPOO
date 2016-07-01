#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <vector>

using std::string;
using std::vector;

#include <SFML/Graphics.hpp>

class Vehicle
{
public:
    bool loadVehicle(const string &);
    void setVehicleTexture();
    void setVehiclePosition(const sf::Vector2f &);
    sf::FloatRect getVehicleBounds() const;
    sf::Sprite getVehicleSprite() const;
    virtual void movement(const int &) = 0;
protected:
    sf::Texture vehicleTexture;
    sf::Sprite vehicleSprite;
    sf::Vector2f position{0.f, 0.f};
    float width, height;
};

//////////////////////////////////////////////////////////////////

class CarPlayer : public Vehicle
{
public:
    virtual void movement(const int &);
    float speedVehicle{100.f};
};

//////////////////////////////////////////////////////////////////

class Obstacle : public Vehicle
{
    friend class Fondo;
public:
    Obstacle &operator=(const Obstacle &);
    virtual void movement(const int &);
    static void setVehicleSpeed(const float &);
    static float getSpeedVehicle();
    static float speedVehicle;
//private:

};

#endif // VEHICLE_H_INCLUDED
