#include "elevatordoors.h"

#include <QDebug>

ElevatorDoors::ElevatorDoors(QObject *parent)
    : QObject(parent)
{
    openingTimer.setSingleShot(true);
    openedTimer.setSingleShot(true);
    closingTimer.setSingleShot(true);

    connect(&openingTimer, &QTimer::timeout, this, &ElevatorDoors::finishOpening);
    connect(&openedTimer, &QTimer::timeout, this, &ElevatorDoors::finishWaiting);
    connect(&closingTimer, &QTimer::timeout, this, &ElevatorDoors::finishClosing);
}

DoorState ElevatorDoors::state() const
{
    return doorState;
}

bool ElevatorDoors::isClosed() const
{
    return doorState == DoorState::Closed;
}

bool ElevatorDoors::isOpen() const
{
    return doorState == DoorState::Open;
}

void ElevatorDoors::open()
{
    if (doorState == DoorState::Open) {
        extendOpenTime();
        return;
    }

    if (doorState == DoorState::Opening) {
        return;
    }

    startOpening();
}

void ElevatorDoors::close()
{
    if (doorState == DoorState::Closed || doorState == DoorState::Closing) {
        return;
    }

    startClosing();
}

void ElevatorDoors::extendOpenTime()
{
    if (doorState != DoorState::Open) {
        open();
        return;
    }

    openedTimer.start(OpenedTimeMs);
    emit logMessage("Doors open time extended");
}

void ElevatorDoors::finishOpening()
{
    setState(DoorState::Open);
    emit logMessage("Doors opened");
    emit opened();
    openedTimer.start(OpenedTimeMs);
}

void ElevatorDoors::finishWaiting()
{
    close();
}

void ElevatorDoors::finishClosing()
{
    setState(DoorState::Closed);
    emit logMessage("Doors closed");
    emit closed();
}

void ElevatorDoors::setState(DoorState state)
{
    if (doorState == state) {
        return;
    }

    doorState = state;
    emit stateChanged(doorState);
}

void ElevatorDoors::startOpening()
{
    stopDoorTimers();
    setState(DoorState::Opening);
    emit logMessage("Doors are opening");
    openingTimer.start(OpeningTimeMs);
}

void ElevatorDoors::startClosing()
{
    stopDoorTimers();
    setState(DoorState::Closing);
    emit logMessage("Doors are closing");
    closingTimer.start(ClosingTimeMs);
}

void ElevatorDoors::stopDoorTimers()
{
    openingTimer.stop();
    openedTimer.stop();
    closingTimer.stop();
}
