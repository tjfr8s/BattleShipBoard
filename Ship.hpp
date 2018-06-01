/************************************************************
 * Author: Tyler Freitas
 * Date: 05/30/2018
 * Description: This file implements a Ship class that 
 * represents a ship for use in a battleship game.
************************************************************/
#ifndef SHIP_HPP
#define SHIP_HPP

#include <string>

class Ship
{
private:
    std::string m_name;
    int m_length;
    int m_damage;

public:
    Ship(std::string name, int length);
    
    std::string getName();    
    int getLength();
    int getDamage();

    void takeHit();
};
#endif 
