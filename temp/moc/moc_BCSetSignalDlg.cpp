/****************************************************************************
** Meta object code from reading C++ file 'BCSetSignalDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/BCSetSignalDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSetSignalDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSetSignalDlg_t {
    QByteArrayData data[13];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSetSignalDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSetSignalDlg_t qt_meta_stringdata_BCSetSignalDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BCSetSignalDlg"
QT_MOC_LITERAL(1, 15, 34), // "on_m_pResetSignalSourceBtn_cl..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 19), // "on_m_pOkBtn_clicked"
QT_MOC_LITERAL(4, 71, 23), // "on_m_pCancelBtn_clicked"
QT_MOC_LITERAL(5, 95, 37), // "on_m_pAddGroupInputChannelBtn..."
QT_MOC_LITERAL(6, 133, 39), // "on_m_pClearGroupInputChannelB..."
QT_MOC_LITERAL(7, 173, 35), // "on_m_pModifyInputChannelBtn_c..."
QT_MOC_LITERAL(8, 209, 13), // "onItemChanged"
QT_MOC_LITERAL(9, 223, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 240, 4), // "item"
QT_MOC_LITERAL(11, 245, 6), // "column"
QT_MOC_LITERAL(12, 252, 37) // "on_m_pDelGroupInputChannelBtn..."

    },
    "BCSetSignalDlg\0on_m_pResetSignalSourceBtn_clicked\0"
    "\0on_m_pOkBtn_clicked\0on_m_pCancelBtn_clicked\0"
    "on_m_pAddGroupInputChannelBtn_clicked\0"
    "on_m_pClearGroupInputChannelBtn_clicked\0"
    "on_m_pModifyInputChannelBtn_clicked\0"
    "onItemChanged\0QTreeWidgetItem*\0item\0"
    "column\0on_m_pDelGroupInputChannelBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSetSignalDlg[] = {

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
       8,    2,   60,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   11,
    QMetaType::Void,

       0        // eod
};

void BCSetSignalDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSetSignalDlg *_t = static_cast<BCSetSignalDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_m_pResetSignalSourceBtn_clicked(); break;
        case 1: _t->on_m_pOkBtn_clicked(); break;
        case 2: _t->on_m_pCancelBtn_clicked(); break;
        case 3: _t->on_m_pAddGroupInputChannelBtn_clicked(); break;
        case 4: _t->on_m_pClearGroupInputChannelBtn_clicked(); break;
        case 5: _t->on_m_pModifyInputChannelBtn_clicked(); break;
        case 6: _t->onItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->on_m_pDelGroupInputChannelBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject BCSetSignalDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSetSignalDlg.data,
      qt_meta_data_BCSetSignalDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSetSignalDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSetSignalDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSetSignalDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSetSignalDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
