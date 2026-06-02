#include "shaftview.h"

#include <QFrame>

ShaftView::ShaftView(QFrame *shaftFrame,
                     QFrame *cabinFrame,
                     QFrame *leftDoorFrame,
                     QFrame *rightDoorFrame,
                     QObject *parent)
    : QObject(parent),
      shaftFrame(shaftFrame),
      cabinFrame(cabinFrame),
      leftDoorFrame(leftDoorFrame),
      rightDoorFrame(rightDoorFrame)
{
    closedLeftDoor = leftDoorFrame->geometry();
    closedRightDoor = rightDoorFrame->geometry();
    openedLeftDoor = QRect(0, 0, 10, closedLeftDoor.height());
    openedRightDoor = QRect(118, 0, 10, closedRightDoor.height());

    setupAnimation(&cabinAnimation, CabinAnimationMs);
    setupAnimation(&leftDoorAnimation, DoorAnimationMs);
    setupAnimation(&rightDoorAnimation, DoorAnimationMs);
}

void ShaftView::animateCabinToFloor(int floor)
{
    if (!cabinFrame) {
        return;
    }

    cabinAnimation.stop();
    cabinAnimation.setTargetObject(cabinFrame);
    cabinAnimation.setPropertyName("geometry");
    cabinAnimation.setStartValue(cabinFrame->geometry());
    cabinAnimation.setEndValue(cabinGeometryForFloor(floor));
    cabinAnimation.start();
}

void ShaftView::animateDoors(DoorState state)
{
    if (state == DoorState::Opening || state == DoorState::Open) {
        animateDoorPair(openedLeftDoor, openedRightDoor);
        return;
    }

    animateDoorPair(closedLeftDoor, closedRightDoor);
}

QRect ShaftView::cabinGeometryForFloor(int floor) const
{
    const QRect current = cabinFrame->geometry();
    const int safeFloor = qBound(MinFloor, floor, MaxFloor);
    const int floorHeight = 112;
    const int baseY = 456;
    const int y = baseY - (safeFloor - MinFloor) * floorHeight;

    return QRect(current.x(), y, current.width(), current.height());
}

void ShaftView::animateDoorPair(const QRect &leftTarget, const QRect &rightTarget)
{
    leftDoorAnimation.stop();
    rightDoorAnimation.stop();

    leftDoorAnimation.setEndValue(leftTarget);
    rightDoorAnimation.setEndValue(rightTarget);
    leftDoorAnimation.start();
    rightDoorAnimation.start();
}

void ShaftView::setupAnimation(QPropertyAnimation *animation, int duration)
{
    animation->setDuration(duration);
    animation->setEasingCurve(QEasingCurve::InOutCubic);

    if (animation == &leftDoorAnimation) {
        animation->setTargetObject(leftDoorFrame);
        animation->setPropertyName("geometry");
    }

    if (animation == &rightDoorAnimation) {
        animation->setTargetObject(rightDoorFrame);
        animation->setPropertyName("geometry");
    }
}
