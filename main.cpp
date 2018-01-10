#include <QCoreApplication>
#include "logic/game.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Game *g = new Game();
    g->start();
    return a.exec();
}
