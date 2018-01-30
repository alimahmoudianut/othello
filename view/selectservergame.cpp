#include "selectservergame.h"
#include <QGridLayout>
#include <QTableWidget>
#include <QTimer>
#include <sstream>
using namespace std;

SelectServerGame::SelectServerGame(QWidget *parent, ClientTerminal *terminal)
    : QDialog(parent)
{

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addLayout(createPushButtonLayout(), 0, 1);

    mainLayout->addWidget(createGameSelectGroup(), 0, 0);

    myTerminal = terminal;
    terminal->doConnect();
    terminal->request("LISTGAME");

    updateGameList();
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateGameList()));
    myTimer->start(1000);

    setLayout(mainLayout);
}

void SelectServerGame::updateGameList()
{
    string res = myTerminal->getLastResponse();
    myTerminal->request("LISTGAME");

    if(res != "")
    {
        stringstream ss(res);
        string prefix;
        string id;
        string player;

        int row = 0;

        myGameIDs.clear();

        while(ss >> prefix >> id >> player)
        {
            char str[32];
            myGameIDs.push_back(id);
            sprintf(str, "Game %s", id.c_str());
            QTableWidgetItem *gameIDItem = new QTableWidgetItem(str);
            QTableWidgetItem *gamePlayerItem = new QTableWidgetItem(player.c_str());
            myTableWidget->setItem(row, 0, gameIDItem);
            myTableWidget->setItem(row, 1, gamePlayerItem);
            row++;
        }
    }
}

void SelectServerGame::startGameClicked()
{
    if(myNewGameRadioBtn->isChecked() == true)
    {
        myTerminal->request("NEWGAME");
        myTimer->stop();
        accept();
    }
    else if(myConnectGameRadioBtn->isChecked() == true)
    {
        QItemSelectionModel *select = myTableWidget->selectionModel();
        if(select->hasSelection() == true)
        {
            char str[256];
            sprintf(str, "JOIN %s", myGameIDs[select->selectedRows().at(0).row()].c_str());
            myTerminal->request(str);
            myTimer->stop();
            accept();
        }
    }
}

QVBoxLayout *SelectServerGame::createPushButtonLayout()
{
    myStartBtn = new QPushButton(tr("&Start"));
    myCancelBtn = new QPushButton(tr("&Cancel"));

    connect(myCancelBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(myStartBtn, SIGNAL(clicked(bool)), this, SLOT(startGameClicked()));

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(myStartBtn);
    leftLayout->addWidget(myCancelBtn);
    leftLayout->setStretch(2, 4);
    return leftLayout;
}

QGroupBox *SelectServerGame::createGameSelectGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Game Select"));

    myTableWidget = new QTableWidget(4, 2, this);
    myTableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    myTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    myTableWidget->setSelectionMode( QAbstractItemView::SingleSelection );

    myNewGameRadioBtn = new QRadioButton(tr("&New Game"));
    myConnectGameRadioBtn = new QRadioButton(tr("&Connect to ..."));

    myNewGameRadioBtn->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(myNewGameRadioBtn);
    vbox->addWidget(myConnectGameRadioBtn);
    vbox->addWidget(myTableWidget);
    groupBox->setLayout(vbox);

    return groupBox;
}
