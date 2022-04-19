#include "class2.h"
#include "ui_class2.h"
#include "QtMqtt/qmqttclient.h"
#include "mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息

//全局变量定义
int mode2=1;   //系统自动手动状态的标志变量 1:手动控制 0：自动控制
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

class2::~class2()
{
    delete ui;
}
void class2::startshow2()
{
    this->show();
    //***********登录腾讯云物联网通信必要设置******************
    QByteArray password = "355d5fa9996e10b9f1a5e2dea0744a1b9998ce12314a58a8a20f17dfc818a767;hmacsha256";//填写密码
    quint16 port = 1883;
    client2=new QMqttClient(this);


        client2->setKeepAlive(120);
        client2->setHostname("106.55.124.154");//设置服务器IP
        client2->setPort(port);//设置服务器端口号
        client2->setClientId("LK58090NWKQT");//cliendID
        //client->setClientId("DXNET9YB6G222");//cliendID
        //client->setUsername("DXNET9YB6G222;12010126;95MMP;1681061987");//userID
        client2->setUsername("LK58090NWKQT;12010126;XLG53;1682060330");
        //client->setPassword(password);//设置一个客户端密码
        client2->setPassword("ca89acab96acec59082f7142414aa96bfac14f6dba275cabb15cda8e58fc0cbd;hmacsha256");//设置一个客户端密码
        client2->cleanSession();//清除缓存
       // client->setVersion(QMQTT::MQTTVersion::V3_1_1);//设置mqtt版
        client2->connectToHost();//连接服务器


        connect(client2,&QMqttClient::connected,
                        this,&class2::connected_isr);
        connect(client2,&QMqttClient::messageReceived,
                        this,&class2::recv_message);

        //更新刷新，没问题
        connect(this,SIGNAL(message_rece2()),
                    this,SLOT(stateupdata2()));
        //发送数据，待定
        connect(this,SIGNAL(message_send2(char * )),
                    this,SLOT(send_message2(char * )));
}

//成功连接回调
void class2::connected_isr()
{
    client2->subscribe(QMqttTopicFilter("LK58090NWK/QT/control"));//订阅频道
    qDebug()<<"Connected class2!";
}

void class2::send_message2(char * msg)
{
    QString payload= msg;//消息内容体
    client2->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client2->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client2->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client2->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    qDebug()<<"2发送成功"<<payload<<endl;
}
//收到消息回调
void class2::recv_message(QByteArray message)
{
    int num = 0 ;   //记录#的多少，相对应数据含义
    QString class_no="0";
    int temp[10]={0};
    int locat,length;

    ui->textBrowser1_rs->setText(QString::number(HumanNum2));
    ui->textBrowser1_wd->setText(Temp2);
    ui->textBrowser1_sd->setText(Humi2);
    ui->textBrowser1_ld->setText(Light2);

    qDebug()<<"2接收信息:"<<message<<endl;

    for( int i = 0 ; i < message.size()  ; i++  )
    {
        if( message[i] == '#' )
        {
            num++;
            temp[num] = i;
            locat = temp[num-1]+1;
            length = temp[num]-temp[num-1]-1;

        }
        else
        {
        //读取数据
        switch(num)
            {
            case 1:break;
            case 2:     //课室号,只能实现一位
                {
                    class_no = message.mid(locat,length);
                }break;

            case 3:     //温度
                {
                    if(class_no == '1')
                    {

                    }
                    else if(class_no == '2')
                    {
                        Temp2 = message.mid(locat,length);
                    }

                    ui->textBrowser1_wd->setText(Temp2);
                }break;

            case 4:     //湿度
                {
                    if(class_no == '1')
                     {

                    }
                    else if(class_no == '2')
                    {
                        Humi2 = message.mid(locat,length);
                    }

                    ui->textBrowser1_sd->setText(Humi2);
                }break;

            case 5:     //亮度
                {
                   if(class_no == '1')
                    {

                    }
                  else if(class_no == '2')
                    {
                        Light2 = message.mid(locat,length);
                    }

                   ui->textBrowser1_ld->setText(Light2);
                }break;

            case 6:     //风扇
                {
                    if(class_no == '1')
                    {

                    }
                    else if(class_no == '2')
                    {
                        FS2_1 = message.mid(locat,1);
                        FS2_2 = message.mid(locat+1,1);
                    }
                }break;

            case 7:     //灯光
                {
                    if(class_no == '1')
                    {

                    }
                    else if(class_no == '2')
                    {
                        D2_1 = message.mid(locat,1);
                        D2_2 = message.mid(locat+1,1);
                        D2_3 = message.mid(locat+2,1);
                        D2_4 = message.mid(locat+3,1);
                    }
                }break;

            case 8:     //空调
                {
                    if(class_no == '1')
                    {

                    }
                    else if(class_no == '2')
                    {
                        KT2 = message.mid(locat,1);
                    }
                }break;

            case 9:     //卡号
                {
                    if(class_no == '1')
                    {

                    }
                    else if(class_no == '2')
                    {
                        Card_ID2 = message.mid(locat,8);
                    }
                }break;

        default:{qDebug()<<"error"<<i;}break;

             }
        }

    }
    emit message_rece2();
}

// 槽函数实现

void class2::readyReadData()
{
    // 从接收缓冲区中读取串口数据
    QByteArray buffer = serial2.readAll();
    //测试格式  视觉人数处理
    qDebug()<<buffer<<endl;
    qDebug()<<"===识别end==="<<endl;
}


void class2::on_checkBox2_clicked()
{
    switch(mode2)
  {
    case 0: //自动
    {
        mode2=1;
    }break;
    case 1: //手动
    {
        mode2=0;
    }break;

  }

    if(mode2==0)    //自动
    {
        ui->d1_2->setDisabled(true);
        ui->d2_2->setDisabled(true);
        ui->d3_2->setDisabled(true);
        ui->d4_2->setDisabled(true);
        ui->fs1_2->setDisabled(true);
        ui->fs2_2->setDisabled(true);
        ui->kt2->setDisabled(true);
    }
    else if(mode2==1)
    {
        ui->d1_2->setDisabled(false);
        ui->d2_2->setDisabled(false);
        ui->d3_2->setDisabled(false);
        ui->d4_2->setDisabled(false);
        ui->fs1_2->setDisabled(false);
        ui->fs2_2->setDisabled(false);
        ui->kt2->setDisabled(false);
    }

    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_d1_2_clicked()
{
    switch (D2_1.toInt())
    {
    case 1:{D2_1="0";}break;
    case 0:{D2_1="1";}break;
    }

    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_d2_2_clicked()
{
    switch (D2_2.toInt())
    {
    case 1:{D2_2="0";}break;
    case 0:{D2_2="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_d3_2_clicked()
{
    switch (D2_3.toInt())
    {
    case 1:{D2_3="0";}break;
    case 0:{D2_3="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_d4_2_clicked()
{
    switch (D2_4.toInt())
    {
    case 1:{D2_4="0";}break;
    case 0:{D2_4="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_fs1_2_clicked()
{
    switch (FS2_1.toInt())
    {
    case 1:{FS2_1="0";}break;
    case 0:{FS2_1="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_fs2_2_clicked()
{
    switch (FS2_2.toInt())
    {
    case 1:{FS2_2="0";}break;
    case 0:{FS2_2="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum2,mode2,D2_1.toInt(),D2_2.toInt(),D2_3.toInt(),D2_4.toInt(),
                FS2_1.toInt(),FS2_2.toInt(),KT2.toInt());

    emit message_send2(str);
}

void class2::on_kt2_clicked()
{
    switch (KT2.toInt())
    {
    case 1:{KT2="0";}break;
    case 0:{KT2="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#2#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
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
