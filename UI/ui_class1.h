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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_class1
{
public:
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QTextBrowser *textBrowser1_rs;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QTextBrowser *textBrowser1_ld;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QTextBrowser *textBrowser1_sd;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *textBrowser1_wd;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *d1;
    QCheckBox *d2;
    QCheckBox *d3;
    QCheckBox *d4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *fs1;
    QCheckBox *fs2;
    QCheckBox *kt;

    void setupUi(QWidget *class1)
    {
        if (class1->objectName().isEmpty())
            class1->setObjectName(QString::fromUtf8("class1"));
        class1->resize(450, 470);
        pushButton = new QPushButton(class1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 400, 101, 41));
        horizontalLayoutWidget = new QWidget(class1);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 451, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(class1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-30, 70, 901, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(class1);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 140, 362, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(gridLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        textBrowser1_rs = new QTextBrowser(frame);
        textBrowser1_rs->setObjectName(QString::fromUtf8("textBrowser1_rs"));

        horizontalLayout_4->addWidget(textBrowser1_rs);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_5 = new QFrame(gridLayoutWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        textBrowser1_ld = new QTextBrowser(frame_5);
        textBrowser1_ld->setObjectName(QString::fromUtf8("textBrowser1_ld"));

        horizontalLayout_5->addWidget(textBrowser1_ld);


        gridLayout->addWidget(frame_5, 0, 1, 1, 1);

        frame_3 = new QFrame(gridLayoutWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        textBrowser1_sd = new QTextBrowser(frame_3);
        textBrowser1_sd->setObjectName(QString::fromUtf8("textBrowser1_sd"));

        horizontalLayout_3->addWidget(textBrowser1_sd);


        gridLayout->addWidget(frame_3, 1, 0, 1, 1);

        frame_2 = new QFrame(gridLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        textBrowser1_wd = new QTextBrowser(frame_2);
        textBrowser1_wd->setObjectName(QString::fromUtf8("textBrowser1_wd"));

        horizontalLayout_2->addWidget(textBrowser1_wd);


        gridLayout->addWidget(frame_2, 1, 1, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(class1);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(80, 90, 311, 53));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox->setFont(font2);

        horizontalLayout_7->addWidget(checkBox);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font2);

        horizontalLayout_7->addWidget(checkBox_2);

        horizontalLayoutWidget_3 = new QWidget(class1);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(72, 260, 291, 61));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        d1 = new QCheckBox(horizontalLayoutWidget_3);
        d1->setObjectName(QString::fromUtf8("d1"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Agency FB"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        d1->setFont(font3);

        horizontalLayout_8->addWidget(d1);

        d2 = new QCheckBox(horizontalLayoutWidget_3);
        d2->setObjectName(QString::fromUtf8("d2"));
        d2->setFont(font3);

        horizontalLayout_8->addWidget(d2);

        d3 = new QCheckBox(horizontalLayoutWidget_3);
        d3->setObjectName(QString::fromUtf8("d3"));
        d3->setFont(font3);

        horizontalLayout_8->addWidget(d3);

        d4 = new QCheckBox(horizontalLayoutWidget_3);
        d4->setObjectName(QString::fromUtf8("d4"));
        d4->setFont(font3);

        horizontalLayout_8->addWidget(d4);

        horizontalLayoutWidget_4 = new QWidget(class1);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(90, 330, 260, 61));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        fs1 = new QCheckBox(horizontalLayoutWidget_4);
        fs1->setObjectName(QString::fromUtf8("fs1"));
        fs1->setFont(font3);

        horizontalLayout_9->addWidget(fs1);

        fs2 = new QCheckBox(horizontalLayoutWidget_4);
        fs2->setObjectName(QString::fromUtf8("fs2"));
        fs2->setFont(font3);

        horizontalLayout_9->addWidget(fs2);

        kt = new QCheckBox(horizontalLayoutWidget_4);
        kt->setObjectName(QString::fromUtf8("kt"));
        kt->setFont(font3);

        horizontalLayout_9->addWidget(kt);


        retranslateUi(class1);

        QMetaObject::connectSlotsByName(class1);
    } // setupUi

    void retranslateUi(QWidget *class1)
    {
        class1->setWindowTitle(QApplication::translate("class1", "Form", nullptr));
        pushButton->setText(QApplication::translate("class1", "\347\255\276\345\210\260\350\241\250", nullptr));
        label->setText(QApplication::translate("class1", "\346\225\231\345\256\2441", nullptr));
        label_2->setText(QApplication::translate("class1", "\344\272\272\346\225\260/\344\270\252", nullptr));
        label_5->setText(QApplication::translate("class1", "\344\272\256\345\272\246/lux", nullptr));
        label_4->setText(QApplication::translate("class1", "\346\271\277\345\272\246/%", nullptr));
        label_3->setText(QApplication::translate("class1", "\346\270\251\345\272\246/\342\204\203", nullptr));
        checkBox->setText(QApplication::translate("class1", "\350\207\252\345\212\250\346\250\241\345\274\217", nullptr));
        checkBox_2->setText(QApplication::translate("class1", "\346\200\273\347\224\265\346\272\220", nullptr));
        d1->setText(QApplication::translate("class1", "\347\201\2571", nullptr));
        d2->setText(QApplication::translate("class1", "\347\201\2572", nullptr));
        d3->setText(QApplication::translate("class1", "\347\201\2573", nullptr));
        d4->setText(QApplication::translate("class1", "\347\201\2574", nullptr));
        fs1->setText(QApplication::translate("class1", "\351\243\216\346\211\2071", nullptr));
        fs2->setText(QApplication::translate("class1", "\351\243\216\346\211\2072", nullptr));
        kt->setText(QApplication::translate("class1", "\347\251\272\350\260\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class class1: public Ui_class1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASS1_H
