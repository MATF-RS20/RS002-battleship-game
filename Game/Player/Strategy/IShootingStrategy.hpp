#ifndef ISHOOTINGSTRATEGY_HPP
#define ISHOOTINGSTRATEGY_HPP

#include "Game/Player/IPlayer.hpp"
#include "Game/Board/Position.hpp"
#include <memory>

class IShootingStrategy
{
public:
    virtual ~IShootingStrategy() {}

    virtual std::shared_ptr<Position> GetAttackingPosition(std::shared_ptr<IPlayer> attacker) = 0;
};

#endif // ISHOOTINGSTRATEGY_HPP
