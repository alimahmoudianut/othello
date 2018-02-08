#include "logic/board.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;


Board::Board(unsigned int col, unsigned int row)
{
    // Initialize row and column numbers
    setRowNum(row);
    setColNum(col);

    // Initialize board, create cells
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            Cell *c = new Cell(i, j);
            myCells.push_back(c);
        }
    }

    // Add central pieces ...
    Piece *pD4 = new Piece(WHITE);
    Piece *pD5 = new Piece(BLACK);
    Piece *pE4 = new Piece(BLACK);
    Piece *pE5 = new Piece(WHITE);
    getCell(3, 3)->setPiece(pD4);
    getCell(4, 3)->setPiece(pD5);
    getCell(3, 4)->setPiece(pE4);
    getCell(4, 4)->setPiece(pE5);
}

Board::Board(string str, unsigned int row, unsigned int col)
{
    // Initialize row and column numbers
    setRowNum(row);
    setColNum(col);

    // Initialize board, create cells
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            Cell *c = new Cell(i, j);
            myCells.push_back(c);
        }
    }

    // update board from string
    stringstream ss(str);
    string line;
    int j = 0;
    ss >> line;
    while(ss >> line)
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == 'O')
            {
                Piece *p = new Piece(WHITE);
                getCell(j, i)->setPiece(p);
            }
            else if(line[i] == 'X')
            {
                Piece *p = new Piece(BLACK);
                getCell(j, i)->setPiece(p);
            }
        }
        j++;
    }
}

Board::~Board()
{
    for(unsigned int i = 0; i < myCells.size(); i++)
    {
        delete myCells[i];
    }
}

Cell *Board::getCell(int r, int c) const
{
    for(unsigned int i = 0; i < myCells.size(); i++)
        if((myCells[i]->getRowNum() == r) &&
           (myCells[i]->getColNum() == c))
            return myCells[i];
    return NULL;
}

unsigned int Board::getRowNum() const
{
    return myRowNum;
}

unsigned int Board::getColNum() const
{
    return myColNum;
}

vector<Cell *> Board::getAllPossibleMovements(int color) const
{
    vector<Cell *> res;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            Cell *c = getCell(i , j);
            if(isPossibleMovement(c, color) == true)
                res.push_back(c);
        }
    }
    return res;
}

vector<Cell *> Board::getCellsByPieceColor(int color) const
{
    vector<Cell *> res;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            Cell *c = getCell(i, j);
            if(c->isEmpty() == false)
            {
                if(c->getPiece()->getColor() == color)
                    res.push_back(c);
            }
        }
    }
    return res;
}

vector<Cell *> Board::getCellsBetweenInLine(Cell *c1, Cell *c2) const
{
    vector<Cell *> res;
    if(c1->getRowNum() == c2->getRowNum())
    {
        int row = c1->getRowNum();
        for(unsigned int i = mini(c1->getColNum(), c2->getColNum()) + 1;
            i < maxi(c1->getColNum(), c2->getColNum()); i++)
            res.push_back(getCell(row, i));
    }
    else if(c1->getColNum() == c2->getColNum())
    {
        int col = c1->getColNum();
        for(unsigned int i = mini(c1->getRowNum(), c2->getRowNum()) + 1;
            i < maxi(c1->getRowNum(), c2->getRowNum()); i++)
            res.push_back(getCell(i, col));
    }
    else if(abs(c1->getRowNum() - c2->getRowNum())
            == abs(c1->getColNum() - c2->getColNum()))
    {
        unsigned int i;
        unsigned int j;
        int diff;

        if(c1->getRowNum() < c2->getRowNum())
        {
            i = c1->getRowNum() + 1;
            j = c1->getColNum();
            if(c1->getColNum() < c2->getColNum())
                diff = 1;
            else
                diff = -1;
        }
        else
        {
            i = c2->getRowNum() + 1;
            j = c2->getColNum();
            if(c2->getColNum() < c1->getColNum())
                diff = 1;
            else
                diff = -1;
        }

        j+= diff;

        for(; i < maxi(c1->getRowNum(), c2->getRowNum()); i++, j+=diff)
        {
            res.push_back(getCell(i, j));
        }
    }
    return res;
}

int Board::getDistanceBetweenInLine(Cell *c1, Cell *c2) const
{
    if(c1->getRowNum() == c2->getRowNum())
        return abs(c1->getColNum() - c2->getColNum());
    else if(c1->getColNum() == c2->getColNum())
        return abs(c1->getRowNum() - c2->getRowNum());
    else if(abs(c1->getRowNum() - c2->getRowNum())
            == abs(c1->getColNum() - c2->getColNum()))
        return abs(c1->getRowNum() - c2->getRowNum());
    return -1;
}

int Board::getPoint(int color) const
{
    return getCellsByPieceColor(color).size();
}

bool Board::isPossibleMovement(Cell *c, int color) const
{

    if(c->isEmpty() == false)
        return false;

    vector<Cell *> sameColorPieces = getCellsByPieceColor(color);
    for(unsigned int i = 0; i < sameColorPieces.size(); i++)
    {
        Cell *c1 = sameColorPieces[i];
        if(isJump(c1, c, color) == true)
            return true;
    }
    return false;
}

bool Board::isInOneLine(Cell *c1, Cell *c2) const
{
    if(c1->getRowNum() == c2->getRowNum())
        return true;
    else if(c1->getColNum() == c2->getColNum())
        return true;
    else if(abs(c1->getRowNum() - c2->getRowNum())
            == abs(c1->getColNum() - c2->getColNum()))
        return true;
    return false;
}

bool Board::isJump(Cell *c1, Cell *c2, int color) const
{
    if(c1 == c2)
        return false;
    vector<Cell *> cellsBetween = getCellsBetweenInLine(c1, c2);
    if(cellsBetween.size() == 0)
        return false;
    else
    {
        for(unsigned int j = 0; j < cellsBetween.size(); j++)
        {
            if(cellsBetween[j]->isEmpty() == true)
                return false;
            else if(cellsBetween[j]->getPiece()->getColor() == color)
                return false;
        }
    }
    return true;
}

int Board::makeJump(Cell *c1, Cell *c2, int color)
{
    if(isJump(c1, c2, color) == false)
        return 0;
    vector<Cell *> cellsBetween = getCellsBetweenInLine(c1, c2);
    for(unsigned int j = 0; j < cellsBetween.size(); j++)
    {
        cellsBetween[j]->getPiece()->flipColor();
    }
    return cellsBetween.size();
}

void Board::setRowNum(unsigned int n)
{
    myRowNum = n;
}

void Board::setColNum(unsigned int n)
{
    myColNum = n;
}

int Board::addMovement(int row, int col, int color)
{
   Cell *c = getCell(row, col);
    if(isPossibleMovement(c, color))
    {
        Piece *p = new Piece(color);
        c->setPiece(p);
        addMovementUpdates(c, color);
        return 0;
    }
    return -1;
}

string Board::toStr() const
{
    std::stringstream out;
    out << "BOARD" << endl;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            out << getCell(i, j)->getPieceSign();
        }
        out << std::endl;
    }
    return out.str();
}

string Board::deepToString() const
{
    stringstream out;
    out << "*------------------------  BOARD  -------------------------*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << toString();
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "* ........................................................ *" << endl;
    out << setfill(' ') << "* |" <<  setw(17) << "" << "| White" << setw(12) << "" << "| Black"
        << setw(11) << "" << "| *"  << std::endl;
    out << "* +------------------------------------------------------+ *" << endl;
    out << setfill(' ') << "* | " <<  setw(16) << "Movements" << "| "
        << setw(17) << getAllPossibleMovementsStr(WHITE) << "| "
        << setw(16) << getAllPossibleMovementsStr(BLACK) << "| *"  << std::endl;
    out << setfill(' ') << "* | " <<  setw(16) << "Point" << "| "
        << setw(17) << getPoint(WHITE) << "| "
        << setw(16) << getPoint(BLACK) << "| *"  << endl;
    out << "* ........................................................ *" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    return out.str();
}

int Board::addMovementUpdates(Cell *c, int color)
{
    int ret = 0;
    std::vector<Cell *> sameColorPieces = getCellsByPieceColor(color);
    for(unsigned int i = 0; i < sameColorPieces.size(); i++)
    {
        Cell *c1 = sameColorPieces[i];
        if(isJump(c1, c, color) == true)
            ret += makeJump(c1, c, color);
    }
    return ret;
}

string Board::getAllPossibleMovementsStr(int color) const
{
    stringstream out;
    std::vector<Cell *> wmvs = getAllPossibleMovements(color);
    for(unsigned int i = 0; i < mini(wmvs.size(), 5); i++)
    {
        out  << wmvs[i]->toString()<< " ";
    }
    return out.str();
}

std::string Board::toString() const
{
    std::stringstream out;
    out << setfill(' ') << "* " << std::left << setw(19) << "" <<
          "    A B C D E F G H" << setw(19) << "" << "*" << std::endl;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        out << setfill(' ') << "* " << std::left << setw(19) << "" << i+1 << "   ";
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            //out << getCell(i, j)->getLabel() << " ";
            out << getCell(i, j)->getPieceSign() << " ";
        }
        out << setw(18) << "" << "*" << std::endl;
    }
    return out.str();
}

unsigned int Board::maxi(unsigned int a, unsigned int b)
{
    return (a > b) ? a : b;
}

unsigned int Board::mini(unsigned int a, unsigned int b)
{
    return (a < b) ? a : b;
}
