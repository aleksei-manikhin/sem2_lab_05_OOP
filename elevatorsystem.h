#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include "elevatorcontroller.h"

#include <QObject>

class ElevatorSystem : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorSystem(QObject *parent = nullptr);

    int currentFloor() const;
    Direction direction() const;
    ControllerState state() const;

public slots:
    void requestCabinFloor(int floor);
    void requestFloorCall(int floor, Direction direction);
    void requestDoorsOpen();
    void requestDoorsClose();
    void requestCabinCancellation();

private slots:
    void onControllerCurrentFloorChanged(int position);
    void onControllerTargetFloorChanged(int position);
    void onControllerCabinButtonLightChanged(int position, bool enabled);
    void onControllerFloorCallLightChanged(int position, Direction direction, bool enabled);

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

private:
    void connectController();

    ElevatorController *controller = nullptr;
};

#endif // ELEVATORSYSTEM_H
