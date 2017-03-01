#pragma once
#include "Simulation.h"
#include "GameObject.h"

class button : public GameObject
{

public:
  float x;
  float y;
  sf::Sprite sprite;
  sf::Sprite clicked_sprite;
  sf::Texture texture;
public:
  button( float x, float y );
  button( std::string filename );
  ~button();
  void setLocation( float x, float y );
  void updateLocation( float xIn, float yIn );
  void draw( sf::RenderWindow &window );
  bool checkIfClicked( sf::RenderWindow &window );
};
