/****************************************************************************
** Meta object code from reading C++ file 'nanopoolapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinersCoffee/nanopoolapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nanopoolapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_workerObject_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_workerObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_workerObject_t qt_meta_stringdata_workerObject = {
    {
QT_MOC_LITERAL(0, 0, 12) // "workerObject"

    },
    "workerObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_workerObject[] = {

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

void workerObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject workerObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_workerObject.data,
      qt_meta_data_workerObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *workerObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *workerObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_workerObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int workerObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_userAccount_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userAccount_t qt_meta_stringdata_userAccount = {
    {
QT_MOC_LITERAL(0, 0, 11) // "userAccount"

    },
    "userAccount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userAccount[] = {

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

void userAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject userAccount::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_userAccount.data,
      qt_meta_data_userAccount,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *userAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userAccount.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int userAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_nanopoolAPI_t {
    QByteArrayData data[14];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nanopoolAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nanopoolAPI_t qt_meta_stringdata_nanopoolAPI = {
    {
QT_MOC_LITERAL(0, 0, 11), // "nanopoolAPI"
QT_MOC_LITERAL(1, 12, 11), // "emitBalance"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "balance"
QT_MOC_LITERAL(4, 33, 12), // "emitUSerInfo"
QT_MOC_LITERAL(5, 46, 19), // "currentCalculatedHR"
QT_MOC_LITERAL(6, 66, 8), // "avrgHrH1"
QT_MOC_LITERAL(7, 75, 8), // "avrgHrH3"
QT_MOC_LITERAL(8, 84, 8), // "avrgHrH6"
QT_MOC_LITERAL(9, 93, 9), // "avrgHrH12"
QT_MOC_LITERAL(10, 103, 9), // "avrgHrH24"
QT_MOC_LITERAL(11, 113, 13), // "replyFinished"
QT_MOC_LITERAL(12, 127, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 142, 5) // "reply"

    },
    "nanopoolAPI\0emitBalance\0\0balance\0"
    "emitUSerInfo\0currentCalculatedHR\0"
    "avrgHrH1\0avrgHrH3\0avrgHrH6\0avrgHrH12\0"
    "avrgHrH24\0replyFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nanopoolAPI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    7,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    5,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void nanopoolAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nanopoolAPI *_t = static_cast<nanopoolAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitBalance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->emitUSerInfo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        case 2: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (nanopoolAPI::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nanopoolAPI::emitBalance)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (nanopoolAPI::*_t)(double , double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nanopoolAPI::emitUSerInfo)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject nanopoolAPI::staticMetaObject = {
    { &userAccount::staticMetaObject, qt_meta_stringdata_nanopoolAPI.data,
      qt_meta_data_nanopoolAPI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *nanopoolAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nanopoolAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nanopoolAPI.stringdata0))
        return static_cast<void*>(this);
    return userAccount::qt_metacast(_clname);
}

int nanopoolAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = userAccount::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void nanopoolAPI::emitBalance(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nanopoolAPI::emitUSerInfo(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6, double _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
