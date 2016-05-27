#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    stack = new QStackedWidget;
    startMenu = new Dialog();
    b = new Board();

    stack->addWidget(startMenu);
    stack->addWidget(b);
    stack->setCurrentWidget(startMenu);

    setFixedSize(stack->currentWidget()->size());
    move((QApplication::desktop()->width() - this->width()) /2,
         (QApplication::desktop()->height() - this->height()) /2);

    setWindowTitle(tr("Chess Game"));
    setCentralWidget(stack);
    connect(startMenu,SIGNAL(rejected()),SLOT(close()));
    connect(startMenu,SIGNAL(accepted()),SLOT(startButtonPressed()));
    close();

}


void MainWindow::startButtonPressed()
{
    stack->setCurrentWidget(b);
    setFixedSize(stack->currentWidget()->size());
    move((QApplication::desktop()->width() - this->width()) /2,
         (QApplication::desktop()->height() - this->height()) /2);
    setCentralWidget(stack);
}
