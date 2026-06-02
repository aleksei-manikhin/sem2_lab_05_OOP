#include "elevatorrequest.h"

ElevatorRequest::ElevatorRequest(int floor, RequestType type, Direction direction)
    : m_floor(floor),
      m_type(type),
      m_direction(direction)
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
    return m_floor;
}

RequestType ElevatorRequest::getType() const
{
    return m_type;
}

Direction ElevatorRequest::getDirection() const
{
    return m_direction;
}

bool ElevatorRequest::isCabinRequest() const
{
    return m_type == RequestType::Cabin;
}

bool ElevatorRequest::isFloorCall() const
{
    return m_type == RequestType::FloorCall;
}

bool ElevatorRequest::isSameButtonAs(const ElevatorRequest &other) const
{
    return m_floor == other.m_floor
            && m_type == other.m_type
            && m_direction == other.m_direction;
}

bool ElevatorRequest::isAheadOf(int currentFloor, Direction travelDirection) const
{
    if (travelDirection == Direction::Up) {
        return m_floor > currentFloor;
    }

    if (travelDirection == Direction::Down) {
        return m_floor < currentFloor;
    }

    return false;
}

bool ElevatorRequest::canBeServedWhileMoving(Direction travelDirection) const
{
    return isCabinRequest()
            || m_direction == travelDirection
            || travelDirection == Direction::Idle;
}

bool ElevatorRequest::shouldStopAt(int elevatorFloor, Direction travelDirection, bool noMoreAhead) const
{
    if (m_floor != elevatorFloor) {
        return false;
    }

    if (canBeServedWhileMoving(travelDirection)) {
        return true;
    }

    return noMoreAhead;
}
