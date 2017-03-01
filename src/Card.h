#pragma once

#include <vector>

#include "GameObject.h"

using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;

class Player;

class Card : public GameObject
{
public:
  Card();
  ~Card();
  virtual void setLocation( float x, float y ) = 0;
  virtual Texture getAppearance() = 0;
  virtual Sprite getSprite() = 0;
  virtual bool checkIfClicked( RenderWindow &window ) = 0;
  virtual void draw( RenderWindow &window ) = 0;
};
