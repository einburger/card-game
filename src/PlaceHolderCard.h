#pragma once

#include <string>

#include "Card.h"

using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Mouse;
using sf::Vector2f;

class PlaceHolderCard :
  public Card
{
public:
  Texture card_appearance;
  Sprite card_sprite;
public:
  PlaceHolderCard();
  ~PlaceHolderCard();
  void setLocation( float x, float y );
  Texture getAppearance();
  Sprite getSprite();
  bool checkIfClicked( RenderWindow &window );
  void draw( RenderWindow &window );
};
