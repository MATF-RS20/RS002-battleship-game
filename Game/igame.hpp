#ifndef IGAME_HPP
#define IGAME_HPP

#include "Game/Board/IBoard.hpp"
#include "Player/IPlayer.hpp"

enum GameStatus {
    InProgress = 0,
    GameOver
};

class IGame
{
public:
    virtual ~IGame() {}

    virtual void InitializeGame(IPlayer player1, IPlayer player2) = 0;
    virtual void AttackBy(IPlayer player) = 0;
    virtual GameStatus GetGameStatus() = 0;
};

#endif // IGAME_HPP
