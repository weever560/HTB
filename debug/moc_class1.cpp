/****************************************************************************
** Meta object code from reading C++ file 'class1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../class1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'class1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_t {
    QByteArrayData data[20];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class1_t qt_meta_stringdata_class1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "class1"
QT_MOC_LITERAL(1, 7, 12), // "message_send"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "char*"
QT_MOC_LITERAL(4, 27, 3), // "msg"
QT_MOC_LITERAL(5, 31, 12), // "message_rece"
QT_MOC_LITERAL(6, 44, 12), // "recv_message"
QT_MOC_LITERAL(7, 57, 7), // "message"
QT_MOC_LITERAL(8, 65, 13), // "connected_isr"
QT_MOC_LITERAL(9, 79, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(10, 102, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(11, 122, 13), // "on_d1_clicked"
QT_MOC_LITERAL(12, 136, 13), // "on_d2_clicked"
QT_MOC_LITERAL(13, 150, 13), // "on_d3_clicked"
QT_MOC_LITERAL(14, 164, 13), // "on_d4_clicked"
QT_MOC_LITERAL(15, 178, 14), // "on_fs1_clicked"
QT_MOC_LITERAL(16, 193, 14), // "on_fs2_clicked"
QT_MOC_LITERAL(17, 208, 13), // "on_kt_clicked"
QT_MOC_LITERAL(18, 222, 12), // "stateupdata1"
QT_MOC_LITERAL(19, 235, 13) // "send_message1"

    },
    "class1\0message_send\0\0char*\0msg\0"
    "message_rece\0recv_message\0message\0"
    "connected_isr\0on_radioButton_clicked\0"
    "on_checkBox_clicked\0on_d1_clicked\0"
    "on_d2_clicked\0on_d3_clicked\0on_d4_clicked\0"
    "on_fs1_clicked\0on_fs2_clicked\0"
    "on_kt_clicked\0stateupdata1\0send_message1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   93,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void class1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<class1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message_send((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->message_rece(); break;
        case 2: _t->recv_message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->connected_isr(); break;
        case 4: _t->on_radioButton_clicked(); break;
        case 5: _t->on_checkBox_clicked(); break;
        case 6: _t->on_d1_clicked(); break;
        case 7: _t->on_d2_clicked(); break;
        case 8: _t->on_d3_clicked(); break;
        case 9: _t->on_d4_clicked(); break;
        case 10: _t->on_fs1_clicked(); break;
        case 11: _t->on_fs2_clicked(); break;
        case 12: _t->on_kt_clicked(); break;
        case 13: _t->stateupdata1(); break;
        case 14: _t->send_message1((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (class1::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&class1::message_send)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (class1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&class1::message_rece)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class1::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_class1.data,
    qt_meta_data_class1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int class1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void class1::message_send(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void class1::message_rece()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
