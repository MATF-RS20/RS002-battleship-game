#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "Game/Board/IBoard.hpp"
#include <QString>

enum PlayerType {
    Human = 0,
    Computer
};

class IPlayer
{
public:
    virtual ~IPlayer() {}

    virtual QString GetPlayerName() = 0;
    virtual PlayerType GetPlayerType() = 0;
    virtual IBoard* GetBoard() = 0;
};

#endif // IPLAYER_HPP
