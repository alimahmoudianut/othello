#include "mainwindow.h"
#include <QtWidgets>
#include "view/newgamedialog.h"
#include <unistd.h>
#include <iostream>
using namespace  std;

MainWindow::MainWindow(QWidget *parent, ClientTerminal *terminal) : QMainWindow(parent)
{
    myTerminal = terminal;
    myBoardWidget = NULL;
    myGame = new Game();
    myNewGameDialog = new NewGameDialog(this, terminal);
    setupWidgets();
    this->show();
    if(myNewGameDialog->exec() == QDialog::Rejected)
    {
        this->close();
        exit(0);
    }
    else
    {
        myGame->setGameType(myNewGameDialog->getGameType());
        cout << myNewGameDialog->getGameType() << endl;
    }
    setupWidgets();
}

void MainWindow::setupWidgets()
{
    if(myBoardWidget != NULL)
        delete myBoardWidget;

    cout << myNewGameDialog->getGameType() << endl;
    if(myNewGameDialog->getGameType() == ONLINE_GAME)
    {
        cout << "This is an online game" << endl;
        myBoardWidget = new BoardWidget(this, myGame, myTerminal);
    }
    else
    {
        myBoardWidget = new BoardWidget(this, myGame);
    }
    setCentralWidget(myBoardWidget);
}
