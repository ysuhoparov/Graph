#include "datadialog.h"
#include "qpen.h"

#include  <QtAlgorithms>

DataDialog::DataDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    ui.widget->xAxis->setRange(0,4800);
    ui.widget->yAxis->setRange(0,4200);
    ui.widget->addGraph();

    updatable = true;
    diff = 16;
}

void DataDialog::draw(QNetworkDatagram & datagram)
{

    if(!updatable) return;

    QVector<double> x, y, m;

    auto data = datagram.data();
    qint16 dt, dt_= 0, max = -1000, index;
    for(unsigned int j = 0; j<8192; j+=2 ) {

        dt = (data.at(j) << 8) | data.at(j+1);   // byte xchg

        if(dt > max) {
            index = j/2;
            max = dt;
        }
        if((dt-dt_) < diff )  dt = dt_ - diff;   // diff filter
        dt_ = dt;

        y.push_back((double)dt);
        m.push_back((double)dt);
        x.push_back((double)j/2);
    }

    std::sort(m.begin(), m.end());

    int samples = 4096;
    double median = (y.at(samples/2) + y.at(samples/2 -1)) / 2;

    for(auto & item : m)
        item = median;



    ui.widget->clearPlottables();

    ui.widget->xAxis->setRange(0,4800);
    ui.widget->yAxis->setRange(0,4200);

    ui.widget->addGraph()->setData(x, y);

    ui.widget->addGraph()->setData(x, m);
    ui.widget->graph(1)->setPen(QPen(QColor(Qt::red)));

    ui.widget->graph(0)->setName("Wave");
    ui.widget->graph(1)->setName("Median");

    ui.widget->legend->setVisible(true);

    ui.widget->replot();


    ui.maxWave->setText( "Max:  Wave[" + QString::number(index) + "] =  " + QString::number(max)  +\
            ",  median = "   + QString::number(median)  );


}


void DataDialog::on_pause_clicked()
{

    if(updatable) {
        ui.pause->setText("Start");
        updatable = false;
    }

    else{
        ui.pause->setText("Pause");
        updatable = true;
    }
}


void DataDialog::on_filrter_valueChanged(int value)
{
    diff = value;
    ui.filterTitle->setText("Filter " + QString::number(value));

}

