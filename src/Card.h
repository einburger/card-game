#pragma once

#include <memory>  // for std::unique_ptr
#include <vector>

//#include <SFML\Graphics.hpp> // for graphics

#include "GameObject.h"

class Room;
class Player;

class Card : public GameObject
{
public:
  //sf::Sprite card_sprite;
public:
  Card();
  ~Card();
  virtual void setLocation( float x, float y ) = 0;
  virtual void playCard( Player *player, std::vector< std::unique_ptr<Room> > &board ) = 0;
  virtual sf::Texture getAppearance() = 0;
  virtual sf::Sprite getSprite() = 0;
  virtual float getPositionX() = 0;
  virtual float getPositionY() = 0;
  virtual bool checkIfClicked( sf::RenderWindow &window ) = 0;
  virtual void draw( sf::RenderWindow &window ) = 0;
};
