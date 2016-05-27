#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);

    QPalette pal;
    pal.setBrush(backgroundRole(),QPixmap(":/board.png"));
    setPalette(pal);
    setFixedSize(QPixmap(":/board.png").size());
}

Board::~Board()
{
    delete ui;
}
