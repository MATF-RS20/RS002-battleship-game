#include "Template/TurnTypes/ComputerTurn.hpp"
#include "Game/Player/Strategy/ShootingStrategyFactory.hpp"
#include <QTime>

ComputerTurn::ComputerTurn(std::shared_ptr<IPlayer> attacker)
    : m_attacker(attacker),
      m_strategy()
{
}

std::shared_ptr<Shoot> ComputerTurn::CreateShoot()
{
    ShootingStrategyFactory shootingStrategyFactory;
    m_strategy = shootingStrategyFactory.CreateComputerStrategy(m_attacker->GetPlayerStrategy());

    std::shared_ptr<Position> position = m_strategy->GetAttackingPosition(m_attacker);
    std::shared_ptr<Shoot> shoot = std::make_shared<Shoot>(position->m_coordinateX, position->m_coordinateY);
    return shoot;
}
