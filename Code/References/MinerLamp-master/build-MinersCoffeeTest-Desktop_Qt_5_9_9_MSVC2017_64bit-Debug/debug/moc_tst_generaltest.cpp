/****************************************************************************
** Meta object code from reading C++ file 'tst_generaltest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MinerLamp-master/tst_generaltest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_generaltest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralTest_t {
    QByteArrayData data[18];
    char stringdata0[439];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralTest_t qt_meta_stringdata_GeneralTest = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GeneralTest"
QT_MOC_LITERAL(1, 12, 12), // "initTestCase"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "cleanupTestCase"
QT_MOC_LITERAL(4, 42, 23), // "test_ParseJsonForMining"
QT_MOC_LITERAL(5, 66, 28), // "test_ParseJsonForMining_data"
QT_MOC_LITERAL(6, 95, 21), // "test_ParseJsonForPool"
QT_MOC_LITERAL(7, 117, 26), // "test_ParseJsonForPool_data"
QT_MOC_LITERAL(8, 144, 26), // "test_ui_MiningArgsLineEdit"
QT_MOC_LITERAL(9, 171, 31), // "test_ui_MiningArgsLineEdit_data"
QT_MOC_LITERAL(10, 203, 26), // "test_ui_MiningArgsComboBox"
QT_MOC_LITERAL(11, 230, 31), // "test_ui_MiningArgsComboBox_data"
QT_MOC_LITERAL(12, 262, 23), // "test_Database_getAdvice"
QT_MOC_LITERAL(13, 286, 28), // "test_Database_getAdvice_data"
QT_MOC_LITERAL(14, 315, 27), // "test_Database_InsertDataNew"
QT_MOC_LITERAL(15, 343, 32), // "test_Database_InsertDataNew_data"
QT_MOC_LITERAL(16, 376, 28), // "test_Database_Get_HistoryNew"
QT_MOC_LITERAL(17, 405, 33) // "test_Database_Get_HistoryNew_..."

    },
    "GeneralTest\0initTestCase\0\0cleanupTestCase\0"
    "test_ParseJsonForMining\0"
    "test_ParseJsonForMining_data\0"
    "test_ParseJsonForPool\0test_ParseJsonForPool_data\0"
    "test_ui_MiningArgsLineEdit\0"
    "test_ui_MiningArgsLineEdit_data\0"
    "test_ui_MiningArgsComboBox\0"
    "test_ui_MiningArgsComboBox_data\0"
    "test_Database_getAdvice\0"
    "test_Database_getAdvice_data\0"
    "test_Database_InsertDataNew\0"
    "test_Database_InsertDataNew_data\0"
    "test_Database_Get_HistoryNew\0"
    "test_Database_Get_HistoryNew_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GeneralTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeneralTest *_t = static_cast<GeneralTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->test_ParseJsonForMining(); break;
        case 3: _t->test_ParseJsonForMining_data(); break;
        case 4: _t->test_ParseJsonForPool(); break;
        case 5: _t->test_ParseJsonForPool_data(); break;
        case 6: _t->test_ui_MiningArgsLineEdit(); break;
        case 7: _t->test_ui_MiningArgsLineEdit_data(); break;
        case 8: _t->test_ui_MiningArgsComboBox(); break;
        case 9: _t->test_ui_MiningArgsComboBox_data(); break;
        case 10: _t->test_Database_getAdvice(); break;
        case 11: _t->test_Database_getAdvice_data(); break;
        case 12: _t->test_Database_InsertDataNew(); break;
        case 13: _t->test_Database_InsertDataNew_data(); break;
        case 14: _t->test_Database_Get_HistoryNew(); break;
        case 15: _t->test_Database_Get_HistoryNew_data(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GeneralTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeneralTest.data,
      qt_meta_data_GeneralTest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GeneralTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralTest.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GeneralTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
