#ifndef ELEVATORSCHEDULER_H
#define ELEVATORSCHEDULER_H

#include "elevatorrequest.h"
#include "floorcatalog.h"

#include <vector>

class ElevatorScheduler
{
public:
    bool addRequest(const ElevatorRequest &request);

    bool hasRequests() const;
    bool shouldStopAt(int floor, Direction travelDirection) const;

    int nextTarget(int currentFloor, Direction currentDirection) const;
    Direction nextDirection(int currentFloor, Direction currentDirection) const;
    std::vector<ElevatorRequest> takeServedAt(int floor, Direction travelDirection);
    std::vector<ElevatorRequest> getRequests() const;

private:
    bool isValidFloor(int floor) const;
    bool isValidRequest(const ElevatorRequest &request) const;
    bool containsRequest(const ElevatorRequest &request) const;
    bool hasRequestsAhead(int currentFloor, Direction direction) const;
    int nearestAnyFloor(int currentFloor) const;
    int nearestFloorInDirection(int currentFloor, Direction direction) const;

    std::vector<ElevatorRequest> requests;
};

#endif // ELEVATORSCHEDULER_H
