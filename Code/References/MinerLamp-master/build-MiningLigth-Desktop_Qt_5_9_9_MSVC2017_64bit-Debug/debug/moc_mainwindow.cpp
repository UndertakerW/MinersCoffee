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
    QByteArrayData data[72];
    char stringdata0[1452];
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
QT_MOC_LITERAL(16, 316, 34), // "on_checkBoxShowHistoryInfo_cl..."
QT_MOC_LITERAL(17, 351, 34), // "on_pushButtonSearchHistory_cl..."
QT_MOC_LITERAL(18, 386, 47), // "on_dateTimeEditHistoryStartTi..."
QT_MOC_LITERAL(19, 434, 8), // "datetime"
QT_MOC_LITERAL(20, 443, 45), // "on_dateTimeEditHistoryEndTime..."
QT_MOC_LITERAL(21, 489, 39), // "on_spinBoxHistoryDeviceNum_va..."
QT_MOC_LITERAL(22, 529, 48), // "on_comboBoxHistoryDataOption_..."
QT_MOC_LITERAL(23, 578, 5), // "index"
QT_MOC_LITERAL(24, 584, 43), // "on_checkBoxHistoryMiningInfoO..."
QT_MOC_LITERAL(25, 628, 7), // "clicked"
QT_MOC_LITERAL(26, 636, 31), // "on_checkBoxShowSettings_clicked"
QT_MOC_LITERAL(27, 668, 7), // "clickes"
QT_MOC_LITERAL(28, 676, 35), // "on_pushButtonCancelAutoPage_c..."
QT_MOC_LITERAL(29, 712, 35), // "on_pushButtonChangePageSize_c..."
QT_MOC_LITERAL(30, 748, 17), // "refreshDeviceInfo"
QT_MOC_LITERAL(31, 766, 18), // "onGpusInfoRecieved"
QT_MOC_LITERAL(32, 785, 14), // "QList<GPUInfo>"
QT_MOC_LITERAL(33, 800, 8), // "gpusinfo"
QT_MOC_LITERAL(34, 809, 15), // "onNvMonitorInfo"
QT_MOC_LITERAL(35, 825, 8), // "gpucount"
QT_MOC_LITERAL(36, 834, 10), // "maxgputemp"
QT_MOC_LITERAL(37, 845, 10), // "mingputemp"
QT_MOC_LITERAL(38, 856, 11), // "maxfanspeed"
QT_MOC_LITERAL(39, 868, 11), // "minfanspeed"
QT_MOC_LITERAL(40, 880, 11), // "maxmemclock"
QT_MOC_LITERAL(41, 892, 11), // "minmemclock"
QT_MOC_LITERAL(42, 904, 11), // "maxgpuclock"
QT_MOC_LITERAL(43, 916, 11), // "mingpuclock"
QT_MOC_LITERAL(44, 928, 12), // "maxpowerdraw"
QT_MOC_LITERAL(45, 941, 12), // "minpowerdraw"
QT_MOC_LITERAL(46, 954, 14), // "totalpowerdraw"
QT_MOC_LITERAL(47, 969, 16), // "onAMDMonitorInfo"
QT_MOC_LITERAL(48, 986, 23), // "on_pushButtonOC_clicked"
QT_MOC_LITERAL(49, 1010, 6), // "onHelp"
QT_MOC_LITERAL(50, 1017, 27), // "on_groupBoxWatchdog_clicked"
QT_MOC_LITERAL(51, 1045, 34), // "on_spinBoxDelayNoHash_valueCh..."
QT_MOC_LITERAL(52, 1080, 25), // "on_pushButtonPool_clicked"
QT_MOC_LITERAL(53, 1106, 32), // "on_pushButtonShowHideLog_clicked"
QT_MOC_LITERAL(54, 1139, 37), // "on_pushButtonDisplayPoolStats..."
QT_MOC_LITERAL(55, 1177, 9), // "onBalance"
QT_MOC_LITERAL(56, 1187, 7), // "balance"
QT_MOC_LITERAL(57, 1195, 14), // "onPoolUserInfo"
QT_MOC_LITERAL(58, 1210, 11), // "userBalance"
QT_MOC_LITERAL(59, 1222, 26), // "currentCalcultatedHashRate"
QT_MOC_LITERAL(60, 1249, 17), // "averageHashRate1H"
QT_MOC_LITERAL(61, 1267, 17), // "averageHashRate3H"
QT_MOC_LITERAL(62, 1285, 17), // "averageHashRate6H"
QT_MOC_LITERAL(63, 1303, 18), // "averageHashRate12H"
QT_MOC_LITERAL(64, 1322, 18), // "averageHashRate24H"
QT_MOC_LITERAL(65, 1341, 36), // "on_pushButtonEthminerBrowser_..."
QT_MOC_LITERAL(66, 1378, 14), // "onHrChartTimer"
QT_MOC_LITERAL(67, 1393, 16), // "onTempChartTimer"
QT_MOC_LITERAL(68, 1410, 17), // "onMouseHoverSlice"
QT_MOC_LITERAL(69, 1428, 10), // "QPieSlice*"
QT_MOC_LITERAL(70, 1439, 5), // "slice"
QT_MOC_LITERAL(71, 1445, 6) // "status"

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
    "on_checkBoxShowHistoryInfo_clicked\0"
    "on_pushButtonSearchHistory_clicked\0"
    "on_dateTimeEditHistoryStartTime_dateTimeChanged\0"
    "datetime\0on_dateTimeEditHistoryEndTime_dateTimeChanged\0"
    "on_spinBoxHistoryDeviceNum_valueChanged\0"
    "on_comboBoxHistoryDataOption_currentIndexChanged\0"
    "index\0on_checkBoxHistoryMiningInfoOverall_clicked\0"
    "clicked\0on_checkBoxShowSettings_clicked\0"
    "clickes\0on_pushButtonCancelAutoPage_clicked\0"
    "on_pushButtonChangePageSize_clicked\0"
    "refreshDeviceInfo\0onGpusInfoRecieved\0"
    "QList<GPUInfo>\0gpusinfo\0onNvMonitorInfo\0"
    "gpucount\0maxgputemp\0mingputemp\0"
    "maxfanspeed\0minfanspeed\0maxmemclock\0"
    "minmemclock\0maxgpuclock\0mingpuclock\0"
    "maxpowerdraw\0minpowerdraw\0totalpowerdraw\0"
    "onAMDMonitorInfo\0on_pushButtonOC_clicked\0"
    "onHelp\0on_groupBoxWatchdog_clicked\0"
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
    "onMouseHoverSlice\0QPieSlice*\0slice\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  199,    2, 0x08 /* Private */,
       3,    1,  200,    2, 0x08 /* Private */,
       6,    0,  203,    2, 0x08 /* Private */,
       7,    1,  204,    2, 0x08 /* Private */,
       9,    1,  207,    2, 0x08 /* Private */,
      10,    1,  210,    2, 0x08 /* Private */,
      12,    0,  213,    2, 0x08 /* Private */,
      13,    1,  214,    2, 0x08 /* Private */,
      14,    0,  217,    2, 0x08 /* Private */,
      15,    1,  218,    2, 0x08 /* Private */,
      16,    1,  221,    2, 0x08 /* Private */,
      17,    0,  224,    2, 0x08 /* Private */,
      18,    1,  225,    2, 0x08 /* Private */,
      20,    1,  228,    2, 0x08 /* Private */,
      21,    1,  231,    2, 0x08 /* Private */,
      22,    1,  234,    2, 0x08 /* Private */,
      24,    1,  237,    2, 0x08 /* Private */,
      26,    1,  240,    2, 0x08 /* Private */,
      28,    0,  243,    2, 0x08 /* Private */,
      29,    0,  244,    2, 0x08 /* Private */,
      30,    0,  245,    2, 0x08 /* Private */,
      31,    1,  246,    2, 0x08 /* Private */,
      34,   12,  249,    2, 0x08 /* Private */,
      47,   12,  274,    2, 0x08 /* Private */,
      48,    0,  299,    2, 0x08 /* Private */,
      49,    0,  300,    2, 0x08 /* Private */,
      50,    1,  301,    2, 0x08 /* Private */,
      51,    1,  304,    2, 0x08 /* Private */,
      52,    1,  307,    2, 0x08 /* Private */,
      53,    1,  310,    2, 0x08 /* Private */,
      54,    0,  313,    2, 0x08 /* Private */,
      55,    1,  314,    2, 0x08 /* Private */,
      57,    7,  317,    2, 0x08 /* Private */,
      65,    0,  332,    2, 0x08 /* Private */,
      66,    0,  333,    2, 0x08 /* Private */,
      67,    0,  334,    2, 0x08 /* Private */,
      68,    2,  335,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   19,
    QMetaType::Void, QMetaType::QDateTime,   19,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   56,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   58,   59,   60,   61,   62,   63,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 69, QMetaType::Bool,   70,   71,

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
        case 10: _t->on_checkBoxShowHistoryInfo_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_pushButtonSearchHistory_clicked(); break;
        case 12: _t->on_dateTimeEditHistoryStartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 13: _t->on_dateTimeEditHistoryEndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 14: _t->on_spinBoxHistoryDeviceNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_comboBoxHistoryDataOption_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_checkBoxHistoryMiningInfoOverall_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_checkBoxShowSettings_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonCancelAutoPage_clicked(); break;
        case 19: _t->on_pushButtonChangePageSize_clicked(); break;
        case 20: _t->refreshDeviceInfo(); break;
        case 21: _t->onGpusInfoRecieved((*reinterpret_cast< QList<GPUInfo>(*)>(_a[1]))); break;
        case 22: _t->onNvMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 23: _t->onAMDMonitorInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 24: _t->on_pushButtonOC_clicked(); break;
        case 25: _t->onHelp(); break;
        case 26: _t->on_groupBoxWatchdog_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_spinBoxDelayNoHash_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_pushButtonPool_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_pushButtonShowHideLog_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_pushButtonDisplayPoolStats_clicked(); break;
        case 31: _t->onBalance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->onPoolUserInfo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        case 33: _t->on_pushButtonEthminerBrowser_clicked(); break;
        case 34: _t->onHrChartTimer(); break;
        case 35: _t->onTempChartTimer(); break;
        case 36: _t->onMouseHoverSlice((*reinterpret_cast< QPieSlice*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
