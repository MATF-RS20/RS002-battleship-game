#include "ShipFactory.hpp"

ShipFactory::ShipFactory()
{}

IShip* ShipFactory::CreateShip(ShipType shipType)
{
    IShip* pShip = nullptr;
    switch (shipType) {
        case ShipType::CarrierType:
            pShip = new Carrier();
            break;
        case ShipType::CruiserType:
            //pShip = new Cruiser(); // todo : implementirati Cruiser klasu
            break;
        case ShipType::DestroyerType:
            //pShip = new Destroyer(); // todo : implementirati Destroyer klasu
            break;
        case ShipType::SubmarineType:
            //pShip = new Submarine(); // todo : implementirati Submarine klasu
            break;
        case ShipType::BattleshipType:
            //pShip = new Battleship(); // todo : implementirati Battleship klasu
            break;
    }

    return pShip;
}
