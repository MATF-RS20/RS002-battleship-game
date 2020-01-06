#include "Game/Board/IBoard.hpp"
#include "Game/Board/Board.hpp"
#include <QTime>
#include <QMessageBox>

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
            m_boardPositions[i][j] = new Position(i, j, PositionStatus::Unknown, AvailabilityStatus::Available);
        }
    }
}

void Board::CreateShips()
{
    QVector<int> rows;
    do {
        int row = qrand() % 10;
        if (rows.contains(row) == false)
            rows.append(row);
    } while(rows.size() < 5);

    // Battleship
    int columnBattleship = qrand() % 6;
    QVector<Position*> battleshipPosition = {new Position(rows[0], columnBattleship, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                             new Position(rows[0], columnBattleship+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                             new Position(rows[0], columnBattleship+2, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                             new Position(rows[0], columnBattleship+3, PositionStatus::Unknown, AvailabilityStatus::Busy)};
    // Carrier
    int columnCarrier = qrand() % 5;
    QVector<Position*> carrierPosition = {new Position(rows[1], columnCarrier, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[1], columnCarrier+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[1], columnCarrier+2, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[1], columnCarrier+3, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[1], columnCarrier+4, PositionStatus::Unknown, AvailabilityStatus::Busy)};
    // Cruiser
    int columnCruiser = qrand() % 7;
    QVector<Position*> cruiserPosition = {new Position(rows[2], columnCruiser, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[2], columnCruiser+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                          new Position(rows[2], columnCruiser+2, PositionStatus::Unknown, AvailabilityStatus::Busy)};

    // Submarine
    int columnSubmarine = qrand() % 7;
    QVector<Position*> submarinePosition = {new Position(rows[3], columnSubmarine, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                            new Position(rows[3], columnSubmarine+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                            new Position(rows[3], columnSubmarine+2, PositionStatus::Unknown, AvailabilityStatus::Busy)};

    // Destroyer
    int columnDestroyer = qrand() % 8;
    QVector<Position*> destroyerPosition = {new Position(rows[4], columnDestroyer, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                            new Position(rows[4], columnDestroyer+1, PositionStatus::Unknown, AvailabilityStatus::Busy)};

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

void Board::SetShipOnPositions(ShipType ship, QVector<QPair<int, int>> positions)
{
    switch(ship)
    {
    case ShipType::BattleshipType:
    {
        CheckPositionsValues(BATTLESHIP_SIZE, positions);
        QVector<Position*> battleshipPosition = {new Position(positions[0].first, positions[0].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[3].first, positions[3].second, PositionStatus::Unknown, AvailabilityStatus::Busy)};
        IShip* battleship = m_shipFactory->CreateShip(ShipType::BattleshipType, battleshipPosition);
        m_ships.push_back(battleship);
        break;
    }
    case ShipType::CruiserType:
    {
        CheckPositionsValues(CRUISER_SIZE, positions);
        QVector<Position*> cruiserPosition = {new Position(positions[0].first, positions[0].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                               new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                               new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy)};
        IShip* cruiser = m_shipFactory->CreateShip(ShipType::CruiserType, cruiserPosition);
        m_ships.push_back(cruiser);
        break;
    }

    case ShipType::CarrierType:
    {
        CheckPositionsValues(CARRIER_SIZE, positions);
        QVector<Position*> carrierPosition = {new Position(positions[0].first, positions[0].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                               new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                               new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                               new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                              new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy)};
        IShip* carrier = m_shipFactory->CreateShip(ShipType::CarrierType, carrierPosition);
        m_ships.push_back(carrier);
        break;
    }
    case ShipType::SubmarineType:
    {
        CheckPositionsValues(SUBMARINE_SIZE, positions);
        QVector<Position*> submarinePosition = {new Position(positions[0].first, positions[0].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy)};
        IShip* submarine = m_shipFactory->CreateShip(ShipType::SubmarineType, submarinePosition);
        m_ships.push_back(submarine);
        break;
    }
    case ShipType::DestroyerType:
    {
        CheckPositionsValues(DESTROYER_SIZE, positions);
        QVector<Position*> destroyerPosition = {new Position(positions[0].first, positions[0].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[1].first, positions[1].second, PositionStatus::Unknown, AvailabilityStatus::Busy),
                                                 new Position(positions[2].first, positions[2].second, PositionStatus::Unknown, AvailabilityStatus::Busy)};
        IShip* destroyer = m_shipFactory->CreateShip(ShipType::DestroyerType, destroyerPosition);
        m_ships.push_back(destroyer);
        break;
    }
    default:
        break;
    }
}

void Board::CheckPositionsValues(uint shipSize, QVector<QPair<int, int>> positions)
{
    if(positions.size() != shipSize)
    {
        QMessageBox gameOverMsgBox;
        gameOverMsgBox.setText(QString("Ship size does not match chosen number of position."));
        gameOverMsgBox.exec();
    }
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
