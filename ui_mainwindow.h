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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QHBoxLayout *horizontalLayout_StartBtn;
    QComboBox *player1Type;
    QRadioButton *radioButtonEasy1;
    QRadioButton *radioButtonHard1;
    QLineEdit *player1NameInput;
    QHBoxLayout *horizontalLayout_Player1;
    QPushButton *startBattleBtn;
    QHBoxLayout *horizontalLayout_Pleyer2;
    QComboBox *player2Type;
    QRadioButton *radioButtonEasy2;
    QRadioButton *radioButtonHard2;
    QLineEdit *player2NameInput;
    QTableWidget *player1Field;
    QTableWidget *player2Field;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ship1Btn;
    QPushButton *ship2Btn;
    QPushButton *ship3Btn;
    QPushButton *ship4Btn;
    QPushButton *ship5Btn;
    QLabel *player1Name;
    QLabel *player2Name;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(950, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 901, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_StartBtn = new QHBoxLayout();
        horizontalLayout_StartBtn->setSpacing(6);
        horizontalLayout_StartBtn->setObjectName(QString::fromUtf8("horizontalLayout_StartBtn"));
        player1Type = new QComboBox(horizontalLayoutWidget);
        player1Type->setObjectName(QString::fromUtf8("player1Type"));

        horizontalLayout_StartBtn->addWidget(player1Type);

        radioButtonEasy1 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButtonEasy1);
        radioButtonEasy1->setObjectName(QString::fromUtf8("radioButtonEasy1"));

        horizontalLayout_StartBtn->addWidget(radioButtonEasy1, 0, Qt::AlignLeft);

        radioButtonHard1 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup->addButton(radioButtonHard1);
        radioButtonHard1->setObjectName(QString::fromUtf8("radioButtonHard1"));

        horizontalLayout_StartBtn->addWidget(radioButtonHard1);

        player1NameInput = new QLineEdit(horizontalLayoutWidget);
        player1NameInput->setObjectName(QString::fromUtf8("player1NameInput"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1NameInput->sizePolicy().hasHeightForWidth());
        player1NameInput->setSizePolicy(sizePolicy);

        horizontalLayout_StartBtn->addWidget(player1NameInput);


        horizontalLayout->addLayout(horizontalLayout_StartBtn);

        horizontalLayout_Player1 = new QHBoxLayout();
        horizontalLayout_Player1->setSpacing(6);
        horizontalLayout_Player1->setObjectName(QString::fromUtf8("horizontalLayout_Player1"));
        startBattleBtn = new QPushButton(horizontalLayoutWidget);
        startBattleBtn->setObjectName(QString::fromUtf8("startBattleBtn"));

        horizontalLayout_Player1->addWidget(startBattleBtn);


        horizontalLayout->addLayout(horizontalLayout_Player1);

        horizontalLayout_Pleyer2 = new QHBoxLayout();
        horizontalLayout_Pleyer2->setSpacing(6);
        horizontalLayout_Pleyer2->setObjectName(QString::fromUtf8("horizontalLayout_Pleyer2"));
        player2Type = new QComboBox(horizontalLayoutWidget);
        player2Type->setObjectName(QString::fromUtf8("player2Type"));

        horizontalLayout_Pleyer2->addWidget(player2Type);

        radioButtonEasy2 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButtonEasy2);
        radioButtonEasy2->setObjectName(QString::fromUtf8("radioButtonEasy2"));

        horizontalLayout_Pleyer2->addWidget(radioButtonEasy2);

        radioButtonHard2 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup_2->addButton(radioButtonHard2);
        radioButtonHard2->setObjectName(QString::fromUtf8("radioButtonHard2"));

        horizontalLayout_Pleyer2->addWidget(radioButtonHard2);

        player2NameInput = new QLineEdit(horizontalLayoutWidget);
        player2NameInput->setObjectName(QString::fromUtf8("player2NameInput"));
        sizePolicy.setHeightForWidth(player2NameInput->sizePolicy().hasHeightForWidth());
        player2NameInput->setSizePolicy(sizePolicy);

        horizontalLayout_Pleyer2->addWidget(player2NameInput);


        horizontalLayout->addLayout(horizontalLayout_Pleyer2);

        player1Field = new QTableWidget(centralWidget);
        if (player1Field->columnCount() < 10)
            player1Field->setColumnCount(10);
        if (player1Field->rowCount() < 10)
            player1Field->setRowCount(10);
        player1Field->setObjectName(QString::fromUtf8("player1Field"));
        player1Field->setGeometry(QRect(10, 120, 341, 341));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(player1Field->sizePolicy().hasHeightForWidth());
        player1Field->setSizePolicy(sizePolicy1);
        player1Field->setFocusPolicy(Qt::StrongFocus);
        player1Field->setContextMenuPolicy(Qt::CustomContextMenu);
        player1Field->setStyleSheet(QString::fromUtf8("QTableWidget::item:selected{ background-color: transparent }"));
        player1Field->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        player1Field->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        player1Field->setAutoScroll(true);
        player1Field->setSelectionMode(QAbstractItemView::SingleSelection);
        player1Field->setShowGrid(true);
        player1Field->setGridStyle(Qt::SolidLine);
        player1Field->setRowCount(10);
        player1Field->setColumnCount(10);
        player2Field = new QTableWidget(centralWidget);
        if (player2Field->columnCount() < 10)
            player2Field->setColumnCount(10);
        if (player2Field->rowCount() < 10)
            player2Field->setRowCount(10);
        player2Field->setObjectName(QString::fromUtf8("player2Field"));
        player2Field->setGeometry(QRect(570, 120, 341, 341));
        sizePolicy1.setHeightForWidth(player2Field->sizePolicy().hasHeightForWidth());
        player2Field->setSizePolicy(sizePolicy1);
        player2Field->setMinimumSize(QSize(0, 0));
        player2Field->setMaximumSize(QSize(777777, 77777));
        player2Field->setStyleSheet(QString::fromUtf8("QTableWidget::item:selected{ background-color: transparent }"));
        player2Field->setSelectionMode(QAbstractItemView::SingleSelection);
        player2Field->setRowCount(10);
        player2Field->setColumnCount(10);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 160, 141, 276));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ship1Btn = new QPushButton(verticalLayoutWidget);
        ship1Btn->setObjectName(QString::fromUtf8("ship1Btn"));
        ship1Btn->setFlat(true);

        verticalLayout->addWidget(ship1Btn);

        ship2Btn = new QPushButton(verticalLayoutWidget);
        ship2Btn->setObjectName(QString::fromUtf8("ship2Btn"));
        ship2Btn->setFlat(true);

        verticalLayout->addWidget(ship2Btn);

        ship3Btn = new QPushButton(verticalLayoutWidget);
        ship3Btn->setObjectName(QString::fromUtf8("ship3Btn"));
        ship3Btn->setFlat(true);

        verticalLayout->addWidget(ship3Btn);

        ship4Btn = new QPushButton(verticalLayoutWidget);
        ship4Btn->setObjectName(QString::fromUtf8("ship4Btn"));
        ship4Btn->setFlat(true);

        verticalLayout->addWidget(ship4Btn);

        ship5Btn = new QPushButton(verticalLayoutWidget);
        ship5Btn->setObjectName(QString::fromUtf8("ship5Btn"));
        ship5Btn->setFlat(true);

        verticalLayout->addWidget(ship5Btn);

        player1Name = new QLabel(centralWidget);
        player1Name->setObjectName(QString::fromUtf8("player1Name"));
        player1Name->setGeometry(QRect(10, 100, 111, 17));
        player2Name = new QLabel(centralWidget);
        player2Name->setObjectName(QString::fromUtf8("player2Name"));
        player2Name->setGeometry(QRect(570, 100, 131, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 19));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Battleship Game", nullptr));
        radioButtonEasy1->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        radioButtonHard1->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        player1NameInput->setText(QString());
        player1NameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Player1", nullptr));
        startBattleBtn->setText(QCoreApplication::translate("MainWindow", "Start Battle", nullptr));
        radioButtonEasy2->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        radioButtonHard2->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        player2NameInput->setText(QString());
        player2NameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Player2", nullptr));
        ship1Btn->setText(QString());
        ship2Btn->setText(QString());
        ship3Btn->setText(QString());
        ship4Btn->setText(QString());
        ship5Btn->setText(QString());
        player1Name->setText(QString());
        player2Name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
