#ifndef SHIPFACTORY_HPP
#define SHIPFACTORY_HPP

#include "Game/Ships/iship.hpp"
#include "Game/Ships/ShipTypes/carrier.hpp"

class ShipFactory
{
public:
    ShipFactory();

    IShip* CreateShip(ShipType shipType);
};


#endif // SHIPFACTORY_HPP
