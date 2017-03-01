#include "Menu.h"

Menu::Menu()
{
  cursor.setSize( Vector2f( CURSOR_SIZE_X, CURSOR_SIZE_Y ) );
  cursor.setFillColor( CURSOR_COLOR );

  button_vector.push_back( unique_ptr( new button( "start_button.jpg" ) ) );
  button_vector[ START ]->updateLocation( START_X, START_Y );

  button_vector.push_back( unique_ptr(new button( "options_button.jpg" ) ) );
  button_vector[ OPTIONS ]->updateLocation( OPTIONS_X, OPTIONS_Y );

  button_vector.push_back( unique_ptr(new button( "quit_button.jpg" ) ) );
  button_vector[ QUIT ]->updateLocation( QUIT_X, QUIT_Y );

  cursor.setPosition( Vector2f( 0, START_Y - Y_OFFSET ) );
}

Menu::~Menu()
{
}

void Menu::click( RenderWindow &window, Simulation &sim )
{
  while ( Keyboard::isKeyPressed( Keyboard::Return ) )
  {
    cursor.setFillColor( CLICKED_COLOR );
    window.draw( cursor );
    window.display();
  }
  cursor.setFillColor( CURSOR_COLOR );

  window.draw( cursor );
  window.display();
  switch ( current_button )
    {
    case START:
      {
    sim.game_state = sim.GAME;
        break;
      }
    case OPTIONS:
      {
        break;
      }
    case QUIT:
      {
    sim.game_state = sim.QUIT;
        break;
      }
    }
}

float Menu::getButtonOffsetY()
{
  return button_vector[ current_button ]->y - Y_OFFSET;
}

void Menu::moveCursorDown()
{
  if ( current_button < QUIT )
    {
      current_button++;
    }
  else
    {
      current_button = START;
    }
  cursor.setPosition( Vector2f( 0, getButtonOffsetY() ) );
}

void Menu::moveCursorUp()
{
  if ( current_button > START )
    {
      current_button--;
    }
  else
    {
      current_button = QUIT;
    }
  cursor.setPosition( Vector2f( 0, getButtonOffsetY() ) );
}

void Menu::draw( RenderWindow &window )
{
  for (const auto &i : button_vector )
    {
      i->draw( window );
    }
  window.draw( cursor );
}
