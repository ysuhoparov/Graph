#ifndef MYNWORK_H
#define MYNWORK_H

#include "datadialog.h"

#include <QObject>

#include <QtNetwork>


class Mynwork: public QObject
{
        Q_OBJECT;

public:
    QUdpSocket * udpSocket;
    QNetworkDatagram  datagram;

    DataDialog * graph = nullptr;

        void initSocket(DataDialog * graph)
        {
            udpSocket = new QUdpSocket();
            udpSocket->bind(QHostAddress::LocalHost, 10002);

            QAbstractSocket::connect(udpSocket,&QUdpSocket::readyRead,this,&Mynwork::readPendingDatagrams);

            this->graph = graph;

        }

        void processTheDatagram(QNetworkDatagram & datagram)
        {
            if(graph != nullptr)
                graph->draw(datagram);

          // qDebug() << datagram.data();

        }

        void readPendingDatagrams()
        {
            while (udpSocket->hasPendingDatagrams()) {
                datagram = udpSocket->receiveDatagram();
                processTheDatagram(datagram);
            }
        }

        ~Mynwork(){
            delete udpSocket;
        }

};

#endif // MYNWORK_H
