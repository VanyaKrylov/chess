#include "startMenu.h"
#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mw = new MainWindow;

    mw->show();
    return a.exec();
}
