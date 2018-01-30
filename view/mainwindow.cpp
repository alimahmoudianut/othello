#include "mainwindow.h"
#include <QtWidgets>
#include "view/newgamedialog.h"

MainWindow::MainWindow(QWidget *parent, ClientTerminal *terminal) : QMainWindow(parent)
{
    myGame = new Game();
    NewGameDialog *d = new NewGameDialog(this, terminal);
    setupWidgets();
    this->show();
    if(d->exec() == QDialog::Rejected)
    {
        this->close();
        exit(0);
    }
}

void MainWindow::setupWidgets()
{
    myBoardWidget = new BoardWidget(this, myGame);
    setCentralWidget(myBoardWidget);
}
