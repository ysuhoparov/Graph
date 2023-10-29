#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>

#include "qnetworkdatagram.h"

#include "ui_datadialog.h"

class DataDialog : public QDialog
{
    Q_OBJECT

public:
    DataDialog(QWidget *parent = nullptr);

    Ui::DataDialog ui;

    void draw(QNetworkDatagram & datagram);


private:

    bool updatable;
    int diff = 64;

private slots:
    void on_pause_clicked();
    void on_filrter_valueChanged(int value);
};

#endif // DATADIALOG_H
