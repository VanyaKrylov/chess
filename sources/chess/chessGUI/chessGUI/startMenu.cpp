#include "startMenu.h"
#include "ui_startMenu.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPalette pal;
    pal.setBrush(backgroundRole(),QPixmap(":/startMenu.png"));
    pal.setBrush(QPalette::ButtonText,QBrush(Qt::white));
    setPalette(pal);
    setFixedSize(QPixmap(":/startMenu.png").size());

    ui->startButton->setText(tr("Start Game"));
    ui->exitButton->setText(tr("Exit"));

}

Dialog::~Dialog()
{
    delete ui;
}
