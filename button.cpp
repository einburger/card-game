#include "button.h"
#include "ResourcePath.hpp"

button::button( float x, float y )
{
  if ( !texture.loadFromFile( resourcePath() + "grid.jpg" ) )
  {
    // error
  }
  sprite.setTexture( texture );
  sprite.setColor( sf::Color( 100, 100, 100 ) );
  sprite.setOrigin( sf::Vector2f( sprite.getTexture()->getSize().x * 0.5,
                                sprite.getTexture()->getSize().y * 0.5 ) );
  setLocation( x, y );
}

button::button( std::string filename )
{
    if ( !texture.loadFromFile( resourcePath() + filename ) )
    {
      // error
    }
    sprite.setTexture( texture );
    sprite.setColor( sf::Color( 100, 100, 100 ) );
    sprite.setOrigin( sf::Vector2f( sprite.getTexture()->getSize().x * 0.5,
      sprite.getTexture()->getSize().y * 0.5 ) );
}

button::~button()
{
}

void button::setLocation( float xIn, float yIn )
{
  x = xIn * 100 + 50;
  y = yIn * 100 - 500;
  sprite.setPosition( x, y );
}

void button::updateLocation( float xIn, float yIn )
{
  x = xIn;
  y = yIn;
  sprite.setPosition( x, y );
}

void button::draw( sf::RenderWindow &window )
{
  window.draw( sprite );
}

bool button::checkIfClicked( sf::RenderWindow &window )
{
  return sprite.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( window ) ) );
}
