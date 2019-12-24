#ifndef SHIPFACTORY_HPP
#define SHIPFACTORY_HPP

#include "Game/Ships/IShip.hpp"
#include "Game/Ships/ShipTypes/Carrier.hpp"

class ShipFactory
{
public:
    ShipFactory();

    IShip* CreateShip(ShipType shipType);
};


#endif // SHIPFACTORY_HPP
