#include "Button.h"

#ifdef __APPLE__
#include "ResourcePath.hpp"
#endif

Button::Button( float xPos, float yPos, std::string file_path )
{
    std::string image_path;

#ifdef __APPLE__
    image_path = resourcePath() + file_path;
#elif _WIN32
    image_path = file_path;
#endif

    if ( !texture.loadFromFile( image_path ) )
        {
            // error
        }
    sprite.setTexture( texture );
    sprite.setColor( BUTTON_COLOR );

    float x = sprite.getTexture()->getSize().x;
    float y = sprite.getTexture()->getSize().y;
    sprite.setOrigin( Vector2f( x/2, y/2 ) );

    updateLocation( xPos, yPos );
}

Button::~Button()
{
}

void Button::setLocation( float xIn, float yIn )
{
    xPos = xIn * 100 + 50;
    yPos = yIn * 100 - 500;
    sprite.setPosition( xPos, yPos );
}

void Button::updateLocation( float xIn, float yIn )
{
    xPos = xIn;
    yPos = yIn;
    sprite.setPosition( xPos, yPos );
}

void Button::draw( RenderWindow &window )
{
    window.draw( sprite );
}

bool Button::checkIfClicked( RenderWindow &window )
{
    Vector2f mousePos = Vector2f( Mouse::getPosition( window ) );
    return sprite.getGlobalBounds().contains( mousePos );
}
