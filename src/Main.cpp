#include "Simulation.h"
#include "Menu.h"

using sf::VideoMode;
using sf::RenderWindow;
using sf::Event;
using sf::Keyboard;
using sf::Mouse;

void updateWindow(RenderWindow &window, Menu &menu )
{
  window.clear( Color::Red );
  menu.draw( window );
  window.display();
}

int main()
{
  // use new standard for random ( normal distributions )
  srand( ( int ) time( nullptr ) );

  /*create the window*/
  RenderWindow window( VideoMode( WINDOW_WIDTH,
                                  WINDOW_HEIGHT ),
                       "Card Game" );

  Simulation sim( window );
  Menu menu;

  while ( window.isOpen() )
    {
      switch ( sim.game_state )
        {
        case sim.MENU:
          {
            Event event;
            while ( window.pollEvent( event ) )
              {
                switch ( event.type )
                  {
                  case Event::Closed:
                    window.close();
                    break;

                  case Event::MouseButtonPressed:
                    break;

                  case Event::KeyPressed:
                    {
                      switch ( event.key.code )
                        {
                        case ( Keyboard::Up ):
                          menu.moveCursorUp();
                          break;

                        case ( Keyboard::Down ):
                          menu.moveCursorDown();
                          break;

                        case ( Keyboard::Return ):
                          menu.click( window, sim );
                          updateWindow( window, menu );
                          break;
                        }
                      break;
                    }

                  default:
                    break;
                  }
                break;
              }
            updateWindow( window, menu );
            break;
          }

        case sim.GAME:
          {
            Event event;
            while ( window.pollEvent( event ) )
              {
                switch ( event.type )
                  {
                  case Event::Closed:
                    {
                      window.close();
                      break;
                    }

                  case Event::MouseButtonPressed:
                    {
                      sim.dragObject( window );
                    }

                  case Event::MouseButtonReleased:
                    {
                      if ( event.key.code == Mouse::Left )
                        {
                          sim.snapToContainer( window );
                        }
                      break;
                    }

                  case Event::KeyPressed:
                    {
                      if ( event.key.code == Keyboard::Return )
                        {
                          sim.nextPlayer();
                        }
                      if ( event.key.code == Keyboard::Space )
                        {
                          sim.game_state = sim.PAUSE;
                        }
                      break;
                    }

                  default:
                    {
                      break;
                    }
                  }
              }
            sim.run( window );
            break;
          }

        case sim.OPTIONS:
          {
            break;
          }

        case sim.PAUSE:
          {
            window.display();
            Event event;
            while ( window.pollEvent( event ) )
              {
                switch ( event.type )
                  {
                  case Event::KeyPressed:
                    if ( event.key.code == Keyboard::Space )
                      {
                        sim.game_state = sim.GAME;
                      }
                    break;

                  case Event::Closed:
                    window.close();
                    break;

                  default:
                    break;
                  }
              }
            break;
          }
        case sim.QUIT:
          {
            window.close();
            break;
          }
        }
    }
  return 0;
}
