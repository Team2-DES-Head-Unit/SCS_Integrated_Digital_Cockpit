/****************************************************************************
** Meta object code from reading C++ file 'Gauge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Gauge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gauge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gauge_t {
    QByteArrayData data[22];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gauge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gauge_t qt_meta_stringdata_Gauge = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Gauge"
QT_MOC_LITERAL(1, 6, 16), // "gaugeSizeChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "startAngleChanged"
QT_MOC_LITERAL(4, 42, 17), // "alignAngleChanged"
QT_MOC_LITERAL(5, 60, 18), // "lowestRangeChanged"
QT_MOC_LITERAL(6, 79, 19), // "highestRangeChanged"
QT_MOC_LITERAL(7, 99, 15), // "arcWidthChanged"
QT_MOC_LITERAL(8, 115, 17), // "outerColorChanged"
QT_MOC_LITERAL(9, 133, 17), // "innerColorChanged"
QT_MOC_LITERAL(10, 151, 16), // "textColorChanged"
QT_MOC_LITERAL(11, 168, 22), // "backgroundColorChanged"
QT_MOC_LITERAL(12, 191, 9), // "gaugeSize"
QT_MOC_LITERAL(13, 201, 10), // "startAngle"
QT_MOC_LITERAL(14, 212, 10), // "alignAngle"
QT_MOC_LITERAL(15, 223, 11), // "lowestRange"
QT_MOC_LITERAL(16, 235, 12), // "highestRange"
QT_MOC_LITERAL(17, 248, 8), // "arcWidth"
QT_MOC_LITERAL(18, 257, 10), // "outerColor"
QT_MOC_LITERAL(19, 268, 10), // "innerColor"
QT_MOC_LITERAL(20, 279, 9), // "textColor"
QT_MOC_LITERAL(21, 289, 15) // "backgroundColor"

    },
    "Gauge\0gaugeSizeChanged\0\0startAngleChanged\0"
    "alignAngleChanged\0lowestRangeChanged\0"
    "highestRangeChanged\0arcWidthChanged\0"
    "outerColorChanged\0innerColorChanged\0"
    "textColorChanged\0backgroundColorChanged\0"
    "gaugeSize\0startAngle\0alignAngle\0"
    "lowestRange\0highestRange\0arcWidth\0"
    "outerColor\0innerColor\0textColor\0"
    "backgroundColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gauge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      10,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
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

 // properties: name, type, flags
      12, QMetaType::QReal, 0x00495103,
      13, QMetaType::QReal, 0x00495103,
      14, QMetaType::QReal, 0x00495103,
      15, QMetaType::QReal, 0x00495103,
      16, QMetaType::QReal, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      18, QMetaType::QColor, 0x00495103,
      19, QMetaType::QColor, 0x00495103,
      20, QMetaType::QColor, 0x00495103,
      21, QMetaType::QColor, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,

       0        // eod
};

void Gauge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gauge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gaugeSizeChanged(); break;
        case 1: _t->startAngleChanged(); break;
        case 2: _t->alignAngleChanged(); break;
        case 3: _t->lowestRangeChanged(); break;
        case 4: _t->highestRangeChanged(); break;
        case 5: _t->arcWidthChanged(); break;
        case 6: _t->outerColorChanged(); break;
        case 7: _t->innerColorChanged(); break;
        case 8: _t->textColorChanged(); break;
        case 9: _t->backgroundColorChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::gaugeSizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::startAngleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::alignAngleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::lowestRangeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::highestRangeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::arcWidthChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::outerColorChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::innerColorChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::textColorChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gauge::backgroundColorChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Gauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getGaugeSize(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getStartAngle(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getAlignAngle(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->getLowestRange(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->getHighestRange(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getArcWidth(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getOuterColor(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getInnerColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Gauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGaugeSize(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setStartAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setAlignAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setLowestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setHighestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 5: _t->setArcWidth(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setOuterColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setInnerColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Gauge::staticMetaObject = { {
    &QQuickPaintedItem::staticMetaObject,
    qt_meta_stringdata_Gauge.data,
    qt_meta_data_Gauge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gauge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gauge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gauge.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Gauge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Gauge::gaugeSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Gauge::startAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Gauge::alignAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Gauge::lowestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Gauge::highestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Gauge::arcWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Gauge::outerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Gauge::innerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Gauge::textColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Gauge::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
struct qt_meta_stringdata_SpeedGauge_t {
    QByteArrayData data[6];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpeedGauge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpeedGauge_t qt_meta_stringdata_SpeedGauge = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SpeedGauge"
QT_MOC_LITERAL(1, 11, 12), // "speedChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "rpmChanged"
QT_MOC_LITERAL(4, 36, 5), // "speed"
QT_MOC_LITERAL(5, 42, 3) // "rpm"

    },
    "SpeedGauge\0speedChanged\0\0rpmChanged\0"
    "speed\0rpm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpeedGauge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   26, // properties
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

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00495103,
       5, QMetaType::QReal, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void SpeedGauge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpeedGauge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->rpmChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpeedGauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpeedGauge::speedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpeedGauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpeedGauge::rpmChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SpeedGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getSpeed(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getRpm(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SpeedGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SpeedGauge::staticMetaObject = { {
    &Gauge::staticMetaObject,
    qt_meta_stringdata_SpeedGauge.data,
    qt_meta_data_SpeedGauge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpeedGauge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpeedGauge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpeedGauge.stringdata0))
        return static_cast<void*>(this);
    return Gauge::qt_metacast(_clname);
}

int SpeedGauge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Gauge::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SpeedGauge::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SpeedGauge::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_RpmGauge_t {
    QByteArrayData data[4];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RpmGauge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RpmGauge_t qt_meta_stringdata_RpmGauge = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RpmGauge"
QT_MOC_LITERAL(1, 9, 10), // "rpmChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3) // "rpm"

    },
    "RpmGauge\0rpmChanged\0\0rpm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RpmGauge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QReal, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void RpmGauge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RpmGauge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rpmChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RpmGauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RpmGauge::rpmChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RpmGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getRpm(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RpmGauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRpm(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RpmGauge::staticMetaObject = { {
    &Gauge::staticMetaObject,
    qt_meta_stringdata_RpmGauge.data,
    qt_meta_data_RpmGauge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RpmGauge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RpmGauge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RpmGauge.stringdata0))
        return static_cast<void*>(this);
    return Gauge::qt_metacast(_clname);
}

int RpmGauge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Gauge::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RpmGauge::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
