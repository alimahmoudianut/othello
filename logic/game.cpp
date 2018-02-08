#include "game.h"
#include "logic/player/cpuplayer.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int Game::ourCnt = 0;

Game::Game(int type)
    :myID(ourCnt++)
{
    myTurn = BLACK;
    if(type == TERMINAL_OFFLINE)
    {
        myBoard = new Board(8, 8);
        myFirstPlayer = new HumanPlayer(WHITE, "Player 1");
        mySecondPlayer = new HumanPlayer(BLACK, "Player 2");
    }
    else if(type == TERMINAL_CLIENT)
    {
        cout << "Start Client Terminal" << endl;
        myBoard = new Board(8, 8);
        myFirstPlayer = NULL;
        mySecondPlayer = NULL;
    }
    else if(type == TERMINAL_SERVER)
    {
        cout << "Start Server Terminal" << endl;
        myBoard = new Board(8, 8);
        myFirstPlayer = NULL;
        mySecondPlayer = NULL;
    }
}

void Game::start(int detail)
{
    for(int i = 0; i < 10; i++)
    {
        if(detail == 0)
            cout << deepToString() << endl;
        myFirstPlayer->play(myBoard);
        if(detail == 0)
            cout << deepToString() << endl;
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

void Game::setLastMovement(string mv, Player *player)
{
    char tmp[256];
    sprintf(tmp, "%s %s", player->getColorStr().c_str(), mv.c_str());
    string lastMV(tmp);
    myLastMovement = lastMV;
}

void Game::setGameType(int gameType)
{
    myGameType = gameType;
    if(mySecondPlayer != NULL)
    {
        delete myFirstPlayer;
        myFirstPlayer = new CpuPlayer(WHITE);
    }
}

void Game::updateBoard(string str)
{
    delete myBoard;
    myBoard = new Board(str);
}

Board *Game::getBoard() const
{
    return myBoard;
}

Player *Game::getFirstPlayer() const
{
    return myFirstPlayer;
}

Player *Game::getSecondPlayer() const
{
    return mySecondPlayer;
}

int Game::getNumberOfPlayers() const
{
    int ret = 0;
    if(getFirstPlayer() != NULL)
        ret ++;
    if(getSecondPlayer() != NULL)
        ret ++;
    return ret;
}

int Game::getGameType() const
{
    return myGameType;
}

int Game::isPlayerTurn(Player *player) const
{
    if(getTurn() == player->getColor())
        return 0;
    else
        return -1;
}

string Game::toString() const
{
    stringstream out;
    out << "GAME " << myID << " ";
    if(getFirstPlayer() != NULL)
        out << getFirstPlayer()->getName() << endl;
    return out.str();
}

string Game::deepToString() const
{
    stringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') <<  "* Game " << std::left << setw(52) << myID  << "*"  << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << myBoard->deepToString();
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    if(myFirstPlayer != NULL)
    {
        out << myFirstPlayer->deepToString(1);
        out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    }
    if(mySecondPlayer != NULL)
    {
        out << mySecondPlayer->deepToString(2);
        out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    }
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

int Game::addMovement(string mv, Player *player)
{
    if(getNumberOfPlayers() != 2)
        return -3;
    if(getTurn() == player->getColor())
    {
        if(myBoard->addMovement(mv[1]-'1', mv[0]-'A', player->getColor()) == 0)
        {
            calculateNextTurn();
            return 0;
        }
        else
            return -1;
    }
    else
        return -2;
}

string Game::getLastMovement() const
{
    return myLastMovement;
}

int Game::getTurn() const
{
    return myTurn;
}

int Game::getID() const
{
    return myID;
}

void Game::calculateNextTurn()
{
    if(myTurn == WHITE)
    {
        if(myBoard->getAllPossibleMovements(BLACK).size() != 0)
        {
            myTurn = BLACK;
        }
    }
    else
    {
        if(myBoard->getAllPossibleMovements(WHITE).size() != 0)
        {
            myTurn = WHITE;
            if(getGameType() == 0)
            {
                this->addMovement(myFirstPlayer->play(myBoard), myFirstPlayer);
            }
        }
    }
}
