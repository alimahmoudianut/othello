#include "mainwindow.h"
#include <QtWidgets>
#include "view/newgamedialog.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent, ClientTerminal *terminal) : QMainWindow(parent)
{
    myTerminal = terminal;
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
    }
}

void MainWindow::setupWidgets()
{
    if(myNewGameDialog->getGameType() == ONLINE_GAME)
        myBoardWidget = new BoardWidget(this, myGame, myTerminal);
    else
        myBoardWidget = new BoardWidget(this, myGame);
    setCentralWidget(myBoardWidget);
}
