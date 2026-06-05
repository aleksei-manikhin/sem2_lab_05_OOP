#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include "elevatorcabin.h"
#include "elevatordoors.h"
#include "elevatorscheduler.h"
#include "floorcatalog.h"

#include <QObject>
#include <QString>

class ShaftView;

class ElevatorController : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorController(QObject *parent = nullptr);

    int currentFloor() const;
    Direction direction() const;
    ControllerState state() const;

    void setShaftView(ShaftView* view);

public slots:
    void addCabinRequest(int floor);
    void addFloorCall(int floor, Direction direction);
    void openDoorsRequested();
    void closeDoorsRequested();
    void cancelCabinRequests();

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
    void writeDebugLog(const QString &message);

private:
    void connectParts();
    void addRequest(const ElevatorRequest &request);
    void continueWork();
    bool serveCurrentFloorIfNeeded();
    void startMovingToNextTarget();
    void stopAtCurrentFloor();
    void stopAtCurrentFloor(Direction serviceDirection, const QString &message);
    void stopForCancellation();
    int nearestStopFloor() const;
    void clearServedButtons(const std::vector<ElevatorRequest> &served);
    void setState(ControllerState state);
    void setDirection(Direction direction);

    ElevatorCabin *cabin = nullptr;
    ElevatorDoors *doors = nullptr;
    ElevatorScheduler scheduler;
    Direction currentDirection = Direction::Idle;
    ControllerState controllerState = ControllerState::Idle;
    int targetFloor = FloorCatalog::FirstPosition;
    bool cancellationStopPending = false;
};

#endif // ELEVATORCONTROLLER_H
