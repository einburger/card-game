#pragma once

#include <iostream>

#include "Card.h"

class ResourceCard :
  public Card
{
public:
  float card_x;
  float card_y;
  sf::Texture card_appearance;
  sf::Sprite card_sprite;
public:
  ResourceCard();
  ~ResourceCard();
  void setLocation( float x, float y );
  void playCard( Player *player, std::vector< std::unique_ptr<Room> > &board );
  sf::Texture getAppearance();
  sf::Sprite getSprite();
  float getPositionX();
  float getPositionY();
  bool checkIfClicked( sf::RenderWindow &window );
  void draw( sf::RenderWindow &window );
};
