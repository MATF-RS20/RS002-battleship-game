/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *player1NameInput;
    QPushButton *startBattleBtn;
    QComboBox *player1Type;
    QComboBox *player2Type;
    QLineEdit *player2NameInput;
    QTableWidget *player1Field;
    QTableWidget *player2Field;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ship1;
    QLabel *ship2;
    QLabel *ship3;
    QLabel *ship4;
    QLabel *ship5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(933, 484);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 20, 841, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        player1Type = new QComboBox(horizontalLayoutWidget);
        player1Type->setObjectName(QString::fromUtf8("playerType"));
        horizontalLayout->addWidget(player1Type);
        player1NameInput = new QLineEdit(horizontalLayoutWidget);
        player1NameInput->setObjectName(QString::fromUtf8("player1NameInput"));
        horizontalLayout->addWidget(player1NameInput);

        startBattleBtn = new QPushButton(horizontalLayoutWidget);
        startBattleBtn->setObjectName(QString::fromUtf8("startBattleBtn"));

        horizontalLayout->addWidget(startBattleBtn);

        player2Type = new QComboBox(horizontalLayoutWidget);
        player2Type->setObjectName(QString::fromUtf8("playerType"));
        horizontalLayout->addWidget(player2Type);
        player2NameInput = new QLineEdit(horizontalLayoutWidget);
        player2NameInput->setObjectName(QString::fromUtf8("player2NameInput"));
        horizontalLayout->addWidget(player2NameInput);

        player1Field = new QTableWidget(centralWidget);
        if (player1Field->columnCount() < 10)
            player1Field->setColumnCount(10);
        if (player1Field->rowCount() < 10)
            player1Field->setRowCount(10);
        player1Field->setObjectName(QString::fromUtf8("player1Field"));
        player1Field->setGeometry(QRect(40, 70, 341, 341));
        player1Field->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        player1Field->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        player1Field->setAutoScroll(true);
        player1Field->setRowCount(10);
        player1Field->setColumnCount(10);
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                player1Field->setItem(i, j, new QTableWidgetItem);
                player1Field->item(i, j)->setBackground(Qt::blue);
            }
        }

        player2Field = new QTableWidget(centralWidget);
        if (player2Field->columnCount() < 10)
            player2Field->setColumnCount(10);
        if (player2Field->rowCount() < 10)
            player2Field->setRowCount(10);
        player2Field->setObjectName(QString::fromUtf8("player2Field"));
        player2Field->setGeometry(QRect(540, 70, 341, 341));
        player2Field->setRowCount(10);
        player2Field->setColumnCount(10);
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                player2Field->setItem(i, j, new QTableWidgetItem);
                player2Field->item(i, j)->setBackground(Qt::blue);
            }
        }

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 79, 141, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ship1 = new QLabel(verticalLayoutWidget);
        ship1->setObjectName(QString::fromUtf8("ship1"));
        ship1->setMaximumSize(QSize(30, 30));

        verticalLayout->addWidget(ship1);

        ship2 = new QLabel(verticalLayoutWidget);
        ship2->setObjectName(QString::fromUtf8("ship2"));
        ship2->setMaximumSize(QSize(60, 30));

        verticalLayout->addWidget(ship2);

        ship3 = new QLabel(verticalLayoutWidget);
        ship3->setObjectName(QString::fromUtf8("ship3"));
        ship3->setMaximumSize(QSize(90, 30));

        verticalLayout->addWidget(ship3);

        ship4 = new QLabel(verticalLayoutWidget);
        ship4->setObjectName(QString::fromUtf8("ship4"));
        ship4->setMaximumSize(QSize(120, 30));

        verticalLayout->addWidget(ship4);

        ship5 = new QLabel(verticalLayoutWidget);
        ship5->setObjectName(QString::fromUtf8("ship5"));
        ship5->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(ship5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 933, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        player1NameInput->setText(QString());
        player1NameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Player1", nullptr));
        startBattleBtn->setText(QCoreApplication::translate("MainWindow", "Start Battle", nullptr));
        player2NameInput->setText(QString());
        player2NameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Player2", nullptr));
        ship1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ship2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ship3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ship4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ship5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
