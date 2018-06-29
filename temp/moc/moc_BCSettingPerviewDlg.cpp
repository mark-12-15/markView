/****************************************************************************
** Meta object code from reading C++ file 'BCSettingPerviewDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingPerviewDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingPerviewDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSettingPerviewDlg_t {
    QByteArrayData data[16];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingPerviewDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingPerviewDlg_t qt_meta_stringdata_BCSettingPerviewDlg = {
    {
QT_MOC_LITERAL(0, 0, 19), // "BCSettingPerviewDlg"
QT_MOC_LITERAL(1, 20, 20), // "onCurrentCellChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 10), // "currentRow"
QT_MOC_LITERAL(4, 53, 13), // "currentColumn"
QT_MOC_LITERAL(5, 67, 11), // "previousRow"
QT_MOC_LITERAL(6, 79, 14), // "previousColumn"
QT_MOC_LITERAL(7, 94, 20), // "on_removeBut_clicked"
QT_MOC_LITERAL(8, 115, 17), // "on_addBut_clicked"
QT_MOC_LITERAL(9, 133, 23), // "on_m_pModifyBtn_clicked"
QT_MOC_LITERAL(10, 157, 40), // "on_m_pResetDefaultMainToolBar..."
QT_MOC_LITERAL(11, 198, 13), // "onItemChanged"
QT_MOC_LITERAL(12, 212, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(13, 229, 4), // "item"
QT_MOC_LITERAL(14, 234, 6), // "column"
QT_MOC_LITERAL(15, 241, 30) // "on_m_pModifyPerviewBtn_clicked"

    },
    "BCSettingPerviewDlg\0onCurrentCellChanged\0"
    "\0currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_removeBut_clicked\0"
    "on_addBut_clicked\0on_m_pModifyBtn_clicked\0"
    "on_m_pResetDefaultMainToolBarBtn_clicked\0"
    "onItemChanged\0QTreeWidgetItem*\0item\0"
    "column\0on_m_pModifyPerviewBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingPerviewDlg[] = {

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
       1,    4,   49,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,
      11,    2,   62,    2, 0x08 /* Private */,
      15,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,
    QMetaType::Void,

       0        // eod
};

void BCSettingPerviewDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingPerviewDlg *_t = static_cast<BCSettingPerviewDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCurrentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->on_removeBut_clicked(); break;
        case 2: _t->on_addBut_clicked(); break;
        case 3: _t->on_m_pModifyBtn_clicked(); break;
        case 4: _t->on_m_pResetDefaultMainToolBarBtn_clicked(); break;
        case 5: _t->onItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_m_pModifyPerviewBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingPerviewDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingPerviewDlg.data,
      qt_meta_data_BCSettingPerviewDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingPerviewDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingPerviewDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingPerviewDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingPerviewDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
