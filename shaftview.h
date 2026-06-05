#ifndef SHAFTVIEW_H
#define SHAFTVIEW_H

#include "elevatorcabin.h"
#include "elevatordoors.h"
#include "elevatorenums.h"

#include <QObject>
#include <QPointer>
#include <QPropertyAnimation>
#include <QRect>

class QFrame;

class ShaftView : public QObject
{
    Q_OBJECT

public:
    ShaftView(QFrame *shaftFrame,
              QFrame *cabinFrame,
              QFrame *leftDoorFrame,
              QFrame *rightDoorFrame,
              QObject *parent = nullptr);

public slots:
    void animateCabinToFloor(int floor);
    void animateDoors(DoorState state);

private slots:
    void playPendingDoorAnimation();

private:
    QRect cabinGeometryForFloor(int floor) const;
    void animateDoorPair(const QRect &leftTarget, const QRect &rightTarget, int duration);
    void setupAnimation(QPropertyAnimation *animation, int duration);

    QPointer<QFrame> shaftFrame;
    QPointer<QFrame> cabinFrame;
    QPointer<QFrame> leftDoorFrame;
    QPointer<QFrame> rightDoorFrame;

    QPropertyAnimation cabinAnimation;
    QPropertyAnimation leftDoorAnimation;
    QPropertyAnimation rightDoorAnimation;

    QRect closedLeftDoor;
    QRect closedRightDoor;
    QRect openedLeftDoor;
    QRect openedRightDoor;
    DoorState pendingDoorState = DoorState::Closed;
    bool hasPendingDoorAnimation = false;

    static constexpr int CabinAnimationMs = ElevatorCabin::MoveTimeMs;
};

#endif // SHAFTVIEW_H
