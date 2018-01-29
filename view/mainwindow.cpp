#include "mainwindow.h"
#include <QtWidgets>
#include "view/newgamedialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    myGame = new Game();
    NewGameDialog *d = new NewGameDialog(this);
    d->show();
    setupWidgets();
}

void MainWindow::setupWidgets()
{
    myBoardWidget = new BoardWidget(this, myGame);
    setCentralWidget(myBoardWidget);
}
