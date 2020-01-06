#ifndef POSITION_HPP
#define POSITION_HPP

enum PositionStatus
{
    Unknown = 0,
    Hit,
    Miss
};

enum AvailabilityStatus
{
    Available = 0,
    Busy
};

struct Position {
    Position(int x, int y, PositionStatus status, AvailabilityStatus availabilityStatus)
    {
        m_coordinateX = x;
        m_coordinateY = y;
        m_status = status;
        m_availabilityStatus = availabilityStatus;
    }

    int m_coordinateX;
    int m_coordinateY;
    PositionStatus m_status;
    AvailabilityStatus m_availabilityStatus;
};

#endif // POSITION_HPP
