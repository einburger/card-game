#include "Board.h"
#include "ResourcePath.hpp"

Board::Board()
{
  Texture block;
  if ( !block.loadFromFile( resourcePath() + "grid.jpg" ) )
    {
      // error
    }
  for ( int i = 0; i < NUMBER_OF_BUTTONS; i++ )
    {
      button_ptr_vec col;
      for ( int j = 0; j < NUMBER_OF_BUTTONS; j++ )
        {
          col.push_back( button_ptr( new button( i, j ) ) );
        }
      buttons.push_back( std::move( col ) );
    }
}

Board::~Board()
{
}

void Board::draw( RenderWindow &window )
{
  for ( int i = 0; i < NUMBER_OF_BUTTONS; i++ )
    {
      for ( int j = 0; j < NUMBER_OF_BUTTONS; j++ )
        {
          window.draw( buttons[ j ][ i ]->sprite );
        }
    }
}

bool Board::checkIfClicked( RenderWindow &window )
{
  return linearSearch( window );
}

bool Board::linearSearch( RenderWindow &window )
{
  Sprite sprite;
  Vector2f mousePos;
  for ( int i = 0; i < NUMBER_OF_BUTTONS; ++i )
    {
      for ( int j = 0; j < NUMBER_OF_BUTTONS; ++j )
        {
          sprite = buttons[ j ][ i ]->sprite;
          mousePos = Vector2f( Mouse::getPosition( window ) );
          if ( sprite.getGlobalBounds().contains( mousePos ) )
            {
              button_x = j;
              button_y = i;
              clicked_sprite = buttons[ j ][ i ]->sprite;
              return true;
            }
        }
    }
  return false;
}
