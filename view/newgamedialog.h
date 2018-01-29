#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QPushButton>
#include <QLayout>

class NewGameDialog : public QDialog
{
    Q_OBJECT
public:
    NewGameDialog(QWidget *parent);

private:
    QGroupBox *createGameSelectGroup();
    QVBoxLayout *createPushButtonLayout();

    QRadioButton *myTwoPlayerGameRadioBtn;
    QRadioButton *mySinglePlayerGameRadioBtn;
    QRadioButton *myServerGameRadioBtn;

    QPushButton *myNewGameBtn;
    QPushButton *myCancelBtn;
};

#endif // NEWGAMEDIALOG_H
