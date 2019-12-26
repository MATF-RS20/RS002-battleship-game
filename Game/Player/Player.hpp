#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Game/Player/IPlayer.hpp"

class Player : public IPlayer
{
public:
    Player(QString playerName, PlayerType player);

    QString GetPlayerName() override;
    PlayerType GetPlayerType() override;
    IBoard* GetBoard() override;

private:
    IBoard* m_board;
    PlayerType m_player;
    QString m_playerName;

};

#endif // PLAYER_HPP
