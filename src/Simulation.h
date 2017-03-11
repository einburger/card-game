#pragma once

/*STL*/
#include <algorithm>                           // for std::shuffle
#include <chrono>                              // for std::chrono::system_clock
#include <memory>                              // for std::unique_ptr
#include <random>                              // for and std::default_random_engine
#include <vector>

#include <SFML/Graphics.hpp>                   // graphics

/*Other Class Headers*/
#include "Player.h"
#include "Board.h"
#include "ResourceCard.h"
#include "GameObject.h"

using sf::RenderWindow;
using sf::Color;
using std::chrono::system_clock;

typedef std::unique_ptr<Player>                unique_player_ptr;
typedef std::vector< std::unique_ptr<Player> > unique_player_ptr_vector;
typedef std::unique_ptr<Card>                  unique_card_ptr;
typedef std::vector< std::unique_ptr<Card> >   unique_card_ptr_vector;
typedef unsigned int uint;

static const uint                              WINDOW_WIDTH = 800;
static const uint                              WINDOW_HEIGHT = 600;
static const uint                              NUMBER_IN_HAND = 5;
static const uint                              NUMBER_OF_CARDS = 100;
static const uint                              NUMBER_OF_PLAYERS = 3;
static constexpr float                         CARD_WIDTH = 100;
static constexpr float                         CARD_X_OFFSET = 150;
static constexpr float                         CARD_Y = 500;

class Card;
class Board;

class Simulation
{
 private:
    unique_card_ptr_vector         deck;
    uint                           seed;

 public:
    enum GameStates
    {
        MENU = 0,
        GAME = 1,
        OPTIONS = 2,
        PAUSE = 3,
        QUIT = 4
    }                              game_state;
    unique_player_ptr_vector       players;
    uint                           current_player;

 private:
    void shuffleCards();
    void playRound( RenderWindow &window );
    bool nextTurn();

 public:
    Simulation( RenderWindow &window );
    ~Simulation();
    void run( RenderWindow &window );
    void dragObject( RenderWindow &window );
    void snapToContainer( RenderWindow &window );
    void nextPlayer();
};
