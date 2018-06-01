#include <iostream>
#include "Ship.hpp"

int main()
{
    // Test ship constructor 
    Ship ship1("ship1", 4);
    
    std::cout << "name: " << ship1.getName() << " length: " 
              << ship1.getLength() << " damage: " << ship1.getDamage();
    // Test takeHit
    ship1.takeHit();
    std::cout << "\ndamage: " << ship1.getDamage();


    return 0;
}
