#include "shaftview.h"
#include "floorcatalog.h"

#include <QAbstractAnimation>
#include <QFrame>
#include <QtGlobal>

ShaftView::ShaftView(QFrame *cabinFrame,
                     QFrame *leftDoorFrame,
                     QFrame *rightDoorFrame,
                     QObject *parent)
    : QObject(parent),
      cabinFrame(cabinFrame),
      leftDoorFrame(leftDoorFrame),
      rightDoorFrame(rightDoorFrame)
{
    if (leftDoorFrame && rightDoorFrame) {
        closedLeftDoor = leftDoorFrame->geometry();
        closedRightDoor = rightDoorFrame->geometry();
        openedLeftDoor = QRect(0, 0, 10, closedLeftDoor.height());
        openedRightDoor = QRect(118, 0, 10, closedRightDoor.height());
    }

    setupAnimation(&cabinAnimation);
    setupAnimation(&leftDoorAnimation);
    setupAnimation(&rightDoorAnimation);

    cabinAnimation.setTargetObject(cabinFrame);
    leftDoorAnimation.setTargetObject(leftDoorFrame);
    rightDoorAnimation.setTargetObject(rightDoorFrame);

    connect(&cabinAnimation, &QPropertyAnimation::finished,
            this, &ShaftView::playPendingDoorAnimation);
}

void ShaftView::animateCabinToPosition(int position, int duration)
{
    if (!cabinFrame) {
        return;
    }

    cabinAnimation.stop();
    cabinAnimation.setDuration(duration);
    cabinAnimation.setStartValue(cabinFrame->geometry());
    cabinAnimation.setEndValue(cabinGeometryForPosition(position));
    cabinAnimation.start();
}

void ShaftView::animateDoors(DoorState state, int duration)
{
    if (state == DoorState::Opening || state == DoorState::Open) {
        if (cabinAnimation.state() == QAbstractAnimation::Running) {
            pendingDoorState = state;
            pendingDoorDuration = duration;
            hasPendingDoorAnimation = true;
            return;
        }

        animateDoorPair(openedLeftDoor, openedRightDoor, duration);
        return;
    }

    hasPendingDoorAnimation = false;
    animateDoorPair(closedLeftDoor, closedRightDoor, duration);
}

void ShaftView::playPendingDoorAnimation()
{
    if (!hasPendingDoorAnimation) {
        return;
    }

    const DoorState state = pendingDoorState;
    const int duration = pendingDoorDuration;
    hasPendingDoorAnimation = false;
    animateDoors(state, duration);
}

QRect ShaftView::cabinGeometryForPosition(int position) const
{
    const QRect current = cabinFrame->geometry();
    const int safeFloor = qBound(FloorCatalog::FirstPosition,
                                 position,
                                 FloorCatalog::LastPosition);
    const int floorHeight = 112;
    const int baseY = 456;
    const int y = baseY - (safeFloor - FloorCatalog::FirstPosition) * floorHeight;

    return QRect(current.x(), y, current.width(), current.height());
}

void ShaftView::animateDoorPair(const QRect &leftTarget, const QRect &rightTarget, int duration)
{
    if (!leftDoorFrame || !rightDoorFrame) {
        return;
    }

    leftDoorAnimation.stop();
    rightDoorAnimation.stop();

    leftDoorAnimation.setDuration(duration);
    rightDoorAnimation.setDuration(duration);
    leftDoorAnimation.setStartValue(leftDoorFrame->geometry());
    rightDoorAnimation.setStartValue(rightDoorFrame->geometry());
    leftDoorAnimation.setEndValue(leftTarget);
    rightDoorAnimation.setEndValue(rightTarget);
    leftDoorAnimation.start();
    rightDoorAnimation.start();
}

void ShaftView::setupAnimation(QPropertyAnimation *animation)
{
    animation->setPropertyName("geometry");
    animation->setEasingCurve(QEasingCurve::InOutCubic);
}
