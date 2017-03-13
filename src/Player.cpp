#include "Player.h"
#include "resourcePath.hpp"

Player::Player() : has_won( false )
{
    game_board.reset( new Board() );
    card_place_holder.reserve( NUMBER_IN_HAND );
    for ( int i = 0; i < NUMBER_IN_HAND; ++i )
        {
            card_place_holder.push_back( unique_card_ptr( new PlaceHolderCard() ) );
            card_place_holder[ i ]->setLocation( ( i * CARD_WIDTH ) +
                                                 CARD_X_OFFSET,
                                                 CARD_Y );
        }
}

Player::~Player()
{
}

float Player::getMouseX( RenderWindow &window )
{
    return Mouse::getPosition( window ).x;
}

float Player::getMouseY( RenderWindow &window )
{
    return Mouse::getPosition( window ).y;
}

bool Player::isWinner()
{
    return has_won;
}

void Player::setCardAtBack( int card_index )
{
    if ( card_index + 1 > current_hand.size() - 1 )
        {
            return;
        }
    int i = card_index + 1;
    for ( ; i < current_hand.size(); ++i )
        {
            std::swap( current_hand[ i - 1 ], current_hand[ i ] );
        }
}

void Player::drawCard( unique_card_ptr &card )
{
    current_hand.push_back( std::move( card ) );
}

void Player::dragCard( RenderWindow &window )
{
    /* Since cards get rendered back to front and the most
       recent selected card gets pushed to the back we must
       make sure that when the mouse is in multiple card
       collision zones the topmost cards in this intersection
       is selected, thus we iterate in reverse ( front to back )
       instead of forward ( back to front ) */
    for ( int i = NUMBER_IN_HAND - 1; i >= 0; --i )
        {
            if ( current_hand[ i ]->checkIfClicked( window ) &&
                 Mouse::isButtonPressed( Mouse::Left ) )
                {
                    setCardAtBack( i );
                    while ( Mouse::isButtonPressed( Mouse::Left ) )
                        {
                            // set card to follow mouse if mouse is down
                            current_hand.back()->setLocation( getMouseX( window ),
                                                              getMouseY( window ) );
                            draw( window );
                            window.display();
                        }
                    return;
                }
        }
}

/* need better method */
void Player::dragCardStack( RenderWindow &window )
{
    float xPos, yPos;
    for ( int i = NUMBER_IN_HAND - 1; i >= 0; --i )
        {
            if (current_hand[ i ]->checkIfClicked( window )
                && Mouse::isButtonPressed( Mouse::Right ) )
                {
                    while ( Mouse::isButtonPressed ( Mouse::Right ) )
                        {
                            current_hand[ i ]->setLocation( Mouse::getPosition( window ).x,
                                                            Mouse::getPosition( window ).y );
                            for ( int j = i + 1; j < NUMBER_IN_HAND; ++j )
                                {
                                    if ( current_hand[ j - 1 ]->getSprite()
                                        .getGlobalBounds()
									   	.intersects( current_hand[ j ]->getSprite().getGlobalBounds() ) )
                                        {
                                            xPos = current_hand[ j - 1 ]->getSprite().getPosition().x;
                                            yPos = current_hand[ j - 1 ]->getSprite().getPosition().y;
                                            current_hand[ j ]->setLocation ( xPos,
                                                                             yPos + SNAP_OFFSET );
                                        }
                                }
                            draw( window );
                            window.display();
                        }
                    return;
                }
        }
}

void Player::dragSnapBlock( RenderWindow &window )
{
    int x, y;
    if ( game_board->checkIfClicked( window ) )
        {
            while ( Mouse::isButtonPressed( Mouse::Left ) )
                {
                    x = game_board->button_x;
                    y = game_board->button_y;
                    game_board->buttons[ x ][ y ]->updateLocation( getMouseX( window ),
                                                                   getMouseY( window ) );
                    draw( window );
                    window.display();
                }
        }
}

void Player::snapObjects( RenderWindow &window )
{
    float sprite_x, sprite_y;
    /* Cards snap to "buttons " */
    if ( current_hand.back()->checkIfClicked( window ) )
        {
            if ( game_board->checkIfClicked( window ) )
                {
                    sprite_x = game_board->clicked_sprite.getPosition().x;
                    sprite_y = game_board->clicked_sprite.getPosition().y;
                    current_hand.back()->setLocation( sprite_x, sprite_y );
                }
        }
    /* Cards snap to place holders */
    for ( int i = 0; i < NUMBER_IN_HAND; ++i )
        {
            if ( card_place_holder[ i ]->checkIfClicked( window ) &&
                 current_hand.back()->checkIfClicked( window ) )
                {
                    sprite_x = card_place_holder[ i ]->getSprite().getPosition().x;
                    sprite_y = card_place_holder[ i ]->getSprite().getPosition().y;
                    current_hand.back()->setLocation( sprite_x, sprite_y );
                    return;
                }
        }
    /* Let player stack cards on top of each other but keep
     * unique Y positions */
    for ( int i = NUMBER_IN_HAND - 2; i >= 0; --i )
        {
            if ( current_hand[ i ]->checkIfClicked( window ) &&
                 current_hand.back()->checkIfClicked( window ) )
                {
                    sprite_x = current_hand[ i ]->getSprite().getPosition().x;
                    sprite_y = current_hand[ i ]->getSprite().getPosition().y;
                    current_hand.back()->setLocation( sprite_x,
                                                      sprite_y + SNAP_OFFSET );
                    return;
                }
        }
}

void Player::highlightCard( RenderWindow &window )
{
    for ( int i = NUMBER_IN_HAND - 1; i >= 0; --i )
        {
            current_hand[ i ]->changeColor( Color( 255, 255, 255 ) );
            if ( current_hand[ i ]->checkIfClicked( window ) )
                {
                    current_hand[ i ]->changeColor( Color( 255, 0, 255 ) );
                    for ( int j = 0; j < i; ++j )
                        {
                            current_hand[ j ]->changeColor(Color( 255, 255, 255 ) );
                        }
                    return;
                }
        }
}

void Player::draw( RenderWindow &window )
{
    // rectangle drawing function?
    RectangleShape bottom_border, top_border, mouse_x, mouse_y;
    bottom_border.setPosition( Vector2f( 0, 400 ) );
    bottom_border.setSize( Vector2f( 800, 400 ) );
    bottom_border.setFillColor( Color::Magenta );

    top_border.setPosition( Vector2f( 0, 0 ) );
    top_border.setSize( Vector2f( 800, 400 ) );
    top_border.setFillColor( Color::Green );

    mouse_y.setPosition( Vector2f( Mouse::getPosition( window ).x, 0 ) );
    mouse_x.setPosition( Vector2f( 0, Mouse::getPosition( window ). y ) );
    mouse_x.setSize( Vector2f( 9000, 1 ) );
    mouse_y.setSize( Vector2f( 1, 9000 ) );
    mouse_x.setFillColor( Color::Red );
    mouse_y.setFillColor( Color::Red );

    std::string player_id_string = "Player " + std::to_string( player_id );
    Text text;
    Font font;

#ifdef __APPLE__
    if ( !font.loadFromFile( resourcePath() + "arial.ttf" ) )
        {
            //error
        }
#elif _WIN32
    if ( !font.loadFromFile( "arial.ttf" ) )
        {
            //error
        }
#endif

    text.setFont( font );
    text.setString( player_id_string );
    text.setCharacterSize( 32 );
    text.setFillColor( Color::Red );
    text.setPosition( Vector2f( 0, 100 ) );

    /////////////////////////////////////////////////////////////////////////


    // render stuff
    window.draw( top_border );
    window.draw( bottom_border );
    window.draw( text );

    game_board->draw( window );

    for ( const auto &i : card_place_holder )
        {
            i->draw( window );
        }

    highlightCard( window );
    for ( const auto &i : current_hand )
        {
            i->draw( window );
        }
    window.draw( mouse_x );
    window.draw( mouse_y );
}
