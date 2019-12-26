#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Game/Player/IPlayer.hpp"

class Player : public IPlayer
{
public:
    Player(QString playerName, PlayerType playerType);

    QString GetPlayerName() override;
    PlayerType GetPlayerType() override;
    IBoard* GetBoard() override;

private:
    PlayerType m_playerType;
    QString m_playerName;
    IBoard* m_board;
};

#endif // PLAYER_HPP
