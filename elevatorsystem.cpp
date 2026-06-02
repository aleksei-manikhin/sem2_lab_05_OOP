#include "elevatorsystem.h"

ElevatorSystem::ElevatorSystem(QObject *parent)
    : QObject(parent),
      controller(new ElevatorController(1, 5, this))
{
    connectController();
}

int ElevatorSystem::currentFloor() const
{
    return controller->currentFloor();
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
    controller->addCabinRequest(floor);
}

void ElevatorSystem::requestFloorCall(int floor, Direction direction)
{
    controller->addFloorCall(floor, direction);
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
    connect(controller, &ElevatorController::cabinButtonLightChanged,
            this, &ElevatorSystem::cabinButtonLightChanged);
    connect(controller, &ElevatorController::floorCallLightChanged,
            this, &ElevatorSystem::floorCallLightChanged);
    connect(controller, &ElevatorController::currentFloorChanged,
            this, &ElevatorSystem::currentFloorChanged);
    connect(controller, &ElevatorController::cabinStateChanged,
            this, &ElevatorSystem::cabinStateChanged);
    connect(controller, &ElevatorController::doorStateChanged,
            this, &ElevatorSystem::doorStateChanged);
    connect(controller, &ElevatorController::controllerStateChanged,
            this, &ElevatorSystem::controllerStateChanged);
    connect(controller, &ElevatorController::directionChanged,
            this, &ElevatorSystem::directionChanged);
    connect(controller, &ElevatorController::targetFloorChanged,
            this, &ElevatorSystem::targetFloorChanged);
    connect(controller, &ElevatorController::logMessage,
            this, &ElevatorSystem::logMessage);
}
