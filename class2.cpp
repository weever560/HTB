#include "class2.h"
#include "ui_class2.h"
#include "QtMqtt/qmqttclient.h"
#include "mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息

//全局变量定义
int mode2;   //系统自动手动状态的标志变量 1:自动控制 0：手动控制
extern QString Temp2,Humi2,Light2;//温度、湿度、亮度
extern QString FS2_1,FS2_2,D2_1,D2_2,D2_3,D2_4;//风扇和灯
extern QString KT2;     //空调
extern QString Card_ID2;//最后处理过的卡号字符串
int HumanNum2=0;//人数

extern char Report2[255];//串口发送给上位机的字符数组
extern QByteArray input[255];
//创建串口对象
QSerialPort serial2;


class2::class2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::class2)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("智能教室登陆系统");

    //**********摄像头串口通讯***********
    //设置串口名COM2
    serial2.setPortName("COM2");
    //设置波特率115200
    serial2.setBaudRate(QSerialPort::Baud115200);
    //设置数据位数8位
    serial2.setDataBits(QSerialPort::Data8);
    //设置无奇偶校验
    serial2.setParity(QSerialPort::NoParity);
    //设置停止位1位
    serial2.setStopBits(QSerialPort::OneStop);
    //设置没有流控制
    serial2.setFlowControl(QSerialPort::NoFlowControl);
    //读写方式打开串口
    serial2.open(QIODevice::ReadWrite);
    // 连接信号和槽
    QObject::connect(&serial2,&QSerialPort::readyRead,
        this,&class2::readyReadData);

    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("教室2");
    //**********背景***********
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("E:/qtdemo/HTB/background/info3.jpg"));
    setPalette(pal);
    this->setFixedSize(450,470);   //禁止拉伸


}

void class2::startshow2()
{

}

class2::~class2()
{
    delete ui;
}

//成功连接回调
void class2::connected_isr()
{

    client2->subscribe(QMqttTopicFilter("LK58090NWK/QT/control"));//订阅频道
    qDebug()<<"Connected 2!";
}

//收到消息回调
void class2::recv_message(QByteArray message)
{


}

// 槽函数实现

void class2::readyReadData()
{
    // 从接收缓冲区中读取串口数据
    QByteArray buffer = serial2.readAll();
    //测试格式  视觉人数处理
    qDebug()<<"---教室2视觉人数处理---";
    for (int i = 0; i < 255 ;i++ ) {
        if(buffer == input[i])
        {
            HumanNum2 = i+1;//人数
            ui->textBrowser1_rs->setText(QString::number(i+1));
            qDebug() << "识别人数：" << i+1 <<endl;
        }
    }
    qDebug()<<"===识别end==="<<endl;
}







void class2::on_checkBox2_stateChanged(int arg1)
{
    switch(mode2)
   {
     case 0: //手动
     {
         mode2=1;
     }break;
     case 1: //自动
     {
         mode2=0;
     }break;

   }

     if(mode2==1)    //自动
     {
         ui->d1_2->setDisabled(true);
         ui->d2_2->setDisabled(true);
         ui->d3_2->setDisabled(true);
         ui->d4_2->setDisabled(true);
         ui->fs1_2->setDisabled(true);
         ui->fs2_2->setDisabled(true);
         ui->kt2->setDisabled(true);
     }
     else if(mode2==0)
     {
         ui->d1_2->setDisabled(false);
         ui->d2_2->setDisabled(false);
         ui->d3_2->setDisabled(false);
         ui->d4_2->setDisabled(false);
         ui->fs1_2->setDisabled(false);
         ui->fs2_2->setDisabled(false);
         ui->kt2->setDisabled(false);
     }

     char str[40];
     sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                 HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                 FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
     emit message_send2(str);
}


void class2::stateupdata2()
{
    ui->checkBox2_2->setChecked(true);
    ui->textBrowser1_rs->setText(QString::number(HumanNum2));
    ui->textBrowser1_wd->setText(Temp2);
    ui->textBrowser1_sd->setText(Humi2);
    ui->textBrowser1_ld->setText(Light2);
    if(D2_1 == "0"){ui->d1_2->setChecked(false);}
    if(D2_1 == "1"){ui->d1_2->setChecked(true);}

    if(D2_2 == "0"){ui->d2_2->setChecked(false);}
    if(D2_2 == "1"){ui->d2_2->setChecked(true);}

    if(D2_3 == "0"){ui->d3_2->setChecked(false);}
    if(D2_3 == "1"){ui->d3_2->setChecked(true);}

    if(D2_4 == "0"){ui->d4_2->setChecked(false);}
    if(D2_4 == "1"){ui->d4_2->setChecked(true);}

    if(FS2_1 == "0"){ui->fs1_2->setChecked(false);}
    if(FS2_1 == "1"){ui->fs1_2->setChecked(true);}

    if(FS2_2 == "0"){ui->fs2_2->setChecked(false);}
    if(FS2_2 == "1"){ui->fs2_2->setChecked(true);}

    if(KT2 == "0"){ui->kt2->setChecked(false);}
    if(KT2 == "1"){ui->kt2->setChecked(true);}

    qDebug()<<"刷新成功"<<endl;
}


void class2::on_d1_2_stateChanged(int arg1)
{
    switch (D2_1.toInt())
        {
        case 1:{D2_1="0";}break;
        case 0:{D2_1="1";}break;
        }
        char str[40];
        sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                    HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                    FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
        emit message_send2(str);
}

void class2::on_d2_2_stateChanged(int arg1)
{
    switch (D2_2.toInt())
       {
       case 1:{D2_2="0";}break;
       case 0:{D2_2="1";}break;
       }
       char str[40];
       sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                   HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                   FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
       emit message_send2(str);
}

void class2::on_d3_2_stateChanged(int arg1)
{
    switch (D2_3.toInt())
        {
        case 1:{D2_3="0";}break;
        case 0:{D2_3="1";}break;
        }
        char str[40];
        sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                    HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                    FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
        emit message_send2(str);
}

void class2::on_d4_2_stateChanged(int arg1)
{
    switch (D2_4.toInt())
        {
        case 1:{D2_4="0";}break;
        case 0:{D2_4="1";}break;
        }
        char str[40];
        sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                    HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                    FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
        emit message_send2(str);
}

void class2::on_fs1_2_stateChanged(int arg1)
{
    switch (FS2_1.toInt())
       {
       case 1:{FS2_1="0";}break;
       case 0:{FS2_1="1";}break;
       }
       char str[40];
       sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                   HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                   FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
       emit message_send2(str);
}

void class2::on_fs2_2_stateChanged(int arg1)
{
    switch (FS2_2.toInt())
        {
        case 1:{FS2_2="0";}break;
        case 0:{FS2_2="1";}break;
        }
        char str[40];
        sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                    HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                    FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
        emit message_send2(str);
}

void class2::on_kt2_stateChanged(int arg1)
{
    switch (KT2.toInt())
        {
        case 1:{KT2="0";}break;
        case 0:{KT2="1";}break;
        }
        char str[40];
        sprintf(str,"$#2#%d#%d#%d%d%d%d#%d%d#%d$",
                    HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                    FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());
        emit message_send2(str);
}
