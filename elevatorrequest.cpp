#include "elevatorrequest.h"

ElevatorRequest::ElevatorRequest(int floor, RequestType type, Direction direction)
    : floorNumber(floor),
      requestType(type),
      requestDirection(direction)
{
}

ElevatorRequest ElevatorRequest::cabin(int floor)
{
    return ElevatorRequest(floor, RequestType::Cabin, Direction::Idle);
}

ElevatorRequest ElevatorRequest::floorCall(int floor, Direction direction)
{
    return ElevatorRequest(floor, RequestType::FloorCall, direction);
}

int ElevatorRequest::getFloor() const
{
    return floorNumber;
}

RequestType ElevatorRequest::getType() const
{
    return requestType;
}

Direction ElevatorRequest::getDirection() const
{
    return requestDirection;
}

bool ElevatorRequest::isCabinRequest() const
{
    return requestType == RequestType::Cabin;
}

bool ElevatorRequest::isFloorCall() const
{
    return requestType == RequestType::FloorCall;
}

bool ElevatorRequest::isSameButtonAs(const ElevatorRequest &other) const
{
    return floorNumber == other.floorNumber
            && requestType == other.requestType
            && requestDirection == other.requestDirection;
}

bool ElevatorRequest::isAheadOf(int currentFloor, Direction travelDirection) const
{
    if (travelDirection == Direction::Up) {
        return floorNumber > currentFloor;
    }

    if (travelDirection == Direction::Down) {
        return floorNumber < currentFloor;
    }

    return false;
}

bool ElevatorRequest::canBeServedWhileMoving(Direction travelDirection) const
{
    return isCabinRequest()
            || requestDirection == travelDirection
            || travelDirection == Direction::Idle;
}

bool ElevatorRequest::shouldStopAt(int elevatorFloor, Direction travelDirection, bool noMoreAhead) const
{
    if (floorNumber != elevatorFloor) {
        return false;
    }

    if (canBeServedWhileMoving(travelDirection)) {
        return true;
    }

    return noMoreAhead;
}
