/****************************************************************************
** Meta object code from reading C++ file 'BCSettingTaskDetailDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingTaskDetailDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingTaskDetailDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCDateButton_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCDateButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCDateButton_t qt_meta_stringdata_BCDateButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BCDateButton"
QT_MOC_LITERAL(1, 13, 9), // "onClicked"
QT_MOC_LITERAL(2, 23, 0) // ""

    },
    "BCDateButton\0onClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCDateButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void BCDateButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCDateButton *_t = static_cast<BCDateButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BCDateButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_BCDateButton.data,
      qt_meta_data_BCDateButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCDateButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCDateButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCDateButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int BCDateButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_BCSettingTaskDetailDlg_t {
    QByteArrayData data[6];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingTaskDetailDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingTaskDetailDlg_t qt_meta_stringdata_BCSettingTaskDetailDlg = {
    {
QT_MOC_LITERAL(0, 0, 22), // "BCSettingTaskDetailDlg"
QT_MOC_LITERAL(1, 23, 41), // "on_m_pTaskTypeCombBox_current..."
QT_MOC_LITERAL(2, 65, 0), // ""
QT_MOC_LITERAL(3, 66, 5), // "index"
QT_MOC_LITERAL(4, 72, 23), // "on_m_pCancelBtn_clicked"
QT_MOC_LITERAL(5, 96, 19) // "on_m_pOKBtn_clicked"

    },
    "BCSettingTaskDetailDlg\0"
    "on_m_pTaskTypeCombBox_currentIndexChanged\0"
    "\0index\0on_m_pCancelBtn_clicked\0"
    "on_m_pOKBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingTaskDetailDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCSettingTaskDetailDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingTaskDetailDlg *_t = static_cast<BCSettingTaskDetailDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_m_pTaskTypeCombBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_m_pCancelBtn_clicked(); break;
        case 2: _t->on_m_pOKBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingTaskDetailDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingTaskDetailDlg.data,
      qt_meta_data_BCSettingTaskDetailDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingTaskDetailDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingTaskDetailDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingTaskDetailDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingTaskDetailDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE