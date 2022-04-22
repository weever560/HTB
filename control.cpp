#include "control.h"
#include "ui_control.h"
#include "mainwindow.h"

extern int HumanNum1;
extern int HumanNum2;
extern QString Temp1,Humi1,Light1;//温度、湿度、亮度
extern QString FS1_1,FS1_2,D1_1,D1_2,D1_3,D1_4;//风扇和灯
extern QString KT1;     //空调
extern QString Card_ID1;//最后处理过的卡号字符串
extern int mode1;   //系统自动手动状态的标志变量 1:手动控制 0：自动控制

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
    qDebug()<<"人数更改成功！！！"<<endl;
}
