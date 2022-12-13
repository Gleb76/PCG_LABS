/****************************************************************************
** Meta object code from reading C++ file 'colorsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../colorsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_colorSystem_t {
    QByteArrayData data[11];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_colorSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_colorSystem_t qt_meta_stringdata_colorSystem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "colorSystem"
QT_MOC_LITERAL(1, 12, 18), // "systemValueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "std::vector<qreal>"
QT_MOC_LITERAL(4, 51, 10), // "new_values"
QT_MOC_LITERAL(5, 62, 8), // "systemId"
QT_MOC_LITERAL(6, 71, 21), // "systemSliderActivated"
QT_MOC_LITERAL(7, 93, 18), // "OnChangeFieldValue"
QT_MOC_LITERAL(8, 112, 8), // "newValue"
QT_MOC_LITERAL(9, 121, 7), // "fieldId"
QT_MOC_LITERAL(10, 129, 15) // "SliderActivated"

    },
    "colorSystem\0systemValueChanged\0\0"
    "std::vector<qreal>\0new_values\0systemId\0"
    "systemSliderActivated\0OnChangeFieldValue\0"
    "newValue\0fieldId\0SliderActivated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_colorSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   42,    2, 0x0a /* Public */,
      10,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void colorSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<colorSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->systemValueChanged((*reinterpret_cast< std::vector<qreal>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->systemSliderActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnChangeFieldValue((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->SliderActivated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (colorSystem::*)(std::vector<qreal> , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&colorSystem::systemValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (colorSystem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&colorSystem::systemSliderActivated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject colorSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_colorSystem.data,
    qt_meta_data_colorSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *colorSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *colorSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_colorSystem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int colorSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void colorSystem::systemValueChanged(std::vector<qreal> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void colorSystem::systemSliderActivated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
