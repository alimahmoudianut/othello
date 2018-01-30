#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QPushButton>
#include <QLayout>
#include "network/clientterminal.h"

enum gameType
{
    SINGLE_PLAYER_GAME,
    TWO_PLAYER_GAME,
    ONLINE_GAME
};

class NewGameDialog : public QDialog
{
    Q_OBJECT
public:
    NewGameDialog(QWidget *parent, ClientTerminal *terminal);

    int getGameType();

private slots:
    void newGameClicked();

private:
    QGroupBox *createGameSelectGroup();
    QVBoxLayout *createPushButtonLayout();

    QRadioButton *myTwoPlayerGameRadioBtn;
    QRadioButton *mySinglePlayerGameRadioBtn;
    QRadioButton *myServerGameRadioBtn;

    QPushButton *myNewGameBtn;
    QPushButton *myCancelBtn;

    ClientTerminal *myTerminal;

    int myGameType;
};

#endif // NEWGAMEDIALOG_H
