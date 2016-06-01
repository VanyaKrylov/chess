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



void Board::mousePressEvent(QMouseEvent *pe)
{
    if(engine.isFigureSelected() == 0)
        select(pe);
    else
        moveFig(pe);
}



void Board::select(QMouseEvent *pe)
{
    bool warning = 0;
    try{
        engine.chooseMyFigure(pe->x()/100,pe->y()/100);
    }
    catch(OutOfBoardException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }
    catch(EmptyCellException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }
    catch(WrongColorMoveException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }

    if (warning == 0){
        if(label = dynamic_cast<QLabel *>(qApp->widgetAt(pe->globalPos())))
                label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    }

}



void Board::moveFig(QMouseEvent *pe)
{
    bool warning = 0;
    try{
        engine.moveMyFigure(pe->x()/100,pe->y()/100);
    }
    catch(OutOfBoardException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }
    catch(AgainstTheRulesException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }
    catch(SameColorFigureException &e){
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        warning = 1;
    }
    catch(KingKilledException &e){
        if(QLabel *lbl = dynamic_cast<QLabel *>(qApp->widgetAt(pe->globalPos())))
            lbl->hide();
        label->move((pe->x()/100)*100, (pe->y()/100)*100);
        label->setFrameStyle(QFrame::Panel | QFrame::Plain);
        QMessageBox *mb = new QMessageBox(QMessageBox::Warning,"Message",e.what());
        mb->exec();
        delete mb;
        //this->close();
        emit gameIsOver();
    }

    if(warning == 0){
        if(QLabel *lbl = dynamic_cast<QLabel *>(qApp->widgetAt(pe->globalPos())))
            lbl->hide();
        label->move((pe->x()/100)*100, (pe->y()/100)*100);
        label->setFrameStyle(QFrame::Panel | QFrame::Plain);
    }

}




Board::~Board()
{
    delete ui;
}
