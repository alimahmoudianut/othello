#include "newgamedialog.h"
#include <QGridLayout>
#include <QBoxLayout>

NewGameDialog::NewGameDialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(createGameSelectGroup(), 0, 0);
    mainLayout->addLayout(createPushButtonLayout(), 0, 1);
    setLayout(mainLayout);
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
    vbox->addStretch(1);

    groupBox->setLayout(vbox);

    return groupBox;
}

QVBoxLayout *NewGameDialog::createPushButtonLayout()
{
    myNewGameBtn = new QPushButton(tr("&New Game"));
    myNewGameBtn->setCheckable(false);
    myCancelBtn = new QPushButton(tr("&Cancel"));

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(myNewGameBtn);
    leftLayout->addWidget(myCancelBtn);
    return leftLayout;
}
