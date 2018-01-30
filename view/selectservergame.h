#ifndef SELECTSERVERGAME_H
#define SELECTSERVERGAME_H

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QPushButton>
#include <QLayout>
#include "network/clientterminal.h"


class SelectServerGame : public QDialog
{
    Q_OBJECT
public:
    SelectServerGame(QWidget *widget, ClientTerminal *terminal);



private:
    QVBoxLayout *createPushButtonLayout();
    QPushButton *myNewGameBtn;
    QPushButton *myCancelBtn;
    ClientTerminal *myTerminal;
};

#endif // SELECTSERVERGAME_H
