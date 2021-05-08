/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinersCoffee/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    QByteArrayData data[73];
    char stringdata0[1700];
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
QT_MOC_LITERAL(16, 316, 34), // "on_pushButtonSearchHistory_cl..."
QT_MOC_LITERAL(17, 351, 47), // "on_dateTimeEditHistoryStartTi..."
QT_MOC_LITERAL(18, 399, 8), // "datetime"
QT_MOC_LITERAL(19, 408, 45), // "on_dateTimeEditHistoryEndTime..."
QT_MOC_LITERAL(20, 454, 39), // "on_spinBoxHistoryDeviceNum_va..."
QT_MOC_LITERAL(21, 494, 43), // "on_checkBoxHistoryMiningInfoO..."
QT_MOC_LITERAL(22, 538, 7), // "clicked"
QT_MOC_LITERAL(23, 546, 31), // "on_checkBoxShowSettings_clicked"
QT_MOC_LITERAL(24, 578, 35), // "on_pushButtonCancelAutoPage_c..."
QT_MOC_LITERAL(25, 614, 35), // "on_pushButtonChangePageSize_c..."
QT_MOC_LITERAL(26, 650, 41), // "on_pushButtonMonitorPage_Over..."
QT_MOC_LITERAL(27, 692, 39), // "on_pushButtonMonitorPage_Mini..."
QT_MOC_LITERAL(28, 732, 39), // "on_pushButtonMonitorPage_Syst..."
QT_MOC_LITERAL(29, 772, 44), // "on_pushButtonMonitorPage_Devi..."
QT_MOC_LITERAL(30, 817, 32), // "on_pushButtonMonitorPage_clicked"
QT_MOC_LITERAL(31, 850, 27), // "on_pushButtonOCPage_clicked"
QT_MOC_LITERAL(32, 878, 29), // "on_pushButtonHelpPage_clicked"
QT_MOC_LITERAL(33, 908, 27), // "on_checkBoxHelpPage_clicked"
QT_MOC_LITERAL(34, 936, 17), // "refreshDeviceInfo"
QT_MOC_LITERAL(35, 954, 18), // "onGPUInfosReceived"
QT_MOC_LITERAL(36, 973, 14), // "QList<GPUInfo>"
QT_MOC_LITERAL(37, 988, 8), // "gpusinfo"
QT_MOC_LITERAL(38, 997, 15), // "onNvMonitorInfo"
QT_MOC_LITERAL(39, 1013, 8), // "gpucount"
QT_MOC_LITERAL(40, 1022, 10), // "maxgputemp"
QT_MOC_LITERAL(41, 1033, 10), // "mingputemp"
QT_MOC_LITERAL(42, 1044, 11), // "maxfanspeed"
QT_MOC_LITERAL(43, 1056, 11), // "minfanspeed"
QT_MOC_LITERAL(44, 1068, 11), // "maxmemclock"
QT_MOC_LITERAL(45, 1080, 11), // "minmemclock"
QT_MOC_LITERAL(46, 1092, 11), // "maxgpuclock"
QT_MOC_LITERAL(47, 1104, 11), // "mingpuclock"
QT_MOC_LITERAL(48, 1116, 12), // "maxpowerdraw"
QT_MOC_LITERAL(49, 1129, 12), // "minpowerdraw"
QT_MOC_LITERAL(50, 1142, 14), // "totalpowerdraw"
QT_MOC_LITERAL(51, 1157, 16), // "onAMDMonitorInfo"
QT_MOC_LITERAL(52, 1174, 23), // "on_pushButtonOC_clicked"
QT_MOC_LITERAL(53, 1198, 6), // "onHelp"
QT_MOC_LITERAL(54, 1205, 27), // "on_groupBoxWatchdog_clicked"
QT_MOC_LITERAL(55, 1233, 34), // "on_spinBoxDelayNoHash_valueCh..."
QT_MOC_LITERAL(56, 1268, 36), // "on_pushButtonEthminerBrowser_..."
QT_MOC_LITERAL(57, 1305, 14), // "onHrChartTimer"
QT_MOC_LITERAL(58, 1320, 17), // "onMouseHoverSlice"
QT_MOC_LITERAL(59, 1338, 10), // "QPieSlice*"
QT_MOC_LITERAL(60, 1349, 5), // "slice"
QT_MOC_LITERAL(61, 1355, 6), // "status"
QT_MOC_LITERAL(62, 1362, 44), // "on_horizontalSliderPowerPerce..."
QT_MOC_LITERAL(63, 1407, 5), // "value"
QT_MOC_LITERAL(64, 1413, 41), // "on_horizontalSliderGpuOffset_..."
QT_MOC_LITERAL(65, 1455, 41), // "on_horizontalSliderMemOffset_..."
QT_MOC_LITERAL(66, 1497, 40), // "on_horizontalSliderFanSpeed_v..."
QT_MOC_LITERAL(67, 1538, 27), // "on_comboBoxDevice_activated"
QT_MOC_LITERAL(68, 1566, 5), // "index"
QT_MOC_LITERAL(69, 1572, 32), // "on_pushButtonOCPageApply_clicked"
QT_MOC_LITERAL(70, 1605, 31), // "on_checkBoxAutoSpeedFan_clicked"
QT_MOC_LITERAL(71, 1637, 34), // "on_spinBoxTemperature_valueCh..."
QT_MOC_LITERAL(72, 1672, 27) // "on_pushButtonAutoOC_clicked"

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
    "on_pushButtonSearchHistory_clicked\0"
    "on_dateTimeEditHistoryStartTime_dateTimeChanged\0"
    "datetime\0on_dateTimeEditHistoryEndTime_dateTimeChanged\0"
    "on_spinBoxHistoryDeviceNum_valueChanged\0"
    "on_checkBoxHistoryMiningInfoOverall_clicked\0"
    "clicked\0on_checkBoxShowSettings_clicked\0"
    "on_pushButtonCancelAutoPage_clicked\0"
    "on_pushButtonChangePageSize_clicked\0"
    "on_pushButtonMonitorPage_Overview_clicked\0"
    "on_pushButtonMonitorPage_Mining_clicked\0"
    "on_pushButtonMonitorPage_System_clicked\0"
    "on_pushButtonMonitorPage_DevicesInfo_clicked\0"
    "on_pushButtonMonitorPage_clicked\0"
    "on_pushButtonOCPage_clicked\0"
    "on_pushButtonHelpPage_clicked\0"
    "on_checkBoxHelpPage_clicked\0"
    "refreshDeviceInfo\0onGPUInfosReceived\0"
    "QList<GPUInfo>\0gpusinfo\0onNvMonitorInfo\0"
    "gpucount\0maxgputemp\0mingputemp\0"
    "maxfanspeed\0minfanspeed\0maxmemclock\0"
    "minmemclock\0maxgpuclock\0mingpuclock\0"
    "maxpowerdraw\0minpowerdraw\0totalpowerdraw\0"
    "onAMDMonitorInfo\0on_pushButtonOC_clicked\0"
    "onHelp\0on_groupBoxWatchdog_clicked\0"
    "on_spinBoxDelayNoHash_valueChanged\0"
    "on_pushButtonEthminerBrowser_clicked\0"
    "onHrChartTimer\0onMouseHoverSlice\0"
    "QPieSlice*\0slice\0status\0"
    "on_horizontalSliderPowerPercent_valueChanged\0"
    "value\0on_horizontalSliderGpuOffset_valueChanged\0"
    "on_horizontalSliderMemOffset_valueChanged\0"
    "on_horizontalSliderFanSpeed_valueChanged\0"
    "on_comboBoxDevice_activated\0index\0"
    "on_pushButtonOCPageApply_clicked\0"
    "on_checkBoxAutoSpeedFan_clicked\0"
    "on_spinBoxTemperature_valueChanged\0"
    "on_pushButtonAutoOC_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x08 /* Private */,
       3,    1,  245,    2, 0x08 /* Private */,
       6,    0,  248,    2, 0x08 /* Private */,
       7,    1,  249,    2, 0x08 /* Private */,
       9,    1,  252,    2, 0x08 /* Private */,
      10,    1,  255,    2, 0x08 /* Private */,
      12,    0,  258,    2, 0x08 /* Private */,
      13,    1,  259,    2, 0x08 /* Private */,
      14,    0,  262,    2, 0x08 /* Private */,
      15,    1,  263,    2, 0x08 /* Private */,
      16,    0,  266,    2, 0x08 /* Private */,
      17,    1,  267,    2, 0x08 /* Private */,
      19,    1,  270,    2, 0x08 /* Private */,
      20,    1,  273,    2, 0x08 /* Private */,
      21,    1,  276,    2, 0x08 /* Private */,
      23,    1,  279,    2, 0x08 /* Private */,
      24,    0,  282,    2, 0x08 /* Private */,
      25,    0,  283,    2, 0x08 /* Private */,
      26,    0,  284,    2, 0x08 /* Private */,
      27,    0,  285,    2, 0x08 /* Private */,
      28,    0,  286,    2, 0x08 /* Private */,
      29,    0,  287,    2, 0x08 /* Private */,
      30,    0,  288,    2, 0x08 /* Private */,
      31,    0,  289,    2, 0x08 /* Private */,
      32,    0,  290,    2, 0x08 /* Private */,
      33,    1,  291,    2, 0x08 /* Private */,
      34,    0,  294,    2, 0x08 /* Private */,
      35,    1,  295,    2, 0x08 /* Private */,
      38,   12,  298,    2, 0x08 /* Private */,
      51,   12,  323,    2, 0x08 /* Private */,
      52,    0,  348,    2, 0x08 /* Private */,
      53,    0,  349,    2, 0x08 /* Private */,
      54,    1,  350,    2, 0x08 /* Private */,
      55,    1,  353,    2, 0x08 /* Private */,
      56,    0,  356,    2, 0x08 /* Private */,
      57,    0,  357,    2, 0x08 /* Private */,
      58,    2,  358,    2, 0x08 /* Private */,
      62,    1,  363,    2, 0x08 /* Private */,
      64,    1,  366,    2, 0x08 /* Private */,
      65,    1,  369,    2, 0x08 /* Private */,
      66,    1,  372,    2, 0x08 /* Private */,
      67,    1,  375,    2, 0x08 /* Private */,
      69,    0,  378,    2, 0x08 /* Private */,
      70,    1,  379,    2, 0x08 /* Private */,
      71,    1,  382,    2, 0x08 /* Private */,
      72,    0,  385,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   18,
    QMetaType::Void, QMetaType::QDateTime,   18,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 59, QMetaType::Bool,   60,   61,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Void,

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
        case 10: _t->on_pushButtonSearchHistory_clicked(); break;
        case 11: _t->on_dateTimeEditHistoryStartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 12: _t->on_dateTimeEditHistoryEndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 13: _t->on_spinBoxHistoryDeviceNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_checkBoxHistoryMiningInfoOverall_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_checkBoxShowSettings_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_pushButtonCancelAutoPage_clicked(); break;
        case 17: _t->on_pushButtonChangePageSize_clicked(); break;
        case 18: _t->on_pushButtonMonitorPage_Overview_clicked(); break;
        case 19: _t->on_pushButtonMonitorPage_Mining_clicked(); break;
        case 20: _t->on_pushButtonMonitorPage_System_clicked(); break;
        case 21: _t->on_pushButtonMonitorPage_DevicesInfo_clicked(); break;
        case 22: _t->on_pushButtonMonitorPage_clicked(); break;
        case 23: _t->on_pushButtonOCPage_clicked(); break;
        case 24: _t->on_pushButtonHelpPage_clicked(); break;
        case 25: _t->on_checkBoxHelpPage_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->refreshDeviceInfo(); break;
        case 27: _t->onGPUInfosReceived((*reinterpret_cast< QList<GPUInfo>(*)>(_a[1]))); break;
        case 28: _t->onNvMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 29: _t->onAMDMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 30: _t->on_pushButtonOC_clicked(); break;
        case 31: _t->onHelp(); break;
        case 32: _t->on_groupBoxWatchdog_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_spinBoxDelayNoHash_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_pushButtonEthminerBrowser_clicked(); break;
        case 35: _t->onHrChartTimer(); break;
        case 36: _t->onMouseHoverSlice((*reinterpret_cast< QPieSlice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 37: _t->on_horizontalSliderPowerPercent_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_horizontalSliderGpuOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_horizontalSliderMemOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_horizontalSliderFanSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_comboBoxDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_pushButtonOCPageApply_clicked(); break;
        case 43: _t->on_checkBoxAutoSpeedFan_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_spinBoxTemperature_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_pushButtonAutoOC_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 36:
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
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
