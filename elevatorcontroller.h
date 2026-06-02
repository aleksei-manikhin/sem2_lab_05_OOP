#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include "elevatorcabin.h"
#include "elevatordoors.h"
#include "elevatorscheduler.h"

#include <QObject>

class ElevatorController : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorController(int minFloor = 1, int maxFloor = 5, QObject *parent = nullptr);

    int currentFloor() const;
    Direction direction() const;
    ControllerState state() const;

public slots:
    void addCabinRequest(int floor);
    void addFloorCall(int floor, Direction direction);
    void openDoorsRequested();
    void closeDoorsRequested();

signals:
    void cabinButtonLightChanged(int floor, bool enabled);
    void floorCallLightChanged(int floor, Direction direction, bool enabled);
    void currentFloorChanged(int floor);
    void cabinStateChanged(CabinState state);
    void doorStateChanged(DoorState state);
    void controllerStateChanged(ControllerState state);
    void directionChanged(Direction direction);
    void targetFloorChanged(int floor);
    void logMessage(const QString &message);

private slots:
    void onCabinReachedFloor(int floor);
    void onDoorsClosed();

private:
    void connectParts();
    void addRequest(const ElevatorRequest &request);
    void continueWork();
    bool serveCurrentFloorIfNeeded();
    void startMovingToNextTarget();
    void stopAtCurrentFloor();
    void clearServedButtons(const std::vector<ElevatorRequest> &served);
    void setState(ControllerState state);
    void setDirection(Direction direction);
    bool doorsCanBeControlled() const;

    ElevatorCabin *cabin = nullptr;
    ElevatorDoors *doors = nullptr;
    ElevatorScheduler scheduler;
    Direction currentDirection = Direction::Idle;
    ControllerState controllerState = ControllerState::Idle;
    int targetFloor = 1;
};

#endif // ELEVATORCONTROLLER_H
