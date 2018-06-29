/****************************************************************************
** Meta object code from reading C++ file 'BCSettingBoardCardDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingBoardCardDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingBoardCardDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSettingBoardCardGraphicsView_t {
    QByteArrayData data[1];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingBoardCardGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingBoardCardGraphicsView_t qt_meta_stringdata_BCSettingBoardCardGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 30) // "BCSettingBoardCardGraphicsView"

    },
    "BCSettingBoardCardGraphicsView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingBoardCardGraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BCSettingBoardCardGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BCSettingBoardCardGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_BCSettingBoardCardGraphicsView.data,
      qt_meta_data_BCSettingBoardCardGraphicsView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingBoardCardGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingBoardCardGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingBoardCardGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int BCSettingBoardCardGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_BCSettingBoardCardDlg_t {
    QByteArrayData data[30];
    char stringdata0[557];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingBoardCardDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingBoardCardDlg_t qt_meta_stringdata_BCSettingBoardCardDlg = {
    {
QT_MOC_LITERAL(0, 0, 21), // "BCSettingBoardCardDlg"
QT_MOC_LITERAL(1, 22, 11), // "onBoardCard"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "timeout"
QT_MOC_LITERAL(4, 43, 4), // "type"
QT_MOC_LITERAL(5, 48, 14), // "onDeviceStatus"
QT_MOC_LITERAL(6, 63, 16), // "nVoltageOfDevice"
QT_MOC_LITERAL(7, 80, 20), // "nElectricityOfDevice"
QT_MOC_LITERAL(8, 101, 20), // "nRotationSpeedOfFan1"
QT_MOC_LITERAL(9, 122, 20), // "nRotationSpeedOfFan2"
QT_MOC_LITERAL(10, 143, 20), // "nRotationSpeedOfFan3"
QT_MOC_LITERAL(11, 164, 20), // "nRotationSpeedOfFan4"
QT_MOC_LITERAL(12, 185, 20), // "nRotationSpeedOfFan5"
QT_MOC_LITERAL(13, 206, 20), // "nRotationSpeedOfFan6"
QT_MOC_LITERAL(14, 227, 20), // "nRotationSpeedOfFan7"
QT_MOC_LITERAL(15, 248, 20), // "nRotationSpeedOfFan8"
QT_MOC_LITERAL(16, 269, 17), // "onBoardCardStatus"
QT_MOC_LITERAL(17, 287, 19), // "nCoreVoltageOfChip1"
QT_MOC_LITERAL(18, 307, 20), // "nRoundVoltageOfChip1"
QT_MOC_LITERAL(19, 328, 23), // "nCoreElectricityOfChip1"
QT_MOC_LITERAL(20, 352, 24), // "nRoundElectricityOfChip1"
QT_MOC_LITERAL(21, 377, 19), // "nCoreVoltageOfChip2"
QT_MOC_LITERAL(22, 397, 20), // "nRoundVoltageOfChip2"
QT_MOC_LITERAL(23, 418, 23), // "nCoreElectricityOfChip2"
QT_MOC_LITERAL(24, 442, 24), // "nRoundElectricityOfChip2"
QT_MOC_LITERAL(25, 467, 19), // "nVoltageOfMemorizer"
QT_MOC_LITERAL(26, 487, 23), // "nElectricityOfMemorizer"
QT_MOC_LITERAL(27, 511, 15), // "nVoltageOfInput"
QT_MOC_LITERAL(28, 527, 19), // "nElectricityOfInput"
QT_MOC_LITERAL(29, 547, 9) // "onTimeOut"

    },
    "BCSettingBoardCardDlg\0onBoardCard\0\0"
    "timeout\0type\0onDeviceStatus\0"
    "nVoltageOfDevice\0nElectricityOfDevice\0"
    "nRotationSpeedOfFan1\0nRotationSpeedOfFan2\0"
    "nRotationSpeedOfFan3\0nRotationSpeedOfFan4\0"
    "nRotationSpeedOfFan5\0nRotationSpeedOfFan6\0"
    "nRotationSpeedOfFan7\0nRotationSpeedOfFan8\0"
    "onBoardCardStatus\0nCoreVoltageOfChip1\0"
    "nRoundVoltageOfChip1\0nCoreElectricityOfChip1\0"
    "nRoundElectricityOfChip1\0nCoreVoltageOfChip2\0"
    "nRoundVoltageOfChip2\0nCoreElectricityOfChip2\0"
    "nRoundElectricityOfChip2\0nVoltageOfMemorizer\0"
    "nElectricityOfMemorizer\0nVoltageOfInput\0"
    "nElectricityOfInput\0onTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingBoardCardDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x08 /* Private */,
       5,   11,   39,    2, 0x08 /* Private */,
      16,   13,   62,    2, 0x08 /* Private */,
      29,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void,

       0        // eod
};

void BCSettingBoardCardDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingBoardCardDlg *_t = static_cast<BCSettingBoardCardDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onBoardCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onDeviceStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11]))); break;
        case 2: _t->onBoardCardStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13]))); break;
        case 3: _t->onTimeOut(); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingBoardCardDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingBoardCardDlg.data,
      qt_meta_data_BCSettingBoardCardDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingBoardCardDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingBoardCardDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingBoardCardDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingBoardCardDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
