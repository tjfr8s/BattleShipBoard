#include "Ship.hpp"
/************************************************************
 * Author: Tyler Freitas
 * Date: 05/30/2018
 * Description: This file implements a Ship class that 
 * represents a ship for use in a battleship game.
************************************************************/


/************************************************************
 * Description: Constructor for ship object with namd and
 * length parameters. Initializes name, length, and damage
 * of ship objects.
 ************************************************************/
Ship::Ship(std::string name, int length)
{
    m_name = name;
    m_length = length; 
    m_damage = 0;
}


std::string Ship::getName()
{
    return m_name;
}


int Ship::getLength()
{
    return m_length;
}


int Ship::getDamage()
{
    return m_damage;
}


/************************************************************
 * Description: Increments the ship's damage by 1.
 ************************************************************/
void Ship::takeHit()
{
    m_damage++;
}
