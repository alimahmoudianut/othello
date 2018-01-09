#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
    Piece();

    int getColor() const;

    void setColor(int color);

    void flipColor();


private:
    int myColor;
};

#endif // PIECE_H
