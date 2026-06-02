/****************************************************************************
** Meta object code from reading C++ file 'elevatorsystem.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../elevatorsystem.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevatorsystem.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14ElevatorSystemE_t {};
} // unnamed namespace

template <> constexpr inline auto ElevatorSystem::qt_create_metaobjectdata<qt_meta_tag_ZN14ElevatorSystemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ElevatorSystem",
        "cabinButtonLightChanged",
        "",
        "floor",
        "enabled",
        "floorCallLightChanged",
        "Direction",
        "direction",
        "currentFloorChanged",
        "cabinStateChanged",
        "CabinState",
        "state",
        "doorStateChanged",
        "DoorState",
        "controllerStateChanged",
        "ControllerState",
        "directionChanged",
        "targetFloorChanged",
        "logMessage",
        "message",
        "requestCabinFloor",
        "requestFloorCall",
        "requestDoorsOpen",
        "requestDoorsClose"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cabinButtonLightChanged'
        QtMocHelpers::SignalData<void(int, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Bool, 4 },
        }}),
        // Signal 'floorCallLightChanged'
        QtMocHelpers::SignalData<void(int, Direction, bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 6, 7 }, { QMetaType::Bool, 4 },
        }}),
        // Signal 'currentFloorChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'cabinStateChanged'
        QtMocHelpers::SignalData<void(CabinState)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'doorStateChanged'
        QtMocHelpers::SignalData<void(DoorState)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 11 },
        }}),
        // Signal 'controllerStateChanged'
        QtMocHelpers::SignalData<void(ControllerState)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 11 },
        }}),
        // Signal 'directionChanged'
        QtMocHelpers::SignalData<void(Direction)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'targetFloorChanged'
        QtMocHelpers::SignalData<void(int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'logMessage'
        QtMocHelpers::SignalData<void(const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'requestCabinFloor'
        QtMocHelpers::SlotData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'requestFloorCall'
        QtMocHelpers::SlotData<void(int, Direction)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 6, 7 },
        }}),
        // Slot 'requestDoorsOpen'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestDoorsClose'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ElevatorSystem, qt_meta_tag_ZN14ElevatorSystemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ElevatorSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ElevatorSystemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ElevatorSystemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14ElevatorSystemE_t>.metaTypes,
    nullptr
} };

void ElevatorSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ElevatorSystem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cabinButtonLightChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->floorCallLightChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Direction>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3]))); break;
        case 2: _t->currentFloorChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->cabinStateChanged((*reinterpret_cast<std::add_pointer_t<CabinState>>(_a[1]))); break;
        case 4: _t->doorStateChanged((*reinterpret_cast<std::add_pointer_t<DoorState>>(_a[1]))); break;
        case 5: _t->controllerStateChanged((*reinterpret_cast<std::add_pointer_t<ControllerState>>(_a[1]))); break;
        case 6: _t->directionChanged((*reinterpret_cast<std::add_pointer_t<Direction>>(_a[1]))); break;
        case 7: _t->targetFloorChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->logMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->requestCabinFloor((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->requestFloorCall((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Direction>>(_a[2]))); break;
        case 11: _t->requestDoorsOpen(); break;
        case 12: _t->requestDoorsClose(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(int , bool )>(_a, &ElevatorSystem::cabinButtonLightChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(int , Direction , bool )>(_a, &ElevatorSystem::floorCallLightChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(int )>(_a, &ElevatorSystem::currentFloorChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(CabinState )>(_a, &ElevatorSystem::cabinStateChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(DoorState )>(_a, &ElevatorSystem::doorStateChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(ControllerState )>(_a, &ElevatorSystem::controllerStateChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(Direction )>(_a, &ElevatorSystem::directionChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(int )>(_a, &ElevatorSystem::targetFloorChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElevatorSystem::*)(const QString & )>(_a, &ElevatorSystem::logMessage, 8))
            return;
    }
}

const QMetaObject *ElevatorSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElevatorSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ElevatorSystemE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ElevatorSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ElevatorSystem::cabinButtonLightChanged(int _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ElevatorSystem::floorCallLightChanged(int _t1, Direction _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void ElevatorSystem::currentFloorChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ElevatorSystem::cabinStateChanged(CabinState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ElevatorSystem::doorStateChanged(DoorState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void ElevatorSystem::controllerStateChanged(ControllerState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void ElevatorSystem::directionChanged(Direction _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void ElevatorSystem::targetFloorChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void ElevatorSystem::logMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
