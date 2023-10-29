#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>

#include "mynwork.h"
#include "datadialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    Ui::MainWindow *ui;


private slots:
    void goView();

    void about();
    void aboutMore();


private:


    void createActions();
    void createMenus();

    QMenu *viewerMenu;
    QMenu *helpMenu;
    QAction *viewAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutFilterAct;

    Mynwork * nw;
    DataDialog * dataDialog;

signals:
};
#endif // MAINWINDOW_H
