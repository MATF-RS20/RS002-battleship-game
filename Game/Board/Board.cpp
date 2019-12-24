#include "Game/Board/Board.hpp"

Board::Board() :
    m_ships()
{}

void Board::InitializeBoard()
{

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
