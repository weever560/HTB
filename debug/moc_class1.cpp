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
    QByteArrayData data[19];
    char stringdata0[267];
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
QT_MOC_LITERAL(5, 31, 12), // "recv_message"
QT_MOC_LITERAL(6, 44, 7), // "message"
QT_MOC_LITERAL(7, 52, 13), // "connected_isr"
QT_MOC_LITERAL(8, 66, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(9, 89, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(10, 114, 4), // "arg1"
QT_MOC_LITERAL(11, 119, 18), // "on_d1_stateChanged"
QT_MOC_LITERAL(12, 138, 18), // "on_d2_stateChanged"
QT_MOC_LITERAL(13, 157, 18), // "on_d3_stateChanged"
QT_MOC_LITERAL(14, 176, 18), // "on_d4_stateChanged"
QT_MOC_LITERAL(15, 195, 19), // "on_fs1_stateChanged"
QT_MOC_LITERAL(16, 215, 19), // "on_fs2_stateChanged"
QT_MOC_LITERAL(17, 235, 18), // "on_kt_stateChanged"
QT_MOC_LITERAL(18, 254, 12) // "stateupdata1"

    },
    "class1\0message_send\0\0char*\0msg\0"
    "recv_message\0message\0connected_isr\0"
    "on_radioButton_clicked\0on_checkBox_stateChanged\0"
    "arg1\0on_d1_stateChanged\0on_d2_stateChanged\0"
    "on_d3_stateChanged\0on_d4_stateChanged\0"
    "on_fs1_stateChanged\0on_fs2_stateChanged\0"
    "on_kt_stateChanged\0stateupdata1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    1,   87,    2, 0x08 /* Private */,
      11,    1,   90,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      15,    1,  102,    2, 0x08 /* Private */,
      16,    1,  105,    2, 0x08 /* Private */,
      17,    1,  108,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void class1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<class1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message_send((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->recv_message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->connected_isr(); break;
        case 3: _t->on_radioButton_clicked(); break;
        case 4: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_d1_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_d2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_d3_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_d4_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_fs1_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_fs2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_kt_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->stateupdata1(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void class1::message_send(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
