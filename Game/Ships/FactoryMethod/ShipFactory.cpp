#include "ShipFactory.hpp"

ShipFactory::ShipFactory()
{}

IShip* ShipFactory::CreateShip(ShipType shipType)
{
    IShip* pShip = nullptr;
    switch (shipType) {
        case ShipType::Carrier:
            //pShip = new Carrier();
            break;
        case ShipType::Cruiser:
            //pShip = new Cruiser(); // todo : implementirati Cruiser klasu
            break;
        case ShipType::Destroyer:
            //pShip = new Destroyer(); // todo : implementirati Destroyer klasu
            break;
        case ShipType::Submarine:
            //pShip = new Submarine(); // todo : implementirati Submarine klasu
            break;
        case ShipType::Battleship:
            //pShip = new Battleship(); // todo : implementirati Battleship klasu
            break;
    }

    return pShip;
}
