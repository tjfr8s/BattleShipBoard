/************************************************************
 * Author: Tyler Freitas
 * Date: 05/31/2018
 * Description: This file defines a BBoard class that 
 * represents a board for playing battleship. 
************************************************************/
#ifndef BBOARD_HPP
#define BBOARD_HPP

#include <iostream>
#include "Ship.hpp"

class BBoard
{
private:
    bool m_attacked[10][10];
    Ship* m_shipLocations[10][10];
    int m_unsunk;
public:
    BBoard();
    
    bool getAttacksArrayElement(int row, int col);
    Ship* getShipsArrayElement(int row, int col);
    int getNumShipsRemaining();

    bool placeShip(Ship& ship, 
                   int row, 
                   int col, 
                   char orientation);

    void printBoard();

    bool attack(int row, int col);


};

#endif
