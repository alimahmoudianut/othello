#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *);

public slots:

private:
    void addPieces();


    QList<QPixmap> myPiecePixmaps;
    QList<QRect> myPieceRects;

    int myWidthGap;
    int myHeightGap;
};

#endif // BOARDWIDGET_H
