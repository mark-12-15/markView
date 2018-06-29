/****************************************************************************
** Meta object code from reading C++ file 'BCSettingMatrixFormatDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingMatrixFormatDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingMatrixFormatDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSettingMatrixFormatDlg_t {
    QByteArrayData data[12];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingMatrixFormatDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingMatrixFormatDlg_t qt_meta_stringdata_BCSettingMatrixFormatDlg = {
    {
QT_MOC_LITERAL(0, 0, 24), // "BCSettingMatrixFormatDlg"
QT_MOC_LITERAL(1, 25, 20), // "onCurrentItemChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 64, 7), // "current"
QT_MOC_LITERAL(5, 72, 8), // "previous"
QT_MOC_LITERAL(6, 81, 20), // "on_m_pAddBtn_clicked"
QT_MOC_LITERAL(7, 102, 23), // "on_m_pRemoveBtn_clicked"
QT_MOC_LITERAL(8, 126, 23), // "on_m_pCancelBtn_clicked"
QT_MOC_LITERAL(9, 150, 19), // "on_m_pOKBtn_clicked"
QT_MOC_LITERAL(10, 170, 23), // "on_m_pModifyBtn_clicked"
QT_MOC_LITERAL(11, 194, 38) // "on_m_pJointWithVP4000ConfigBt..."

    },
    "BCSettingMatrixFormatDlg\0onCurrentItemChanged\0"
    "\0QListWidgetItem*\0current\0previous\0"
    "on_m_pAddBtn_clicked\0on_m_pRemoveBtn_clicked\0"
    "on_m_pCancelBtn_clicked\0on_m_pOKBtn_clicked\0"
    "on_m_pModifyBtn_clicked\0"
    "on_m_pJointWithVP4000ConfigBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingMatrixFormatDlg[] = {

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
       1,    2,   49,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCSettingMatrixFormatDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingMatrixFormatDlg *_t = static_cast<BCSettingMatrixFormatDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCurrentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 1: _t->on_m_pAddBtn_clicked(); break;
        case 2: _t->on_m_pRemoveBtn_clicked(); break;
        case 3: _t->on_m_pCancelBtn_clicked(); break;
        case 4: _t->on_m_pOKBtn_clicked(); break;
        case 5: _t->on_m_pModifyBtn_clicked(); break;
        case 6: _t->on_m_pJointWithVP4000ConfigBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingMatrixFormatDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingMatrixFormatDlg.data,
      qt_meta_data_BCSettingMatrixFormatDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingMatrixFormatDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingMatrixFormatDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingMatrixFormatDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingMatrixFormatDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
