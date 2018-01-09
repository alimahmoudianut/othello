#include <QCoreApplication>
#include "logic/board.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Board b(8, 8);

    while(1)
    {
        cout << b.deepToString();
        string mv;
        cin >> mv;
        b.addMovement(mv[1]-'1', mv[0]-'A', WHITE);
    }
    return a.exec();
}
