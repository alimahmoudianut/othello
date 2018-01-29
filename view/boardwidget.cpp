#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent)
{

}

void BoardWidget::paintEvent(QPaintEvent *)
{

}

void BoardWidget::addPieces()
{
    QRect mRect;
    QSize *size = new QSize(80, 50);

    myPiecePixmaps.clear();
    myPieceRects.clear();

    myWidthGap = 80;
    myHeightGap = 25;
    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j < 9; j++)
        {
            mRect = QRect(j * (size->width() + myWidthGap) ,
                          i * (size->height() + myHeightGap),
                          size->width(),
                          size->height());

            QPixmap temp;
        }
    }

}
