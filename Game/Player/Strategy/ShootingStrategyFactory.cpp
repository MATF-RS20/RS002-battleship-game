#include "ShootingStrategyFactory.hpp"
#include "EasyMode.hpp"
#include "HardMode.hpp"

ShootingStrategyFactory::ShootingStrategyFactory()
{

}

IShootingStrategy* ShootingStrategyFactory::CreateComputerStrategy(PlayerStrategy computerStrategy)
{
    switch(computerStrategy)
    {
        case PlayerStrategy::Easy:
        {
            return new EasyMode();
        }
        case PlayerStrategy::Hard:
        {
            return new HardMode();
        }
    }
}


