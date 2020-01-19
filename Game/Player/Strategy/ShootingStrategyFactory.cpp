#include "ShootingStrategyFactory.hpp"
#include "EasyMode.hpp"
#include "HardMode.hpp"

ShootingStrategyFactory::ShootingStrategyFactory()
{

}

std::shared_ptr<IShootingStrategy> ShootingStrategyFactory::CreateComputerStrategy(PlayerStrategy computerStrategy)
{
    switch(computerStrategy)
    {
        case PlayerStrategy::Easy:
        {
            return std::make_shared<EasyMode>();
        }
        case PlayerStrategy::Hard:
        {
            return std::make_shared<HardMode>();
        }
    }
}


