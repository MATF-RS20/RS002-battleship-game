#ifndef BOARD_HPP
#define BOARD_HPP

#define BOARD_SIZE 10

#include "Game/Board/IBoard.hpp"
#include "Game/Board/Position.hpp"

class Board : public IBoard
{
public:

    Board();

    void InitializeBoard() override;
    void CreateShips(int x, int y) override;
    void PlaceShips(int x, int y) override;
    int NumberOfAvailableShips() override;
    void SetXYStatus(int x, int y, PositionStatus xyStatus) override;
    QVector<IShip*> GetShips() override;

private:
    QVector<IShip*> m_ships;
    Position* m_boardPositions[BOARD_SIZE][BOARD_SIZE];
};

#endif // BOARD_HPP
