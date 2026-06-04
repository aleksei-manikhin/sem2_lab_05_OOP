#include "elevatorsystem.h"
#include "floorcatalog.h"

ElevatorSystem::ElevatorSystem(QObject *parent)
    : QObject(parent),
      controller(new ElevatorController(this))
{
    connectController();
}

int ElevatorSystem::currentFloor() const
{
    return FloorCatalog::numberFromPosition(controller->currentFloor());
}

Direction ElevatorSystem::direction() const
{
    return controller->direction();
}

ControllerState ElevatorSystem::state() const
{
    return controller->state();
}

void ElevatorSystem::requestCabinFloor(int floor)
{
    controller->addCabinRequest(FloorCatalog::positionFromNumber(floor));
}

void ElevatorSystem::requestFloorCall(int floor, Direction direction)
{
    controller->addFloorCall(FloorCatalog::positionFromNumber(floor), direction);
}

void ElevatorSystem::requestDoorsOpen()
{
    controller->openDoorsRequested();
}

void ElevatorSystem::requestDoorsClose()
{
    controller->closeDoorsRequested();
}

void ElevatorSystem::connectController()
{
    connectButtonSignals();
    connectStateSignals();
}

void ElevatorSystem::connectButtonSignals()
{
    connect(controller, &ElevatorController::cabinButtonLightChanged,
            this, [this](int position, bool enabled) {
        emit cabinButtonLightChanged(FloorCatalog::numberFromPosition(position), enabled);
    });
    connect(controller, &ElevatorController::floorCallLightChanged,
            this, [this](int position, Direction direction, bool enabled) {
        emit floorCallLightChanged(FloorCatalog::numberFromPosition(position), direction, enabled);
    });
    connect(controller, &ElevatorController::currentFloorChanged,
            this, [this](int position) {
        emit currentFloorChanged(FloorCatalog::numberFromPosition(position));
    });
}

void ElevatorSystem::connectStateSignals()
{
    connect(controller, &ElevatorController::cabinStateChanged,
            this, &ElevatorSystem::cabinStateChanged);
    connect(controller, &ElevatorController::doorStateChanged,
            this, &ElevatorSystem::doorStateChanged);
    connect(controller, &ElevatorController::controllerStateChanged,
            this, &ElevatorSystem::controllerStateChanged);
    connect(controller, &ElevatorController::directionChanged,
            this, &ElevatorSystem::directionChanged);
    connect(controller, &ElevatorController::targetFloorChanged,
            this, [this](int position) {
        emit targetFloorChanged(FloorCatalog::numberFromPosition(position));
    });
    connect(controller, &ElevatorController::logMessage,
            this, &ElevatorSystem::logMessage);
}
