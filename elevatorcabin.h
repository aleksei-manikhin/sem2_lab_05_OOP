#ifndef ELEVATORCABIN_H
#define ELEVATORCABIN_H

#include "elevatorenums.h"
#include "floorcatalog.h"

#include <QObject>
#include <QPointer>
#include <QTimer>

class ShaftView;

class ElevatorCabin : public QObject
{
    Q_OBJECT

public:
    explicit ElevatorCabin(QObject *parent = nullptr);

    int currentFloor() const;
    Direction direction() const;
    CabinState state() const;
    bool isMoving() const;

    void setShaftView(ShaftView* view);

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

    int currentFloorNumber = FloorCatalog::FirstPosition;
    Direction cabinDirection = Direction::Idle;
    CabinState cabinState = CabinState::Stopped;
    QTimer moveTimer;
    QPointer<ShaftView> shaftView;

    static constexpr int MoveTimeMs = 1200;
};

#endif // ELEVATORCABIN_H
