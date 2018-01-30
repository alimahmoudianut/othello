#include "selectservergame.h"
#include <QGridLayout>
#include <QTableWidget>

SelectServerGame::SelectServerGame(QWidget *parent, ClientTerminal *terminal)
    : QDialog(parent)
{

    QGridLayout *mainLayout = new QGridLayout;
    QTableWidget * tableWidget = new QTableWidget(4, 2, this);

    mainLayout->addWidget(tableWidget, 0, 0);
    mainLayout->addLayout(createPushButtonLayout(), 0, 1);

    myTerminal = terminal;
    terminal->doConnect();

    this->setMaximumSize(QSize(500, 400));
    this->setMinimumSize(QSize(500, 400));
}

QVBoxLayout *SelectServerGame::createPushButtonLayout()
{
    myNewGameBtn = new QPushButton(tr("&New Game"));
    myCancelBtn = new QPushButton(tr("&Cancel"));

    connect(myCancelBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(myNewGameBtn);
    leftLayout->addWidget(myCancelBtn);
    leftLayout->setStretch(0, 1);
    return leftLayout;
}
