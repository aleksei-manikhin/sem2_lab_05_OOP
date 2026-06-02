#include "elevatorcabin.h"

ElevatorCabin::ElevatorCabin(int minFloor, int maxFloor, QObject *parent)
    : QObject(parent),
      minFloor(minFloor),
      maxFloor(maxFloor),
      currentFloorNumber(minFloor)
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

void ElevatorCabin::move(Direction direction)
{
    if (!canMove(direction)) {
        return;
    }

    setDirection(direction);
    setState(CabinState::PreparingToMove);
    emit logMessage("Cabin is preparing to move");

    setState(CabinState::Moving);
    emit logMessage("Cabin started moving");
    moveTimer.start(MoveTimeMs);
}

void ElevatorCabin::stop()
{
    if (cabinState == CabinState::Stopped) {
        return;
    }

    moveTimer.stop();
    setDirection(Direction::Idle);
    setState(CabinState::Stopped);
    emit logMessage(QString("Cabin stopped at floor %1").arg(currentFloorNumber));
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
        return currentFloorNumber < maxFloor;
    }

    if (direction == Direction::Down) {
        return currentFloorNumber > minFloor;
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
    emit logMessage(QString("Cabin arrived at floor %1").arg(currentFloorNumber));
    emit floorReached(currentFloorNumber);
}
