/****************************************************************************
** Meta object code from reading C++ file 'BCLocalServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Common/BCLocalServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCLocalServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCLocalServer_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCLocalServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCLocalServer_t qt_meta_stringdata_BCLocalServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BCLocalServer"
QT_MOC_LITERAL(1, 14, 9), // "onTimeout"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "SendTcpData"
QT_MOC_LITERAL(4, 37, 3), // "cmd"
QT_MOC_LITERAL(5, 41, 6), // "cmdLen"
QT_MOC_LITERAL(6, 48, 18), // "SendSerialPortData"
QT_MOC_LITERAL(7, 67, 16), // "onRecvSerialData"
QT_MOC_LITERAL(8, 84, 13), // "onRecvUdpData"
QT_MOC_LITERAL(9, 98, 17), // "onRecvUdpData2000"
QT_MOC_LITERAL(10, 116, 13) // "onRecvTcpData"

    },
    "BCLocalServer\0onTimeout\0\0SendTcpData\0"
    "cmd\0cmdLen\0SendSerialPortData\0"
    "onRecvSerialData\0onRecvUdpData\0"
    "onRecvUdpData2000\0onRecvTcpData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCLocalServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    2,   55,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x28 /* Private | MethodCloned */,
       6,    1,   63,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCLocalServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCLocalServer *_t = static_cast<BCLocalServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimeout(); break;
        case 1: _t->SendTcpData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SendTcpData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->SendSerialPortData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onRecvSerialData(); break;
        case 5: _t->onRecvUdpData(); break;
        case 6: _t->onRecvUdpData2000(); break;
        case 7: _t->onRecvTcpData(); break;
        default: ;
        }
    }
}

const QMetaObject BCLocalServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BCLocalServer.data,
      qt_meta_data_BCLocalServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCLocalServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCLocalServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCLocalServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BCLocalServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
