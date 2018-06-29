/****************************************************************************
** Meta object code from reading C++ file 'BCLocalDatabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Common/BCLocalDatabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCLocalDatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCLocalDatabase_t {
    QByteArrayData data[18];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCLocalDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCLocalDatabase_t qt_meta_stringdata_BCLocalDatabase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BCLocalDatabase"
QT_MOC_LITERAL(1, 16, 14), // "onVP4000Config"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "lstInputChannel"
QT_MOC_LITERAL(4, 48, 15), // "lstGroupDisplay"
QT_MOC_LITERAL(5, 64, 15), // "lstDefaultScene"
QT_MOC_LITERAL(6, 80, 14), // "onVP2000Config"
QT_MOC_LITERAL(7, 95, 7), // "timeout"
QT_MOC_LITERAL(8, 103, 4), // "arrX"
QT_MOC_LITERAL(9, 108, 4), // "arrY"
QT_MOC_LITERAL(10, 113, 4), // "resX"
QT_MOC_LITERAL(11, 118, 4), // "resY"
QT_MOC_LITERAL(12, 123, 7), // "pcCount"
QT_MOC_LITERAL(13, 131, 10), // "vedioCount"
QT_MOC_LITERAL(14, 142, 7), // "hdCount"
QT_MOC_LITERAL(15, 150, 10), // "onVP2000IP"
QT_MOC_LITERAL(16, 161, 2), // "ip"
QT_MOC_LITERAL(17, 164, 10) // "onDemoMode"

    },
    "BCLocalDatabase\0onVP4000Config\0\0"
    "lstInputChannel\0lstGroupDisplay\0"
    "lstDefaultScene\0onVP2000Config\0timeout\0"
    "arrX\0arrY\0resX\0resY\0pcCount\0vedioCount\0"
    "hdCount\0onVP2000IP\0ip\0onDemoMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCLocalDatabase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       6,    8,   41,    2, 0x08 /* Private */,
      15,    2,   58,    2, 0x08 /* Private */,
      17,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,   16,
    QMetaType::Void,

       0        // eod
};

void BCLocalDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCLocalDatabase *_t = static_cast<BCLocalDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onVP4000Config((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->onVP2000Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->onVP2000IP((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->onDemoMode(); break;
        default: ;
        }
    }
}

const QMetaObject BCLocalDatabase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BCLocalDatabase.data,
      qt_meta_data_BCLocalDatabase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCLocalDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCLocalDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCLocalDatabase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BCLocalDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
