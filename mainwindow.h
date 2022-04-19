#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtMqtt/qmqttclient.h"
#include "class1.h"
#include "class2.h"
#include "QtMqtt/qmqttclient.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
     QMqttClient *client;//mqtt服务器对象

signals:
    void rece_message(void);
protected slots:
    void connected_isr();//连接回调函数
private slots:
    void recv_message(QByteArray message);//接收mqtt消息回调
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton_clicked();

    void send_message(char * msg1);    //收到分控改变信号向服务器发送信息

    void changeshijue();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void mqtt_tem_handler(QString res);
    void mqtt_wet_handler(QString res);
    void readyReadData();
    class1 * Class1;//添加私有成员
    class2 * Class2;//添加私有成员

};
#endif // MAINWINDOW_H
