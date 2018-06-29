/****************************************************************************
** Meta object code from reading C++ file 'BCSettingCameraWidgetDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingCameraWidgetDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingCameraWidgetDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCCameraDisplayUnitWidget_t {
    QByteArrayData data[3];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCCameraDisplayUnitWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCCameraDisplayUnitWidget_t qt_meta_stringdata_BCCameraDisplayUnitWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "BCCameraDisplayUnitWidget"
QT_MOC_LITERAL(1, 26, 22), // "onStartVideobtnClicked"
QT_MOC_LITERAL(2, 49, 0) // ""

    },
    "BCCameraDisplayUnitWidget\0"
    "onStartVideobtnClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCCameraDisplayUnitWidget[] = {

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
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void BCCameraDisplayUnitWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCCameraDisplayUnitWidget *_t = static_cast<BCCameraDisplayUnitWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartVideobtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BCCameraDisplayUnitWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BCCameraDisplayUnitWidget.data,
      qt_meta_data_BCCameraDisplayUnitWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCCameraDisplayUnitWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCCameraDisplayUnitWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCCameraDisplayUnitWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BCCameraDisplayUnitWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_BCSettingCameraWidgetDlg_t {
    QByteArrayData data[26];
    char stringdata0[722];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingCameraWidgetDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingCameraWidgetDlg_t qt_meta_stringdata_BCSettingCameraWidgetDlg = {
    {
QT_MOC_LITERAL(0, 0, 24), // "BCSettingCameraWidgetDlg"
QT_MOC_LITERAL(1, 25, 25), // "onTreeWidgetDoubleClicked"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 69, 32), // "on_pushButton_CameraLink_clicked"
QT_MOC_LITERAL(5, 102, 33), // "on_pushButton_VideoSelect_cli..."
QT_MOC_LITERAL(6, 136, 28), // "on_toolButton_leftUP_pressed"
QT_MOC_LITERAL(7, 165, 29), // "on_toolButton_leftUP_released"
QT_MOC_LITERAL(8, 195, 24), // "on_toolButton_up_pressed"
QT_MOC_LITERAL(9, 220, 25), // "on_toolButton_up_released"
QT_MOC_LITERAL(10, 246, 29), // "on_toolButton_rightUp_pressed"
QT_MOC_LITERAL(11, 276, 30), // "on_toolButton_rightUp_released"
QT_MOC_LITERAL(12, 307, 26), // "on_toolButton_left_pressed"
QT_MOC_LITERAL(13, 334, 27), // "on_toolButton_left_released"
QT_MOC_LITERAL(14, 362, 27), // "on_toolButton_right_pressed"
QT_MOC_LITERAL(15, 390, 28), // "on_toolButton_right_released"
QT_MOC_LITERAL(16, 419, 30), // "on_toolButton_leftDown_pressed"
QT_MOC_LITERAL(17, 450, 31), // "on_toolButton_leftDown_released"
QT_MOC_LITERAL(18, 482, 26), // "on_toolButton_Down_pressed"
QT_MOC_LITERAL(19, 509, 27), // "on_toolButton_Down_released"
QT_MOC_LITERAL(20, 537, 31), // "on_toolButton_rightDown_pressed"
QT_MOC_LITERAL(21, 569, 32), // "on_toolButton_rightDown_released"
QT_MOC_LITERAL(22, 602, 28), // "on_toolButton_ZoomIn_pressed"
QT_MOC_LITERAL(23, 631, 29), // "on_toolButton_ZoomIn_released"
QT_MOC_LITERAL(24, 661, 29), // "on_toolButton_ZoomOut_pressed"
QT_MOC_LITERAL(25, 691, 30) // "on_toolButton_ZoomOut_released"

    },
    "BCSettingCameraWidgetDlg\0"
    "onTreeWidgetDoubleClicked\0\0QTreeWidgetItem*\0"
    "on_pushButton_CameraLink_clicked\0"
    "on_pushButton_VideoSelect_clicked\0"
    "on_toolButton_leftUP_pressed\0"
    "on_toolButton_leftUP_released\0"
    "on_toolButton_up_pressed\0"
    "on_toolButton_up_released\0"
    "on_toolButton_rightUp_pressed\0"
    "on_toolButton_rightUp_released\0"
    "on_toolButton_left_pressed\0"
    "on_toolButton_left_released\0"
    "on_toolButton_right_pressed\0"
    "on_toolButton_right_released\0"
    "on_toolButton_leftDown_pressed\0"
    "on_toolButton_leftDown_released\0"
    "on_toolButton_Down_pressed\0"
    "on_toolButton_Down_released\0"
    "on_toolButton_rightDown_pressed\0"
    "on_toolButton_rightDown_released\0"
    "on_toolButton_ZoomIn_pressed\0"
    "on_toolButton_ZoomIn_released\0"
    "on_toolButton_ZoomOut_pressed\0"
    "on_toolButton_ZoomOut_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingCameraWidgetDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  129,    2, 0x0a /* Public */,
       4,    0,  134,    2, 0x08 /* Private */,
       5,    0,  135,    2, 0x08 /* Private */,
       6,    0,  136,    2, 0x08 /* Private */,
       7,    0,  137,    2, 0x08 /* Private */,
       8,    0,  138,    2, 0x08 /* Private */,
       9,    0,  139,    2, 0x08 /* Private */,
      10,    0,  140,    2, 0x08 /* Private */,
      11,    0,  141,    2, 0x08 /* Private */,
      12,    0,  142,    2, 0x08 /* Private */,
      13,    0,  143,    2, 0x08 /* Private */,
      14,    0,  144,    2, 0x08 /* Private */,
      15,    0,  145,    2, 0x08 /* Private */,
      16,    0,  146,    2, 0x08 /* Private */,
      17,    0,  147,    2, 0x08 /* Private */,
      18,    0,  148,    2, 0x08 /* Private */,
      19,    0,  149,    2, 0x08 /* Private */,
      20,    0,  150,    2, 0x08 /* Private */,
      21,    0,  151,    2, 0x08 /* Private */,
      22,    0,  152,    2, 0x08 /* Private */,
      23,    0,  153,    2, 0x08 /* Private */,
      24,    0,  154,    2, 0x08 /* Private */,
      25,    0,  155,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void BCSettingCameraWidgetDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingCameraWidgetDlg *_t = static_cast<BCSettingCameraWidgetDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTreeWidgetDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_CameraLink_clicked(); break;
        case 2: _t->on_pushButton_VideoSelect_clicked(); break;
        case 3: _t->on_toolButton_leftUP_pressed(); break;
        case 4: _t->on_toolButton_leftUP_released(); break;
        case 5: _t->on_toolButton_up_pressed(); break;
        case 6: _t->on_toolButton_up_released(); break;
        case 7: _t->on_toolButton_rightUp_pressed(); break;
        case 8: _t->on_toolButton_rightUp_released(); break;
        case 9: _t->on_toolButton_left_pressed(); break;
        case 10: _t->on_toolButton_left_released(); break;
        case 11: _t->on_toolButton_right_pressed(); break;
        case 12: _t->on_toolButton_right_released(); break;
        case 13: _t->on_toolButton_leftDown_pressed(); break;
        case 14: _t->on_toolButton_leftDown_released(); break;
        case 15: _t->on_toolButton_Down_pressed(); break;
        case 16: _t->on_toolButton_Down_released(); break;
        case 17: _t->on_toolButton_rightDown_pressed(); break;
        case 18: _t->on_toolButton_rightDown_released(); break;
        case 19: _t->on_toolButton_ZoomIn_pressed(); break;
        case 20: _t->on_toolButton_ZoomIn_released(); break;
        case 21: _t->on_toolButton_ZoomOut_pressed(); break;
        case 22: _t->on_toolButton_ZoomOut_released(); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingCameraWidgetDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingCameraWidgetDlg.data,
      qt_meta_data_BCSettingCameraWidgetDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingCameraWidgetDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingCameraWidgetDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingCameraWidgetDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingCameraWidgetDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
