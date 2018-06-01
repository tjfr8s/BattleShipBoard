#include <iostream>
#include "Ship.hpp"
#include "BBoard.hpp"

int main()
{
    // Test BBoard constructor
    BBoard board1;

    // Test getAttacksArrayElement() on single element
    if(board1.getAttacksArrayElement(1,1))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    // Test getShipsArrayElement
    board1.getShipsArrayElement(1,1);
    // Test placing a ship
    Ship bob("bob",3);
    if(board1.placeShip(bob, 2, 3, 'R'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    
    // Test placing new ship in same spot as old ship
    Ship ship1("bob2",3);
    if(board1.placeShip(ship1, 2, 3, 'R'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }

    // Test placing new ship overlapping end of another ship
    Ship ship2("bob3",3);
    if(board1.placeShip(ship2,2, 5, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    
    // Test placing ship past end of another ship
    Ship bob3("bob3",3);
    if(board1.placeShip(bob3, 2, 6, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }

    Ship ship3("bob4",3);

    // Test placing new ship overlapping start of another ship
    if(board1.placeShip(ship3, 2, 3, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    
    // Test placing ship before start of another ship
    Ship ship4("bob4",3);
    if(board1.placeShip(ship4, 2, 2, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }

    Ship ship5("bob5", 3);
    // Test placing ship that ends in last column
    if(board1.placeShip(ship5, 1, 7, 'R'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    
    Ship ship6("bob6",3);
    // Test placing ship that runs off last column
    if(board1.placeShip(ship6, 6, 8, 'R'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    Ship ship7("bob3", 3);
    // Test placing ship that ends in last row 
    if(board1.placeShip(ship7, 7, 2, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    // Test placing ship that runs off last row 
    Ship bob4("bob3",3);
    if(board1.placeShip(bob4, 8, 1, 'C'))
    {
        std::cout << "ship placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }
    else
    {
        std::cout << "ship not placed" << std::endl;
        board1.printBoard();
        std::cout << '\n';
    }

    // Test single attack.
    std::cout << "ships left: " << board1.getNumShipsRemaining() << "\n";
    board1.attack(7,2);
    board1.printBoard();
    std::cout << "\nships left: " << board1.getNumShipsRemaining() << "\n";

    board1.attack(8,2);
    board1.printBoard();
    std::cout << "\nships left: " << board1.getNumShipsRemaining() << "\n";
    board1.attack(9,2);
    std::cout << "\n";
    board1.printBoard();
    std::cout << "\nships left: " << board1.getNumShipsRemaining()<< "\n";
    
    
    return 0;
}
