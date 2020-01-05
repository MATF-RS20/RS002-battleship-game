#include "Game/Board/IBoard.hpp"
#include "Game/Board/Board.hpp"

Board::Board() :
    m_ships(),
    m_shipFactory(new ShipFactory())
{}

Board::~Board()
{
    delete m_boardPositions;
}

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

void Board::CreateShips()
{
    // Battleship
    QVector<Position*> battleshipPosition = {new Position(0, 0, PositionStatus::Unknown),
                                             new Position(0, 1, PositionStatus::Unknown),
                                             new Position(0, 2, PositionStatus::Unknown),
                                             new Position(0, 3, PositionStatus::Unknown)};
    // Carrier
    QVector<Position*> carrierPosition = {new Position(1, 0, PositionStatus::Unknown),
                                          new Position(1, 1, PositionStatus::Unknown),
                                          new Position(1, 2, PositionStatus::Unknown),
                                          new Position(1, 3, PositionStatus::Unknown),
                                          new Position(1, 4, PositionStatus::Unknown)};
    // Cruiser
    QVector<Position*> cruiserPosition = {new Position(2, 0, PositionStatus::Unknown),
                                          new Position(2, 1, PositionStatus::Unknown),
                                          new Position(2, 2, PositionStatus::Unknown)};

    // Submarine
    QVector<Position*> submarinePosition = {new Position(3, 0, PositionStatus::Unknown),
                                            new Position(3, 1, PositionStatus::Unknown),
                                            new Position(3, 2, PositionStatus::Unknown)};

    // Destroyer
    QVector<Position*> destroyerPosition = {new Position(4, 0, PositionStatus::Unknown),
                                            new Position(4, 1, PositionStatus::Unknown)};

    IShip* battleship = m_shipFactory->CreateShip(ShipType::BattleshipType, battleshipPosition);
    IShip* carrier = m_shipFactory->CreateShip(ShipType::CarrierType, carrierPosition);
    IShip* cruiser = m_shipFactory->CreateShip(ShipType::CruiserType, cruiserPosition);
    IShip* destroyer = m_shipFactory->CreateShip(ShipType::DestroyerType, destroyerPosition);
    IShip* submarine = m_shipFactory->CreateShip(ShipType::SubmarineType, submarinePosition);

    m_ships.push_back(battleship);
    m_ships.push_back(carrier);
    m_ships.push_back(cruiser);
    m_ships.push_back(destroyer);
    m_ships.push_back(submarine);
}

void Board::PlaceShips(int x, int y)
{

}

int Board::NumberOfAvailableShips()
{
    foreach (IShip* ship, m_ships) {
        if(ship->GetShipStatus() == ShipStatus::Sunken)
            m_ships.remove(m_ships.indexOf(ship));
    }

    return m_ships.size();
}

void Board::AttackOnCoordinates(int x, int y)
{
    PositionStatus attackStatus = PositionStatus::Miss;

    foreach (IShip* ship, m_ships) {

        QVector<Position*> shipPositions;
        shipPositions = ship->getShipPositions();

        foreach (Position* shipCoordinate, shipPositions) {
            if(shipCoordinate->m_coordinateX == x
               && shipCoordinate->m_coordinateY == y)
            {
                attackStatus = PositionStatus::Hit;
                shipCoordinate->m_status = PositionStatus::Hit;
            }
        }
    }

    m_boardPositions[x][y]->m_status = attackStatus;
}

PositionStatus Board::GetPositionStatus(int x, int y)
{
    PositionStatus status = m_boardPositions[x][y]->m_status;
    return status;
}

QVector<IShip*> Board::GetShips()
{
    return m_ships;
}
