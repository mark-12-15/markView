/****************************************************************************
** Meta object code from reading C++ file 'AlarmManagement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/AlarmManagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlarmManagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlarmManagement_t {
    QByteArrayData data[17];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlarmManagement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlarmManagement_t qt_meta_stringdata_AlarmManagement = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AlarmManagement"
QT_MOC_LITERAL(1, 16, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 63, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(5, 87, 11), // "AddTreeNode"
QT_MOC_LITERAL(6, 99, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 116, 4), // "root"
QT_MOC_LITERAL(8, 121, 5), // "texts"
QT_MOC_LITERAL(9, 127, 15), // "clickSectionBox"
QT_MOC_LITERAL(10, 143, 23), // "changeBoxStateInSection"
QT_MOC_LITERAL(11, 167, 10), // "QCheckBox*"
QT_MOC_LITERAL(12, 178, 7), // "section"
QT_MOC_LITERAL(13, 186, 5), // "index"
QT_MOC_LITERAL(14, 192, 27), // "checkAllBoxByTopLeavelIndex"
QT_MOC_LITERAL(15, 220, 10), // "clickState"
QT_MOC_LITERAL(16, 231, 23) // "on_pushButton_3_clicked"

    },
    "AlarmManagement\0on_pushButton_clicked\0"
    "\0on_pushButton_2_clicked\0"
    "on_pushButton_4_clicked\0AddTreeNode\0"
    "QTreeWidgetItem*\0root\0texts\0clickSectionBox\0"
    "changeBoxStateInSection\0QCheckBox*\0"
    "section\0index\0checkAllBoxByTopLeavelIndex\0"
    "clickState\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlarmManagement[] = {

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
       5,    2,   57,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    2,   63,    2, 0x08 /* Private */,
      14,    2,   68,    2, 0x08 /* Private */,
      16,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QStringList,    7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   13,   15,
    QMetaType::Void,

       0        // eod
};

void AlarmManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlarmManagement *_t = static_cast<AlarmManagement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->AddTreeNode((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 4: _t->clickSectionBox(); break;
        case 5: _t->changeBoxStateInSection((*reinterpret_cast< QCheckBox*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->checkAllBoxByTopLeavelIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCheckBox* >(); break;
            }
            break;
        }
    }
}

const QMetaObject AlarmManagement::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AlarmManagement.data,
      qt_meta_data_AlarmManagement,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AlarmManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlarmManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmManagement.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AlarmManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
