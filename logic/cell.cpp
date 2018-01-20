#include "logic/cell.h"
#include "logic/piece.h"
#include <string>
#include <sstream>

Cell::Cell(int r, int c)
{
    setRowNum(r);
    setColNum(c);
    setPiece(NULL);
}

int Cell::getRowNum() const
{
    return myRowNum;
}

int Cell::getColNum() const
{
    return myColNum;
}

std::string Cell::getLabel() const
{
    char col = getColNum() + 'A';
    int row = getRowNum() + 1;

    std::stringstream label;
    label << col << row;

    return label.str();
}

std::string Cell::getPieceSign() const
{
    if(getPiece() == NULL)
        return ".";
    if(getPiece()->getColor() == WHITE)
        return "O";
    else if(getPiece()->getColor() == BLACK)
        return "X";
    return " ";
}

Piece *Cell::getPiece() const
{
    return myPiece;
}

void Cell::setRowNum(const int r)
{
    myRowNum = r;
}

void Cell::setColNum(const int c)
{
    myColNum = c;
}

void Cell::setPiece(Piece *piece)
{
    myPiece = piece;
}

bool Cell::isEmpty()
{
    if(getPiece() == NULL)
        return true;
    return false;
}

std::string Cell::toString() const
{
    std::stringstream out;
    out << getLabel();
    return out.str();
}

std::string Cell::deepToString() const
{
    return std::string("abc");

}
