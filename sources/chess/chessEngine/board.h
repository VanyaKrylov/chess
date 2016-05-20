#ifndef BOARD_H
#define BOARD_H
#include"figures.h"

//TODO в c++ используется cmath
#include <math.h>

//Документировать класс. имя тут надо документировать.
//TODO везде, где надо, добавить const, noexcept.
//Определиться с *T и * T

class Board
{
public:
    Board();
    ~Board();

    /**
     * @brief addFigure - adding a figure to the board
     * @param fig - pointer to Figure object
     */
    
    //* fig 
    void addFigure(Figure* fig);

    /**
     * @brief removeFigure - replaces figure from the current place on the board with a nullptr
     * @param pos - reference to Cell object of the figure's position
     */
    
    //*pos - везде по-разному
    void removeFigure(Cell *pos);

    /**
     * @brief selectFigure - select a figure, changes the selectedFigure value
     * @param cell
     */
    void selectFigure(Cell *cell);

    /**
     * @brief changePosition - moves the selectedFigure to pos2
     * @param pos2 - reference to Cell object, contains the position
     */
    void changePosition(Cell *pos);

    /**
     * @brief isFigureSelected - checks whether there is any Figure selected
     * @return bool value, TRUE - selected, FALSE - not selected
     */
    bool isFigureSelected();


    //TODO додокументировать x и y
    /**
     * @brief getFigure - gets the Figure from the array
     * @param x -
     * @param y
     * @return pointer to Figure object
     */
    Figure* getFigure(Cell* pos);

    /**
     * @brief getSelectedFigure - returns the selected figure
    //лучше без returns.
     * @return returns pointer to the SelectedFigure
     */
    Figure* getSelectedFigure();

    /**
     * @brief CheckPossibleMoves - game logic rules
     * @param pos - pointer to Cell object, position where the figure is supposed to be moves
     * @return TRUE if the rules are not broken, False otherwise
     */
    bool CheckPossibleMoves(Cell* pos);

private:
    Figure* pFigures[8][8];
    
    //с маленькой буквы - неконстантные объекты. с большой - классы
    Figure* SelectedFigure;

};

#endif // BOARD_H
