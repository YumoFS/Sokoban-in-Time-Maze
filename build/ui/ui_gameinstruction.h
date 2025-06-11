/********************************************************************************
** Form generated from reading UI file 'gameinstruction.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEINSTRUCTION_H
#define UI_GAMEINSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameInstruction
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Return_GameInstruction;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameInstruction)
    {
        if (GameInstruction->objectName().isEmpty())
            GameInstruction->setObjectName("GameInstruction");
        GameInstruction->resize(640, 533);
        GameInstruction->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 216, 76);"));
        centralwidget = new QWidget(GameInstruction);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 640, 480));
        widget->setMinimumSize(QSize(640, 480));
        widget->setMaximumSize(QSize(640, 480));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Return_GameInstruction = new QPushButton(widget);
        Return_GameInstruction->setObjectName("Return_GameInstruction");
        Return_GameInstruction->setMinimumSize(QSize(50, 30));
        Return_GameInstruction->setMaximumSize(QSize(50, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        Return_GameInstruction->setFont(font);
        Return_GameInstruction->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Return_GameInstruction);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(400, 40));
        label_2->setMaximumSize(QSize(400, 40));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(550, 345));
        label->setMaximumSize(QSize(550, 345));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(10);
        font2.setBold(false);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        GameInstruction->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameInstruction);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 37));
        GameInstruction->setMenuBar(menubar);
        statusbar = new QStatusBar(GameInstruction);
        statusbar->setObjectName("statusbar");
        GameInstruction->setStatusBar(statusbar);

        retranslateUi(GameInstruction);

        QMetaObject::connectSlotsByName(GameInstruction);
    } // setupUi

    void retranslateUi(QMainWindow *GameInstruction)
    {
        GameInstruction->setWindowTitle(QCoreApplication::translate("GameInstruction", "MainWindow", nullptr));
        Return_GameInstruction->setText(QCoreApplication::translate("GameInstruction", "Return", nullptr));
        label_2->setText(QCoreApplication::translate("GameInstruction", "Game Instruction", nullptr));
        label->setText(QCoreApplication::translate("GameInstruction", "Welcome to \"Sokoban in Time Maze,\" a puzzle game that combines classic Sokoban elements with a time-reversal mechanism. \n"
"Below are the basic instructions to help you quickly get started and enjoy the game.\n"
"\n"
"I. Basic Operations:\n"
"\342\221\240\343\200\200Movement: Use the W (up), A (left), S (down), and D (right) keys on the keyboard to control the character's movement.\n"
"\342\221\241\343\200\200Pushing Boxes: When the character is adjacent to a box, use the corresponding arrow key to push the box. Boxes can \n"
"only move one space at a time.\n"
"\342\221\242\343\200\200Time Reversal: When you need to re strategize, you can activate the time reversal feature to return to a previous point \n"
"in time.\n"
"\342\221\243\343\200\200Safe Points: Locate and utilize safe points within the maze; these points will not change state when time is reversed \n"
"and can be used to store key boxes.\n"
"\n"
"II. Game Objectives:\n"
"\342\221\240 Push all boxes to their designated locations to unlock the esc"
                        "ape point.\n"
"\342\221\241 Reach the escape point to complete the maze.\n"
"\n"
"III. Game Tips:\n"
"If you encounter difficulties during the game, you can refer to the game tips or use the time reversal feature.\n"
"\n"
"IV. Game Completion:\n"
"The maze is completed when you successfully push all boxes to their designated locations and reach the escape point.\n"
"\n"
"We wish you an enjoyable gaming experience and the pleasure of solving puzzles!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameInstruction: public Ui_GameInstruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEINSTRUCTION_H
