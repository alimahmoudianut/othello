#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QApplication>
#include "logic/game.h"
#include "network/serverterminal.h"
#include "network/clientterminal.h"
#include "view/mainwindow.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    ServerTerminal server;
    ClientTerminal *s = new ClientTerminal();
    MainWindow* win;

    QApplication a(argc, argv);

    QCommandLineParser *parser = new QCommandLineParser();
    QCommandLineOption typeOpt(QStringList() << "type"
                          , QCoreApplication::translate("main", "Game type (offline, client, server)")
                          , QCoreApplication::translate("main", "O-C-S"));

    parser->addHelpOption();
    parser->addVersionOption();

    parser->addOption(typeOpt);
    parser->process(a);

    QString typeStr = parser->value(typeOpt);

    if(typeStr.toLower() == "c" || typeStr.toLower() == "client")
    {
        s->doConnect();
        win = new MainWindow(0, s);
    }
    else if(typeStr.toLower() == "s" || typeStr.toLower() == "server")
    {
        server.startServer();
        server.startCLI();
    }
    else
    {
        Game *g = new Game(TERMINAL_OFFLINE);
        g->start();
    }
    return a.exec();
}
