#include "Game/Board/IBoard.hpp"
#include "Game/Board/Board.hpp"
#include <QTime>

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
    QVector<int> rows;
    qsrand(QTime::currentTime().msec());
    do {
        int row = qrand() % 10;
        if (rows.contains(row) == false)
            rows.append(row);
    } while(rows.size() < 5);

    // Battleship
    int columnBattleship = qrand() % 6;
    QVector<Position*> battleshipPosition = {new Position(rows[0], columnBattleship, PositionStatus::Unknown),
                                             new Position(rows[0], columnBattleship+1, PositionStatus::Unknown),
                                             new Position(rows[0], columnBattleship+2, PositionStatus::Unknown),
                                             new Position(rows[0], columnBattleship+3, PositionStatus::Unknown)};
    // Carrier
    int columnCarrier = qrand() % 5;
    QVector<Position*> carrierPosition = {new Position(rows[1], columnCarrier, PositionStatus::Unknown),
                                          new Position(rows[1], columnCarrier+1, PositionStatus::Unknown),
                                          new Position(rows[1], columnCarrier+2, PositionStatus::Unknown),
                                          new Position(rows[1], columnCarrier+3, PositionStatus::Unknown),
                                          new Position(rows[1], columnCarrier+4, PositionStatus::Unknown)};
    // Cruiser
    int columnCruiser = qrand() % 7;
    QVector<Position*> cruiserPosition = {new Position(rows[2], columnCruiser, PositionStatus::Unknown),
                                          new Position(rows[2], columnCruiser+1, PositionStatus::Unknown),
                                          new Position(rows[2], columnCruiser+2, PositionStatus::Unknown)};

    // Submarine
    int columnSubmarine = qrand() % 7;
    QVector<Position*> submarinePosition = {new Position(rows[3], columnSubmarine, PositionStatus::Unknown),
                                            new Position(rows[3], columnSubmarine+1, PositionStatus::Unknown),
                                            new Position(rows[3], columnSubmarine+2, PositionStatus::Unknown)};

    // Destroyer
    int columnDestroyer = qrand() % 8;
    QVector<Position*> destroyerPosition = {new Position(rows[4], columnDestroyer, PositionStatus::Unknown),
                                            new Position(rows[4], columnDestroyer+1, PositionStatus::Unknown)};

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
