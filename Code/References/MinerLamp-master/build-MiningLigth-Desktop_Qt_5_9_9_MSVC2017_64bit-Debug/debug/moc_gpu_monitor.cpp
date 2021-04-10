/****************************************************************************
** Meta object code from reading C++ file 'gpu_monitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinerLamp-master/gpu_monitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpu_monitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gpu_monitor_t {
    QByteArrayData data[15];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gpu_monitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gpu_monitor_t qt_meta_stringdata_gpu_monitor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "gpu_monitor"
QT_MOC_LITERAL(1, 12, 13), // "gpuInfoSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "gpucount"
QT_MOC_LITERAL(4, 36, 10), // "maxgputemp"
QT_MOC_LITERAL(5, 47, 10), // "mingputemp"
QT_MOC_LITERAL(6, 58, 11), // "maxfanspeed"
QT_MOC_LITERAL(7, 70, 11), // "minfanspeed"
QT_MOC_LITERAL(8, 82, 11), // "maxmemclock"
QT_MOC_LITERAL(9, 94, 11), // "minmemclock"
QT_MOC_LITERAL(10, 106, 11), // "maxgpuclock"
QT_MOC_LITERAL(11, 118, 11), // "mingpuclock"
QT_MOC_LITERAL(12, 130, 12), // "maxpowerdraw"
QT_MOC_LITERAL(13, 143, 12), // "minpowerdraw"
QT_MOC_LITERAL(14, 156, 14) // "totalpowerdraw"

    },
    "gpu_monitor\0gpuInfoSignal\0\0gpucount\0"
    "maxgputemp\0mingputemp\0maxfanspeed\0"
    "minfanspeed\0maxmemclock\0minmemclock\0"
    "maxgpuclock\0mingpuclock\0maxpowerdraw\0"
    "minpowerdraw\0totalpowerdraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gpu_monitor[] = {

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
       1,   12,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,

       0        // eod
};

void gpu_monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gpu_monitor *_t = static_cast<gpu_monitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gpuInfoSignal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< uint(*)>(_a[8])),(*reinterpret_cast< uint(*)>(_a[9])),(*reinterpret_cast< uint(*)>(_a[10])),(*reinterpret_cast< uint(*)>(_a[11])),(*reinterpret_cast< uint(*)>(_a[12]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (gpu_monitor::*_t)(unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gpu_monitor::gpuInfoSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject gpu_monitor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_gpu_monitor.data,
      qt_meta_data_gpu_monitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gpu_monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gpu_monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gpu_monitor.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int gpu_monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void gpu_monitor::gpuInfoSignal(unsigned int _t1, unsigned int _t2, unsigned int _t3, unsigned int _t4, unsigned int _t5, unsigned int _t6, unsigned int _t7, unsigned int _t8, unsigned int _t9, unsigned int _t10, unsigned int _t11, unsigned int _t12)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
