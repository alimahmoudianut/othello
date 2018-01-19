#include "game.h"
#include <iostream>
using namespace std;

Game::Game(int type)
{
    if(type == TERMINAL_OFFLINE)
    {
        myBoard = new Board(8, 8);
        myFirstPlayer = new HumanPlayer(WHITE);
        mySecondPlayer = new HumanPlayer(BLACK);
    }
    else if(type == TERMINAL_CLIENT)
    {
        cout << "Start Client Terminal" << endl;
    }
    else if(type == TERMINAL_SERVER)
    {
        cout << "Start Server Terminal" << endl;
    }
}

void Game::start()
{
    while(1)
    {
        myFirstPlayer->play(myBoard);
        mySecondPlayer->play(myBoard);
    }
}
