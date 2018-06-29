/****************************************************************************
** Meta object code from reading C++ file 'BCAutoDateDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/BCAutoDateDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCAutoDateDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCAutoDateDlg_t {
    QByteArrayData data[9];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCAutoDateDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCAutoDateDlg_t qt_meta_stringdata_BCAutoDateDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BCAutoDateDlg"
QT_MOC_LITERAL(1, 14, 26), // "on_pushButton_down_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "slot_Finished"
QT_MOC_LITERAL(4, 56, 14), // "slot_ReadyRead"
QT_MOC_LITERAL(5, 71, 21), // "slot_downloadProgress"
QT_MOC_LITERAL(6, 93, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(7, 120, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 144, 19) // "slot_requestTimeout"

    },
    "BCAutoDateDlg\0on_pushButton_down_clicked\0"
    "\0slot_Finished\0slot_ReadyRead\0"
    "slot_downloadProgress\0on_pushButton_exit_clicked\0"
    "on_pushButton_2_clicked\0slot_requestTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCAutoDateDlg[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    2,   52,    2, 0x08 /* Private */,
       6,    0,   57,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCAutoDateDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCAutoDateDlg *_t = static_cast<BCAutoDateDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_down_clicked(); break;
        case 1: _t->slot_Finished(); break;
        case 2: _t->slot_ReadyRead(); break;
        case 3: _t->slot_downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->on_pushButton_exit_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->slot_requestTimeout(); break;
        default: ;
        }
    }
}

const QMetaObject BCAutoDateDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCAutoDateDlg.data,
      qt_meta_data_BCAutoDateDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCAutoDateDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCAutoDateDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCAutoDateDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCAutoDateDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
