#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Game/Player/IPlayer.hpp"

class Player : public IPlayer
{
public:
    Player(IBoard* board, PlayerType player);

    QString GetPlayerName() override;
    PlayerType GetPlayerType() override;
    IBoard* GetBoard() override;

private:
    IBoard* m_board;
    PlayerType m_player;

};

#endif // PLAYER_HPP
