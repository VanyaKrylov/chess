#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QtWidgets>
#include "API.h"


//#include "exceptions.h"



namespace Ui {
class Board;
class ChessEngine;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    //int getXposCursor(QMouseEvent *pe);
    //int getYposCursor(QMouseEvent *pe);


    //void select(QMouseEvent *pe);
    //void moveFig(QMouseEvent *pe);
    ~Board();

protected:
    //virtual void mousePressEvent(QMouseEvent *pe);

private:
    Ui::Board *ui;
    //QMouseEvent *pe;
    ChessEngine *engine;
};

#endif // BOARD_H
