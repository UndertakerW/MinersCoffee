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
    QByteArrayData data[60];
    char stringdata0[1297];
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
QT_MOC_LITERAL(7, 97, 19), // "onReadyToStartMiner"
QT_MOC_LITERAL(8, 117, 34), // "on_pushButtonSearchHistory_cl..."
QT_MOC_LITERAL(9, 152, 47), // "on_dateTimeEditHistoryStartTi..."
QT_MOC_LITERAL(10, 200, 8), // "datetime"
QT_MOC_LITERAL(11, 209, 45), // "on_dateTimeEditHistoryEndTime..."
QT_MOC_LITERAL(12, 255, 39), // "on_spinBoxHistoryDeviceNum_va..."
QT_MOC_LITERAL(13, 295, 4), // "arg1"
QT_MOC_LITERAL(14, 300, 35), // "on_pushButtonCancelAutoPage_c..."
QT_MOC_LITERAL(15, 336, 35), // "on_pushButtonChangePageSize_c..."
QT_MOC_LITERAL(16, 372, 41), // "on_pushButtonMonitorPage_Over..."
QT_MOC_LITERAL(17, 414, 39), // "on_pushButtonMonitorPage_Mini..."
QT_MOC_LITERAL(18, 454, 39), // "on_pushButtonMonitorPage_Syst..."
QT_MOC_LITERAL(19, 494, 44), // "on_pushButtonMonitorPage_Devi..."
QT_MOC_LITERAL(20, 539, 32), // "on_pushButtonMonitorPage_clicked"
QT_MOC_LITERAL(21, 572, 27), // "on_pushButtonOCPage_clicked"
QT_MOC_LITERAL(22, 600, 29), // "on_pushButtonHelpPage_clicked"
QT_MOC_LITERAL(23, 630, 27), // "on_checkBoxHelpPage_clicked"
QT_MOC_LITERAL(24, 658, 7), // "clicked"
QT_MOC_LITERAL(25, 666, 17), // "refreshDeviceInfo"
QT_MOC_LITERAL(26, 684, 18), // "onGPUInfosReceived"
QT_MOC_LITERAL(27, 703, 14), // "QList<GPUInfo>"
QT_MOC_LITERAL(28, 718, 8), // "gpusinfo"
QT_MOC_LITERAL(29, 727, 15), // "onNvMonitorInfo"
QT_MOC_LITERAL(30, 743, 8), // "gpucount"
QT_MOC_LITERAL(31, 752, 10), // "maxgputemp"
QT_MOC_LITERAL(32, 763, 10), // "mingputemp"
QT_MOC_LITERAL(33, 774, 11), // "maxfanspeed"
QT_MOC_LITERAL(34, 786, 11), // "minfanspeed"
QT_MOC_LITERAL(35, 798, 11), // "maxmemclock"
QT_MOC_LITERAL(36, 810, 11), // "minmemclock"
QT_MOC_LITERAL(37, 822, 11), // "maxgpuclock"
QT_MOC_LITERAL(38, 834, 11), // "mingpuclock"
QT_MOC_LITERAL(39, 846, 12), // "maxpowerdraw"
QT_MOC_LITERAL(40, 859, 12), // "minpowerdraw"
QT_MOC_LITERAL(41, 872, 14), // "totalpowerdraw"
QT_MOC_LITERAL(42, 887, 6), // "onHelp"
QT_MOC_LITERAL(43, 894, 14), // "onHrChartTimer"
QT_MOC_LITERAL(44, 909, 17), // "onMouseHoverSlice"
QT_MOC_LITERAL(45, 927, 10), // "QPieSlice*"
QT_MOC_LITERAL(46, 938, 5), // "slice"
QT_MOC_LITERAL(47, 944, 6), // "status"
QT_MOC_LITERAL(48, 951, 44), // "on_horizontalSliderPowerPerce..."
QT_MOC_LITERAL(49, 996, 5), // "value"
QT_MOC_LITERAL(50, 1002, 41), // "on_horizontalSliderGpuOffset_..."
QT_MOC_LITERAL(51, 1044, 41), // "on_horizontalSliderMemOffset_..."
QT_MOC_LITERAL(52, 1086, 40), // "on_horizontalSliderFanSpeed_v..."
QT_MOC_LITERAL(53, 1127, 27), // "on_comboBoxDevice_activated"
QT_MOC_LITERAL(54, 1155, 5), // "index"
QT_MOC_LITERAL(55, 1161, 32), // "on_pushButtonOCPageApply_clicked"
QT_MOC_LITERAL(56, 1194, 31), // "on_checkBoxAutoSpeedFan_clicked"
QT_MOC_LITERAL(57, 1226, 7), // "checked"
QT_MOC_LITERAL(58, 1234, 34), // "on_spinBoxTemperature_valueCh..."
QT_MOC_LITERAL(59, 1269, 27) // "on_pushButtonAutoOC_clicked"

    },
    "MainWindow\0setIcon\0\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0on_pushButton_clicked\0"
    "onReadyToStartMiner\0"
    "on_pushButtonSearchHistory_clicked\0"
    "on_dateTimeEditHistoryStartTime_dateTimeChanged\0"
    "datetime\0on_dateTimeEditHistoryEndTime_dateTimeChanged\0"
    "on_spinBoxHistoryDeviceNum_valueChanged\0"
    "arg1\0on_pushButtonCancelAutoPage_clicked\0"
    "on_pushButtonChangePageSize_clicked\0"
    "on_pushButtonMonitorPage_Overview_clicked\0"
    "on_pushButtonMonitorPage_Mining_clicked\0"
    "on_pushButtonMonitorPage_System_clicked\0"
    "on_pushButtonMonitorPage_DevicesInfo_clicked\0"
    "on_pushButtonMonitorPage_clicked\0"
    "on_pushButtonOCPage_clicked\0"
    "on_pushButtonHelpPage_clicked\0"
    "on_checkBoxHelpPage_clicked\0clicked\0"
    "refreshDeviceInfo\0onGPUInfosReceived\0"
    "QList<GPUInfo>\0gpusinfo\0onNvMonitorInfo\0"
    "gpucount\0maxgputemp\0mingputemp\0"
    "maxfanspeed\0minfanspeed\0maxmemclock\0"
    "minmemclock\0maxgpuclock\0mingpuclock\0"
    "maxpowerdraw\0minpowerdraw\0totalpowerdraw\0"
    "onHelp\0onHrChartTimer\0onMouseHoverSlice\0"
    "QPieSlice*\0slice\0status\0"
    "on_horizontalSliderPowerPercent_valueChanged\0"
    "value\0on_horizontalSliderGpuOffset_valueChanged\0"
    "on_horizontalSliderMemOffset_valueChanged\0"
    "on_horizontalSliderFanSpeed_valueChanged\0"
    "on_comboBoxDevice_activated\0index\0"
    "on_pushButtonOCPageApply_clicked\0"
    "on_checkBoxAutoSpeedFan_clicked\0checked\0"
    "on_spinBoxTemperature_valueChanged\0"
    "on_pushButtonAutoOC_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x08 /* Private */,
       3,    1,  180,    2, 0x08 /* Private */,
       6,    0,  183,    2, 0x08 /* Private */,
       7,    0,  184,    2, 0x08 /* Private */,
       8,    0,  185,    2, 0x08 /* Private */,
       9,    1,  186,    2, 0x08 /* Private */,
      11,    1,  189,    2, 0x08 /* Private */,
      12,    1,  192,    2, 0x08 /* Private */,
      14,    0,  195,    2, 0x08 /* Private */,
      15,    0,  196,    2, 0x08 /* Private */,
      16,    0,  197,    2, 0x08 /* Private */,
      17,    0,  198,    2, 0x08 /* Private */,
      18,    0,  199,    2, 0x08 /* Private */,
      19,    0,  200,    2, 0x08 /* Private */,
      20,    0,  201,    2, 0x08 /* Private */,
      21,    0,  202,    2, 0x08 /* Private */,
      22,    0,  203,    2, 0x08 /* Private */,
      23,    1,  204,    2, 0x08 /* Private */,
      25,    0,  207,    2, 0x08 /* Private */,
      26,    1,  208,    2, 0x08 /* Private */,
      29,   12,  211,    2, 0x08 /* Private */,
      42,    0,  236,    2, 0x08 /* Private */,
      43,    0,  237,    2, 0x08 /* Private */,
      44,    2,  238,    2, 0x08 /* Private */,
      48,    1,  243,    2, 0x08 /* Private */,
      50,    1,  246,    2, 0x08 /* Private */,
      51,    1,  249,    2, 0x08 /* Private */,
      52,    1,  252,    2, 0x08 /* Private */,
      53,    1,  255,    2, 0x08 /* Private */,
      55,    0,  258,    2, 0x08 /* Private */,
      56,    1,  259,    2, 0x08 /* Private */,
      58,    1,  262,    2, 0x08 /* Private */,
      59,    0,  265,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   10,
    QMetaType::Void, QMetaType::QDateTime,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45, QMetaType::Bool,   46,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Int,   49,
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
        case 3: _t->onReadyToStartMiner(); break;
        case 4: _t->on_pushButtonSearchHistory_clicked(); break;
        case 5: _t->on_dateTimeEditHistoryStartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 6: _t->on_dateTimeEditHistoryEndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 7: _t->on_spinBoxHistoryDeviceNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonCancelAutoPage_clicked(); break;
        case 9: _t->on_pushButtonChangePageSize_clicked(); break;
        case 10: _t->on_pushButtonMonitorPage_Overview_clicked(); break;
        case 11: _t->on_pushButtonMonitorPage_Mining_clicked(); break;
        case 12: _t->on_pushButtonMonitorPage_System_clicked(); break;
        case 13: _t->on_pushButtonMonitorPage_DevicesInfo_clicked(); break;
        case 14: _t->on_pushButtonMonitorPage_clicked(); break;
        case 15: _t->on_pushButtonOCPage_clicked(); break;
        case 16: _t->on_pushButtonHelpPage_clicked(); break;
        case 17: _t->on_checkBoxHelpPage_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->refreshDeviceInfo(); break;
        case 19: _t->onGPUInfosReceived((*reinterpret_cast< QList<GPUInfo>(*)>(_a[1]))); break;
        case 20: _t->onNvMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 21: _t->onHelp(); break;
        case 22: _t->onHrChartTimer(); break;
        case 23: _t->onMouseHoverSlice((*reinterpret_cast< QPieSlice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->on_horizontalSliderPowerPercent_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_horizontalSliderGpuOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_horizontalSliderMemOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_horizontalSliderFanSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_comboBoxDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_pushButtonOCPageApply_clicked(); break;
        case 30: _t->on_checkBoxAutoSpeedFan_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_spinBoxTemperature_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_pushButtonAutoOC_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
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
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
