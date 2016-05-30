#pragma once
#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include"figures.h"


//TODO в c++ используется cmath
#include <math.h>

//Документировать класс. имя тут надо документировать.
//TODO везде, где надо, добавить const, noexcept.
//Определиться с *T и * T

class BoardLogic
{
public:
    BoardLogic();
    ~BoardLogic();

    /**
     * @brief addFigure - adding a figure to the board
     * @param fig - pointer to Figure object
     */
    
    //* fig 
    void addMyFigure(myFigure* fig);

    /**
     * @brief removeFigure - replaces figure from the current place on the board with a nullptr
     * @param pos - reference to Cell object of the figure's position
     */
    
    //*pos - везде по-разному
    void removeMyFigure(myCell *pos);

    /**
     * @brief selectFigure - select a figure, changes the selectedFigure value
     * @param cell
     */
    void selectMyFigure(myCell *cell);

    /**
     * @brief changePosition - moves the selectedFigure to pos2
     * @param pos2 - reference to Cell object, contains the position
     */
    void changeMyFigPosition(myCell *pos);

    /**
     * @brief isFigureSelected - checks whether there is any Figure selected
     * @return bool value, TRUE - selected, FALSE - not selected
     */
    bool isMyFigureSelected();


    //TODO додокументировать x и y
    /**
     * @brief getFigure - gets the Figure from the array
     * @param x -
     * @param y
     * @return pointer to Figure object
     */
    myFigure* getMyFigure(myCell* pos);

    /**
     * @brief getSelectedFigure - returns the selected figure
    //лучше без returns.
     * @return returns pointer to the SelectedFigure
     */
    myFigure* getSelectedFigure();

    /**
     * @brief CheckPossibleMoves - game logic rules
     * @param pos - pointer to Cell object, position where the figure is supposed to be moves
     * @return TRUE if the rules are not broken, False otherwise
     */
    bool checkPossibleMoves(myCell* pos);

private:
    myFigure* pFigures[8][8];
    
    //с маленькой буквы - неконстантные объекты. с большой - классы
    myFigure* selectedFigure;

};

#endif // BOARDLOGIC_H
