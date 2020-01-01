#include "ShipFactory.hpp"
#include "Game/Ships/ShipTypes/Carrier.hpp"
#include "Game/Ships/ShipTypes/Cruiser.hpp"
#include "Game/Ships/ShipTypes/Destroyer.hpp"
#include "Game/Ships/ShipTypes/Submarine.hpp"
#include "Game/Ships/ShipTypes/Battleship.hpp"

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
            pShip = new Cruiser();
            break;
        case ShipType::DestroyerType:
            pShip = new Destroyer();
            break;
        case ShipType::SubmarineType:
            pShip = new Submarine();
            break;
        case ShipType::BattleshipType:
            pShip = new Battleship();
            break;
    }

    return pShip;
}
