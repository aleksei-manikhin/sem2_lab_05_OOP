#include "elevatorcabin.h"
#include "floorcatalog.h"
#include "shaftview.h"

ElevatorCabin::ElevatorCabin(QObject *parent)
    : QObject(parent),
      currentFloorNumber(FloorCatalog::FirstPosition)
{
    moveTimer.setSingleShot(false);
    connect(&moveTimer, &QTimer::timeout, this, &ElevatorCabin::onMoveTick);
}

int ElevatorCabin::currentFloor() const
{
    return currentFloorNumber;
}

Direction ElevatorCabin::direction() const
{
    return cabinDirection;
}

CabinState ElevatorCabin::state() const
{
    return cabinState;
}

bool ElevatorCabin::isMoving() const
{
    return cabinState == CabinState::Moving;
}

void ElevatorCabin::setShaftView(ShaftView* view)
{
    shaftView = view;
}

void ElevatorCabin::move(Direction direction)
{
    if (!canMove(direction)) {
        return;
    }

    setDirection(direction);
    setState(CabinState::Moving);
    emit logMessage("Cabin started moving");
    moveTimer.start(MoveTimeMs);
    if (shaftView) {
        shaftView->animateCabinToPosition(nextFloor(), MoveTimeMs);
    }
}

void ElevatorCabin::stop()
{
    if (cabinState == CabinState::Stopped) {
        return;
    }

    moveTimer.stop();
    setDirection(Direction::Idle);
    setState(CabinState::Stopped);
    emit logMessage(QString("Cabin stopped at floor %1")
                    .arg(FloorCatalog::numberFromPosition(currentFloorNumber)));
}

void ElevatorCabin::onMoveTick()
{
    if (!canMove(cabinDirection)) {
        stop();
        return;
    }

    arriveToNextFloor();
}

bool ElevatorCabin::canMove(Direction direction) const
{
    if (direction == Direction::Up) {
        return currentFloorNumber < FloorCatalog::LastPosition;
    }

    if (direction == Direction::Down) {
        return currentFloorNumber > FloorCatalog::FirstPosition;
    }

    return false;
}

int ElevatorCabin::nextFloor() const
{
    if (cabinDirection == Direction::Up) {
        return currentFloorNumber + 1;
    }

    if (cabinDirection == Direction::Down) {
        return currentFloorNumber - 1;
    }

    return currentFloorNumber;
}

void ElevatorCabin::setState(CabinState state)
{
    if (cabinState == state) {
        return;
    }

    cabinState = state;
    emit stateChanged(cabinState);
}

void ElevatorCabin::setDirection(Direction direction)
{
    if (cabinDirection == direction) {
        return;
    }

    cabinDirection = direction;
    emit directionChanged(cabinDirection);
}

void ElevatorCabin::arriveToNextFloor()
{
    currentFloorNumber = nextFloor();
    emit floorChanged(currentFloorNumber);
    emit logMessage(QString("Cabin arrived at floor %1")
                    .arg(FloorCatalog::numberFromPosition(currentFloorNumber)));
    emit floorReached(currentFloorNumber);

    if (isMoving() && canMove(cabinDirection) && shaftView) {
        shaftView->animateCabinToPosition(nextFloor(), MoveTimeMs);
    }
}
