#include "game.h"

Game::Game()
{
    myBoard = new Board(8, 8);
    myFirstPlayer = new HumanPlayer(WHITE);
    mySecondPlayer = new HumanPlayer(BLACK);
}

void Game::start()
{
    while(1)
    {
        myFirstPlayer->play(myBoard);
        mySecondPlayer->play(myBoard);
    }
}
