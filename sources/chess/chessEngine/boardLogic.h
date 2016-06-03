#pragma once
#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include"figures.h"
#include "exceptions.h"



#include <cmath>



/**
 * @brief The BoardLogic class - class which contains the Game board realisation and game logic
 */
class BoardLogic
{
public:
    BoardLogic();
    ~BoardLogic();

    /**
     * @brief addFigure - adding a figure to the board
     * @param fig - pointer to Figure object
     */
    void addMyFigure(myFigure *fig);

    /**
     * @brief removeFigure - replaces figure from the current place on the board with a nullptr
     * @param pos - reference to Cell object of the figure's position
     */
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



    /**
     * @brief getMyFigure - gets the pointer from the array
     * @param pos - position in the array
     * @return  pointer ti myFigure object
     */
    myFigure* getMyFigure(myCell *pos);

    /**
     * @brief getSelectedFigure - gets the selected figure
     * @return returns pointer to the SelectedFigure
     */
    myFigure* getSelectedFigure();

    /**
     * @brief CheckPossibleMoves - game logic rules
     * @param pos - pointer to Cell object, position where the figure is supposed to be moves
     * @return TRUE if the rules are not broken, False otherwise
     */
    bool checkPossibleMoves(myCell *pos);

    /**
     * @brief changePreviousColor changes the previousFigColor value
     */
    void changePreviousColor();

private:
    myFigure* pFigures[8][8];
    
    myFigure* selectedFigure;
    bool previousFigColor;

};

#endif // BOARDLOGIC_H
