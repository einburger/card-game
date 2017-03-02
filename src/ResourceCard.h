#pragma once

#include <string>

#include "Card.h"

using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Mouse;
using sf::Vector2f;
using sf::Color;

class ResourceCard :
  public Card
{
public:
  Texture card_appearance;
  Sprite card_sprite;
public:
  ResourceCard();
  ~ResourceCard();
  void setLocation( float x, float y );
  Texture getAppearance();
  Sprite getSprite();
  void changeColor( Color color );
  bool checkIfClicked( RenderWindow &window );
  void draw( RenderWindow &window );
};
