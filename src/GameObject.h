#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
 public:
    GameObject();
    virtual ~GameObject();
    virtual void draw(sf::RenderWindow &window) = 0;
};
