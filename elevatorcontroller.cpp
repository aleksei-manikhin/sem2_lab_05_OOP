#include "elevatorcontroller.h"
#include "floorcatalog.h"

#include <QDebug>

ElevatorController::ElevatorController(QObject *parent)
    : QObject(parent),
      cabin(new ElevatorCabin(this)),
      doors(new ElevatorDoors(this)),
      targetFloor(FloorCatalog::FirstPosition)
{
    connectParts();
}

int ElevatorController::currentFloor() const
{
    return cabin->currentFloor();
}

Direction ElevatorController::direction() const
{
    return currentDirection;
}

ControllerState ElevatorController::state() const
{
    return controllerState;
}

void ElevatorController::setShaftView(ShaftView* view)
{
    cabin->setShaftView(view);
    doors->setShaftView(view);
}

void ElevatorController::addCabinRequest(int floor)
{
    addRequest(ElevatorRequest(floor, RequestType::Cabin, Direction::Idle));
}

void ElevatorController::addFloorCall(int floor, Direction direction)
{
    addRequest(ElevatorRequest(floor, RequestType::FloorCall, direction));
}

void ElevatorController::openDoorsRequested()
{
    if (cabin->isMoving()) {
        emit logMessage("Cabin is moving, so doors cannot be opened");
        return;
    }

    emit logMessage("Open doors button accepted");
    doors->open();
}

void ElevatorController::closeDoorsRequested()
{
    if (cabin->isMoving()) {
        emit logMessage("Cabin is moving, so doors cannot be closed");
        return;
    }

    if (doors->isClosed()) {
        emit logMessage("Doors are already closed");
        return;
    }

    doors->close();
    emit logMessage("Close doors button accepted");
}

void ElevatorController::cancelCabinRequests()
{
    const std::vector<ElevatorRequest> cancelled = scheduler.takeCabinRequests();
    clearServedButtons(cancelled);

    if (cancelled.empty()) {
        emit logMessage("No cabin requests to cancel");
    } else {
        emit logMessage("Cabin requests cancelled");
    }

    if (cabin->isMoving()) {
        cancellationStopPending = true;
        targetFloor = nearestStopFloor();
        emit targetFloorChanged(targetFloor);
        emit logMessage(QString("Elevator will stop at nearest floor %1")
                        .arg(FloorCatalog::numberFromPosition(targetFloor)));
        return;
    }

    stopForCancellation();
}

void ElevatorController::onCabinReachedFloor(int floor)
{
    if (cancellationStopPending) {
        stopForCancellation();
        return;
    }

    if (!scheduler.shouldStopAt(floor, currentDirection)) {
        return;
    }

    stopAtCurrentFloor();
}

void ElevatorController::onDoorsClosed()
{
    continueWork();
}

void ElevatorController::writeDebugLog(const QString &message)
{
    qDebug() << message;
}

void ElevatorController::connectParts()
{
    connect(cabin, &ElevatorCabin::floorReached, this, &ElevatorController::onCabinReachedFloor);
    connect(cabin, &ElevatorCabin::floorChanged, this, &ElevatorController::currentFloorChanged);
    connect(cabin, &ElevatorCabin::stateChanged, this, &ElevatorController::cabinStateChanged);
    connect(doors, &ElevatorDoors::closed, this, &ElevatorController::onDoorsClosed);
    connect(doors, &ElevatorDoors::stateChanged, this, &ElevatorController::doorStateChanged);
    connect(cabin, &ElevatorCabin::logMessage, this, &ElevatorController::logMessage);
    connect(doors, &ElevatorDoors::logMessage, this, &ElevatorController::logMessage);
    connect(this, &ElevatorController::logMessage, this, &ElevatorController::writeDebugLog);
}

void ElevatorController::addRequest(const ElevatorRequest &request)
{
    const bool added = scheduler.addRequest(request);
    if (!added) {
        return;
    }

    emit logMessage(QString("Request accepted for floor %1")
                    .arg(FloorCatalog::numberFromPosition(request.getFloor())));

    if (request.isCabinRequest()) {
        emit cabinButtonLightChanged(request.getFloor(), true);
    } else {
        emit floorCallLightChanged(request.getFloor(), request.getDirection(), true);
    }

    continueWork();
}

void ElevatorController::continueWork()
{
    if (cabin->isMoving() || !doors->isClosed()) {
        return;
    }

    if (serveCurrentFloorIfNeeded()) {
        return;
    }

    startMovingToNextTarget();
}

bool ElevatorController::serveCurrentFloorIfNeeded()
{
    if (!scheduler.shouldStopAt(currentFloor(), currentDirection)) {
        return false;
    }

    stopAtCurrentFloor();
    return true;
}

void ElevatorController::startMovingToNextTarget()
{
    if (!scheduler.hasRequests()) {
        targetFloor = currentFloor();
        emit targetFloorChanged(targetFloor);
        setDirection(Direction::Idle);
        setState(ControllerState::Idle);
        return;
    }

    setState(ControllerState::UpdatingTarget);
    targetFloor = scheduler.nextTarget(currentFloor(), currentDirection);
    emit targetFloorChanged(targetFloor);
    setDirection(scheduler.nextDirection(currentFloor(), currentDirection));
    emit logMessage(QString("New target floor is %1")
                    .arg(FloorCatalog::numberFromPosition(targetFloor)));

    setState(ControllerState::Moving);
    cabin->move(currentDirection);
}

void ElevatorController::stopAtCurrentFloor()
{
    stopAtCurrentFloor(currentDirection,
                       QString("Target reached at floor %1")
                       .arg(FloorCatalog::numberFromPosition(currentFloor())));
}

void ElevatorController::stopAtCurrentFloor(Direction serviceDirection, const QString &message)
{
    cabin->stop();
    setState(ControllerState::TargetReached);
    emit logMessage(message);

    const std::vector<ElevatorRequest> served = scheduler.takeServedAt(currentFloor(), serviceDirection);
    clearServedButtons(served);
    doors->open();
}

void ElevatorController::stopForCancellation()
{
    cancellationStopPending = false;

    setDirection(Direction::Idle);
    targetFloor = currentFloor();
    emit targetFloorChanged(targetFloor);
    stopAtCurrentFloor(Direction::Idle,
                       QString("Cancellation stop at floor %1")
                       .arg(FloorCatalog::numberFromPosition(currentFloor())));
}

int ElevatorController::nearestStopFloor() const
{
    if (currentDirection == Direction::Up && currentFloor() < FloorCatalog::LastPosition) {
        return currentFloor() + 1;
    }

    if (currentDirection == Direction::Down && currentFloor() > FloorCatalog::FirstPosition) {
        return currentFloor() - 1;
    }

    return currentFloor();
}

void ElevatorController::clearServedButtons(const std::vector<ElevatorRequest> &served)
{
    for (const ElevatorRequest &request : served) {
        if (request.isCabinRequest()) {
            emit cabinButtonLightChanged(request.getFloor(), false);
        } else {
            emit floorCallLightChanged(request.getFloor(), request.getDirection(), false);
        }
    }
}

void ElevatorController::setState(ControllerState state)
{
    if (controllerState == state) {
        return;
    }

    controllerState = state;
    emit controllerStateChanged(controllerState);
}

void ElevatorController::setDirection(Direction direction)
{
    if (currentDirection == direction) {
        return;
    }

    currentDirection = direction;
    emit directionChanged(currentDirection);
}
