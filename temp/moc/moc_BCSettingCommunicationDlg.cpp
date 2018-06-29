/****************************************************************************
** Meta object code from reading C++ file 'BCSettingCommunicationDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Setting/BCSettingCommunicationDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCSettingCommunicationDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCSettingCommunicationUdp_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingCommunicationUdp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingCommunicationUdp_t qt_meta_stringdata_BCSettingCommunicationUdp = {
    {
QT_MOC_LITERAL(0, 0, 25), // "BCSettingCommunicationUdp"
QT_MOC_LITERAL(1, 26, 9), // "sigDevice"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "name"
QT_MOC_LITERAL(4, 42, 2), // "ip"
QT_MOC_LITERAL(5, 45, 4), // "port"
QT_MOC_LITERAL(6, 50, 4), // "mask"
QT_MOC_LITERAL(7, 55, 7), // "gateway"
QT_MOC_LITERAL(8, 63, 3), // "mac"
QT_MOC_LITERAL(9, 67, 12), // "sigPreviewIP"
QT_MOC_LITERAL(10, 80, 23), // "processPendingDatagrams"
QT_MOC_LITERAL(11, 104, 14), // "onSearchDevice"
QT_MOC_LITERAL(12, 119, 21), // "onSearchPreviewDevice"
QT_MOC_LITERAL(13, 141, 20) // "onRecvPreviewUdpData"

    },
    "BCSettingCommunicationUdp\0sigDevice\0"
    "\0name\0ip\0port\0mask\0gateway\0mac\0"
    "sigPreviewIP\0processPendingDatagrams\0"
    "onSearchDevice\0onSearchPreviewDevice\0"
    "onRecvPreviewUdpData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingCommunicationUdp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x06 /* Public */,
       9,    2,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    0,   64,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BCSettingCommunicationUdp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingCommunicationUdp *_t = static_cast<BCSettingCommunicationUdp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDevice((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 1: _t->sigPreviewIP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->processPendingDatagrams(); break;
        case 3: _t->onSearchDevice(); break;
        case 4: _t->onSearchPreviewDevice(); break;
        case 5: _t->onRecvPreviewUdpData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BCSettingCommunicationUdp::*_t)(const QString & , const QString & , int , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCSettingCommunicationUdp::sigDevice)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BCSettingCommunicationUdp::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BCSettingCommunicationUdp::sigPreviewIP)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject BCSettingCommunicationUdp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BCSettingCommunicationUdp.data,
      qt_meta_data_BCSettingCommunicationUdp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingCommunicationUdp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingCommunicationUdp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingCommunicationUdp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BCSettingCommunicationUdp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BCSettingCommunicationUdp::sigDevice(const QString & _t1, const QString & _t2, int _t3, const QString & _t4, const QString & _t5, const QString & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BCSettingCommunicationUdp::sigPreviewIP(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_BCSettingCommunicationDlg_t {
    QByteArrayData data[21];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCSettingCommunicationDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCSettingCommunicationDlg_t qt_meta_stringdata_BCSettingCommunicationDlg = {
    {
QT_MOC_LITERAL(0, 0, 25), // "BCSettingCommunicationDlg"
QT_MOC_LITERAL(1, 26, 19), // "onCurrentRowChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 35), // "on_m_pUseNetConnectRadioBtn_c..."
QT_MOC_LITERAL(4, 83, 35), // "on_m_pUseComConnectRadioBtn_c..."
QT_MOC_LITERAL(5, 119, 24), // "on_m_pMoreSetBtn_clicked"
QT_MOC_LITERAL(6, 144, 29), // "on_m_pSearchDeviceBtn_clicked"
QT_MOC_LITERAL(7, 174, 25), // "on_m_pDemoModeBtn_clicked"
QT_MOC_LITERAL(8, 200, 19), // "on_m_pOkBtn_clicked"
QT_MOC_LITERAL(9, 220, 23), // "on_m_pCancelBtn_clicked"
QT_MOC_LITERAL(10, 244, 35), // "on_m_pModifyDeviceConfigBtn_c..."
QT_MOC_LITERAL(11, 280, 11), // "onAddDevice"
QT_MOC_LITERAL(12, 292, 4), // "name"
QT_MOC_LITERAL(13, 297, 2), // "ip"
QT_MOC_LITERAL(14, 300, 4), // "port"
QT_MOC_LITERAL(15, 305, 4), // "mask"
QT_MOC_LITERAL(16, 310, 7), // "gateway"
QT_MOC_LITERAL(17, 318, 3), // "mac"
QT_MOC_LITERAL(18, 322, 17), // "onAddPrevewDevice"
QT_MOC_LITERAL(19, 340, 36), // "on_m_pDeviceType_currentIndex..."
QT_MOC_LITERAL(20, 377, 5) // "index"

    },
    "BCSettingCommunicationDlg\0onCurrentRowChanged\0"
    "\0on_m_pUseNetConnectRadioBtn_clicked\0"
    "on_m_pUseComConnectRadioBtn_clicked\0"
    "on_m_pMoreSetBtn_clicked\0"
    "on_m_pSearchDeviceBtn_clicked\0"
    "on_m_pDemoModeBtn_clicked\0on_m_pOkBtn_clicked\0"
    "on_m_pCancelBtn_clicked\0"
    "on_m_pModifyDeviceConfigBtn_clicked\0"
    "onAddDevice\0name\0ip\0port\0mask\0gateway\0"
    "mac\0onAddPrevewDevice\0"
    "on_m_pDeviceType_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCSettingCommunicationDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x08 /* Private */,
       3,    0,   83,    2, 0x08 /* Private */,
       4,    0,   84,    2, 0x08 /* Private */,
       5,    0,   85,    2, 0x08 /* Private */,
       6,    0,   86,    2, 0x08 /* Private */,
       7,    0,   87,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    0,   89,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    6,   91,    2, 0x08 /* Private */,
      18,    2,  104,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void BCSettingCommunicationDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCSettingCommunicationDlg *_t = static_cast<BCSettingCommunicationDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCurrentRowChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->on_m_pUseNetConnectRadioBtn_clicked(); break;
        case 2: _t->on_m_pUseComConnectRadioBtn_clicked(); break;
        case 3: _t->on_m_pMoreSetBtn_clicked(); break;
        case 4: _t->on_m_pSearchDeviceBtn_clicked(); break;
        case 5: _t->on_m_pDemoModeBtn_clicked(); break;
        case 6: _t->on_m_pOkBtn_clicked(); break;
        case 7: _t->on_m_pCancelBtn_clicked(); break;
        case 8: _t->on_m_pModifyDeviceConfigBtn_clicked(); break;
        case 9: _t->onAddDevice((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 10: _t->onAddPrevewDevice((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_m_pDeviceType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BCSettingCommunicationDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BCSettingCommunicationDlg.data,
      qt_meta_data_BCSettingCommunicationDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCSettingCommunicationDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCSettingCommunicationDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCSettingCommunicationDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BCSettingCommunicationDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
