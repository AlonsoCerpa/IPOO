#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <iostream>

using std::string;

#include <SFML/Graphics.hpp>

class Car                    //Abstract class
{
public:
    bool loadCar(const string &);
    void setCarTexture();
    void setCarPosition(const sf::Vector2f &);
    sf::FloatRect getCarBounds() const;
    sf::Sprite getCarSprite() const;
    virtual void movement(const int &dir = 0) = 0;
protected:
    sf::Texture carTexture;
    sf::Sprite carSprite;
    sf::RenderWindow ventana;
    sf::Vector2f position{0.f, 0.f};
    float speedCar{4.f};
};

//////////////////////////////////////////////////////////////////

class CarPlayer : public Car
{
public:
    virtual void movement(const int &);
};

//////////////////////////////////////////////////////////////////

class CarObstacle : public Car
{
public:
    virtual void movement(const int &);
};

#endif // CAR_H_INCLUDED
