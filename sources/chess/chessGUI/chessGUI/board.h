#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QtWidgets>
#include "API.h"
#include "QApplication"

//#include "exceptions.h"



namespace Ui {
class Board;

}
/**
 * @brief The Board class
 */
class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);

    /**
     * @brief select - selects the figure
     * @param pe - pointer to MousePressEvent
     */
    void select(QMouseEvent *pe);

    /**
     * @brief moveFig - moves the figure
     * @param pe - pointer to MousePressEvent
     */
    void moveFig(QMouseEvent *pe);
    ~Board();

protected:
    /**
     * @brief mousePressEvent - overrided mousePressEvent
     * @param pe - pointer to mousePressEvent
     */
    virtual void mousePressEvent(QMouseEvent *pe);

signals:
    void gameIsOver();

private:
    Ui::Board *ui;
    QLabel * label;
    QMouseEvent *pe;
    ChessEngine engine;
};

#endif // BOARD_H
