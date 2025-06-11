/********************************************************************************
** Form generated from reading UI file 'levelselection2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELSELECTION2_H
#define UI_LEVELSELECTION2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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

class Ui_LevelSelection2
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Return_LevelSelection;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QPushButton *Level2;
    QPushButton *Level5;
    QSpacerItem *verticalSpacer_3;
    QPushButton *Level3;
    QPushButton *Level4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Level6;
    QPushButton *Level1;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LevelSelection2)
    {
        if (LevelSelection2->objectName().isEmpty())
            LevelSelection2->setObjectName("LevelSelection2");
        LevelSelection2->resize(662, 611);
        LevelSelection2->setMinimumSize(QSize(662, 611));
        LevelSelection2->setMaximumSize(QSize(662, 611));
        LevelSelection2->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"background-color: rgb(255, 216, 76);\n"
"color: rgb(0, 0, 0);\n"
"setFixedSize:(650, 650);"));
        LevelSelection2->setIconSize(QSize(50, 50));
        centralwidget = new QWidget(LevelSelection2);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 640, 592));
        widget->setMinimumSize(QSize(640, 551));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Return_LevelSelection = new QPushButton(widget);
        Return_LevelSelection->setObjectName("Return_LevelSelection");
        Return_LevelSelection->setMinimumSize(QSize(50, 30));
        Return_LevelSelection->setMaximumSize(QSize(50, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        Return_LevelSelection->setFont(font);
        Return_LevelSelection->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(Return_LevelSelection);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(400, 30));
        label->setMaximumSize(QSize(400, 30));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        Level2 = new QPushButton(widget);
        Level2->setObjectName("Level2");
        Level2->setMinimumSize(QSize(90, 90));
        Level2->setMaximumSize(QSize(90, 90));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setUnderline(true);
        Level2->setFont(font2);
        Level2->setStyleSheet(QString::fromUtf8("background-image: url(:/2.2.png);\n"
"image: url(:/2.2.png);"));

        gridLayout->addWidget(Level2, 0, 2, 1, 1);

        Level5 = new QPushButton(widget);
        Level5->setObjectName("Level5");
        Level5->setMinimumSize(QSize(90, 90));
        Level5->setMaximumSize(QSize(90, 90));
        Level5->setFont(font2);
        Level5->setStyleSheet(QString::fromUtf8("background-image: url(:/5.2.png);\n"
"image: url(:/5.2.png);"));
        Level5->setIconSize(QSize(16, 16));

        gridLayout->addWidget(Level5, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        Level3 = new QPushButton(widget);
        Level3->setObjectName("Level3");
        Level3->setMinimumSize(QSize(90, 90));
        Level3->setMaximumSize(QSize(90, 90));
        Level3->setFont(font2);
        Level3->setStyleSheet(QString::fromUtf8("background-image: url(:/3.2.png);\n"
"image: url(:/3.2.png);"));

        gridLayout->addWidget(Level3, 2, 0, 1, 1);

        Level4 = new QPushButton(widget);
        Level4->setObjectName("Level4");
        Level4->setMinimumSize(QSize(90, 90));
        Level4->setMaximumSize(QSize(90, 90));
        Level4->setFont(font2);
        Level4->setStyleSheet(QString::fromUtf8("background-image: url(:/4.2.png);\n"
"image: url(:/4.2.png);"));

        gridLayout->addWidget(Level4, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        Level6 = new QPushButton(widget);
        Level6->setObjectName("Level6");
        Level6->setMinimumSize(QSize(90, 90));
        Level6->setMaximumSize(QSize(90, 90));
        Level6->setFont(font2);
        Level6->setStyleSheet(QString::fromUtf8("background-image: url(:/6.2.png);\n"
"image: url(:/6.2.png);"));

        gridLayout->addWidget(Level6, 4, 2, 1, 1);

        Level1 = new QPushButton(widget);
        Level1->setObjectName("Level1");
        Level1->setMinimumSize(QSize(90, 90));
        Level1->setMaximumSize(QSize(90, 90));
        Level1->setFont(font2);
        Level1->setStyleSheet(QString::fromUtf8("image: url(:/1.2.png);\n"
"background-image: url(:/1.2.png);\n"
""));
        Level1->setIconSize(QSize(16, 16));

        gridLayout->addWidget(Level1, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        LevelSelection2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LevelSelection2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 662, 37));
        LevelSelection2->setMenuBar(menubar);
        statusbar = new QStatusBar(LevelSelection2);
        statusbar->setObjectName("statusbar");
        LevelSelection2->setStatusBar(statusbar);

        retranslateUi(LevelSelection2);

        QMetaObject::connectSlotsByName(LevelSelection2);
    } // setupUi

    void retranslateUi(QMainWindow *LevelSelection2)
    {
        LevelSelection2->setWindowTitle(QCoreApplication::translate("LevelSelection2", "MainWindow", nullptr));
        Return_LevelSelection->setText(QCoreApplication::translate("LevelSelection2", "Return", nullptr));
        label->setText(QCoreApplication::translate("LevelSelection2", "Level Selection", nullptr));
        Level2->setText(QCoreApplication::translate("LevelSelection2", "Level 2", nullptr));
        Level5->setText(QCoreApplication::translate("LevelSelection2", "Level 5", nullptr));
        Level3->setText(QCoreApplication::translate("LevelSelection2", "Level 3", nullptr));
        Level4->setText(QCoreApplication::translate("LevelSelection2", "Level 4", nullptr));
        Level6->setText(QCoreApplication::translate("LevelSelection2", "Level 6", nullptr));
        Level1->setText(QCoreApplication::translate("LevelSelection2", "Level 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelSelection2: public Ui_LevelSelection2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELSELECTION2_H
