#include "cell.h"
#include "piece.h"
#include <string>
#include <sstream>

Cell::Cell(int r, int c)
{
    setRowNum(r);
    setColNum(c);
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

Piece *Cell::getPiece()
{
    return getPiece();
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

std::string Cell::toString() const
{
    std::stringstream out;
    out << "Cell(" << getRowNum() << ", " << getColNum() << ", " << getLabel() << ")" << std::endl;
    return out.str();
}

std::string Cell::deepToString() const
{
    return std::string("abc");

}
