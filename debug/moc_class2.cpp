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
    QByteArrayData data[18];
    char stringdata0[259];
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
QT_MOC_LITERAL(5, 32, 12), // "recv_message"
QT_MOC_LITERAL(6, 45, 7), // "message"
QT_MOC_LITERAL(7, 53, 13), // "connected_isr"
QT_MOC_LITERAL(8, 67, 12), // "stateupdata2"
QT_MOC_LITERAL(9, 80, 25), // "on_checkBox2_stateChanged"
QT_MOC_LITERAL(10, 106, 4), // "arg1"
QT_MOC_LITERAL(11, 111, 20), // "on_d1_2_stateChanged"
QT_MOC_LITERAL(12, 132, 20), // "on_d2_2_stateChanged"
QT_MOC_LITERAL(13, 153, 20), // "on_d3_2_stateChanged"
QT_MOC_LITERAL(14, 174, 20), // "on_d4_2_stateChanged"
QT_MOC_LITERAL(15, 195, 21), // "on_fs1_2_stateChanged"
QT_MOC_LITERAL(16, 217, 21), // "on_fs2_2_stateChanged"
QT_MOC_LITERAL(17, 239, 19) // "on_kt2_stateChanged"

    },
    "class2\0message_send2\0\0char*\0msg\0"
    "recv_message\0message\0connected_isr\0"
    "stateupdata2\0on_checkBox2_stateChanged\0"
    "arg1\0on_d1_2_stateChanged\0"
    "on_d2_2_stateChanged\0on_d3_2_stateChanged\0"
    "on_d4_2_stateChanged\0on_fs1_2_stateChanged\0"
    "on_fs2_2_stateChanged\0on_kt2_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   77,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void class2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<class2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message_send2((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->recv_message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->connected_isr(); break;
        case 3: _t->stateupdata2((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 4: _t->on_checkBox2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_d1_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_d2_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_d3_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_d4_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_fs1_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_fs2_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_kt2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void class2::message_send2(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
