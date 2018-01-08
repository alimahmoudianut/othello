#ifndef PIECE_H
#define PIECE_H

#define WHITE 0
#define BLACK 1

class Piece
{
public:
    Piece(int color);

    int getColor() const;

    void setColor(int color);

    void flipColor();


private:
    int myColor;
};

#endif // PIECE_H
