#pragma once

/* #include <memory> */
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "button.h"
#include "Simulation.h"

using sf::Color;
using sf::Keyboard;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::Vector2f;

typedef std::unique_ptr<button> unique_ptr;
typedef std::vector< std::unique_ptr<button> > unique_ptr_vector;

class button;

class Menu
{
 private:
  int current_button = 0;
  RectangleShape cursor;

 public:
  const Color CURSOR_COLOR         = Color( 100, 100, 100, 150 );
  const Color CLICKED_COLOR        = Color( 255, 255, 100, 100 );
  const float CURSOR_SIZE_X        = 800;
  const float CURSOR_SIZE_Y        = 50;
  const float Y_OFFSET             = 25;

  const float START_X              = 400;
  const float START_Y              = 100;
  const float OPTIONS_X            = 400;
  const float OPTIONS_Y            = 300;
  const float QUIT_X               = 400;
  const float QUIT_Y               = 500;

  unique_ptr_vector button_vector;

  enum Choice
  {
    START = 0,
    OPTIONS = 1,
    QUIT = 2
  } choice;

 private:
  float getButtonOffsetY();

 public:
  Menu();
  ~Menu();
  void click(sf::RenderWindow &window, Simulation &sim);
  void moveCursorDown();
  void moveCursorUp();
  void draw(sf::RenderWindow &window);
};
