/********************************************************************************
** Form generated from reading UI file 'ZeroCalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEROCALCULATOR_H
#define UI_ZEROCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZeroCalculatorClass
{
public:

    void setupUi(QWidget *ZeroCalculatorClass)
    {
        if (ZeroCalculatorClass->objectName().isEmpty())
            ZeroCalculatorClass->setObjectName(QString::fromUtf8("ZeroCalculatorClass"));
        ZeroCalculatorClass->resize(600, 400);

        retranslateUi(ZeroCalculatorClass);

        QMetaObject::connectSlotsByName(ZeroCalculatorClass);
    } // setupUi

    void retranslateUi(QWidget *ZeroCalculatorClass)
    {
        ZeroCalculatorClass->setWindowTitle(QApplication::translate("ZeroCalculatorClass", "ZeroCalculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZeroCalculatorClass: public Ui_ZeroCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEROCALCULATOR_H
