#ifndef CLASS1_H
#define CLASS1_H
#include "QtMqtt/qmqttclient.h"
#include <QWidget>

namespace Ui {
class class1;
}

class class1 : public QWidget
{
    Q_OBJECT

signals:
    void message_send(char * msg);  //（总控）跟总部发送信号告诉他发送信息
    void message_rece();            //（分控）自己接受mqtt信息后改变状态
    void shijue();                  //视觉

public:
    explicit class1(QWidget *parent = nullptr);
    ~class1();
    QMqttClient *client1;
    void startshow();

private slots:
    void recv_message(QByteArray message);//接收消息回调
    void connected_isr();//连接回调函数

    void on_radioButton_clicked();

    void on_checkBox_clicked();

    void on_d1_clicked();

    void on_d2_clicked();

    void on_d3_clicked();

    void on_d4_clicked();

    void on_fs1_clicked();

    void on_fs2_clicked();

    void on_kt_clicked();

    void stateupdata1();

    void send_message1(char * );    //分控，发送信息

    void on_pushButton_clicked();

private:
    Ui::class1 *ui;
    void readyReadData();
    void readyReadData2();
};

#endif // CLASS1_H
