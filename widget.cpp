#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"

int i = 3;  //三次登录机会


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("E:/qtdemo/HTB/icon/info.png"));  //图案
    this->setWindowTitle("智能教室登陆系统");
    //背景
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("E:/qtdemo/HTB/background/school.jpeg"));
    setPalette(pal);
    this->setFixedSize(this->width(),this->height());   //禁止拉伸


    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress("47.113.203.27"),80);//服务器公网地址


    connect(socket,&QTcpSocket::connected,this,&Widget::connect_success);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::server_reply);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect_success()
{
    QMessageBox::information(this,"连接提示","连接服务器成功");
}



void Widget::on_registerButton_clicked()
{
    QString username = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();

    QJsonObject obj ;
    obj.insert("cmd","register");
    obj.insert("user",username);
    obj.insert("password",password);

    QByteArray ba = QJsonDocument(obj).toJson();    //toJson转为文本格式来通信
    socket->write(ba);
}

void Widget::server_reply()
{
    QByteArray ba = socket->readAll();
    QJsonObject obj = QJsonDocument::fromJson(ba).object();     //从Json转为object对象
    QString cmd = obj.value("cmd").toString();
    if(cmd == "register_reply")
    {
        client_register_handler(obj.value("result").toString());
    }
    if(cmd == "login_reply")
    {
        client_login_handler(obj.value("result").toString());
    }
}

void Widget::client_register_handler(QString res)
{
    if(res == "success")
    {
        QMessageBox::information(this,"注册提示","注册成功");
    }
    else if (res == "failure")
    {
        QMessageBox::warning(this,"注册失败","注册失败");
    }
}

void Widget::client_login_handler(QString res)
{
    if(res == "login_success")
    {
        QMessageBox::information(this,"登录提示","分控登录成功");
        mainwindow = new MainWindow(this);
        close();
        mainwindow->show();
    }
/*    else if(res == "login_main_success")
    {
        QMessageBox::information(this,"登录提示","总控登录成功");
        mainwindow = new MainWindow(this);
        close();
        mainwindow->show();
    }*/
    else if (res == "user_not_exist")
    {
        if(i == 0)
         close();

        else
        {i--;
        QMessageBox::warning(this,"登录失败","登录失败，用户不存在!!!");}

    }
    else if(res == "password effort")
    {
        if(i == 0)
         close();

        else{
        i--;
        QMessageBox::warning(this,"登录失败","登录失败，密码错误!!!");}
    }
}

void Widget::on_loginButton_clicked()
{
    QString username = ui->userLineEdit->text();
    QString password = ui->passwdLineEdit->text();

    QJsonObject obj ;
    obj.insert("cmd","login");
    obj.insert("user",username);
    obj.insert("password",password);

    QByteArray ba = QJsonDocument(obj).toJson();    //toJson转为Json格式来通信
    socket->write(ba);
}
