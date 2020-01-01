#ifndef BOARD_HPP
#define BOARD_HPP

#define BOARD_SIZE 10

#include "Game/Board/IBoard.hpp"
#include "Game/Board/Position.hpp"
#include "Game/Ships/FactoryMethod/ShipFactory.hpp"

class Board : public IBoard
{
public:

    Board();

    void InitializeBoard() override;
    void CreateShips() override;
    void PlaceShips(int x, int y) override;
    int NumberOfAvailableShips() override;
    void SetXYStatus(int x, int y, PositionStatus xyStatus) override;
    QVector<ShipCoordinates*> GetShips() override;

private:
    QVector<ShipCoordinates*> m_ships;
    Position* m_boardPositions[BOARD_SIZE][BOARD_SIZE];
    ShipFactory* m_shipFactory;
};

#endif // BOARD_HPP
