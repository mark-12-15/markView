/****************************************************************************
** Meta object code from reading C++ file 'BCControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/BCControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCControl_t {
    QByteArrayData data[16];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCControl_t qt_meta_stringdata_BCControl = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BCControl"
QT_MOC_LITERAL(1, 10, 12), // "onSetVisible"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 31), // "on_m_pShowVedioCheckBox_clicked"
QT_MOC_LITERAL(4, 56, 7), // "checked"
QT_MOC_LITERAL(5, 64, 42), // "on_m_pShowModeComboBox_curren..."
QT_MOC_LITERAL(6, 107, 5), // "index"
QT_MOC_LITERAL(7, 113, 17), // "onActionTriggered"
QT_MOC_LITERAL(8, 131, 5), // "value"
QT_MOC_LITERAL(9, 137, 14), // "onRangeChanged"
QT_MOC_LITERAL(10, 152, 3), // "min"
QT_MOC_LITERAL(11, 156, 3), // "max"
QT_MOC_LITERAL(12, 160, 20), // "onRefreshVedioStatus"
QT_MOC_LITERAL(13, 181, 9), // "onTimeOut"
QT_MOC_LITERAL(14, 191, 19), // "onReadConfigTimeOut"
QT_MOC_LITERAL(15, 211, 16) // "onRecvTcpMessage"

    },
    "BCControl\0onSetVisible\0\0"
    "on_m_pShowVedioCheckBox_clicked\0checked\0"
    "on_m_pShowModeComboBox_currentIndexChanged\0"
    "index\0onActionTriggered\0value\0"
    "onRangeChanged\0min\0max\0onRefreshVedioStatus\0"
    "onTimeOut\0onReadConfigTimeOut\0"
    "onRecvTcpMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       3,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       7,    1,   68,    2, 0x08 /* Private */,
       9,    2,   71,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCControl *_t = static_cast<BCControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSetVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_m_pShowVedioCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_m_pShowModeComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onRefreshVedioStatus(); break;
        case 6: _t->onTimeOut(); break;
        case 7: _t->onReadConfigTimeOut(); break;
        case 8: _t->onRecvTcpMessage(); break;
        default: ;
        }
    }
}

const QMetaObject BCControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BCControl.data,
      qt_meta_data_BCControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCControl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BCControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
