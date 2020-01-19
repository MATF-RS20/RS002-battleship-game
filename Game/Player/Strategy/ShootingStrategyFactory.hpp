#ifndef SHOOTINGSTRATEGYFACTORY_HPP
#define SHOOTINGSTRATEGYFACTORY_HPP

#include "IShootingStrategy.hpp"
#include <memory>

class ShootingStrategyFactory
{
public:
    ShootingStrategyFactory();

    std::shared_ptr<IShootingStrategy> CreateComputerStrategy(PlayerStrategy computerStrategy);
};

#endif // SHOOTINGSTRATEGYFACTORY_HPP
