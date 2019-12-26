#include "Game/Board/Board.hpp"

Board::Board() :
    m_ships()
{}

void Board::InitializeBoard()
{
    for(int i = 0 ; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            m_boardPositions[i][j] = new Position(i,j, PositionStatus::Unknown);
        }
    }
}

void Board::CreateShips(int x, int y)
{

}

void Board::PlaceShips(int x, int y)
{

}

int Board::NumberOfAvailableShips()
{
    return 0;
}

void Board::SetXYStatus(int x, int y, PositionStatus xyStatus)
{

}

QVector<IShip*> Board::GetShips()
{
    return m_ships;
}
