#include "board.h"
#include "ui_board.h"


Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);

    //pe = new QMouseEvent;

    QPalette pal;
    pal.setBrush(backgroundRole(),QPixmap(":/board.png"));
    setPalette(pal);
    setFixedSize(QPixmap(":/board.png").size());



}



/*void Board::mousePressEvent(QMouseEvent *pe)
{
    if(engine.isFigureSelected() == 0)
        select(pe);
    else
        moveFig(pe);
}



void Board::select(QMouseEvent *pe)
{
    try{
        engine->chooseMyFigure(pe->x()/100,pe->y()/100);
    }
    catch(OutOfBoardException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
    }
    catch(EmptyCellException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
    }
}



void Board::moveFig(QMouseEvent *pe)
{
    try{
        engine->moveMyFigure(pe->x()/100,pe->y()/100);
    }
    catch(OutOfBoardException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
    }
    catch(AgainstTheRulesException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
    }
    catch(SameColorFigureException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
    }
}
*/



Board::~Board()
{
    delete ui;
}
