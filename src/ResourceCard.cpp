#include "ResourceCard.h"

#ifdef __APPLE__
#include "ResourcePath.hpp"
#endif

ResourceCard::ResourceCard()
{
    std::string image_path;

#ifdef __APPLE__
    image_path = resourcePath() + "ResourceCard.jpg";
#elif _WIN32
    image_path = "ResourceCard.jpg";
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

ResourceCard::~ResourceCard()
{
}

Texture ResourceCard::getAppearance()
{
    return card_appearance;
}

void ResourceCard::setLocation( float x, float y )
{
    card_sprite.setPosition( Vector2f( x, y ) );
}

Sprite ResourceCard::getSprite()
{
    return card_sprite;
}

void ResourceCard::changeColor( Color color )
{
    card_sprite.setColor( color );
}

bool ResourceCard::checkIfClicked( RenderWindow &window )
{
    Vector2f mousePos = Vector2f( Mouse::getPosition( window ) );
    return card_sprite.getGlobalBounds().contains( mousePos );
}

void ResourceCard::draw( RenderWindow &window )
{
    if (!checkIfClicked( window ))
        {
            card_sprite.setColor(sf::Color(255, 255, 255));
        }
    window.draw( card_sprite );
}
