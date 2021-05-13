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
    QByteArrayData data[57];
    char stringdata0[1274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "iconActivated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(4, 60, 6), // "reason"
QT_MOC_LITERAL(5, 67, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 89, 19), // "onReadyToStartMiner"
QT_MOC_LITERAL(7, 109, 34), // "on_pushButtonSearchHistory_cl..."
QT_MOC_LITERAL(8, 144, 47), // "on_dateTimeEditHistoryStartTi..."
QT_MOC_LITERAL(9, 192, 8), // "datetime"
QT_MOC_LITERAL(10, 201, 45), // "on_dateTimeEditHistoryEndTime..."
QT_MOC_LITERAL(11, 247, 39), // "on_spinBoxHistoryDeviceNum_va..."
QT_MOC_LITERAL(12, 287, 4), // "arg1"
QT_MOC_LITERAL(13, 292, 35), // "on_pushButtonCancelAutoPage_c..."
QT_MOC_LITERAL(14, 328, 35), // "on_pushButtonChangePageSize_c..."
QT_MOC_LITERAL(15, 364, 41), // "on_pushButtonMonitorPage_Over..."
QT_MOC_LITERAL(16, 406, 39), // "on_pushButtonMonitorPage_Mini..."
QT_MOC_LITERAL(17, 446, 39), // "on_pushButtonMonitorPage_Syst..."
QT_MOC_LITERAL(18, 486, 44), // "on_pushButtonMonitorPage_Devi..."
QT_MOC_LITERAL(19, 531, 32), // "on_pushButtonMonitorPage_clicked"
QT_MOC_LITERAL(20, 564, 27), // "on_pushButtonOCPage_clicked"
QT_MOC_LITERAL(21, 592, 27), // "on_pushButtonSystem_clicked"
QT_MOC_LITERAL(22, 620, 29), // "on_pushButtonHelpPage_clicked"
QT_MOC_LITERAL(23, 650, 17), // "refreshDeviceInfo"
QT_MOC_LITERAL(24, 668, 18), // "onGPUInfosReceived"
QT_MOC_LITERAL(25, 687, 14), // "QList<GPUInfo>"
QT_MOC_LITERAL(26, 702, 8), // "gpusinfo"
QT_MOC_LITERAL(27, 711, 15), // "onNvMonitorInfo"
QT_MOC_LITERAL(28, 727, 8), // "gpucount"
QT_MOC_LITERAL(29, 736, 10), // "maxgputemp"
QT_MOC_LITERAL(30, 747, 10), // "mingputemp"
QT_MOC_LITERAL(31, 758, 11), // "maxfanspeed"
QT_MOC_LITERAL(32, 770, 11), // "minfanspeed"
QT_MOC_LITERAL(33, 782, 11), // "maxmemclock"
QT_MOC_LITERAL(34, 794, 11), // "minmemclock"
QT_MOC_LITERAL(35, 806, 11), // "maxgpuclock"
QT_MOC_LITERAL(36, 818, 11), // "mingpuclock"
QT_MOC_LITERAL(37, 830, 12), // "maxpowerdraw"
QT_MOC_LITERAL(38, 843, 12), // "minpowerdraw"
QT_MOC_LITERAL(39, 856, 14), // "totalpowerdraw"
QT_MOC_LITERAL(40, 871, 14), // "onHrChartTimer"
QT_MOC_LITERAL(41, 886, 17), // "onMouseHoverSlice"
QT_MOC_LITERAL(42, 904, 10), // "QPieSlice*"
QT_MOC_LITERAL(43, 915, 5), // "slice"
QT_MOC_LITERAL(44, 921, 6), // "status"
QT_MOC_LITERAL(45, 928, 44), // "on_horizontalSliderPowerPerce..."
QT_MOC_LITERAL(46, 973, 5), // "value"
QT_MOC_LITERAL(47, 979, 41), // "on_horizontalSliderGpuOffset_..."
QT_MOC_LITERAL(48, 1021, 41), // "on_horizontalSliderMemOffset_..."
QT_MOC_LITERAL(49, 1063, 40), // "on_horizontalSliderFanSpeed_v..."
QT_MOC_LITERAL(50, 1104, 27), // "on_comboBoxDevice_activated"
QT_MOC_LITERAL(51, 1132, 5), // "index"
QT_MOC_LITERAL(52, 1138, 32), // "on_pushButtonOCPageApply_clicked"
QT_MOC_LITERAL(53, 1171, 31), // "on_checkBoxAutoSpeedFan_clicked"
QT_MOC_LITERAL(54, 1203, 7), // "checked"
QT_MOC_LITERAL(55, 1211, 34), // "on_spinBoxTemperature_valueCh..."
QT_MOC_LITERAL(56, 1246, 27) // "on_pushButtonAutoOC_clicked"

    },
    "MainWindow\0iconActivated\0\0"
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
    "on_pushButtonSystem_clicked\0"
    "on_pushButtonHelpPage_clicked\0"
    "refreshDeviceInfo\0onGPUInfosReceived\0"
    "QList<GPUInfo>\0gpusinfo\0onNvMonitorInfo\0"
    "gpucount\0maxgputemp\0mingputemp\0"
    "maxfanspeed\0minfanspeed\0maxmemclock\0"
    "minmemclock\0maxgpuclock\0mingpuclock\0"
    "maxpowerdraw\0minpowerdraw\0totalpowerdraw\0"
    "onHrChartTimer\0onMouseHoverSlice\0"
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
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x08 /* Private */,
       5,    0,  172,    2, 0x08 /* Private */,
       6,    0,  173,    2, 0x08 /* Private */,
       7,    0,  174,    2, 0x08 /* Private */,
       8,    1,  175,    2, 0x08 /* Private */,
      10,    1,  178,    2, 0x08 /* Private */,
      11,    1,  181,    2, 0x08 /* Private */,
      13,    0,  184,    2, 0x08 /* Private */,
      14,    0,  185,    2, 0x08 /* Private */,
      15,    0,  186,    2, 0x08 /* Private */,
      16,    0,  187,    2, 0x08 /* Private */,
      17,    0,  188,    2, 0x08 /* Private */,
      18,    0,  189,    2, 0x08 /* Private */,
      19,    0,  190,    2, 0x08 /* Private */,
      20,    0,  191,    2, 0x08 /* Private */,
      21,    0,  192,    2, 0x08 /* Private */,
      22,    0,  193,    2, 0x08 /* Private */,
      23,    0,  194,    2, 0x08 /* Private */,
      24,    1,  195,    2, 0x08 /* Private */,
      27,   12,  198,    2, 0x08 /* Private */,
      40,    0,  223,    2, 0x08 /* Private */,
      41,    2,  224,    2, 0x08 /* Private */,
      45,    1,  229,    2, 0x08 /* Private */,
      47,    1,  232,    2, 0x08 /* Private */,
      48,    1,  235,    2, 0x08 /* Private */,
      49,    1,  238,    2, 0x08 /* Private */,
      50,    1,  241,    2, 0x08 /* Private */,
      52,    0,  244,    2, 0x08 /* Private */,
      53,    1,  245,    2, 0x08 /* Private */,
      55,    1,  248,    2, 0x08 /* Private */,
      56,    0,  251,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    9,
    QMetaType::Void, QMetaType::QDateTime,    9,
    QMetaType::Void, QMetaType::Int,   12,
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
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42, QMetaType::Bool,   43,   44,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   54,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->onReadyToStartMiner(); break;
        case 3: _t->on_pushButtonSearchHistory_clicked(); break;
        case 4: _t->on_dateTimeEditHistoryStartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 5: _t->on_dateTimeEditHistoryEndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 6: _t->on_spinBoxHistoryDeviceNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonCancelAutoPage_clicked(); break;
        case 8: _t->on_pushButtonChangePageSize_clicked(); break;
        case 9: _t->on_pushButtonMonitorPage_Overview_clicked(); break;
        case 10: _t->on_pushButtonMonitorPage_Mining_clicked(); break;
        case 11: _t->on_pushButtonMonitorPage_System_clicked(); break;
        case 12: _t->on_pushButtonMonitorPage_DevicesInfo_clicked(); break;
        case 13: _t->on_pushButtonMonitorPage_clicked(); break;
        case 14: _t->on_pushButtonOCPage_clicked(); break;
        case 15: _t->on_pushButtonSystem_clicked(); break;
        case 16: _t->on_pushButtonHelpPage_clicked(); break;
        case 17: _t->refreshDeviceInfo(); break;
        case 18: _t->onGPUInfosReceived((*reinterpret_cast< QList<GPUInfo>(*)>(_a[1]))); break;
        case 19: _t->onNvMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 20: _t->onHrChartTimer(); break;
        case 21: _t->onMouseHoverSlice((*reinterpret_cast< QPieSlice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->on_horizontalSliderPowerPercent_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_horizontalSliderGpuOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_horizontalSliderMemOffset_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_horizontalSliderFanSpeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_comboBoxDevice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_pushButtonOCPageApply_clicked(); break;
        case 28: _t->on_checkBoxAutoSpeedFan_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_spinBoxTemperature_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_pushButtonAutoOC_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
