#include "class1.h"
#include "ui_class1.h"
#include "QtMqtt/qmqttclient.h"
#include "mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QFile>              //进行文件操作
#include <QMediaPlayer>
#include <QProcess>
#include "control.h"


//全局变量定义
int mode1=0;   //系统自动手动状态的标志变量 1:手动控制 0：自动控制
extern QString Temp1,Humi1,Light1;//温度、湿度、亮度
extern QString FS1_1,FS1_2,D1_1,D1_2,D1_3,D1_4;//风扇和灯
extern QString KT1;     //空调
extern QString Card_ID1;//最后处理过的卡号字符串
int HumanNum1=0;//人数
extern int HumanNum2;
extern QByteArray input[255];
QString students[10]={"刘骏帆","谢海钰","卢宇杭"};
int qiandao=1;//签到序号
int flag=0;   //劝退标志位
int flag1[10]={0};
int flag2=0;      //摄像头发送

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

    ui->checkBox->setText("手动模式");

}

class1::~class1()
{
    delete ui;
}

void class1::startshow()
{
    this->show();
    control *q = new control();
    q->show();
    //***********登录腾讯云物联网通信必要设置******************
    QByteArray password = "355d5fa9996e10b9f1a5e2dea0744a1b9998ce12314a58a8a20f17dfc818a767;hmacsha256";//填写密码
    quint16 port = 1883;
    client1=new QMqttClient(this);


        client1->setKeepAlive(120);
        client1->setHostname("106.55.124.154");//设置服务器IP
        client1->setPort(port);//设置服务器端口号
        client1->setClientId("LK58090NWKQT");//cliendID
        //client->setClientId("DXNET9YB6G222");//cliendID
        //client->setUsername("DXNET9YB6G222;12010126;95MMP;1681061987");//userID
        client1->setUsername("LK58090NWKQT;12010126;XLG53;1682060330");
        //client->setPassword(password);//设置一个客户端密码
        client1->setPassword("ca89acab96acec59082f7142414aa96bfac14f6dba275cabb15cda8e58fc0cbd;hmacsha256");//设置一个客户端密码
        client1->cleanSession();//清除缓存
       // client->setVersion(QMQTT::MQTTVersion::V3_1_1);//设置mqtt版
        client1->connectToHost();//连接服务器


        connect(client1,&QMqttClient::connected,
                        this,&class1::connected_isr);
        connect(client1,&QMqttClient::messageReceived,
                        this,&class1::recv_message);

        connect(this,SIGNAL(message_rece()),
                    this,SLOT(stateupdata1()));

        connect(this,SIGNAL(message_send(char * )),
                    this,SLOT(send_message1(char * )));
        connect(q,SIGNAL(huchange()),this,SLOT(stateupdata1()));

        ui->d1->setDisabled(true);
        ui->d2->setDisabled(true);
        ui->d3->setDisabled(true);
        ui->d4->setDisabled(true);
        ui->fs1->setDisabled(true);
        ui->fs2->setDisabled(true);
        ui->kt->setDisabled(true);

        //test card
        //QByteArray test = "#1#26#41#277.50#11#1111#1#00000001#1";
        //recv_message(test);

}

//成功连接回调
void class1::connected_isr()
{
    client1->subscribe(QMqttTopicFilter("LK58090NWK/QT/control"));//订阅频道
    qDebug()<<"Connected class1!";
}

void class1::send_message1(char * msg)
{
    QString payload= msg;//消息内容体
    client1->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client1->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client1->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    for(int i = 0;i<100;i++)
    {;}
    client1->publish(QMqttTopicName("LK58090NWK/QT/event"),payload.toLocal8Bit(),2);//发布消息
    qDebug()<<"1发送成功"<<payload<<endl;
}
//收到消息回调
void class1::recv_message(QByteArray message)
{
    int num = 0 ;   //记录#的多少，相对应数据含义
    QString class_no="1";
    QString temp1="0",temp2="0";//亮度整数
    int temp[10]={0};
    int locat,length;

    ui->textBrowser1_rs->setText(QString::number(HumanNum1));
    ui->textBrowser1_wd->setText(Temp1);
    ui->textBrowser1_sd->setText(Humi1);
    ui->textBrowser1_ld->setText(Light1);

    qDebug()<<"1接收信息:"<<message<<endl;

    //为了识别卡号多跑一次
    for( int i = 0 ; i <= message.size()  ; i++  )
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
                    qDebug()<<"class"<<class_no;//debug
                }break;

            case 3:     //温度
                {
                    if(class_no == '1')
                    {
                        Temp1 = message.mid(locat,length);
                    }
                    else if(class_no == '2')
                    {

                    }
                    ui->textBrowser1_wd->setText(Temp1);

                }break;

            case 4:     //湿度
                {
                    if(class_no == '1')
                     {
                        Humi1 = message.mid(locat,length);
                    }
                    else if(class_no == '2')
                    {

                    }
                    ui->textBrowser1_sd->setText(Humi1);

                }break;

            case 5:     //亮度
                {
                   if(class_no == '1')
                    {
                        Light1 = message.mid(locat,length);
                    }
                  else if(class_no == '2')
                    {

                    }
                   ui->textBrowser1_ld->setText(Light1);

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

                    }
                }break;

            case 9:     //卡号
                {
                    if(class_no == '1')
                    {
                        Card_ID1 = message.mid(locat,8);
                        qDebug()<<"card.id"<<Card_ID1;//debug
                    }
                    else if(class_no == '2')
                    {

                    }
                }break;

        default:{qDebug()<<"error"<<i;}break;

             }
        }


    }
    emit message_rece();
}

// 槽函数实现

void class1::readyReadData()
{
    // 从接收缓冲区中读取串口数据
    QByteArray buffer = serial.readAll();
    //测试格式  视觉人数处理

    for (int i = 0; i < 255 ;i++ ) {
        if(buffer == input[i])
        {
            HumanNum1 = i+1;//人数
            ui->textBrowser1_rs->setText(QString::number(i+1));

        }
    }

    emit shijue();

    flag2++;
    if(flag2 >=5)
    {
        qDebug()<<"---教室1视觉人数处理---";
        qDebug() << "识别人数：" << HumanNum1 <<endl;
        flag2=0;
        //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
        char str[40];
        sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                    HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                    FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

        emit message_send(str);
    }


}

void class1::on_radioButton_clicked()
{


}

void class1::on_checkBox_clicked()
{
    switch(mode1)
  {
    case 0: //自动
    {
        mode1=1;
    }break;
    case 1: //手动
    {
        mode1=0;
    }break;

  }

    if(mode1==0)    //自动
    {
        ui->d1->setDisabled(true);
        ui->d2->setDisabled(true);
        ui->d3->setDisabled(true);
        ui->d4->setDisabled(true);
        ui->fs1->setDisabled(true);
        ui->fs2->setDisabled(true);
        ui->kt->setDisabled(true);
    }
    else if(mode1==1)
    {
        ui->d1->setDisabled(false);
        ui->d2->setDisabled(false);
        ui->d3->setDisabled(false);
        ui->d4->setDisabled(false);
        ui->fs1->setDisabled(false);
        ui->fs2->setDisabled(false);
        ui->kt->setDisabled(false);
    }

    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);

}

void class1::on_d1_clicked()
{
    switch (D1_1.toInt())
    {
    case 1:{D1_1="0";}break;
    case 0:{D1_1="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];

    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_d2_clicked()
{
    switch (D1_2.toInt())
    {
    case 1:{D1_2="0";}break;
    case 0:{D1_2="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_d3_clicked()
{
    switch (D1_3.toInt())
    {
    case 1:{D1_3="0";}break;
    case 0:{D1_3="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_d4_clicked()
{
    switch (D1_4.toInt())
    {
    case 1:{D1_4="0";}break;
    case 0:{D1_4="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_fs1_clicked()
{
    switch (FS1_1.toInt())
    {
    case 1:{FS1_1="0";}break;
    case 0:{FS1_1="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_fs2_clicked()
{
    switch (FS1_2.toInt())
    {
    case 1:{FS1_2="0";}break;
    case 0:{FS1_2="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::on_kt_clicked()
{
    switch (KT1.toInt())
    {
    case 1:{KT1="0";}break;
    case 0:{KT1="1";}break;
    }
    //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
    char str[40];
    sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());

    emit message_send(str);
}

void class1::stateupdata1()
{
    ui->checkBox_2->setChecked(true);
    ui->textBrowser1_rs->setText(QString::number(HumanNum1));
    ui->textBrowser1_wd->setText(Temp1);
    ui->textBrowser1_sd->setText(Humi1);
    ui->textBrowser1_ld->setText(Light1);


    if(D1_1 == "0"){ui->d1->setChecked(false);}
    if(D1_1 != "0"){D1_1="1";ui->d1->setChecked(true);}

    if(D1_2 == "0"){ui->d2->setChecked(false);}
    if(D1_2 != "0"){D1_2="1";ui->d2->setChecked(true);}

    if(D1_3 == "0"){ui->d3->setChecked(false);}
    if(D1_3 != "0"){D1_3="1";ui->d3->setChecked(true);}

    if(D1_4 == "0"){ui->d4->setChecked(false);}
    if(D1_4 != "0"){D1_4="1";ui->d4->setChecked(true);}

    if(FS1_1 == "0"){ui->fs1->setChecked(false);}
    if(FS1_1 != "0"){FS1_1="1";ui->fs1->setChecked(true);}

    if(FS1_2 == "0"){ui->fs2->setChecked(false);}
    if(FS1_2 != "0"){FS1_2="1";ui->fs2->setChecked(true);}

    if(KT1 == "0"){ui->kt->setChecked(false);}
    if(KT1 != "0"){KT1="1";ui->kt->setChecked(true);}

    if(Card_ID1 == "e1eff3cc")  //student1
    {
        if(flag1[0]==0){
        //创建对象并绑定到对应文件
        QString filepath = "E:\\qtdemo\\HTB\\text\\签到表.txt";
        QFile file(filepath);
        //设定文件的打开方式
        //向文件中写入内容
        file.open(QIODevice::Append | QIODevice::Text);
        char str[20];
        sprintf(str,"学生%d：刘骏帆 \n",qiandao);
        file.write(str);
        qiandao++;
        flag1[0]=1;
        }
    }
    else if(Card_ID1 == "5c8be33f") //student2
    {
        if(flag1[1]==0){
    //创建对象并绑定到对应文件
    QString filepath = "E:\\qtdemo\\HTB\\text\\签到表.txt";
    QFile file(filepath);
    //设定文件的打开方式
    //向文件中写入内容
    file.open(QIODevice::Append | QIODevice::Text);
    char str[20];
    sprintf(str,"学生%d：谢海钰 \n",qiandao);
    file.write(str);
    qiandao++;
    flag1[1]=1;
        }
    }

    //如果课室2也没人，1正常开。
    //2的人数大于1且1少人。1劝退
    if(HumanNum1<10 && HumanNum2 > HumanNum1)
    {
        if(flag == 0)
        {
        QMediaPlayer *player = new QMediaPlayer;
        //播放进度的信号提示
        connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        player->setMedia(QUrl::fromLocalFile("E:\\qtdemo\\HTB\\sound\\人少.mp3"));
        player->setVolume(50); //0~100音量范围,默认是100
        player->play();

        //电器全部关闭
        D1_1 = "0";
        D1_2 = "0";
        D1_3 = "0";
        D1_4 = "0";
        FS1_1 = "0";
        FS1_2 = "0";
        KT1 = "0";

        //$#课室号#电源开关#人数#控制（自动手动）#灯状态（0011）#窗帘#风扇（10）#空调$
        char str[40];
        sprintf(str,"$#1#1#%d#%d#%d%d%d%d#1#%d%d#%d$",
                    HumanNum1,mode1,D1_1.toInt(),D1_2.toInt(),D1_3.toInt(),D1_4.toInt(),
                    FS1_1.toInt(),FS1_2.toInt(),KT1.toInt());
        flag = 1 ;

        emit message_send(str);
        }

    }
    else if(HumanNum1 >=10) //这里只是考虑课室一的逻辑
    {
        flag = 0;
    }
    qDebug()<<"刷新成功"<<endl;
}

void class1::on_pushButton_clicked()
{
    QProcess *txt = new QProcess;
    txt->execute("explorer E:\\qtdemo\\HTB\\text\\签到表.txt");
    qDebug()<<"打开成功!";
}
