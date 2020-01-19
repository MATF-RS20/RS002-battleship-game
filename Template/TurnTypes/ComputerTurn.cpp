#include "Template/TurnTypes/ComputerTurn.hpp"
#include "Game/Player/Strategy/ShootingStrategyFactory.hpp"
#include <QTime>

ComputerTurn::ComputerTurn(std::shared_ptr<IPlayer> attacker)
    : m_attacker(attacker),
      m_strategy()
{
    //ShootingStrategyFactory shootingStrategyFactory;
    //m_strategy = shootingStrategyFactory.CreateComputerStrategy(attacker->GetPlayerStrategy());
}

std::shared_ptr<Shoot> ComputerTurn::CreateShoot()
{
    ShootingStrategyFactory shootingStrategyFactory;
    m_strategy = shootingStrategyFactory.CreateComputerStrategy(m_attacker->GetPlayerStrategy());

    QPair<int, int> position = m_strategy->GetAttackingPosition(m_attacker);

    std::shared_ptr<Shoot> shoot = std::make_shared<Shoot>(position.first, position.second);
    return shoot;
}
