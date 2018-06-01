/************************************************************
 * Author: Tyler Freitas
 * Date: 05/31/2018
 * Description: This file implements a BBoard class that 
 * represents a board for playing battleship. 
************************************************************/

#include "Ship.hpp"
#include "BBoard.hpp"
BBoard::BBoard()
{
    m_unsunk = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            m_attacked[i][j] = false;
            m_shipLocations[i][j] = nullptr;
        }
    }
}


bool BBoard::getAttacksArrayElement(int row, int col)
{
    return m_attacked[row][col];
}


Ship* BBoard::getShipsArrayElement(int row, int col)
{
    return m_shipLocations[row][col];
}


int BBoard::getNumShipsRemaining()
{
    return m_unsunk;
}


/************************************************************
 * Description: This function takes a pointer to a ship 
 * object, its row and column closest to (0,0), and its 
 * orientation ('R' if ship occupies a row, or 'C' if it
 * occupies a column. If the ship fits on the board and
 * doesn't overlap another ship the function places the 
 * ship and returns true. Otherwise, it returns false.
************************************************************/
bool BBoard::placeShip(Ship& ship,
                       int row,
                       int col,
                       char orientation)
{
    bool shipPlaced = false;
    int squaresPlaced = 0;
    
    // Check bounds of board array when placing whip in a 
    // row or column. 
    if(orientation == 'C' 
       && (row + ship.getLength() -1 < 10)
       && row >= 0)
    {
        shipPlaced = true;
    }
    else if(orientation == 'R' 
            && (col + ship.getLength() -1< 10)
            && row >= 0)
    {
        shipPlaced = true;
    } 

    // Place ship address in each squre that the ship will occupy
    while((squaresPlaced < ship.getLength()) && shipPlaced)
    {
        // Place ship and increment index according to ship
        // orientation.
        if(orientation == 'C' 
           && m_shipLocations[row][col] == nullptr)
        {
            m_shipLocations[row][col] = &ship; 
            row++;
            squaresPlaced++;
        }
        else if(orientation == 'R'
                && m_shipLocations[row][col] == nullptr)
        {
            m_shipLocations[row][col] = &ship;
            col++;
            squaresPlaced++;
        }
        else
        {
            shipPlaced = false;
        }
    }
    
    // Increase number of unsunk ships if new ship is placed.
    if(shipPlaced)
    {
        m_unsunk++;
    }
    return shipPlaced;
}


/************************************************************
 * Description: This funciton allows the player to attack a 
 * specific location on the board. If there is a ship there
 * and the squre has not been previously hit the ship will 
 * take damage and the hit will be recorded in the array. 
 * If the entire ship is hit it will sink. This 
 * function returs true on all hits (even repeats) and false
 * on misses.
************************************************************/
bool BBoard::attack(int row, int col)
{
    // Record if attack is a hit.
    bool hit = false; 
    // Store ship pointer from ship array.
    Ship* shipLocation = getShipsArrayElement(row, col);
    // Set to true if location has been previouly attacked.
    bool previousHit = getAttacksArrayElement(row, col);

    // Record misses on unattacked squares.
    if(!previousHit && shipLocation == nullptr)
    {
        hit = false;
        
        m_attacked[row][col] = true; 
    }
    // Record hit on unattacked square and update status of
    // the hit ship.
    else if(!previousHit && shipLocation != nullptr)
    {
        hit = true; 
        m_attacked[row][col] = true; 
        shipLocation->takeHit();
        if(shipLocation->getDamage() == shipLocation->getLength())
        {
            m_unsunk--;
            std::cout << "They sank " << shipLocation->getName() 
                      << "!";
        }
    }
    // Hits on previously hit squares still count as true.
    else if(previousHit && shipLocation != nullptr)
    {
        hit = true;
    }

    return hit;

}


void BBoard::printBoard()
{
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
        {
            if(!m_attacked[row][col]
               && m_shipLocations[row][col] == nullptr)
                std::cout << '.';
            else if(!m_attacked[row][col] 
                    && m_shipLocations[row][col] != nullptr)
                std::cout << 's';
            else if(m_attacked[row][col]
                    && m_shipLocations[row][col] == nullptr)
                std::cout << 'o';
            else if(m_attacked[row][col]
                    && m_shipLocations[row][col] != nullptr)
                std::cout << 'x';
        }
        std::cout << '\n';
    }
}
