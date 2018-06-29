/****************************************************************************
** Meta object code from reading C++ file 'BCVedioDecodeThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Player/BCVedioDecodeThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCVedioDecodeThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCVeioDecodeThread_t {
    QByteArrayData data[14];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCVeioDecodeThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCVeioDecodeThread_t qt_meta_stringdata_BCVeioDecodeThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BCVeioDecodeThread"
QT_MOC_LITERAL(1, 19, 19), // "sigAppendVedioFrame"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 2), // "id"
QT_MOC_LITERAL(4, 43, 2), // "pY"
QT_MOC_LITERAL(5, 46, 2), // "pU"
QT_MOC_LITERAL(6, 49, 2), // "pV"
QT_MOC_LITERAL(7, 52, 6), // "HI_U32"
QT_MOC_LITERAL(8, 59, 5), // "width"
QT_MOC_LITERAL(9, 65, 6), // "height"
QT_MOC_LITERAL(10, 72, 7), // "yStride"
QT_MOC_LITERAL(11, 80, 8), // "uvStride"
QT_MOC_LITERAL(12, 89, 16), // "tmp_prew_pos_tab"
QT_MOC_LITERAL(13, 106, 16) // "onRecvTcpMessage"

    },
    "BCVeioDecodeThread\0sigAppendVedioFrame\0"
    "\0id\0pY\0pU\0pV\0HI_U32\0width\0height\0"
    "yStride\0uvStride\0tmp_prew_pos_tab\0"
    "onRecvTcpMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCVeioDecodeThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    9,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, QMetaType::QByteArray,    3,    4,    5,    6,    8,    9,   10,   11,   12,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void BCVeioDecodeThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCVeioDecodeThread *_t = static_cast<BCVeioDecodeThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAppendVedioFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4])),(*reinterpret_cast< HI_U32(*)>(_a[5])),(*reinterpret_cast< HI_U32(*)>(_a[6])),(*reinterpret_cast< HI_U32(*)>(_a[7])),(*reinterpret_cast< HI_U32(*)>(_a[8])),(*reinterpret_cast< const QByteArray(*)>(_a[9]))); break;
        case 1: _t->onRecvTcpMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BCVeioDecodeThread::*_t)(int , const QByteArray & , const QByteArray & , const QByteArray & , HI_U32 , HI_U32 , HI_U32 , HI_U32 , const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCVeioDecodeThread::sigAppendVedioFrame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BCVeioDecodeThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_BCVeioDecodeThread.data,
      qt_meta_data_BCVeioDecodeThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCVeioDecodeThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCVeioDecodeThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCVeioDecodeThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BCVeioDecodeThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BCVeioDecodeThread::sigAppendVedioFrame(int _t1, const QByteArray & _t2, const QByteArray & _t3, const QByteArray & _t4, HI_U32 _t5, HI_U32 _t6, HI_U32 _t7, HI_U32 _t8, const QByteArray & _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
