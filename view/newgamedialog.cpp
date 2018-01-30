#include "newgamedialog.h"
#include <QGridLayout>
#include <QBoxLayout>
#include <QTableView>
#include "selectservergame.h"
#include <iostream>
using namespace std;

NewGameDialog::NewGameDialog(QWidget *parent, ClientTerminal *terminal)
    : QDialog(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(createGameSelectGroup(), 0, 0);
    mainLayout->addLayout(createPushButtonLayout(), 0, 1);
    setLayout(mainLayout);

    myTerminal = terminal;

}

void NewGameDialog::newGameClicked()
{
    if(myTwoPlayerGameRadioBtn->isChecked() == true)
        accept();
    else if(mySinglePlayerGameRadioBtn->isChecked() == true)
        accept();
    else if(myServerGameRadioBtn->isChecked() == true)
    {
        SelectServerGame *sDialog = new SelectServerGame(this, myTerminal);
        sDialog->show();
    }
}

QGroupBox *NewGameDialog::createGameSelectGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Game Type"));

    myTwoPlayerGameRadioBtn = new QRadioButton(tr("&Two Player"));
    mySinglePlayerGameRadioBtn = new QRadioButton(tr("&Single Player"));
    myServerGameRadioBtn = new QRadioButton(tr("&Online"));

    myTwoPlayerGameRadioBtn->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(myTwoPlayerGameRadioBtn);
    vbox->addWidget(mySinglePlayerGameRadioBtn);
    vbox->addWidget(myServerGameRadioBtn);

    QVBoxLayout *empty = new QVBoxLayout;
    vbox->addLayout(empty);
    empty->stretch(0);

    groupBox->setLayout(vbox);

    return groupBox;
}

QVBoxLayout *NewGameDialog::createPushButtonLayout()
{
    myNewGameBtn = new QPushButton(tr("&New Game"));
    myCancelBtn = new QPushButton(tr("&Cancel"));

    connect(myCancelBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(myNewGameBtn, SIGNAL(clicked(bool)), this, SLOT(newGameClicked()));

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(myNewGameBtn);
    leftLayout->addWidget(myCancelBtn);
    return leftLayout;
}
