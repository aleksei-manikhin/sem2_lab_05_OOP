#include "elevatorscheduler.h"

#include <QtGlobal>

ElevatorScheduler::ElevatorScheduler(int minFloor, int maxFloor)
    : minFloor(minFloor),
      maxFloor(maxFloor)
{
}

bool ElevatorScheduler::addCabinRequest(int floor)
{
    return addRequest(ElevatorRequest::cabin(floor));
}

bool ElevatorScheduler::addFloorCall(int floor, Direction direction)
{
    if (direction == Direction::Idle) {
        return false;
    }

    return addRequest(ElevatorRequest::floorCall(floor, direction));
}

bool ElevatorScheduler::addRequest(const ElevatorRequest &request)
{
    if (!isValidRequest(request) || containsRequest(request)) {
        return false;
    }

    requests.push_back(request);
    return true;
}

bool ElevatorScheduler::hasRequests() const
{
    return !requests.empty();
}

bool ElevatorScheduler::hasRequestForButton(const ElevatorRequest &request) const
{
    return containsRequest(request);
}

bool ElevatorScheduler::shouldStopAt(int floor, Direction travelDirection) const
{
    const bool noMoreAhead = !hasRequestsAhead(floor, travelDirection);

    for (const ElevatorRequest &request : requests) {
        if (request.shouldStopAt(floor, travelDirection, noMoreAhead)) {
            return true;
        }
    }

    return false;
}

int ElevatorScheduler::nextTarget(int currentFloor, Direction currentDirection) const
{
    if (!hasRequests()) {
        return currentFloor;
    }

    const Direction direction = nextDirection(currentFloor, currentDirection);
    const int target = nearestFloorInDirection(currentFloor, direction);

    if (target != currentFloor) {
        return target;
    }

    return nearestAnyFloor(currentFloor);
}

Direction ElevatorScheduler::nextDirection(int currentFloor, Direction currentDirection) const
{
    if (currentDirection != Direction::Idle && hasRequestsAhead(currentFloor, currentDirection)) {
        return currentDirection;
    }

    const int nearest = nearestAnyFloor(currentFloor);
    if (nearest > currentFloor) {
        return Direction::Up;
    }

    if (nearest < currentFloor) {
        return Direction::Down;
    }

    return Direction::Idle;
}

std::vector<ElevatorRequest> ElevatorScheduler::takeServedAt(int floor, Direction travelDirection)
{
    std::vector<ElevatorRequest> served;
    const bool noMoreAhead = !hasRequestsAhead(floor, travelDirection);

    for (auto it = requests.begin(); it != requests.end();) {
        if (it->shouldStopAt(floor, travelDirection, noMoreAhead)) {
            served.push_back(*it);
            it = requests.erase(it);
        } else {
            ++it;
        }
    }

    return served;
}

std::vector<ElevatorRequest> ElevatorScheduler::getRequests() const
{
    return requests;
}

bool ElevatorScheduler::isValidFloor(int floor) const
{
    return floor >= minFloor && floor <= maxFloor;
}

bool ElevatorScheduler::isValidRequest(const ElevatorRequest &request) const
{
    if (!isValidFloor(request.getFloor())) {
        return false;
    }

    if (request.isCabinRequest()) {
        return true;
    }

    if (request.getDirection() == Direction::Up) {
        return request.getFloor() < maxFloor;
    }

    if (request.getDirection() == Direction::Down) {
        return request.getFloor() > minFloor;
    }

    return false;
}

bool ElevatorScheduler::containsRequest(const ElevatorRequest &request) const
{
    for (const ElevatorRequest &storedRequest : requests) {
        if (storedRequest.isSameButtonAs(request)) {
            return true;
        }
    }

    return false;
}

bool ElevatorScheduler::hasRequestsAhead(int currentFloor, Direction direction) const
{
    for (const ElevatorRequest &request : requests) {
        if (request.isAheadOf(currentFloor, direction)) {
            return true;
        }
    }

    return false;
}

int ElevatorScheduler::nearestAnyFloor(int currentFloor) const
{
    int nearest = currentFloor;
    int bestDistance = maxFloor - minFloor + 1;

    for (const ElevatorRequest &request : requests) {
        const int distance = qAbs(request.getFloor() - currentFloor);
        if (distance < bestDistance) {
            nearest = request.getFloor();
            bestDistance = distance;
        }
    }

    return nearest;
}

int ElevatorScheduler::nearestFloorInDirection(int currentFloor, Direction direction) const
{
    int nearest = currentFloor;
    int bestDistance = maxFloor - minFloor + 1;

    for (const ElevatorRequest &request : requests) {
        if (request.isAheadOf(currentFloor, direction)) {
            const int distance = qAbs(request.getFloor() - currentFloor);
            if (distance < bestDistance) {
                nearest = request.getFloor();
                bestDistance = distance;
            }
        }
    }

    return nearest;
}
