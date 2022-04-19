/****************************************************************************
** Meta object code from reading C++ file 'class2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../class2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'class2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class2_t {
    QByteArrayData data[20];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class2_t qt_meta_stringdata_class2 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "class2"
QT_MOC_LITERAL(1, 7, 13), // "message_send2"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "char*"
QT_MOC_LITERAL(4, 28, 3), // "msg"
QT_MOC_LITERAL(5, 32, 13), // "message_rece2"
QT_MOC_LITERAL(6, 46, 7), // "shijue2"
QT_MOC_LITERAL(7, 54, 12), // "recv_message"
QT_MOC_LITERAL(8, 67, 7), // "message"
QT_MOC_LITERAL(9, 75, 13), // "connected_isr"
QT_MOC_LITERAL(10, 89, 12), // "stateupdata2"
QT_MOC_LITERAL(11, 102, 20), // "on_checkBox2_clicked"
QT_MOC_LITERAL(12, 123, 15), // "on_d1_2_clicked"
QT_MOC_LITERAL(13, 139, 15), // "on_d2_2_clicked"
QT_MOC_LITERAL(14, 155, 15), // "on_d3_2_clicked"
QT_MOC_LITERAL(15, 171, 15), // "on_d4_2_clicked"
QT_MOC_LITERAL(16, 187, 16), // "on_fs1_2_clicked"
QT_MOC_LITERAL(17, 204, 16), // "on_fs2_2_clicked"
QT_MOC_LITERAL(18, 221, 14), // "on_kt2_clicked"
QT_MOC_LITERAL(19, 236, 13) // "send_message2"

    },
    "class2\0message_send2\0\0char*\0msg\0"
    "message_rece2\0shijue2\0recv_message\0"
    "message\0connected_isr\0stateupdata2\0"
    "on_checkBox2_clicked\0on_d1_2_clicked\0"
    "on_d2_2_clicked\0on_d3_2_clicked\0"
    "on_d4_2_clicked\0on_fs1_2_clicked\0"
    "on_fs2_2_clicked\0on_kt2_clicked\0"
    "send_message2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   94,    2, 0x08 /* Private */,
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
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    8,
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

void class2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<class2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message_send2((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->message_rece2(); break;
        case 2: _t->shijue2(); break;
        case 3: _t->recv_message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->connected_isr(); break;
        case 5: _t->stateupdata2(); break;
        case 6: _t->on_checkBox2_clicked(); break;
        case 7: _t->on_d1_2_clicked(); break;
        case 8: _t->on_d2_2_clicked(); break;
        case 9: _t->on_d3_2_clicked(); break;
        case 10: _t->on_d4_2_clicked(); break;
        case 11: _t->on_fs1_2_clicked(); break;
        case 12: _t->on_fs2_2_clicked(); break;
        case 13: _t->on_kt2_clicked(); break;
        case 14: _t->send_message2((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (class2::*)(char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&class2::message_send2)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (class2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&class2::message_rece2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (class2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&class2::shijue2)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class2::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_class2.data,
    qt_meta_data_class2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int class2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void class2::message_send2(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void class2::message_rece2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void class2::shijue2()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
