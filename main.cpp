#include "mainwindow.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    MainWindow q;
    q.show();
    return a.exec();
}
