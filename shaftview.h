#ifndef SHAFTVIEW_H
#define SHAFTVIEW_H

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
    ShaftView(QFrame *cabinFrame,
              QFrame *leftDoorFrame,
              QFrame *rightDoorFrame,
              QObject *parent = nullptr);

    void animateCabinToPosition(int position, int duration);
    void animateDoors(DoorState state, int duration);

private slots:
    void playPendingDoorAnimation();

private:
    QRect cabinGeometryForPosition(int position) const;
    void animateDoorPair(const QRect &leftTarget, const QRect &rightTarget, int duration);
    void setupAnimation(QPropertyAnimation *animation);

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
    int pendingDoorDuration = 0;
    bool hasPendingDoorAnimation = false;
};

#endif // SHAFTVIEW_H
