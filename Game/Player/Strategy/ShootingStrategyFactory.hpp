#ifndef SHOOTINGSTRATEGYFACTORY_HPP
#define SHOOTINGSTRATEGYFACTORY_HPP

#include "IShootingStrategy.hpp"

class ShootingStrategyFactory
{
public:
    ShootingStrategyFactory();

    IShootingStrategy* CreateComputerStrategy(PlayerStrategy computerStrategy);
};

#endif // SHOOTINGSTRATEGYFACTORY_HPP
