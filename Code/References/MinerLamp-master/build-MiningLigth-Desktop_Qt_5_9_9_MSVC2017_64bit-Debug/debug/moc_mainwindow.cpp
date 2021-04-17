/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinerLamp-master/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_autoStart_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_autoStart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_autoStart_t qt_meta_stringdata_autoStart = {
    {
QT_MOC_LITERAL(0, 0, 9), // "autoStart"
QT_MOC_LITERAL(1, 10, 17), // "readyToStartMiner"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "autoStart\0readyToStartMiner\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_autoStart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void autoStart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        autoStart *_t = static_cast<autoStart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyToStartMiner(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (autoStart::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&autoStart::readyToStartMiner)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject autoStart::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_autoStart.data,
      qt_meta_data_autoStart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *autoStart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *autoStart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_autoStart.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int autoStart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void autoStart::readyToStartMiner()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[984];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "setIcon"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "iconActivated"
QT_MOC_LITERAL(4, 34, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(5, 68, 6), // "reason"
QT_MOC_LITERAL(6, 75, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 97, 30), // "on_spinBoxMax0MHs_valueChanged"
QT_MOC_LITERAL(8, 128, 4), // "arg1"
QT_MOC_LITERAL(9, 133, 28), // "on_spinBoxDelay_valueChanged"
QT_MOC_LITERAL(10, 162, 28), // "on_checkBoxOnlyShare_clicked"
QT_MOC_LITERAL(11, 191, 7), // "checked"
QT_MOC_LITERAL(12, 199, 25), // "on_pushButtonHelp_clicked"
QT_MOC_LITERAL(13, 225, 32), // "on_spinBoxDelay0MHs_valueChanged"
QT_MOC_LITERAL(14, 258, 19), // "onReadyToStartMiner"
QT_MOC_LITERAL(15, 278, 37), // "on_checkBoxAutoShowDeviceInfo..."
QT_MOC_LITERAL(16, 316, 15), // "onNvMonitorInfo"
QT_MOC_LITERAL(17, 332, 8), // "gpucount"
QT_MOC_LITERAL(18, 341, 10), // "maxgputemp"
QT_MOC_LITERAL(19, 352, 10), // "mingputemp"
QT_MOC_LITERAL(20, 363, 11), // "maxfanspeed"
QT_MOC_LITERAL(21, 375, 11), // "minfanspeed"
QT_MOC_LITERAL(22, 387, 11), // "maxmemclock"
QT_MOC_LITERAL(23, 399, 11), // "minmemclock"
QT_MOC_LITERAL(24, 411, 11), // "maxgpuclock"
QT_MOC_LITERAL(25, 423, 11), // "mingpuclock"
QT_MOC_LITERAL(26, 435, 12), // "maxpowerdraw"
QT_MOC_LITERAL(27, 448, 12), // "minpowerdraw"
QT_MOC_LITERAL(28, 461, 14), // "totalpowerdraw"
QT_MOC_LITERAL(29, 476, 16), // "onAMDMonitorInfo"
QT_MOC_LITERAL(30, 493, 23), // "on_pushButtonOC_clicked"
QT_MOC_LITERAL(31, 517, 6), // "onHelp"
QT_MOC_LITERAL(32, 524, 27), // "on_groupBoxWatchdog_clicked"
QT_MOC_LITERAL(33, 552, 34), // "on_spinBoxDelayNoHash_valueCh..."
QT_MOC_LITERAL(34, 587, 25), // "on_pushButtonPool_clicked"
QT_MOC_LITERAL(35, 613, 32), // "on_pushButtonShowHideLog_clicked"
QT_MOC_LITERAL(36, 646, 37), // "on_pushButtonDisplayPoolStats..."
QT_MOC_LITERAL(37, 684, 9), // "onBalance"
QT_MOC_LITERAL(38, 694, 7), // "balance"
QT_MOC_LITERAL(39, 702, 14), // "onPoolUserInfo"
QT_MOC_LITERAL(40, 717, 11), // "userBalance"
QT_MOC_LITERAL(41, 729, 26), // "currentCalcultatedHashRate"
QT_MOC_LITERAL(42, 756, 17), // "averageHashRate1H"
QT_MOC_LITERAL(43, 774, 17), // "averageHashRate3H"
QT_MOC_LITERAL(44, 792, 17), // "averageHashRate6H"
QT_MOC_LITERAL(45, 810, 18), // "averageHashRate12H"
QT_MOC_LITERAL(46, 829, 18), // "averageHashRate24H"
QT_MOC_LITERAL(47, 848, 36), // "on_pushButtonEthminerBrowser_..."
QT_MOC_LITERAL(48, 885, 14), // "onHrChartTimer"
QT_MOC_LITERAL(49, 900, 16), // "onTempChartTimer"
QT_MOC_LITERAL(50, 917, 24), // "onRefreshDeviceInfoTimer"
QT_MOC_LITERAL(51, 942, 17), // "onMouseHoverSlice"
QT_MOC_LITERAL(52, 960, 10), // "QPieSlice*"
QT_MOC_LITERAL(53, 971, 5), // "slice"
QT_MOC_LITERAL(54, 977, 6) // "status"

    },
    "MainWindow\0setIcon\0\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0on_pushButton_clicked\0"
    "on_spinBoxMax0MHs_valueChanged\0arg1\0"
    "on_spinBoxDelay_valueChanged\0"
    "on_checkBoxOnlyShare_clicked\0checked\0"
    "on_pushButtonHelp_clicked\0"
    "on_spinBoxDelay0MHs_valueChanged\0"
    "onReadyToStartMiner\0"
    "on_checkBoxAutoShowDeviceInfo_clicked\0"
    "onNvMonitorInfo\0gpucount\0maxgputemp\0"
    "mingputemp\0maxfanspeed\0minfanspeed\0"
    "maxmemclock\0minmemclock\0maxgpuclock\0"
    "mingpuclock\0maxpowerdraw\0minpowerdraw\0"
    "totalpowerdraw\0onAMDMonitorInfo\0"
    "on_pushButtonOC_clicked\0onHelp\0"
    "on_groupBoxWatchdog_clicked\0"
    "on_spinBoxDelayNoHash_valueChanged\0"
    "on_pushButtonPool_clicked\0"
    "on_pushButtonShowHideLog_clicked\0"
    "on_pushButtonDisplayPoolStats_clicked\0"
    "onBalance\0balance\0onPoolUserInfo\0"
    "userBalance\0currentCalcultatedHashRate\0"
    "averageHashRate1H\0averageHashRate3H\0"
    "averageHashRate6H\0averageHashRate12H\0"
    "averageHashRate24H\0"
    "on_pushButtonEthminerBrowser_clicked\0"
    "onHrChartTimer\0onTempChartTimer\0"
    "onRefreshDeviceInfoTimer\0onMouseHoverSlice\0"
    "QPieSlice*\0slice\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x08 /* Private */,
       3,    1,  145,    2, 0x08 /* Private */,
       6,    0,  148,    2, 0x08 /* Private */,
       7,    1,  149,    2, 0x08 /* Private */,
       9,    1,  152,    2, 0x08 /* Private */,
      10,    1,  155,    2, 0x08 /* Private */,
      12,    0,  158,    2, 0x08 /* Private */,
      13,    1,  159,    2, 0x08 /* Private */,
      14,    0,  162,    2, 0x08 /* Private */,
      15,    1,  163,    2, 0x08 /* Private */,
      16,   12,  166,    2, 0x08 /* Private */,
      29,   12,  191,    2, 0x08 /* Private */,
      30,    0,  216,    2, 0x08 /* Private */,
      31,    0,  217,    2, 0x08 /* Private */,
      32,    1,  218,    2, 0x08 /* Private */,
      33,    1,  221,    2, 0x08 /* Private */,
      34,    1,  224,    2, 0x08 /* Private */,
      35,    1,  227,    2, 0x08 /* Private */,
      36,    0,  230,    2, 0x08 /* Private */,
      37,    1,  231,    2, 0x08 /* Private */,
      39,    7,  234,    2, 0x08 /* Private */,
      47,    0,  249,    2, 0x08 /* Private */,
      48,    0,  250,    2, 0x08 /* Private */,
      49,    0,  251,    2, 0x08 /* Private */,
      50,    0,  252,    2, 0x08 /* Private */,
      51,    2,  253,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   40,   41,   42,   43,   44,   45,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52, QMetaType::Bool,   53,   54,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setIcon(); break;
        case 1: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_spinBoxMax0MHs_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBoxDelay_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkBoxOnlyShare_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonHelp_clicked(); break;
        case 7: _t->on_spinBoxDelay0MHs_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onReadyToStartMiner(); break;
        case 9: _t->on_checkBoxAutoShowDeviceInfo_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onNvMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 11: _t->onAMDMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 12: _t->on_pushButtonOC_clicked(); break;
        case 13: _t->onHelp(); break;
        case 14: _t->on_groupBoxWatchdog_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_spinBoxDelayNoHash_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pushButtonPool_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_pushButtonShowHideLog_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonDisplayPoolStats_clicked(); break;
        case 19: _t->onBalance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->onPoolUserInfo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        case 21: _t->on_pushButtonEthminerBrowser_clicked(); break;
        case 22: _t->onHrChartTimer(); break;
        case 23: _t->onTempChartTimer(); break;
        case 24: _t->onRefreshDeviceInfoTimer(); break;
        case 25: _t->onMouseHoverSlice((*reinterpret_cast< QPieSlice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPieSlice* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
