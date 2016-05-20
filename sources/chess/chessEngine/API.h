#ifndef CHESSENGINE_H
#define CHESSENGINE_H
#include "board.h"

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
    void chooseFigure(int x, int y);

    /**
     * @brief moveFigure
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void moveFigure(int x, int y);

    Figure* getFigure(int x, int y);



private:
    //TODO подумать о том, чтобы динамически создавать объекты.
    //не только к данному месту относится.
    //и с указателями, выделением, освобождением памяти поупражняешься.
    //и более высокую эффективность получишь
    //profit.
    
    //ну это так, на будущее. 
    Board board;


};

#endif // CHESSENGINE_H
