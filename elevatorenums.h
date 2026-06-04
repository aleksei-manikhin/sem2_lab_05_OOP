#ifndef ELEVATORENUMS_H
#define ELEVATORENUMS_H

enum class Direction
{
    Idle,
    Up,
    Down
};

enum class CabinState
{
    Stopped,
    Moving,
    Locked,
    Unlocked
};

enum class DoorState
{
    Opening,
    Open,
    Closing,
    Closed
};

enum class ControllerState
{
    Idle,
    Moving,
    UpdatingTarget,
    TargetReached
};

enum class RequestType
{
    Cabin,
    FloorCall
};

#endif // ELEVATORENUMS_H
