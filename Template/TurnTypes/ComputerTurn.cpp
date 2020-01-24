#include "Template/TurnTypes/ComputerTurn.hpp"
#include "Game/Player/Strategy/ShootingStrategyFactory.hpp"
#include <QTime>

ComputerTurn::ComputerTurn(std::shared_ptr<IPlayer> attacker)
    : m_attacker(attacker),
      m_strategy()
{
}

// For computer player, we have two different strategies
// and so we use shootingStrategyFactory to make the suitable one
std::shared_ptr<Shoot> ComputerTurn::CreateShoot()
{
    ShootingStrategyFactory shootingStrategyFactory;
    // we pass player's strategy argument to make suitable strategy
    m_strategy = shootingStrategyFactory.CreateComputerStrategy(m_attacker->GetPlayerStrategy());

    // either way, we get the position to attack
    std::shared_ptr<Position> position = m_strategy->GetAttackingPosition(m_attacker);
    // and make a shoot from it
    std::shared_ptr<Shoot> shoot = std::make_shared<Shoot>(position->m_coordinateX, position->m_coordinateY);
    return shoot;
}
