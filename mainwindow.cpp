#include "Game/Player/Player.hpp"
#include "Game/Board/Board.hpp"
#include "Game/Game.hpp"
#include <iostream>
#include <QThread>
#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QDir>
#include <QMessageBox>
#include <QtDebug>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            ui->player1Field->setItem(i, j, new QTableWidgetItem);
            ui->player1Field->item(i, j)->setBackground(Qt::blue);
            ui->player2Field->setItem(i, j, new QTableWidgetItem);
            ui->player2Field->item(i, j)->setBackground(Qt::blue);
        }
    }

    connect(ui->player1Field, SIGNAL(cellClicked(int, int)), this, SLOT(player1FieldClicked(int, int)));
    connect(ui->player2Field, SIGNAL(cellClicked(int, int)), this, SLOT(player2FieldClicked(int, int)));

    ui->radioButtonEasy1->setHidden(true);
    ui->radioButtonHard1->setHidden(true);
    ui->radioButtonEasy2->setHidden(true);
    ui->radioButtonHard2->setHidden(true);

    ui->player1Type->addItems({"Player", "Computer"});
    ui->player2Type->addItems({"Player", "Computer"});
    connect(ui->player1Type,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(typeChanged1(const QString&)));
    connect(ui->player2Type,SIGNAL(currentIndexChanged(const QString&)), this,SLOT(typeChanged2(const QString&)));

    ui->startBattleBtn->setDisabled(true);

    connect(ui->player1NameInput, SIGNAL(textChanged(const QString &)), this, SLOT(playerNameEdited(const QString &)));
    connect(ui->player2NameInput, SIGNAL(textChanged(const QString &)), this, SLOT(playerNameEdited(const QString &)));


    for (int i = 0; i < 10; i++) {
        ui->player1Field->setColumnWidth(i,30);
        ui->player1Field->setRowHeight(i,30);
        ui->player2Field->setColumnWidth(i,30);
        ui->player2Field->setRowHeight(i,30);
    }

//    connect(ui->ship1, SIGNAL(clicked(const QString& text)), &lineEdit, SLOT(setText(const QString& text)));
//    connect(ui->ship1, &QLabel::, &lineEdit, SLOT(setText(const QString& text)));

//    QPixmap pixmap("image_path");
//    QIcon ButtonIcon(pixmap);
//    button->setIcon(ButtonIcon);
    QPixmap pixmap("Assets/Images/2.png");
    ui->ship1Btn->setIcon(QIcon(QPixmap("Assets/Images/2.png")));
    ui->ship1Btn->setIconSize(QSize(60, 30));
    ui->ship2Btn->setIcon(QIcon(QPixmap("Assets/Images/3.png")));
    ui->ship2Btn->setIconSize(QSize(90, 30));
    ui->ship3Btn->setIcon(QIcon(QPixmap("Assets/Images/3.png")));
    ui->ship3Btn->setIconSize(QSize(90, 30));
    ui->ship4Btn->setIcon(QIcon(QPixmap("Assets/Images/4.png")));
    ui->ship4Btn->setIconSize(QSize(120, 30));
    ui->ship5Btn->setIcon(QIcon(QPixmap("Assets/Images/5.png")));
    ui->ship5Btn->setIconSize(QSize(150, 30));

    // prikaz i odabir brodova
    // TODO: napraviti draggable elemente koje mozemo pomerati u tabelu
//    ui->ship1->setPixmap(QPixmap("Assets/Images/2.png"));
//    ui->ship2->setPixmap(QPixmap("Assets/Images/3.png"));
//    ui->ship3->setPixmap(QPixmap("Assets/Images/3.png"));
//    ui->ship4->setPixmap(QPixmap("Assets/Images/4.png"));
//    ui->ship5->setPixmap(QPixmap("Assets/Images/5.png"));

    connect(ui->startBattleBtn, &QPushButton::clicked, this, [this](){
        ui->player1NameInput->setDisabled(true);
        ui->player2NameInput->setDisabled(true);
        ui->player1Type->setDisabled(true);
        ui->player2Type->setDisabled(true);
    });



    // ubacio sam staticki ove brodove samo da vidim kako ce da izgleda
//    // 1. ship, x = 3, y = 2, size = 2
//    setShip(3,2,2);

//    // 2. ship, x = 5, y = 7, size = 3
//    setShip(5,7,3);

//    // 2. ship, x = 5, y = 7, size = 3
//    setShip(0,1,3);

//    // 4. ship, x = 2, y = 0, size = 4
//    setShip(2,0,4);

//    // 5. ship, x = 8, y = 4, size = 5
//    setShip(8,4,5);

//    ui->player1Field->setCellWidget(1,5,ui->player1Field->cellWidget(8,4));
//    ui->player1Field->cellWidget(8,5)

    ui->player1Field->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect( ui->player1Field, SIGNAL( cellDoubleClicked (int, int) ),
     this, SLOT( cellSelected( int, int ) ) );

    ui->player1Field->setEnabled(false);
    ui->player2Field->setEnabled(false);

//    QPixmap background("Assets/Images/background.jpg");

    this->centralWidget()->setStyleSheet(
             "background-image:url(\"Assets/Images/background.jpg\"); background-position: center;" );
    ui->player1Field->setStyleSheet("background:none");
    ui->player2Field->setStyleSheet("background:none");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::player1FieldClicked(int x, int y)
{
    checkGameStatus();
    selectedRow = x;
    selectedColumn = y;

    bool playAgain = false;
    do {
        playAgain = m_game->AttackBy(m_player2, m_player1);
    } while(playAgain);

    updateFields();

    if (playAgain == false) {
        ui->player1Field->setEnabled(false);
        ui->player2Field->setEnabled(true);
    }
}

void MainWindow::player2FieldClicked(int x, int y)
{
    checkGameStatus();
    selectedRow = x;
    selectedColumn = y;

    bool playAgain = false;
    do {
        playAgain = m_game->AttackBy(m_player1, m_player2);
    } while(playAgain);

    updateFields();

    if (playAgain == false) {
        ui->player1Field->setEnabled(true);
        ui->player2Field->setEnabled(false);
    }

    if(m_player2->GetPlayerType() == PlayerType::Computer) {
        ui->player1Field->setEnabled(true);
        ui->player2Field->setEnabled(false);
        QApplication::processEvents();
        do {
            playAgain = m_game->AttackBy(m_player2, m_player1);
            updateFields();
            QApplication::processEvents();
            QThread::msleep(500);
        } while(playAgain);
        ui->player1Field->setEnabled(false);
        ui->player2Field->setEnabled(true);
    }

    checkGameStatus();
}

int MainWindow::getSelectedRow()
{
    QApplication::processEvents();
    int selectedRow = 0;
    if(ui->player1Field->isEnabled() == true) {
        selectedRow = ui->player1Field->selectedItems().first()->row();
    }

    if(ui->player2Field->isEnabled() == true) {
        selectedRow = ui->player2Field->selectedItems().first()->row();
    }

    return selectedRow;
}

int MainWindow::getSelectedColumn()
{
    QApplication::processEvents();
    int selectedColumn = 0;
    if(ui->player1Field->isEnabled() == true) {
        selectedColumn = ui->player1Field->selectedItems().first()->column();
    }

    if(ui->player2Field->isEnabled() == true) {
        selectedColumn = ui->player2Field->selectedItems().first()->column();
    }

    return selectedColumn;
}

void MainWindow::on_startBattleBtn_clicked()
{
    QString player1Name = ui->player1NameInput->text();
    QString player2Name = ui->player2NameInput->text();

    PlayerType player1Type = PlayerType::Human;
    if(ui->player1Type->currentText() == "Computer")
            player1Type = PlayerType::Computer;

    PlayerType player2Type = PlayerType::Human;
    if(ui->player2Type->currentText() == "Computer")
            player2Type = PlayerType::Computer;

    m_player1 = std::make_shared<Player>(player1Name, player1Type, ui->radioButtonHard1->isChecked() ? PlayerStrategy::Hard : PlayerStrategy::Easy);
    m_player2 = std::make_shared<Player>(player2Name, player2Type, ui->radioButtonHard2->isChecked() ? PlayerStrategy::Hard : PlayerStrategy::Easy);

    m_game = new Game(this, m_player1, m_player2);

    ui->player1Field->setEnabled(false);
    ui->player2Field->setEnabled(true);
    QThread::msleep(200);
    updateFields();

    if (player1Type == PlayerType::Computer && player2Type == PlayerType::Computer)
        autoplayCompVsComp();
}

void MainWindow::autoplayCompVsComp()
{
    do {
        checkGameStatus();
        bool playAgain = false;

        ui->player1Field->setEnabled(false);
        ui->player2Field->setEnabled(true);
        QApplication::processEvents();
        do
        {
            playAgain = m_game->AttackBy(m_player1, m_player2);
            updateFields();
            QThread::msleep(200);
            checkGameStatus();
        }
        while(playAgain);

        ui->player1Field->setEnabled(true);
        ui->player2Field->setEnabled(false);
        QApplication::processEvents();
        do
        {
            playAgain = m_game->AttackBy(m_player2, m_player1);
            updateFields();
            QApplication::processEvents();
            QThread::msleep(200);
            checkGameStatus();
        }
        while(playAgain);
    } while(m_game->GetGameState() != GameState::GameOver);
}

void MainWindow::updateFields()
{
    QApplication::processEvents();
    for(int row = 0; row < 10; ++row)
    {
        for(int column = 0; column < 10; ++column)
        {
            PositionStatus status1 = m_player1->GetBoard()->GetPositionStatus(row, column);
            PositionStatus status2 = m_player2->GetBoard()->GetPositionStatus(row, column);

            QLabel *miss = new QLabel();
            miss->setPixmap(QPixmap("Assets/Images/miss.png"));
            miss->setScaledContents(true);
            QLabel *hit = new QLabel();
            hit->setPixmap(QPixmap("Assets/Images/hit.png"));
            hit->setScaledContents(true);
            switch(status1)
            {
                case PositionStatus::Hit:
                    ui->player1Field->item(row, column)->setBackground(Qt::black);
//                    ui->player1Field->setCellWidget(row,column,hit);
                    break;
                case PositionStatus::Miss:
//                    ui->player1Field->setCellWidget(row,column,miss);
                      ui->player1Field->item(row, column)->setBackground(Qt::red);
                    break;
            }

            switch(status2)
            {
                case PositionStatus::Hit:
                    ui->player2Field->item(row, column)->setBackground(Qt::black);
                    break;
                case PositionStatus::Miss:
                    ui->player2Field->item(row, column)->setBackground(Qt::red);
                    break;
            }
        }
    }
    QApplication::processEvents();
}

void MainWindow::checkGameStatus() {
    if (m_game->GetGameState() == GameState::GameOver) {
        QMessageBox gameOverMsgBox;
        int status1 = m_player1->GetBoard()->NumberOfAvailableShips();
        int status2 = m_player2->GetBoard()->NumberOfAvailableShips();
        if (status1 == 0)
            gameOverMsgBox.setText(QString("Game over! Player 2 won the game!"));
        if (status2 == 0)
            gameOverMsgBox.setText(QString("Game over! Player 1 won the game!"));
        gameOverMsgBox.exec();
        //QApplication::exit();
    }
}

void MainWindow::setShip(int x, int y, int size)
{
    for (int i = 0; i < size ; i++ ) {
        QLabel *ship = new QLabel();
        std::string imageNamePom;
        if (size == 1)
            imageNamePom = "Assets/Images/" + std::to_string(size) + ".png";
        else
            imageNamePom = "Assets/Images/" + std::to_string(size) + "_" + std::to_string(i+1) + ".png";
        const char* imageName = imageNamePom.c_str();
        ship->setPixmap(QPixmap(imageName));
        ship->setScaledContents(true);
        ui->player1Field->setCellWidget(x,y+i,ship);

    }
}

void MainWindow::typeChanged1(const QString& name)
{
    if (name.toStdString().compare("Computer") == 0) {
        ui->player1NameInput->hide();
        ui->radioButtonEasy1->setVisible(true);
        ui->radioButtonEasy1->setChecked(true);
        ui->radioButtonHard1->setVisible(true);
        if (!ui->player2NameInput->text().isEmpty())
            ui->startBattleBtn->setEnabled(true);
        if (ui->player2Type->currentText().toStdString().compare("Computer") == 0)
            ui->startBattleBtn->setEnabled(true);
    }
    else if (name.toStdString().compare("Player") == 0) {
        ui->player1NameInput->show();
        ui->radioButtonEasy1->setHidden(true);
        ui->radioButtonHard1->setHidden(true);
        if (ui->player2NameInput->text().isEmpty() || ui->player1NameInput->text().isEmpty())
            ui->startBattleBtn->setDisabled(true);

        if (ui->player2Type->currentText().toStdString().compare("Computer") == 0) {
            ui->radioButtonEasy1->setVisible(true);
            ui->radioButtonHard1->setVisible(true);
        }
    }
}

void MainWindow::typeChanged2(const QString& name)
{
    if (name.toStdString().compare("Computer") == 0) {
        ui->player2NameInput->hide();
        ui->radioButtonEasy2->setVisible(true);
        ui->radioButtonEasy2->setChecked(true);
        ui->radioButtonHard2->setVisible(true);
        if (!ui->player1NameInput->text().isEmpty())
            ui->startBattleBtn->setEnabled(true);

        if (ui->player1Type->currentText().toStdString().compare("Computer") == 0)
            ui->startBattleBtn->setEnabled(true);
    }
    else if (name.toStdString().compare("Player") == 0) {
        ui->player2NameInput->show();
        ui->radioButtonEasy2->setHidden(true);
        ui->radioButtonHard2->setHidden(true);
        if (ui->player2NameInput->text().isEmpty() || ui->player1NameInput->text().isEmpty())
            ui->startBattleBtn->setDisabled(true);

        if (ui->player1Type->currentText().toStdString().compare("Computer") == 0) {
            ui->radioButtonEasy2->setVisible(true);
            ui->radioButtonHard2->setVisible(true);
        }
    }
}

void MainWindow::playerNameEdited(const QString & text) {
    if(!ui->player2NameInput->text().isEmpty() && !ui->player1NameInput->text().isEmpty()) {
        ui->startBattleBtn->setEnabled(true);
    }
    else if ((!ui->player1NameInput->text().isEmpty() && ui->player2Type->currentText().toStdString().compare("Computer") == 0) ||
             (!ui->player2NameInput->text().isEmpty() && ui->player1Type->currentText().toStdString().compare("Computer") == 0)) {
        ui->startBattleBtn->setEnabled(true);
    }
    else if (ui->player2Type->currentText().toStdString().compare("Computer") == 0 && ui->player1Type->currentText().toStdString().compare("Computer") == 0) {
        ui->startBattleBtn->setEnabled(true);
    }
    else {
        ui->startBattleBtn->setDisabled(true);
    }
}
