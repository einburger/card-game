#pragma once

#include <memory> //for std::unique_ptr
#include <vector>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameObject.h"

using sf::Texture;
using sf::RenderWindow;
using sf::Sprite;

class Button;

typedef std::unique_ptr<Button>                button_ptr;
typedef std::vector<button_ptr>                button_ptr_vec;
typedef std::vector<button_ptr_vec>            button_ptr_2d_vec;

class Board : public GameObject
{
 public:
  const int                                    NUMBER_OF_BUTTONS = 4;
  button_ptr_2d_vec                            buttons;
  Sprite                                       clicked_sprite;
  float                                        button_x;
  float                                        button_y;

 private:
  bool linearSearch( RenderWindow &window );

 public:
  Board();
  ~Board();
  void draw(RenderWindow &window);
  bool checkIfClicked( RenderWindow &window );
};
