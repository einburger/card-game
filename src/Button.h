#pragma once

#include <string>

#include "Simulation.h"
#include "GameObject.h"

using sf::Sprite;
using sf::Texture;
using sf::RenderWindow;
using sf::Color;
using sf::Vector2f;
using sf::Mouse;

static const float                BUTTON_SPACING  = 100;
static const float                BUTTON_X_OFFSET = 200;
static const float                BUTTON_Y_OFFSET = 50;

class Button : public GameObject
{
public:
  const Color                     BUTTON_COLOR = Color( 100,
                                                        100,
                                                        100 );
  float                           xPos;
  float                           yPos;
  Sprite                          sprite;
  Sprite                          clicked_sprite;
  Texture                         texture;
public:
  Button( float xPos, float yPos, std::string file_path );
  ~Button();
  void setLocation( float x, float y );
  void updateLocation( float xIn, float yIn );
  void draw( RenderWindow &window );
  bool checkIfClicked( RenderWindow &window );
};
