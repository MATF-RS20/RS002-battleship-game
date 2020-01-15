#-------------------------------------------------
#
# Project created by QtCreator 2019-12-23T18:50:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BattleshipGameProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Game/Ships/FactoryMethod/ShipFactory.cpp \
        Game/Ships/ShipTypes/Carrier.cpp \
        main.cpp \
        mainwindow.cpp \
    Game/Ships/ShipTypes/Cruiser.cpp \
    Game/Ships/ShipTypes/Battleship.cpp \
    Game/Ships/ShipTypes/Submarine.cpp \
    Game/Ships/ShipTypes/Destroyer.cpp \
    Game/Board/Board.cpp \
    Game/Player/Player.cpp \
    Game/Game.cpp \
    Template/FactoryMethod/TurnFactory.cpp \
    Template/Turn.cpp \
    Template/TurnTypes/ComputerTurn.cpp \
    Template/TurnTypes/HumanTurn.cpp \
    Template/Shoot.cpp \
    Game/Player/Strategy/EasyMode.cpp \
    Game/Player/Strategy/HardMode.cpp

HEADERS += \
        Game/Board/IBoard.hpp \
        Game/IGame.hpp \
        Game/Player/IPlayer.hpp \
        Game/Ships/FactoryMethod/ShipFactory.hpp \
        Game/Ships/IShip.hpp \
        Game/Ships/ShipTypes/Carrier.hpp \
        mainwindow.h \
    Game/Ships/ShipTypes/Cruiser.hpp \
    Game/Ships/ShipTypes/Battleship.hpp \
    Game/Ships/ShipTypes/Submarine.hpp \
    Game/Ships/ShipTypes/Destroyer.hpp \
    Game/Board/Board.hpp \
    Game/Player/Player.hpp \
    Game/IGame.hpp \
    Game/Game.hpp \
    Template/FactoryMethod/TurnFactory.hpp \
    Game/Board/Position.hpp \
    Template/Turn.hpp \
    Template/Shoot.hpp \
    Template/TurnTypes/ComputerTurn.hpp \
    Template/TurnTypes/HumanTurn.hpp \
    Game/Player/Strategy/EasyMode.h \
    Game/Player/Strategy/HardMode.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
