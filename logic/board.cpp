#include "logic/board.h"
#include <iostream>
#include <sstream>

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

    Piece *pD4 = new Piece(WHITE);
    Piece *pD5 = new Piece(BLACK);
    Piece *pE4 = new Piece(BLACK);
    Piece *pE5 = new Piece(WHITE);
    getCell(3, 3)->setPiece(pD4);
    getCell(4, 3)->setPiece(pD5);
    getCell(3, 4)->setPiece(pE4);
    getCell(4, 4)->setPiece(pE5);

    std::vector<Cell *> mvs = getAllPossibleMovements(BLACK);
    for(unsigned int i = 0; i < mvs.size(); i++)
        std::cout << mvs[i]->toString();
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

std::vector<Cell *> Board::getAllPossibleMovements(int color) const
{
    std::vector<Cell *> res;
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

std::vector<Cell *> Board::getCellsByPieceColor(int color) const
{
    std::vector<Cell *> res;
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

std::vector<Cell *> Board::getCellsBetweenInLine(Cell *c1, Cell *c2) const
{
    std::vector<Cell *> res;
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
        unsigned int i = mini(c1->getRowNum(), c2->getRowNum()) + 1;
        unsigned int j = mini(c1->getColNum(), c2->getColNum()) + 1;
        for(; i < maxi(c1->getRowNum(), c2->getRowNum()) && j < maxi(c1->getColNum(), c2->getColNum()); i++, j++)
            res.push_back(getCell(i, j));
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

bool Board::isPossibleMovement(Cell *c, int color) const
{
    if(c->isEmpty() == false)
        return false;

    std::vector<Cell *> sameColorPieces = getCellsByPieceColor(color);
    for(unsigned int i = 0; i < sameColorPieces.size(); i++)
    {
        Cell *c1 = sameColorPieces[i];
        if(c1 == c)
            continue;
        std::vector<Cell *> piecesBetween = getCellsBetweenInLine(c, c1);
        if(piecesBetween.size() > 0)
        {
            int jump = true;
            for(unsigned int j = 0; j < piecesBetween.size(); j++)
            {
                if(piecesBetween[j]->isEmpty() == true)
                {
                    jump = false;
                    break;
                }
                else if(piecesBetween[j]->getPiece()->getColor() == color)
                {
                    jump = false;
                    break;
                }
            }
            if(jump == true)
                return true;
        }

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

void Board::setRowNum(unsigned int n)
{
    myRowNum = n;
}

void Board::setColNum(unsigned int n)
{
    myColNum = n;
}

std::string Board::printBoard() const
{
    std::stringstream out;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            //out << getCell(i, j)->getLabel() << " ";
            out << getCell(i, j)->getPieceSign() << " ";
        }
        out << std::endl;
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
