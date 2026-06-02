/****************************************************************************
** Meta object code from reading C++ file 'elevatorcabin.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../elevatorcabin.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevatorcabin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13ElevatorCabinE_t {};
} // unnamed namespace

template <> constexpr inline auto ElevatorCabin::qt_create_metaobjectdata<qt_meta_tag_ZN13ElevatorCabinE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ElevatorCabin",
        "floorChanged",
        "",
        "floor",
        "floorReached",
        "stateChanged",
        "CabinState",
        "state",
        "directionChanged",
        "Direction",
        "direction",
        "logMessage",
        "message",
        "move",
        "stop",
        "onMoveTick"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'floorChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'floorReached'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(CabinState)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'directionChanged'
        QtMocHelpers::SignalData<void(Direction)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'logMessage'
        QtMocHelpers::SignalData<void(const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
        // Slot 'move'
        QtMocHelpers::SlotData<void(Direction)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onMoveTick'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ElevatorCabin, qt_meta_tag_ZN13ElevatorCabinE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ElevatorCabin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ElevatorCabinE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ElevatorCabinE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ElevatorCabinE_t>.metaTypes,
    nullptr
} };

void ElevatorCabin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ElevatorCabin *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->floorChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->floorReached((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->stateChanged((*reinterpret_cast<std::add_pointer_t<CabinState>>(_a[1]))); break;
        case 3: _t->directionChanged((*reinterpret_cast<std::add_pointer_t<Direction>>(_a[1]))); break;
        case 4: _t->logMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->move((*reinterpret_cast<std::add_pointer_t<Direction>>(_a[1]))); break;
        case 6: _t->stop(); break;
        case 7: _t->onMoveTick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ElevatorCabin::*)(int )>(_a, &ElevatorCabin::floorChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorCabin::*)(int )>(_a, &ElevatorCabin::floorReached, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorCabin::*)(CabinState )>(_a, &ElevatorCabin::stateChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorCabin::*)(Direction )>(_a, &ElevatorCabin::directionChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorCabin::*)(const QString & )>(_a, &ElevatorCabin::logMessage, 4))
            return;
    }
}

const QMetaObject *ElevatorCabin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElevatorCabin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ElevatorCabinE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ElevatorCabin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ElevatorCabin::floorChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ElevatorCabin::floorReached(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ElevatorCabin::stateChanged(CabinState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ElevatorCabin::directionChanged(Direction _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ElevatorCabin::logMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
