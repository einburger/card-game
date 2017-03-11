#include "PlaceHolderCard.h"

#ifdef __APPLE__
#include "ResourcePath.hpp"
#endif

PlaceHolderCard::PlaceHolderCard()
{
    std::string image_path;
#ifdef __APPLE__
    image_path = resourcePath() + "PlaceHolderCard.jpg";
#elif _WIN32
    image_path = "PlaceHolderCard.jpg";
#endif

    if ( !card_appearance.loadFromFile( image_path ) )
        {
            // error
        }
    card_sprite.setTexture( card_appearance );
    float x = card_sprite.getTexture()->getSize().x;
    float y = card_sprite.getTexture()->getSize().y;
    card_sprite.setOrigin( Vector2f( x/2, y/2 ) );
}


PlaceHolderCard::~PlaceHolderCard()
{
}

Texture PlaceHolderCard::getAppearance()
{
    return card_appearance;
}

void PlaceHolderCard::setLocation( float x, float y )
{
    card_sprite.setPosition( Vector2f( x, y ) );
}

Sprite PlaceHolderCard::getSprite()
{
    return card_sprite;
}

bool PlaceHolderCard::checkIfClicked( RenderWindow& window )
{
    Vector2f mousePos = Vector2f( Mouse::getPosition( window ) );
    return card_sprite.getGlobalBounds().contains( mousePos );
}

void PlaceHolderCard::changeColor( Color color )
{
    card_sprite.setColor( color );
}

void PlaceHolderCard::draw( RenderWindow& window )
{
    window.draw( card_sprite );
}
