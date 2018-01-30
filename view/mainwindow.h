#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "view/boardwidget.h"
#include "view/newgamedialog.h"
#include "logic/game.h"
#include "network/clientterminal.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent, ClientTerminal *terminal);

signals:

public slots:

private:
    void setupWidgets();

    NewGameDialog *myNewGameDialog;
    BoardWidget *myBoardWidget;
    QGridLayout * myGrid;
    ClientTerminal *myTerminal;

    Game *myGame;
};

#endif // MAINWINDOW_H
