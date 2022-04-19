#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "class1.h"
#include "class2.h"
#include "QtMqtt/qmqttclient.h"
#include <QByteArray>
#include <QString>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息


//全局变量定义
QString Temp1="0",Humi1="0",Light1="0";//温度、湿度、亮度
QString FS1_1="0",FS1_2="0",D1_1="0",D1_2="0",D1_3="0",D1_4="0";//风扇和灯
QString KT1="0";
QString Card_ID1="0";//最后处理过的卡号字符串
extern int HumanNum1;//人数
extern int HumanNum2;//人数

extern int mode1;
extern int mode2;
QString Temp2="0",Humi2="0",Light2="0";//温度、湿度、亮度
QString FS2_1="0",FS2_2="0",D2_1="0",D2_2="0",D2_3="0",D2_4="0";//风扇和灯
QString KT2="0";
QString Card_ID2="0";//最后处理过的卡号字符串

 QByteArray input[255] = {"\x01","\x02","\x03","\x04","\x05","\x06","\x07","\x08","\x09","\x0A","\x0B","\x0C","\x0D","\x0E","\x0F"
                   ,"\x10","\x11","\x12","\x13","\x14","\x15","\x16","\x17","\x18","\x19","\x1A","\x1B","\x1C","\x1D","\x1E","\x1F"
                   ,"\x20","\x21","\x22","\x23","\x24","\x25","\x26","\x27","\x28","\x29","\x2A","\x2B","\x2C","\x2D","\x2E","\x2F"
                   ,"\x30","\x31","\x32","\x33","\x34","\x35","\x36","\x37","\x38","\x39","\x3A","\x3B","\x3C","\x3D","\x3E","\x3F"
                   ,"\x40","\x41","\x42","\x43","\x44","\x45","\x46","\x47","\x48","\x49","\x4A","\x4B","\x4C","\x4D","\x4E","\x4F"
                   ,"\x50","\x51","\x52","\x53","\x54","\x55","\x56","\x57","\x58","\x59","\x5A","\x5B","\x5C","\x5D","\x5E","\x5F"
                   ,"\x60","\x61","\x62","\x63","\x64","\x65","\x66","\x67","\x68","\x69","\x6A","\x6B","\x6C","\x6D","\x6E","\x6F"
                   ,"\x70","\x71","\x72","\x73","\x74","\x75","\x76","\x77","\x78","\x79","\x7A","\x7B","\x7C","\x7D","\x7E","\x7F"
                   ,"\x80","\x81","\x82","\x83","\x84","\x85","\x86","\x87","\x88","\x89","\x8A","\x8B","\x8C","\x8D","\x8E","\x8F"
                   ,"\x90","\x91","\x92","\x93","\x94","\x95","\x96","\x97","\x98","\x99","\x9A","\x9B","\x9C","\x9D","\x9E","\x9F"
                   ,"\xA0","\xA1","\xA2","\xA3","\xA4","\xA5","\xA6","\xA7","\xA8","\xA9","\xAA","\xAB","\xAC","\xAD","\xAE","\xAF"
                   ,"\xB0","\xB1","\xB2","\xB3","\xB4","\xB5","\xB6","\xB7","\xB8","\xB9","\xBA","\xBB","\xBC","\xBD","\xBE","\xBF"
                   ,"\xC0","\xC1","\xC2","\xC3","\xC4","\xC5","\xC6","\xC7","\xC8","\xC9","\xCA","\xCB","\xCC","\xCD","\xCE","\xCF"
                   ,"\xD0","\xD1","\xD2","\xD3","\xD4","\xD5","\xD6","\xD7","\xD8","\xD9","\xDA","\xDB","\xDC","\xDD","\xDE","\xDF"
                   ,"\xE0","\xE1","\xE2","\xE3","\xE4","\xE5","\xE6","\xE7","\xE8","\xE9","\xEA","\xEB","\xEC","\xED","\xEE","\xEF"
                   ,"\xF0","\xF1","\xF2","\xF3","\xF4","\xF5","\xF6","\xF7","\xF8","\xF9","\xFA","\xFB","\xFC","\xFD","\xFE","\xFF"};    //处理接收到的python“\x”


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("智能教室登陆系统");
    //**********背景***********
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("E:/qtdemo/HTB/background/info2.jpg"));
    setPalette(pal);
    this->setFixedSize(850,500);   //禁止拉伸
    ui->pushButton3->setDisabled(true);
    ui->pushButton4->setDisabled(true);


    //***********登录腾讯云物联网通信必要设置******************
    QByteArray password = "355d5fa9996e10b9f1a5e2dea0744a1b9998ce12314a58a8a20f17dfc818a767;hmacsha256";//填写密码
    quint16 port = 1883;
    client=new QMqttClient(this);


        client->setKeepAlive(120);
        client->setHostname("106.55.124.154");//设置服务器IP
        client->setPort(port);//设置服务器端口号
        client->setClientId("LK58090NWKQT");//cliendID
        //client->setClientId("DXNET9YB6G222");//cliendID
        //client->setUsername("DXNET9YB6G222;12010126;95MMP;1681061987");//userID
        client->setUsername("LK58090NWKQT;12010126;XLG53;1682060330");
        //client->setPassword(password);//设置一个客户端密码
        client->setPassword("ca89acab96acec59082f7142414aa96bfac14f6dba275cabb15cda8e58fc0cbd;hmacsha256");//设置一个客户端密码
        client->cleanSession();//清除缓存
       // client->setVersion(QMQTT::MQTTVersion::V3_1_1);//设置mqtt版
        client->connectToHost();//连接服务器

        Class1 = new class1();
        Class2 = new class2();
        //接收
        connect(client,&QMqttClient::connected,
                        this,&MainWindow::connected_isr);
        connect(client,&QMqttClient::messageReceived,
                        this,&MainWindow::recv_message);
        connect(this,SIGNAL(rece_message()),
                    Class1,SLOT(stateupdata1()));
        connect(this,SIGNAL(rece_message()),
                    Class2,SLOT(stateupdata2()));


        //发送
        connect(Class1,SIGNAL(message_send(char * )),
                    this,SLOT(send_message(char * )));
        connect(Class2,SIGNAL(message_send2(char * )),
                    this,SLOT(send_message(char * )));

        //视觉
        connect(Class1,SIGNAL(shijue()),
                    this,SLOT(changeshijue()));
        connect(Class2,SIGNAL(shijue2()),
                    this,SLOT(changeshijue()));




}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeshijue()
{
    ui->textBrowser1_rs->setText(QString::number(HumanNum1));
    ui->textBrowser2_rs->setText(QString::number(HumanNum2));
}

//成功连接回调
void MainWindow::connected_isr()
{
    qDebug()<<"Connected successfully!";
    //client->subscribe(QMqttTopicFilter("DXNET9YB6G/222/test"));//订阅频道
    client->subscribe(QMqttTopicFilter("LK58090NWK/QT/control"));//订阅频道
}
           //#1    #26 #41 #277.50  #11    #1111 #1  #"
//收到消息回调 #课室号#温度#湿度#亮度（6）#风扇12#灯1234#空调#卡号（8）#
           //0     2   5   8        15    18     23  25
void MainWindow::recv_message(QByteArray message)
{
    int num = 0 ;   //记录#的多少，相对应数据含义
    QString class_no="0";
    int temp[10]={0};
    int locat,length;


    qDebug()<<"接收信息:"<<message<<endl;

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
                        Temp1 = message.mid(locat,length);
                    }
                    else if(class_no == '2')
                    {
                        Temp2 = message.mid(locat,length);
                    }
                    ui->textBrowser1_wd->setText(Temp1);
                    ui->textBrowser2_wd->setText(Temp2);
                }break;

            case 4:     //湿度
                {
                    if(class_no == '1')
                     {
                        Humi1 = message.mid(locat,length);
                    }
                    else if(class_no == '2')
                    {
                        Humi2 = message.mid(locat,length);
                    }
                    ui->textBrowser1_sd->setText(Humi1);
                    ui->textBrowser2_sd->setText(Humi2);
                }break;

            case 5:     //亮度
                {
                   if(class_no == '1')
                    {
                        Light1 = message.mid(locat,length);
                    }
                  else if(class_no == '2')
                    {
                        Light2 = message.mid(locat,length);
                    }
                   ui->textBrowser1_ld->setText(Light1);
                   ui->textBrowser2_ld->setText(Light2);
                }break;

            case 6:     //风扇
                {
                    if(class_no == '1')
                    {
                        FS1_1 = message.mid(locat,1);
                        FS1_2 = message.mid(locat+1,1);
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
                        D1_1 = message.mid(locat,1);
                        D1_2 = message.mid(locat+1,1);
                        D1_3 = message.mid(locat+2,1);
                        D1_4 = message.mid(locat+3,1);
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
                        KT1 = message.mid(locat,1);
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
                        Card_ID1 = message.mid(locat,8);
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

    emit rece_message();

}
//$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
void MainWindow::send_message(char * msg1)
{
    //提高发送质量的同时提高发送次数
    QString payload= msg1;//消息内容体
    client->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息

    qDebug()<<"发送成功"<<payload<<endl;
}

void MainWindow::on_pushButton1_clicked()
{
    Class1->show();
}

void MainWindow::on_pushButton2_clicked()
{

    Class2->show();
}

void MainWindow::mqtt_tem_handler(QString res)
{

}



void MainWindow::on_pushButton_clicked()
{
    // #教室号#课室总电源开关#人数#自动手动#灯开关#窗帘开关#风扇开关#空调开关
    QString payload="$#1#1#14#0#0011#1#1#1$";//消息内容体
    client->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit());//发布消息

    qDebug()<<"===发good==="<<endl;

}
