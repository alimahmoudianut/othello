#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "view/boardwidget.h"
#include "logic/game.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = NULL);

signals:

public slots:

private:
    void setupWidgets();

    BoardWidget *myBoardWidget;
    QGridLayout * myGrid;

    Game *myGame;
};

#endif // MAINWINDOW_H
