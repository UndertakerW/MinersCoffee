/****************************************************************************
** Meta object code from reading C++ file 'minerprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinerLamp-master/minerprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minerprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_zeroMHsWaitter_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zeroMHsWaitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zeroMHsWaitter_t qt_meta_stringdata_zeroMHsWaitter = {
    {
QT_MOC_LITERAL(0, 0, 14) // "zeroMHsWaitter"

    },
    "zeroMHsWaitter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zeroMHsWaitter[] = {

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

void zeroMHsWaitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject zeroMHsWaitter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_zeroMHsWaitter.data,
      qt_meta_data_zeroMHsWaitter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *zeroMHsWaitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zeroMHsWaitter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zeroMHsWaitter.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int zeroMHsWaitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_restarter_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_restarter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_restarter_t qt_meta_stringdata_restarter = {
    {
QT_MOC_LITERAL(0, 0, 9), // "restarter"
QT_MOC_LITERAL(1, 10, 13), // "restartsignal"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "restarter\0restartsignal\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_restarter[] = {

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

void restarter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        restarter *_t = static_cast<restarter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->restartsignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (restarter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&restarter::restartsignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject restarter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_restarter.data,
      qt_meta_data_restarter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *restarter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *restarter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_restarter.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int restarter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void restarter::restartsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_anyMHsWaitter_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_anyMHsWaitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_anyMHsWaitter_t qt_meta_stringdata_anyMHsWaitter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "anyMHsWaitter"
QT_MOC_LITERAL(1, 14, 10), // "notHashing"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "anyMHsWaitter\0notHashing\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_anyMHsWaitter[] = {

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

void anyMHsWaitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        anyMHsWaitter *_t = static_cast<anyMHsWaitter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notHashing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (anyMHsWaitter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&anyMHsWaitter::notHashing)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject anyMHsWaitter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_anyMHsWaitter.data,
      qt_meta_data_anyMHsWaitter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *anyMHsWaitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *anyMHsWaitter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_anyMHsWaitter.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int anyMHsWaitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void anyMHsWaitter::notHashing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_PoolInfoThread_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PoolInfoThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PoolInfoThread_t qt_meta_stringdata_PoolInfoThread = {
    {
QT_MOC_LITERAL(0, 0, 14) // "PoolInfoThread"

    },
    "PoolInfoThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PoolInfoThread[] = {

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

void PoolInfoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PoolInfoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PoolInfoThread.data,
      qt_meta_data_PoolInfoThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PoolInfoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PoolInfoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PoolInfoThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PoolInfoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MinerProcess_t {
    QByteArrayData data[21];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MinerProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MinerProcess_t qt_meta_stringdata_MinerProcess = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MinerProcess"
QT_MOC_LITERAL(1, 13, 11), // "emitStarted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "emitStoped"
QT_MOC_LITERAL(4, 37, 12), // "emitHashRate"
QT_MOC_LITERAL(5, 50, 8), // "QString&"
QT_MOC_LITERAL(6, 59, 8), // "hashrate"
QT_MOC_LITERAL(7, 68, 9), // "emitError"
QT_MOC_LITERAL(8, 78, 14), // "emitMiningInfo"
QT_MOC_LITERAL(9, 93, 10), // "MiningInfo"
QT_MOC_LITERAL(10, 104, 8), // "mingInfo"
QT_MOC_LITERAL(11, 113, 12), // "emitPoolInfo"
QT_MOC_LITERAL(12, 126, 15), // "QList<PoolInfo>"
QT_MOC_LITERAL(13, 142, 9), // "poolInfos"
QT_MOC_LITERAL(14, 152, 16), // "onReadyToMonitor"
QT_MOC_LITERAL(15, 169, 11), // "onNoHashing"
QT_MOC_LITERAL(16, 181, 8), // "onDonate"
QT_MOC_LITERAL(17, 190, 14), // "onBackToNormal"
QT_MOC_LITERAL(18, 205, 16), // "onReadyToRestart"
QT_MOC_LITERAL(19, 222, 17), // "refreshMiningInfo"
QT_MOC_LITERAL(20, 240, 15) // "refreshPoolInfo"

    },
    "MinerProcess\0emitStarted\0\0emitStoped\0"
    "emitHashRate\0QString&\0hashrate\0emitError\0"
    "emitMiningInfo\0MiningInfo\0mingInfo\0"
    "emitPoolInfo\0QList<PoolInfo>\0poolInfos\0"
    "onReadyToMonitor\0onNoHashing\0onDonate\0"
    "onBackToNormal\0onReadyToRestart\0"
    "refreshMiningInfo\0refreshPoolInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MinerProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    1,   85,    2, 0x06 /* Public */,
      11,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   91,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,
      17,    0,   94,    2, 0x0a /* Public */,
      18,    0,   95,    2, 0x0a /* Public */,
      19,    0,   96,    2, 0x0a /* Public */,
      20,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MinerProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MinerProcess *_t = static_cast<MinerProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitStarted(); break;
        case 1: _t->emitStoped(); break;
        case 2: _t->emitHashRate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->emitError(); break;
        case 4: _t->emitMiningInfo((*reinterpret_cast< MiningInfo(*)>(_a[1]))); break;
        case 5: _t->emitPoolInfo((*reinterpret_cast< QList<PoolInfo>(*)>(_a[1]))); break;
        case 6: _t->onReadyToMonitor(); break;
        case 7: _t->onNoHashing(); break;
        case 8: _t->onDonate(); break;
        case 9: _t->onBackToNormal(); break;
        case 10: _t->onReadyToRestart(); break;
        case 11: _t->refreshMiningInfo(); break;
        case 12: _t->refreshPoolInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MinerProcess::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitStoped)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitHashRate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitError)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)(MiningInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitMiningInfo)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)(QList<PoolInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitPoolInfo)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MinerProcess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MinerProcess.data,
      qt_meta_data_MinerProcess,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MinerProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MinerProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MinerProcess.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MinerProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MinerProcess::emitStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MinerProcess::emitStoped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MinerProcess::emitHashRate(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MinerProcess::emitError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MinerProcess::emitMiningInfo(MiningInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MinerProcess::emitPoolInfo(QList<PoolInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_donateThrd_t {
    QByteArrayData data[4];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_donateThrd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_donateThrd_t qt_meta_stringdata_donateThrd = {
    {
QT_MOC_LITERAL(0, 0, 10), // "donateThrd"
QT_MOC_LITERAL(1, 11, 6), // "donate"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12) // "backToNormal"

    },
    "donateThrd\0donate\0\0backToNormal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_donateThrd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void donateThrd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        donateThrd *_t = static_cast<donateThrd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->donate(); break;
        case 1: _t->backToNormal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (donateThrd::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&donateThrd::donate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (donateThrd::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&donateThrd::backToNormal)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject donateThrd::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_donateThrd.data,
      qt_meta_data_donateThrd,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *donateThrd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *donateThrd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_donateThrd.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int donateThrd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void donateThrd::donate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void donateThrd::backToNormal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
