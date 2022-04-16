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
    void message_send(char * msg);

public:
    explicit class1(QWidget *parent = nullptr);
    ~class1();
    QMqttClient *client1;
    void startshow();

private slots:
    void recv_message(QByteArray message);//接收消息回调
    void connected_isr();//连接回调函数

    void on_radioButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_d1_stateChanged(int arg1);

    void on_d2_stateChanged(int arg1);

    void on_d3_stateChanged(int arg1);

    void on_d4_stateChanged(int arg1);

    void on_fs1_stateChanged(int arg1);

    void on_fs2_stateChanged(int arg1);

    void on_kt_stateChanged(int arg1);

    void stateupdata1();

private:
    Ui::class1 *ui;
    void readyReadData();

};

#endif // CLASS1_H
