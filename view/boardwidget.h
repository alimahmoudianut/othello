#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QList>
#include <logic/game.h>
#include "network/clientterminal.h"



class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr, Game *game = NULL);
    explicit BoardWidget(QWidget *parent, Game *game, ClientTerminal *terminal);

signals:

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

public slots:

private:
    int getCellXPos(int row, int col) const;
    int getCellYPos(int row, int col) const;

    Cell *findCellByPoint(const QPoint &point) const;

    Game *myGame;

    int myPadWidth;
    int myPadHeight;

    int myGapWidth;
    int myGapHeight;

    int myCellWidth;
    int myCellHeight;

    ClientTerminal * myTerminal;
};

#endif // BOARDWIDGET_H
