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
    QMqttClient *client;

signals:
    void message_send2(char * msg);
private slots:
    void recv_message(QByteArray message);//接收消息回调
    void connected_isr();//连接回调函数


    void stateupdata2(char * msg);

    void on_checkBox2_stateChanged(int arg1);

    void on_d1_2_stateChanged(int arg1);

    void on_d2_2_stateChanged(int arg1);

    void on_d3_2_stateChanged(int arg1);

    void on_d4_2_stateChanged(int arg1);

    void on_fs1_2_stateChanged(int arg1);

    void on_fs2_2_stateChanged(int arg1);

    void on_kt2_stateChanged(int arg1);

private:
    Ui::class2 *ui;
    void readyReadData();

};

#endif // CLASS1_H
