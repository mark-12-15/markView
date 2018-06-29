/****************************************************************************
** Meta object code from reading C++ file 'BCSignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/BCSignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSignal_t {
    QByteArrayData data[15];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSignal_t qt_meta_stringdata_BCSignal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BCSignal"
QT_MOC_LITERAL(1, 9, 42), // "on_m_pShowModeComboBox_curren..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "index"
QT_MOC_LITERAL(4, 59, 31), // "on_m_pShowVedioCheckBox_clicked"
QT_MOC_LITERAL(5, 91, 7), // "checked"
QT_MOC_LITERAL(6, 99, 12), // "onSetVisible"
QT_MOC_LITERAL(7, 112, 8), // "bVisible"
QT_MOC_LITERAL(8, 121, 17), // "onActionTriggered"
QT_MOC_LITERAL(9, 139, 5), // "value"
QT_MOC_LITERAL(10, 145, 14), // "onRangeChanged"
QT_MOC_LITERAL(11, 160, 3), // "min"
QT_MOC_LITERAL(12, 164, 3), // "max"
QT_MOC_LITERAL(13, 168, 20), // "onRefreshVedioStatus"
QT_MOC_LITERAL(14, 189, 47) // "on_m_pInputChannelVedioTabWid..."

    },
    "BCSignal\0on_m_pShowModeComboBox_currentIndexChanged\0"
    "\0index\0on_m_pShowVedioCheckBox_clicked\0"
    "checked\0onSetVisible\0bVisible\0"
    "onActionTriggered\0value\0onRangeChanged\0"
    "min\0max\0onRefreshVedioStatus\0"
    "on_m_pInputChannelVedioTabWidget_currentChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSignal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       8,    1,   58,    2, 0x08 /* Private */,
      10,    2,   61,    2, 0x08 /* Private */,
      13,    0,   66,    2, 0x08 /* Private */,
      14,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void BCSignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSignal *_t = static_cast<BCSignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_m_pShowModeComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_m_pShowVedioCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSetVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onRefreshVedioStatus(); break;
        case 6: _t->on_m_pInputChannelVedioTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BCSignal::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BCSignal.data,
      qt_meta_data_BCSignal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSignal.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BCSignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
