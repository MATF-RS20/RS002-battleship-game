#ifndef BOARD_HPP
#define BOARD_HPP

#include "Game/Board/IBoard.hpp"

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
};

#endif // BOARD_HPP
