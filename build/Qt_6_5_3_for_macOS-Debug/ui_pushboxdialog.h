/********************************************************************************
** Form generated from reading UI file 'pushboxdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSHBOXDIALOG_H
#define UI_PUSHBOXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PushBoxDialog
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *PushBoxDialog)
    {
        if (PushBoxDialog->objectName().isEmpty())
            PushBoxDialog->setObjectName("PushBoxDialog");
        PushBoxDialog->resize(500, 600);
        PushBoxDialog->setMinimumSize(QSize(500, 600));
        PushBoxDialog->setMaximumSize(QSize(500, 600));
        PushBoxDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 216, 75);\n"
""));
        widget = new QWidget(PushBoxDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(57, 57, 385, 385));
        widget->setMinimumSize(QSize(385, 385));
        widget->setMaximumSize(QSize(385, 385));
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 216, 75);\n"
"border: 5px solid #000000;\n"
""));
        label = new QLabel(PushBoxDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 58, 16));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        label_2 = new QLabel(PushBoxDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 520, 171, 31));

        retranslateUi(PushBoxDialog);

        QMetaObject::connectSlotsByName(PushBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *PushBoxDialog)
    {
        PushBoxDialog->setWindowTitle(QCoreApplication::translate("PushBoxDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PushBoxDialog", "Level 1", nullptr));
        label_2->setText(QCoreApplication::translate("PushBoxDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PushBoxDialog: public Ui_PushBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSHBOXDIALOG_H
