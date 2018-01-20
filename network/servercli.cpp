#include "servercli.h"
#include "network/serverconnection.h"
#include <iostream>
using namespace std;

ServerCLI::ServerCLI()
{

}

void ServerCLI::run()
{
    while(1)
    {
        string cmd;
        cout << "Command (m for help) >> ";
        cin >> cmd;
        if(cmd == "m")
        {
            cout << endl;
            cout << "Help:" << endl << endl;
            cout << "  Generic " << endl;
            cout << "   G   list all active games" << endl;
            cout << "   C   list all clients" << endl;
            cout << "   P   list all players" << endl;
            cout << endl <<  "  Game " << endl;
            cout << "   D   show details of a game" << endl;
            cout << endl << endl;
        }
        else if (cmd == "G")
        {
            for(unsigned int i = 0; i < ServerConnection::ourGames.size(); i++)
            {
                cout << ServerConnection::ourGames[i]->toString() << endl;
            }
        }
        else
        {
            cout << cmd << ": unknown command" << endl;
        }
    }

}
