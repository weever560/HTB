#include "class1.h"
#include "ui_class1.h"
#include "QtMqtt/qmqttclient.h"
#include "mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息

//全局变量定义
int mode1=0;   //系统自动手动状态的标志变量 1:自动控制 0：手动控制
extern QString Temp1,Humi1,Light1;//温度、湿度、亮度
extern QString FS1_1,FS1_2,D1_1,D1_2,D1_3,D1_4;//风扇和灯
extern QString KT1;     //空调
extern QString Card_ID1;//最后处理过的卡号字符串
int HumanNum1=12;//人数

extern QByteArray input[255];
//创建串口对象
QSerialPort serial;


class1::class1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::class1)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("智能教室登陆系统");

    //**********摄像头串口通讯***********
    //设置串口名COM2
    serial.setPortName("COM2");
    //设置波特率115200
    serial.setBaudRate(QSerialPort::Baud115200);
    //设置数据位数8位
    serial.setDataBits(QSerialPort::Data8);
    //设置无奇偶校验
    serial.setParity(QSerialPort::NoParity);
    //设置停止位1位
    serial.setStopBits(QSerialPort::OneStop);
    //设置没有流控制
    serial.setFlowControl(QSerialPort::NoFlowControl);
    //读写方式打开串口
    serial.open(QIODevice::ReadWrite);
    // 连接信号和槽
    QObject::connect(&serial,&QSerialPort::readyRead,
        this,&class1::readyReadData);

    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("教室1");
    //**********背景***********
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("E:/qtdemo/HTB/background/info3.jpg"));
    setPalette(pal);
    this->setFixedSize(450,470);   //禁止拉伸

}

class1::~class1()
{
    delete ui;
}

//成功连接回调
void class1::connected_isr()
{

    client->subscribe(QMqttTopicFilter("LK58090NWK/QT/control"));//订阅频道
    qDebug()<<"Connected 1!";
}

//收到消息回调
void class1::recv_message(QByteArray message)
{


}

// 槽函数实现

void class1::readyReadData()
{
    // 从接收缓冲区中读取串口数据
    QByteArray buffer = serial.readAll();
    //测试格式  视觉人数处理
    qDebug()<<"---教室1视觉人数处理---";
    for (int i = 0; i < 255 ;i++ ) {
        if(buffer == input[i])
        {
            HumanNum1 = i+1;//人数
            ui->textBrowser1_rs->setText(QString::number(i+1));
            qDebug() << "识别人数：" << i+1 <<endl;
        }
    }
    qDebug()<<"===识别end==="<<endl;
}

void class1::on_radioButton_clicked()
{


}

void class1::on_checkBox_stateChanged(int arg1)
{
    switch(mode1)
  {
    case 0: //手动
    {
        mode1=1;
    }break;
    case 1: //自动
    {
        mode1=0;
    }break;

  }

    if(mode1==1)    //自动
    {
        ui->d1->setDisabled(true);
        ui->d2->setDisabled(true);
        ui->d3->setDisabled(true);
        ui->d4->setDisabled(true);
        ui->fs1->setDisabled(true);
        ui->fs2->setDisabled(true);
        ui->kt->setDisabled(true);
    }
    else if(mode1==0)
    {
        ui->d1->setDisabled(false);
        ui->d2->setDisabled(false);
        ui->d3->setDisabled(false);
        ui->d4->setDisabled(false);
        ui->fs1->setDisabled(false);
        ui->fs2->setDisabled(false);
        ui->kt->setDisabled(false);
    }

    char str[40];
    sprintf(str,"$#1#%d#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);

}

void class1::on_d1_stateChanged(int arg1)
{
    switch (D1_1.toInt())
    {
    case 1:{D1_1="0";}break;
    case 0:{D1_1="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_d2_stateChanged(int arg1)
{
    switch (D1_2.toInt())
    {
    case 1:{D1_2="0";}break;
    case 0:{D1_2="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_d3_stateChanged(int arg1)
{
    switch (D1_3.toInt())
    {
    case 1:{D1_3="0";}break;
    case 0:{D1_3="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_d4_stateChanged(int arg1)
{
    switch (D1_4.toInt())
    {
    case 1:{D1_4="0";}break;
    case 0:{D1_4="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_fs1_stateChanged(int arg1)
{
    switch (FS1_1.toInt())
    {
    case 1:{FS1_1="0";}break;
    case 0:{FS1_1="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_fs2_stateChanged(int arg1)
{
    switch (FS1_2.toInt())
    {
    case 1:{FS1_2="0";}break;
    case 0:{FS1_2="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::on_kt_stateChanged(int arg1)
{
    switch (KT1.toInt())
    {
    case 1:{KT1="0";}break;
    case 0:{KT1="1";}break;
    }
    char str[40];
    sprintf(str,"$#1#%d#%d#%d%d%d%d#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
    ui->textBrowser1_ld->setText(str);
    emit message_send(str);
}

void class1::stateupdata1(char *msg)
{
    ui->checkBox_2->setChecked(true);
    if(D1_1 == "0"){ui->d1->setChecked(false);}
    if(D1_1 == "1"){ui->d1->setChecked(true);}

    if(D1_2 == "0"){ui->d2->setChecked(false);}
    if(D1_2 == "1"){ui->d2->setChecked(true);}

    if(D1_3 == "0"){ui->d3->setChecked(false);}
    if(D1_3 == "1"){ui->d3->setChecked(true);}

    if(D1_4 == "0"){ui->d4->setChecked(false);}
    if(D1_4 == "1"){ui->d4->setChecked(true);}

    if(FS1_1 == "0"){ui->fs1->setChecked(false);}
    if(FS1_1 == "1"){ui->fs1->setChecked(true);}

    if(FS1_2 == "0"){ui->fs2->setChecked(false);}
    if(FS1_2 == "1"){ui->fs2->setChecked(true);}

    if(KT1 == "0"){ui->kt->setChecked(false);}
    if(KT1 == "1"){ui->kt->setChecked(true);}

    qDebug()<<"刷新成功"<<endl;
}
