#pragma once
#ifndef CHESSENGINE_H
#define CHESSENGINE_H
#include "boardLogic.h"
#include "exceptions.h"
//додокументировать
//TODO где надо добавить const
class ChessEngine
{

public:
    ChessEngine();

    /**
     * @brief chooseFigure - select a figure
     * @param x - position x
     * @param y - position y
     */
    void chooseMyFigure(int x, int y);

    /**
     * @brief moveFigure
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void moveMyFigure(int x, int y);

    /**
     * @brief getMyFigure return pointer to the object on current position
     * @param x - horizontal coordinate
     * @param y - vertical coordinate
     * @return pointer to myFigure object
     */
    myFigure* getMyFigure(int x, int y);

    /**
     * @brief isFigureSelected - checks whether the figure is selected or not
     * @return TRUE if selected and FALSE if not
     */
    bool isFigureSelected();


private:
    //TODO подумать о том, чтобы динамически создавать объекты.
    //не только к данному месту относится.
    //и с указателями, выделением, освобождением памяти поупражняешься.
    //и более высокую эффективность получишь
    //profit.

    //ну это так, на будущее.
    BoardLogic chessBoard;


};

#endif // CHESSENGINE_H
