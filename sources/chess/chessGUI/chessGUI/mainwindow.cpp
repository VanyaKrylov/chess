#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    /*QHBoxLayout *hl = new QHBoxLayout;
    QVBoxLayout *vl = new QVBoxLayout;
    QLabel *lbl = new QLabel;
    lbl->setText(tr("Are you sure?"));
    yes = new QPushButton;
    no = new QPushButton;*/
    stack = new QStackedWidget;
    startMenu = new Dialog();


    /*hl->addWidget(yes);
    hl->addWidget(no);

    vl->addLayout(hl);
    vl->addWidget(lbl);
    setLayout(vl);*/

    stack->addWidget(startMenu);
    stack->setCurrentWidget(startMenu);
    setFixedSize(stack->currentWidget()->size());
    setCentralWidget(stack);
    connect(startMenu,SIGNAL(rejected()),SLOT(close()));
    //connect(yes,SIGNAL(clicked(bool)),SLOT(close()));
    //connect(no,SIGNAL(clicked(bool)),SLOT(noButtonPressed()));

}

void MainWindow::exitButtonPressed()
{
    close();
}
