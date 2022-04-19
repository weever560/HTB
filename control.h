#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>

namespace Ui {
class control;
}

class control : public QWidget
{
    Q_OBJECT

signals:
    void huchange();
public:
    explicit control(QWidget *parent = nullptr);
    ~control();

private slots:
    void on_pushButton_clicked();

private:
    Ui::control *ui;
};

#endif // CONTROL_H
