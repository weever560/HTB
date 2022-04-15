/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QPushButton *loginButton;
    QLabel *label;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *userLineEdit;
    QLineEdit *passwdLineEdit;
    QPushButton *registerButton;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 572);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 150, 311, 161));
        widget->setStyleSheet(QString::fromUtf8(""));
        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(150, 110, 93, 34));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\226\265\345\221\234\344\275\223"));
        font.setPointSize(15);
        loginButton->setFont(font);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 91, 38));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\215\241\351\200\232\347\256\200\344\275\223"));
        font1.setPointSize(17);
        label->setFont(font1);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(99, -1, 201, 97));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        userLineEdit = new QLineEdit(widget_5);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(22);
        userLineEdit->setFont(font2);
        userLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(userLineEdit);

        passwdLineEdit = new QLineEdit(widget_5);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setFont(font2);
        passwdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(passwdLineEdit);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(50, 110, 93, 34));
        registerButton->setFont(font);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(29, 49, 71, 37));
        label_2->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", nullptr));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        userLineEdit->setText(QString());
        passwdLineEdit->setText(QString());
        registerButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
