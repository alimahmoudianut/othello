#ifndef CLIENT_TERMINAL_H
#define CLIENT_TERMINAL_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class ClientTerminal : public QObject
{
    Q_OBJECT
public:
    explicit ClientTerminal(QObject *parent = 0);

    void doConnect();

signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;

};

#endif // MYTCPSOCKET_H
