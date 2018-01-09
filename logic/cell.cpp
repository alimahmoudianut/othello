#include "cell.h"
#include "piece.h"
#include <string>
#include <sstream>

Cell::Cell(int x, int y)
{
    setAxisX(x);
    setAxisY(y);
}

int Cell::getAxisX() const
{
    return myAxisX;
}

int Cell::getAxisY() const
{
    return myAxisY;
}

std::string Cell::getLabel() const
{
    char col = getAxisX() + 'A';
    int row = getAxisY() + 1;

    std::stringstream label;
    label << col << row;

    return label.str();
}

Piece *Cell::getPiece()
{
    return getPiece();
}

void Cell::setAxisX(const int x)
{
    myAxisX = x;
}

void Cell::setAxisY(const int y)
{
    myAxisY = y;
}

void Cell::setPiece(Piece *piece)
{
    myPiece = piece;
}

std::string Cell::toString() const
{
    std::stringstream out;
    out << "Cell(" << getAxisX() << ", " << getAxisY() << ", " << getLabel() << ")" << std::endl;
    return out.str();
}

std::string Cell::deepToString() const
{
    return std::string("abc");

}
