#pragma once

#include <string>
#include <vector>
#include <algorithm>                       // for std::swap

#include "Simulation.h"
#include "GameObject.h"
#include "PlaceHolderCard.h"

using sf::RenderWindow;
using sf::RectangleShape;
using sf::Mouse;
using sf::Vector2f;
using sf::Color;
using sf::Text;
using sf::Font;

class Board;

typedef std::vector< std::unique_ptr<Card> > unique_card_ptr_vector;
typedef std::unique_ptr<Board>               unique_board_ptr;
typedef std::unique_ptr<Card>                unique_card_ptr;

class Player : public GameObject
{
 private:
  bool has_won;

 public:
  unique_board_ptr       game_board;
  unique_card_ptr_vector current_hand;
  unique_card_ptr_vector card_place_holder;
  int                    player_id;

 private:
  void setCardAtBack( int card_index );

 public:
  Player();
  ~Player();
  float getMouseX( RenderWindow &window );
  float getMouseY( RenderWindow &window );
  bool isWinner();
  void drawCard( unique_card_ptr &card );
  void dragCard( RenderWindow &window );
  void dragSnapBlock( RenderWindow &window );
  void snapObjects( RenderWindow &window );
  void draw( RenderWindow &window );
};
