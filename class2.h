#ifndef CLASS2_H
#define CLASS2_H

#include "QtMqtt/qmqttclient.h"
#include <QWidget>

namespace Ui {
class class2;
}

class class2 : public QWidget
{
    Q_OBJECT

public:
    explicit class2(QWidget *parent = nullptr);
    ~class2();
    QMqttClient *client2;
    void startshow2();

signals:
    void message_send2(char * msg);
    void message_rece2();

private slots:
    void recv_message(QByteArray message);//接收消息回调
    void connected_isr();//连接回调函数


    void stateupdata2();

    void on_checkBox2_clicked();

    void on_d1_2_clicked();

    void on_d2_2_clicked();

    void on_d3_2_clicked();

    void on_d4_2_clicked();

    void on_fs1_2_clicked();

    void on_fs2_2_clicked();

    void on_kt2_clicked();

    void send_message2(char * );    //分控，发送信息

private:
    Ui::class2 *ui;
    void readyReadData();

};

#endif // CLASS1_H
