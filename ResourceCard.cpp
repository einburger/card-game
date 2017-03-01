#include "ResourceCard.h"
#include "ResourcePath.hpp"

ResourceCard::ResourceCard()
{
  if ( !card_appearance.loadFromFile( resourcePath() + "ResourceCard.jpg" ) )
  {
    // error
  }
  card_sprite.setTexture( card_appearance );
  card_sprite.setOrigin( sf::Vector2f( card_sprite.getTexture()->getSize().x * 0.5, card_sprite.getTexture()->getSize().y * 0.5 ) );
}

ResourceCard::~ResourceCard()
{
}

void ResourceCard::playCard( Player *player, std::vector< std::unique_ptr<Room> > &board )
{
}

sf::Texture ResourceCard::getAppearance()
{
  return card_appearance;
}

void ResourceCard::setLocation( float x, float y )
{
  card_x = x;
  card_y = y;
  card_sprite.setPosition( sf::Vector2f( card_x, card_y ) );
}

sf::Sprite ResourceCard::getSprite()
{
  return card_sprite;
}

float ResourceCard::getPositionX()
{
  return card_x;
}

float ResourceCard::getPositionY()
{
  return card_y;
}

bool ResourceCard::checkIfClicked( sf::RenderWindow &window )
{
  return ( card_sprite.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( window ) ) ) );
}

void ResourceCard::draw( sf::RenderWindow &window )
{
  window.draw( card_sprite );
}
