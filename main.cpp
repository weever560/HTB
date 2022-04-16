#include "mainwindow.h"
#include "widget.h"
#include "class1.h"
#include "class2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  Widget w;
  //  w.show();
    //成品记得注释下面的
    // MainWindow q;
    //   q.show();
       class2 e;
       e.startshow2();

    return a.exec();
}
