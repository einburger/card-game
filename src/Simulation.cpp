#include "Simulation.h"

Simulation::Simulation( RenderWindow &window )
{
    seed = system_clock::now().time_since_epoch().count();
    game_state = MENU;
    players.reserve( NUMBER_OF_PLAYERS );
    deck.reserve( NUMBER_OF_CARDS );

    for ( int i = 0; i < NUMBER_OF_CARDS; i++ )
        {
            deck.push_back( unique_card_ptr( new ResourceCard() ) );
        }
    shuffleCards();

    for ( int i = 0; i < NUMBER_OF_PLAYERS; i++ )
        {
            players.push_back( unique_player_ptr( new Player() ) );
            players[ i ]->player_id = i;
        }

    for ( auto &player : players )
        {
            for ( int j = 0; j < NUMBER_IN_HAND; j++ )
                {
                    player->drawCard( deck.back() );
                    deck.pop_back();
                    player->current_hand[ j ]->setLocation( ( j * CARD_WIDTH ) +
                                                            CARD_X_OFFSET,
                                                            CARD_Y );
                }
        }
    current_player = 1;
}

Simulation::~Simulation()
{
}

void Simulation::playRound( RenderWindow &window )
{
    players[ current_player ]->draw( window );
    // if ( !nextTurn() )
    //  {
    //   isGameOver = true;
    // }
}

void Simulation::shuffleCards()
{
    std::shuffle( deck.begin(),
                  deck.end(),
                  std::default_random_engine( seed ) );
}

bool Simulation::nextTurn()
{
    for ( const auto &player : players )
        {
            if ( player->isWinner() )
                {
                    return false;
                }
        }
    return true;
}

void Simulation::run( RenderWindow &window )
{
    window.clear( Color::Black );
    playRound( window );
    window.display();
}

void Simulation::dragObject( RenderWindow &window )
{
    players[ current_player ]->dragCard( window );
    players[ current_player ]->dragCardStack( window );
    players[ current_player ]->dragSnapBlock( window );
    players[ current_player ]->draw( window );
    window.display();
}

void Simulation::snapToContainer( RenderWindow &window )
{
    players[ current_player ]->snapObjects( window );
    players[ current_player ]->draw( window );
    window.display();
}

void Simulation::nextPlayer()
{
    current_player < NUMBER_OF_PLAYERS - 1 ?
                     current_player++ :
        current_player = 1;
}
