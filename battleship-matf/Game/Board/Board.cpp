#include "Game/Board/IBoard.hpp"
#include "Game/Board/Board.hpp"
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <future>
#include <iostream>
#include <mutex>


#include "mainwindow.h"

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
//    QVector<int> rows;
//    QVector<int> cols;
//    do {
//        int row = qrand() % 10;
//        int col = qrand() % 10;
//        if (rows.contains(row) == false)
//            rows.append(row);
//        rows.append(row);
//        cols.append(col);
//    } while(rows.size() < 5);

    // Battleship
//    int columnBattleship = qrand() % 6;
//    QVector<Position*> battleshipPosition = {new Position(rows[0], columnBattleship, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                             new Position(rows[0], columnBattleship+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                             new Position(rows[0], columnBattleship+2, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                             new Position(rows[0], columnBattleship+3, PositionStatus::Unknown, AvailabilityStatus::Busy)};
    // horizontal position

    QVector<Position*> battleshipPosition = PlaceShipOnTable(4);
//    QVector<Position*> battleshipPosition = std::async(PlaceShipOnTable, 4);

    // Carrier
//    int columnCarrier = qrand() % 5;
//    QVector<Position*> carrierPosition = {new Position(rows[1], columnCarrier, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[1], columnCarrier+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[1], columnCarrier+2, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[1], columnCarrier+3, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[1], columnCarrier+4, PositionStatus::Unknown, AvailabilityStatus::Busy)};
    QVector<Position*> carrierPosition = PlaceShipOnTable(5);

    //    if(qrand() % 10 <= 5) {
//        while (GetAvailabilityStatus(rows[1], cols[1]) == Busy ||
//               GetAvailabilityStatus(rows[1], cols[1]+1) == Busy ||
//               GetAvailabilityStatus(rows[1], cols[1]+2) == Busy ||
//               GetAvailabilityStatus(rows[1], cols[1]+3) == Busy) {
//            rows[1] = qrand() % 10;
//            cols[1] = qrand() % 10;
//        }
//        carrierPosition = {new Position(rows[1], cols[1], PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1], cols[1]+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1], cols[1]+2, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1], cols[1]+3, PositionStatus::Unknown, AvailabilityStatus::Busy)};

//    } else { // vertical position
//        while (GetAvailabilityStatus(rows[1], cols[1]) == Busy ||
//               GetAvailabilityStatus(rows[1]+1, cols[1]) == Busy ||
//               GetAvailabilityStatus(rows[1]+2, cols[1]) == Busy ||
//               GetAvailabilityStatus(rows[1]+3, cols[1]) == Busy) {
//            rows[1] = qrand() % 10;
//            cols[1] = qrand() % 10;
//        }
//        carrierPosition = {new Position(rows[1], cols[1], PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1]+1, cols[1], PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1]+2, cols[1], PositionStatus::Unknown, AvailabilityStatus::Busy),
//                              new Position(rows[1]+3, cols[1], PositionStatus::Unknown, AvailabilityStatus::Busy)};
//    }


    // Cruiser
    QVector<Position*> cruiserPosition = PlaceShipOnTable(3);

//    int columnCruiser = qrand() % 7;
//    QVector<Position*> cruiserPosition = {new Position(rows[2], columnCruiser, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[2], columnCruiser+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                          new Position(rows[2], columnCruiser+2, PositionStatus::Unknown, AvailabilityStatus::Busy)};

//    qDebug() << columnCruiser;
    // Submarine
    QVector<Position*> submarinePosition = PlaceShipOnTable(3);

//    int columnSubmarine = qrand() % 7;
//    QVector<Position*> submarinePosition = {new Position(rows[3], columnSubmarine, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                            new Position(rows[3], columnSubmarine+1, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                            new Position(rows[3], columnSubmarine+2, PositionStatus::Unknown, AvailabilityStatus::Busy)};

    // Destroyer
    QVector<Position*> destroyerPosition = PlaceShipOnTable(2);
//    int columnDestroyer = qrand() % 8;
//    QVector<Position*> destroyerPosition = {new Position(rows[4], columnDestroyer, PositionStatus::Unknown, AvailabilityStatus::Busy),
//                                            new Position(rows[4], columnDestroyer+1, PositionStatus::Unknown, AvailabilityStatus::Busy)};

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

AvailabilityStatus Board::GetAvailabilityStatus(int x, int y)
{
    AvailabilityStatus status = m_boardPositions[x][y]->m_availabilityStatus;
//    qDebug() << GetAvailabilityStatus(x, y);
    return status;
}

QVector<Position*> Board::PlaceShipOnTable(int size)
{
    int x,y;
    // horizontal position
    QVector<Position*> shipPosition;
    if(qrand() % 10 <= 5) {
        x = qrand() % 10;
        y = qrand() % (10-size);
        for(int i = 0; i < size; i++) {
            if(GetAvailabilityStatus(x, y+i) == AvailabilityStatus::Busy) {
                qDebug() << "Jeste";
                i = 0;
                x = qrand() % (10-size);
                y = qrand() % (10-size);
            }
        }
        for(int i = 0; i < size; i++) {
            shipPosition.append(new Position(x, y+i, PositionStatus::Unknown, AvailabilityStatus::Busy));
            m_boardPositions[x][y+i]->m_availabilityStatus = AvailabilityStatus::Busy;
        }
//        MainWindow::setShip(x,y,size);
    } else { // vertical position
        x = qrand() % (10-size);
        y = qrand() % 10;
        for(int i = 0; i < size; i++) {
            if(GetAvailabilityStatus(x+i, y) == AvailabilityStatus::Busy) {
                qDebug() << "Jeste";
                i = 0;
                x = qrand() % (10-size);
                y = qrand() % (10-size);
            }
        }
        for(int i = 0; i < size; i++) {
            shipPosition.append(new Position(x+i, y, PositionStatus::Unknown, AvailabilityStatus::Busy));
            m_boardPositions[x+i][y]->m_availabilityStatus = AvailabilityStatus::Busy;
        }
    }
    return shipPosition;
}
