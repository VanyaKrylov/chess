#ifndef CHESSENGINE_H
#define CHESSENGINE_H
#include "board.h"

class ChessEngine
{

public:
    ChessEngine();

    /**
     * @brief choose the element on the board
     * @param pos - reference to Cell object which contains position of the element to be chosen
     */
    void choose(Cell& pos);

    /**
     * @brief move - move chosen figure to another position on the board
     * @param pos - reference to Cell object - position where selectedFigure will be placed
     */
    void move(Cell& pos);

private:
    Board board;


};

#endif // CHESSENGINE_H
