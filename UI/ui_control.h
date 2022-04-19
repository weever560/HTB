/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_control
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *control)
    {
        if (control->objectName().isEmpty())
            control->setObjectName(QString::fromUtf8("control"));
        control->resize(400, 182);
        pushButton = new QPushButton(control);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 110, 93, 28));
        textEdit = new QTextEdit(control);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 110, 104, 31));
        label = new QLabel(control);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 120, 72, 15));
        label_2 = new QLabel(control);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 72, 15));
        textEdit_2 = new QTextEdit(control);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(120, 70, 104, 31));

        retranslateUi(control);

        QMetaObject::connectSlotsByName(control);
    } // setupUi

    void retranslateUi(QWidget *control)
    {
        control->setWindowTitle(QApplication::translate("control", "Form", nullptr));
        pushButton->setText(QApplication::translate("control", "PushButton", nullptr));
        label->setText(QApplication::translate("control", "\346\225\231\345\256\2442\344\272\272\346\225\260", nullptr));
        label_2->setText(QApplication::translate("control", "\346\225\231\345\256\2441\344\272\272\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class control: public Ui_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
