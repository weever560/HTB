#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void connect_success();
    void server_reply();

    void on_registerButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    MainWindow *mainwindow;//添加总控私有成员
    class1 * Class1;//添加私有成员
    class2 * Class2;//添加私有成员

    void client_register_handler(QString res);
    void client_login_handler(QString res);
};
#endif // WIDGET_H
