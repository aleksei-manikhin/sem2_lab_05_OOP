#ifndef ELEVATORCABIN_H
#define ELEVATORCABIN_H

#include "elevatorenums.h"

#include <QObject>
#include <QTimer>

class ElevatorCabin : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorCabin(int minFloor = 1, int maxFloor = 5, QObject *parent = nullptr);

    int currentFloor() const;
    Direction direction() const;
    CabinState state() const;
    bool isMoving() const;

public slots:
    void move(Direction direction);
    void stop();

signals:
    void floorChanged(int floor);
    void floorReached(int floor);
    void stateChanged(CabinState state);
    void directionChanged(Direction direction);
    void logMessage(const QString &message);

private slots:
    void onMoveTick();

private:
    bool canMove(Direction direction) const;
    int nextFloor() const;
    void setState(CabinState state);
    void setDirection(Direction direction);
    void arriveToNextFloor();

    int minFloor = 1;
    int maxFloor = 5;
    int currentFloorNumber = 1;
    Direction cabinDirection = Direction::Idle;
    CabinState cabinState = CabinState::Stopped;
    QTimer moveTimer;

    static constexpr int MoveTimeMs = 900;
};

#endif // ELEVATORCABIN_H
