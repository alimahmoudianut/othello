#include <QCoreApplication>
#include <QDebug>
#include "logic/cell.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "We have launched our project.";
    Cell *c1 = new Cell(2, 3);
    cout << c1->toString();
    return a.exec();
}
