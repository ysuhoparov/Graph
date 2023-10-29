#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <about.h>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QWidget *widget = new QWidget;
    QWidget *topFiller = new QWidget;
    QWidget *bottomFiller = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    setWindowTitle("Wave viewer");
    resize(1280, 720);
    createMenus();

    nw = nullptr;
    dataDialog = nullptr;

}


MainWindow::~MainWindow()
{
    delete ui;
    if (nw!=nullptr) delete nw;
}

void MainWindow::goView()
{
    delete nw;

    dataDialog = new DataDialog(this);
    dataDialog->show();

    nw = new Mynwork();
    nw->initSocket(dataDialog);

}


void MainWindow::aboutMore()
{
    QMessageBox::about(this, tr("More "), ab.aboutF);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), ab.about);
}


void MainWindow::createMenus()
{
    viewerMenu = menuBar()->addMenu(tr("&Viewer "));

    viewAct = new QAction(tr("&Wave Viewer"), this);
    viewAct->setShortcuts(QKeySequence::AddTab);   // CtrT
    viewAct->setStatusTip(tr("Show the wave graph"));
    connect(viewAct, &QAction::triggered, this, &MainWindow::goView);
    viewerMenu->addAction(viewAct);

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Cut);  // CtrlX
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);
    viewerMenu->addSeparator();
    viewerMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
    helpMenu->addAction(aboutAct);

    aboutFilterAct = new QAction(tr("&More"), this);
    aboutFilterAct->setStatusTip(tr("Show the application's About more box"));
    connect(aboutFilterAct, &QAction::triggered, this, &MainWindow::aboutMore);
    helpMenu->addAction(aboutFilterAct);
}



