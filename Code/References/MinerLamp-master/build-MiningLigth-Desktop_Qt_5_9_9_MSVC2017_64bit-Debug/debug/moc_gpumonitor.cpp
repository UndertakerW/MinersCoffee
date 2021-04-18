/****************************************************************************
** Meta object code from reading C++ file 'gpumonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinerLamp-master/gpumonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpumonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GPUMonitor_t {
    QByteArrayData data[25];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GPUMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GPUMonitor_t qt_meta_stringdata_GPUMonitor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GPUMonitor"
QT_MOC_LITERAL(1, 11, 21), // "gpusInfoSignalRefresh"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "std::vector<GPUInfo>"
QT_MOC_LITERAL(4, 55, 8), // "gpusinfo"
QT_MOC_LITERAL(5, 64, 13), // "gpuInfoSignal"
QT_MOC_LITERAL(6, 78, 8), // "gpucount"
QT_MOC_LITERAL(7, 87, 10), // "maxgputemp"
QT_MOC_LITERAL(8, 98, 10), // "mingputemp"
QT_MOC_LITERAL(9, 109, 11), // "maxfanspeed"
QT_MOC_LITERAL(10, 121, 11), // "minfanspeed"
QT_MOC_LITERAL(11, 133, 11), // "maxmemclock"
QT_MOC_LITERAL(12, 145, 11), // "minmemclock"
QT_MOC_LITERAL(13, 157, 11), // "maxgpuclock"
QT_MOC_LITERAL(14, 169, 11), // "mingpuclock"
QT_MOC_LITERAL(15, 181, 12), // "maxpowerdraw"
QT_MOC_LITERAL(16, 194, 12), // "minpowerdraw"
QT_MOC_LITERAL(17, 207, 14), // "totalpowerdraw"
QT_MOC_LITERAL(18, 222, 14), // "gpuInfoSignal1"
QT_MOC_LITERAL(19, 237, 5), // "uint*"
QT_MOC_LITERAL(20, 243, 10), // "Allgputemp"
QT_MOC_LITERAL(21, 254, 11), // "Allfanspeed"
QT_MOC_LITERAL(22, 266, 11), // "Allmemclock"
QT_MOC_LITERAL(23, 278, 11), // "Allgpuclock"
QT_MOC_LITERAL(24, 290, 12) // "Allpowerdraw"

    },
    "GPUMonitor\0gpusInfoSignalRefresh\0\0"
    "std::vector<GPUInfo>\0gpusinfo\0"
    "gpuInfoSignal\0gpucount\0maxgputemp\0"
    "mingputemp\0maxfanspeed\0minfanspeed\0"
    "maxmemclock\0minmemclock\0maxgpuclock\0"
    "mingpuclock\0maxpowerdraw\0minpowerdraw\0"
    "totalpowerdraw\0gpuInfoSignal1\0uint*\0"
    "Allgputemp\0Allfanspeed\0Allmemclock\0"
    "Allgpuclock\0Allpowerdraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GPUMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,   12,   32,    2, 0x06 /* Public */,
      18,    7,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 19, 0x80000000 | 19, 0x80000000 | 19, 0x80000000 | 19, 0x80000000 | 19, QMetaType::UInt,    6,   20,   21,   22,   23,   24,   17,

       0        // eod
};

void GPUMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GPUMonitor *_t = static_cast<GPUMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gpusInfoSignalRefresh((*reinterpret_cast< std::vector<GPUInfo>(*)>(_a[1]))); break;
        case 1: _t->gpuInfoSignal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        case 2: _t->gpuInfoSignal1((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint*(*)>(_a[2])),(*reinterpret_cast< uint*(*)>(_a[3])),(*reinterpret_cast< uint*(*)>(_a[4])),(*reinterpret_cast< uint*(*)>(_a[5])),(*reinterpret_cast< uint*(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GPUMonitor::*_t)(std::vector<GPUInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GPUMonitor::gpusInfoSignalRefresh)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GPUMonitor::*_t)(unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GPUMonitor::gpuInfoSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GPUMonitor::*_t)(unsigned int , unsigned int * , unsigned int * , unsigned int * , unsigned int * , unsigned int * , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GPUMonitor::gpuInfoSignal1)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GPUMonitor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GPUMonitor.data,
      qt_meta_data_GPUMonitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GPUMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GPUMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GPUMonitor.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GPUMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GPUMonitor::gpusInfoSignalRefresh(std::vector<GPUInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GPUMonitor::gpuInfoSignal(unsigned int _t1, unsigned int _t2, unsigned int _t3, unsigned int _t4, unsigned int _t5, unsigned int _t6, unsigned int _t7, unsigned int _t8, unsigned int _t9, unsigned int _t10, unsigned int _t11, unsigned int _t12)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GPUMonitor::gpuInfoSignal1(unsigned int _t1, unsigned int * _t2, unsigned int * _t3, unsigned int * _t4, unsigned int * _t5, unsigned int * _t6, unsigned int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
