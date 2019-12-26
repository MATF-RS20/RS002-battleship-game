#ifndef POSITION_HPP
#define POSITION_HPP

#include "Game/Board/IBoard.hpp"

struct Position
{
    Position(int x, int y, PositionStatus status)
    {
        m_coordinateX = x;
        m_coordinateY = y;
        m_status = status;
    }

    int m_coordinateX;
    int m_coordinateY;
    PositionStatus m_status;

};

#endif // POSITION_HPP
