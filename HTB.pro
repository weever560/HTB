QT       += core gui network serialport multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
UI_DIR=./UI

#makefile
SOURCES += \
    class1.cpp \
    class2.cpp \
    main.cpp \
    mainwindow.cpp \
    widget.cpp

HEADERS += \
    class1.h \
    class2.h \
    mainwindow.h \
    widget.h

FORMS += \
    class1.ui \
    class2.ui \
    mainwindow.ui \
    widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lQt5Mqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lQt5Mqttd

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES += \
    rlsb.py


