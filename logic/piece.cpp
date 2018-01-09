#include "piece.h"

Piece::Piece()
{

}

int Piece::getColor() const
{
    return myColor;
}

void Piece::setColor(int color)
{
    myColor = color;
}

void Piece::flipColor()
{
    setColor(!getColor());
}
