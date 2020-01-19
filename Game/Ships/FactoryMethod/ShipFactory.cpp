#include "ShipFactory.hpp"
#include "Game/Ships/ShipTypes/Carrier.hpp"
#include "Game/Ships/ShipTypes/Cruiser.hpp"
#include "Game/Ships/ShipTypes/Destroyer.hpp"
#include "Game/Ships/ShipTypes/Submarine.hpp"
#include "Game/Ships/ShipTypes/Battleship.hpp"

ShipFactory::ShipFactory()
{}

IShip* ShipFactory::CreateShip(ShipType shipType, QVector<std::shared_ptr<Position>> shipCoordinates)
{
    IShip* pShip = nullptr;
    switch (shipType) {
        case ShipType::CarrierType:
            pShip = new Carrier(shipCoordinates);
            break;
        case ShipType::CruiserType:
            pShip = new Cruiser(shipCoordinates);
            break;
        case ShipType::DestroyerType:
            pShip = new Destroyer(shipCoordinates);
            break;
        case ShipType::SubmarineType:
            pShip = new Submarine(shipCoordinates);
            break;
        case ShipType::BattleshipType:
            pShip = new Battleship(shipCoordinates);
            break;
    }

    return pShip;
}
