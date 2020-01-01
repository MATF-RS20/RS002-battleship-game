#ifndef SHIPFACTORY_HPP
#define SHIPFACTORY_HPP

#include "Game/Ships/IShip.hpp"

class ShipFactory
{
public:
    ShipFactory();

    IShip* CreateShip(ShipType shipType);
};


#endif // SHIPFACTORY_HPP
