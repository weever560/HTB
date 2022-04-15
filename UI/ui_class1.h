/********************************************************************************
** Form generated from reading UI file 'class1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASS1_H
#define UI_CLASS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_class1
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *class1)
    {
        if (class1->objectName().isEmpty())
            class1->setObjectName(QString::fromUtf8("class1"));
        class1->resize(649, 445);
        textBrowser = new QTextBrowser(class1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 130, 256, 192));

        retranslateUi(class1);

        QMetaObject::connectSlotsByName(class1);
    } // setupUi

    void retranslateUi(QWidget *class1)
    {
        class1->setWindowTitle(QApplication::translate("class1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class class1: public Ui_class1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASS1_H
