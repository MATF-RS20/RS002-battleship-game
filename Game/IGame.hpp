#ifndef IGAME_HPP
#define IGAME_HPP

#include "Game/Player/IPlayer.hpp"
#include <memory>

enum GameState
{
    InProgress,
    GameOver
};


class IGame
{
public:
    virtual ~IGame() {}
    virtual bool AttackBy(std::shared_ptr<IPlayer> player, std::shared_ptr<IPlayer> defender) = 0;
    virtual GameState GetGameState() = 0;
};

#endif // IGAME_HPP
