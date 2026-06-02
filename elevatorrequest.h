#ifndef ELEVATORREQUEST_H
#define ELEVATORREQUEST_H

#include "elevatorenums.h"

class ElevatorRequest
{
public:
    ElevatorRequest() = default;
    ElevatorRequest(int floor, RequestType type, Direction direction);

    static ElevatorRequest cabin(int floor);
    static ElevatorRequest floorCall(int floor, Direction direction);

    int getFloor() const;
    RequestType getType() const;
    Direction getDirection() const;

    bool isCabinRequest() const;
    bool isFloorCall() const;
    bool isSameButtonAs(const ElevatorRequest &other) const;
    bool isAheadOf(int currentFloor, Direction travelDirection) const;
    bool canBeServedWhileMoving(Direction travelDirection) const;
    bool shouldStopAt(int elevatorFloor, Direction travelDirection, bool noMoreAhead) const;

private:
    int m_floor = 1;
    RequestType m_type = RequestType::Cabin;
    Direction m_direction = Direction::Idle;
};

#endif // ELEVATORREQUEST_H
