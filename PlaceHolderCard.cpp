#include "PlaceHolderCard.h"
#include "ResourcePath.hpp"

PlaceHolderCard::PlaceHolderCard()
{
  if ( !card_appearance.loadFromFile( resourcePath() + "PlaceHolderCard.JPG" ) )
    {
      // error
    }
  card_sprite.setTexture( card_appearance );
  card_sprite.setOrigin( sf::Vector2f( card_sprite.getTexture()->getSize().x * 0.5, card_sprite.getTexture()->getSize().y * 0.5 ) );
}


PlaceHolderCard::~PlaceHolderCard()
{
}

void PlaceHolderCard::playCard( Player *player, std::vector< std::unique_ptr<Room> >& board )
{
}

sf::Texture PlaceHolderCard::getAppearance()
{
  return card_appearance;
}

void PlaceHolderCard::setLocation( float x, float y )
{
  card_x = x;
  card_y = y;
  card_sprite.setPosition( sf::Vector2f( card_x, card_y ) );
  card_sprite.setOrigin( sf::Vector2f( card_sprite.getTexture()->getSize().x * 0.5, card_sprite.getTexture()->getSize().y * 0.5 ) );
}

sf::Sprite PlaceHolderCard::getSprite()
{
  return card_sprite;
}

float PlaceHolderCard::getPositionX()
{
  return card_x;
}

float PlaceHolderCard::getPositionY()
{
  return card_y;
}

bool PlaceHolderCard::checkIfClicked( sf::RenderWindow& window )
{
  return card_sprite.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( window ) ) );
}

void PlaceHolderCard::draw( sf::RenderWindow& window )
{
  window.draw( card_sprite );
}
