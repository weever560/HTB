#include "control.h"
#include "ui_control.h"
#include "mainwindow.h"

extern int HumanNum1;
extern int HumanNum2;
control::control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control)
{
    ui->setupUi(this);
}

control::~control()
{
    delete ui;
}

void control::on_pushButton_clicked()
{
    HumanNum1 = ui->textEdit_2->toPlainText().toInt();
    qDebug()<<"HumanNum1="<<HumanNum1<<endl;
    HumanNum2 = ui->textEdit->toPlainText().toInt();
    qDebug()<<"HumanNum2="<<HumanNum2<<endl;
    emit huchange();
}
