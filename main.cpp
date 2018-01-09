#include <QCoreApplication>
#include "logic/board.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Board b(8, 8);
    cout << b.printBoard();
    return a.exec();
}
