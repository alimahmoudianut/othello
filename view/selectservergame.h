#ifndef SELECTSERVERGAME_H
#define SELECTSERVERGAME_H

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QPushButton>
#include <QLayout>
#include "network/clientterminal.h"
#include <QTableWidget>


class SelectServerGame : public QDialog
{
    Q_OBJECT
public:
    SelectServerGame(QWidget *widget, ClientTerminal *terminal);

private slots:
    void updateGameList();
    void startGameClicked();

private:
    QVBoxLayout *createPushButtonLayout();
    QGroupBox *createGameSelectGroup();
    QPushButton *myStartBtn;
    QPushButton *myCancelBtn;
    ClientTerminal *myTerminal;
    QTableWidget * myTableWidget;

    QRadioButton *myNewGameRadioBtn;
    QRadioButton *myConnectGameRadioBtn;

    QTimer *myTimer;

    vector <string> myGameIDs;
};

#endif // SELECTSERVERGAME_H
