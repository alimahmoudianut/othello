#include "game.h"
#include <iostream>
#include <sstream>
using namespace std;

int Game::ourCnt = 0;

Game::Game(int type)
    :myID(ourCnt++)
{
    if(type == TERMINAL_OFFLINE)
    {
        myBoard = new Board(8, 8);
        myFirstPlayer = new HumanPlayer(WHITE, "Player 1");
        mySecondPlayer = new HumanPlayer(BLACK, "Player 2");
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

void Game::setFirstPlayer(Player *firstPlayer)
{
    myFirstPlayer = firstPlayer;
}

void Game::setSecondPlayer(Player *secondPlayer)
{
    mySecondPlayer = secondPlayer;
}

string Game::toString() const
{
    stringstream out;
    out << "GAME " << myID << endl;
    return out.str();
}

string Game::toDeepString() const
{
    stringstream out;
    out << myBoard->deepToString() << endl;
    return out.str();
}
