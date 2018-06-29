/****************************************************************************
** Meta object code from reading C++ file 'BCSignalWindowDisplayWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/BCSignalWindowDisplayWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSignalWindowDisplayWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSignalWindowDisplayWidget_t {
    QByteArrayData data[10];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSignalWindowDisplayWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSignalWindowDisplayWidget_t qt_meta_stringdata_BCSignalWindowDisplayWidget = {
    {
QT_MOC_LITERAL(0, 0, 27), // "BCSignalWindowDisplayWidget"
QT_MOC_LITERAL(1, 28, 21), // "on_m_pLockBtn_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 27), // "on_m_pFullscreenBtn_clicked"
QT_MOC_LITERAL(4, 79, 27), // "on_m_pWindowShowBtn_clicked"
QT_MOC_LITERAL(5, 107, 22), // "on_m_pCloseBtn_clicked"
QT_MOC_LITERAL(6, 130, 12), // "onIPVTimeout"
QT_MOC_LITERAL(7, 143, 23), // "on_m_pRemoteBtn_clicked"
QT_MOC_LITERAL(8, 167, 21), // "onConstructionTimeout"
QT_MOC_LITERAL(9, 189, 20) // "onDestructionTimeout"

    },
    "BCSignalWindowDisplayWidget\0"
    "on_m_pLockBtn_clicked\0\0"
    "on_m_pFullscreenBtn_clicked\0"
    "on_m_pWindowShowBtn_clicked\0"
    "on_m_pCloseBtn_clicked\0onIPVTimeout\0"
    "on_m_pRemoteBtn_clicked\0onConstructionTimeout\0"
    "onDestructionTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSignalWindowDisplayWidget[] = {

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
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCSignalWindowDisplayWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSignalWindowDisplayWidget *_t = static_cast<BCSignalWindowDisplayWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_m_pLockBtn_clicked(); break;
        case 1: _t->on_m_pFullscreenBtn_clicked(); break;
        case 2: _t->on_m_pWindowShowBtn_clicked(); break;
        case 3: _t->on_m_pCloseBtn_clicked(); break;
        case 4: _t->onIPVTimeout(); break;
        case 5: _t->on_m_pRemoteBtn_clicked(); break;
        case 6: _t->onConstructionTimeout(); break;
        case 7: _t->onDestructionTimeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BCSignalWindowDisplayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BCSignalWindowDisplayWidget.data,
      qt_meta_data_BCSignalWindowDisplayWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSignalWindowDisplayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSignalWindowDisplayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSignalWindowDisplayWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BCSignalWindowDisplayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
