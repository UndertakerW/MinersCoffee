/****************************************************************************
** Meta object code from reading C++ file 'minerprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinersCoffee/minerprocess.h"
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
    QByteArrayData data[13];
    char stringdata0[155];
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
QT_MOC_LITERAL(4, 37, 9), // "emitError"
QT_MOC_LITERAL(5, 47, 14), // "emitMiningInfo"
QT_MOC_LITERAL(6, 62, 10), // "MiningInfo"
QT_MOC_LITERAL(7, 73, 8), // "mingInfo"
QT_MOC_LITERAL(8, 82, 12), // "emitPoolInfo"
QT_MOC_LITERAL(9, 95, 15), // "QList<PoolInfo>"
QT_MOC_LITERAL(10, 111, 9), // "poolInfos"
QT_MOC_LITERAL(11, 121, 17), // "refreshMiningInfo"
QT_MOC_LITERAL(12, 139, 15) // "refreshPoolInfo"

    },
    "MinerProcess\0emitStarted\0\0emitStoped\0"
    "emitError\0emitMiningInfo\0MiningInfo\0"
    "mingInfo\0emitPoolInfo\0QList<PoolInfo>\0"
    "poolInfos\0refreshMiningInfo\0refreshPoolInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MinerProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       8,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   58,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
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
        case 2: _t->emitError(); break;
        case 3: _t->emitMiningInfo((*reinterpret_cast< MiningInfo(*)>(_a[1]))); break;
        case 4: _t->emitPoolInfo((*reinterpret_cast< QList<PoolInfo>(*)>(_a[1]))); break;
        case 5: _t->refreshMiningInfo(); break;
        case 6: _t->refreshPoolInfo(); break;
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
            typedef void (MinerProcess::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitError)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)(MiningInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitMiningInfo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MinerProcess::*_t)(QList<PoolInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinerProcess::emitPoolInfo)) {
                *result = 4;
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
void MinerProcess::emitError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MinerProcess::emitMiningInfo(MiningInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MinerProcess::emitPoolInfo(QList<PoolInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
