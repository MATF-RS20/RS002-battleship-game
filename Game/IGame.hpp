#ifndef IGAME_HPP
#define IGAME_HPP

#include "Game/Player/IPlayer.hpp"

enum GameState
{
    InProgress,
    GameOver
};


class IGame
{
public:
    virtual ~IGame() {}
    virtual bool AttackBy(IPlayer* player, IPlayer* defender) = 0;
    virtual GameState GetGameState() = 0;
    virtual void SwapPlayers() = 0;
};

#endif // IGAME_HPP
