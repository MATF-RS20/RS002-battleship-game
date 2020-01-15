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
    ~Board();

    void InitializeBoard() override;
    void CreateShips() override;    
    void SetShipOnPositions(ShipType ship, QVector<QPair<int, int>> positions) override;
    int NumberOfAvailableShips() override;    
    void AttackOnCoordinates(int x, int y) override;
    PositionStatus GetPositionStatus(int x, int y) override;
    QVector<IShip*> GetShips() override;
    AvailabilityStatus GetAvailabilityStatus(int x, int y) override;
    QVector<Position*> PlaceShipOnTable(int size);

private:
    void CheckPositionsValues(uint ship, QVector<QPair<int, int>> positions);

    QVector<IShip*> m_ships;
    Position* m_boardPositions[BOARD_SIZE][BOARD_SIZE];
    ShipFactory* m_shipFactory;

};

#endif // BOARD_HPP
