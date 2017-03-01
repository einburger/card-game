#include "Menu.h"

Menu::Menu()
{
  cursor.setPosition( Vector2f( 0, START_Y - Y_OFFSET ) );
  cursor.setSize( Vector2f( CURSOR_SIZE_X, CURSOR_SIZE_Y ) );
  cursor.setFillColor( CURSOR_COLOR );

  button_vector.push_back( unique_button_ptr(new Button( START_X,
                                                         START_Y,
                                                         "start_button.jpg" ) ) );

  button_vector.push_back( unique_button_ptr(new Button( OPTIONS_X,
                                                         OPTIONS_Y,
                                                         "options_button.jpg" ) ) );

  button_vector.push_back( unique_button_ptr(new Button( QUIT_X,
                                                         QUIT_Y,
                                                         "quit_button.jpg" ) ) );
}

Menu::~Menu()
{
}

void Menu::click( RenderWindow &window, Simulation &sim )
{
  changeCursorColor( window, sim );
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
  return button_vector[ current_button ]->yPos - Y_OFFSET;
}

void Menu::changeCursorColor( RenderWindow &window, Simulation &sim )
{
  if ( Keyboard::isKeyPressed( Keyboard::Return ) )
    {
      cursor.setFillColor( CLICKED_COLOR );
      window.draw( cursor );
      window.display();
      while ( Keyboard::isKeyPressed( Keyboard::Return) )
        {
        }
    }
  cursor.setFillColor( CURSOR_COLOR );
  window.draw( cursor );
  window.display();
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
