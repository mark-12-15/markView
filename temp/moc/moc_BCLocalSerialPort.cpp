/****************************************************************************
** Meta object code from reading C++ file 'BCLocalSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Common/BCLocalSerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCLocalSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCLocalSerialPort_t {
    QByteArrayData data[20];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCLocalSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCLocalSerialPort_t qt_meta_stringdata_BCLocalSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 17), // "BCLocalSerialPort"
QT_MOC_LITERAL(1, 18, 11), // "sigDemoMode"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "sigVP4000Config"
QT_MOC_LITERAL(4, 47, 15), // "lstInputChannel"
QT_MOC_LITERAL(5, 63, 15), // "lstGroupDisplay"
QT_MOC_LITERAL(6, 79, 15), // "lstDefaultScene"
QT_MOC_LITERAL(7, 95, 15), // "sigVP2000Config"
QT_MOC_LITERAL(8, 111, 7), // "timeout"
QT_MOC_LITERAL(9, 119, 4), // "arrX"
QT_MOC_LITERAL(10, 124, 4), // "arrY"
QT_MOC_LITERAL(11, 129, 4), // "resX"
QT_MOC_LITERAL(12, 134, 4), // "resY"
QT_MOC_LITERAL(13, 139, 7), // "pcCount"
QT_MOC_LITERAL(14, 147, 10), // "vedioCount"
QT_MOC_LITERAL(15, 158, 7), // "hdCount"
QT_MOC_LITERAL(16, 166, 11), // "sigVP2000IP"
QT_MOC_LITERAL(17, 178, 2), // "ip"
QT_MOC_LITERAL(18, 181, 13), // "onRecvMessage"
QT_MOC_LITERAL(19, 195, 9) // "onTimeOut"

    },
    "BCLocalSerialPort\0sigDemoMode\0\0"
    "sigVP4000Config\0lstInputChannel\0"
    "lstGroupDisplay\0lstDefaultScene\0"
    "sigVP2000Config\0timeout\0arrX\0arrY\0"
    "resX\0resY\0pcCount\0vedioCount\0hdCount\0"
    "sigVP2000IP\0ip\0onRecvMessage\0onTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCLocalSerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    3,   45,    2, 0x06 /* Public */,
       7,    8,   52,    2, 0x06 /* Public */,
      16,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,   74,    2, 0x08 /* Private */,
      19,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCLocalSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCLocalSerialPort *_t = static_cast<BCLocalSerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDemoMode(); break;
        case 1: _t->sigVP4000Config((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 2: _t->sigVP2000Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 3: _t->sigVP2000IP((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->onRecvMessage(); break;
        case 5: _t->onTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BCLocalSerialPort::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCLocalSerialPort::sigDemoMode)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BCLocalSerialPort::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCLocalSerialPort::sigVP4000Config)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BCLocalSerialPort::*_t)(int , int , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCLocalSerialPort::sigVP2000Config)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BCLocalSerialPort::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCLocalSerialPort::sigVP2000IP)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject BCLocalSerialPort::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_BCLocalSerialPort.data,
      qt_meta_data_BCLocalSerialPort,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCLocalSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCLocalSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCLocalSerialPort.stringdata0))
        return static_cast<void*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int BCLocalSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BCLocalSerialPort::sigDemoMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BCLocalSerialPort::sigVP4000Config(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BCLocalSerialPort::sigVP2000Config(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BCLocalSerialPort::sigVP2000IP(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
