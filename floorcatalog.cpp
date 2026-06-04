#include "floorcatalog.h"

int FloorCatalog::minPosition()
{
    return FirstPosition;
}

int FloorCatalog::maxPosition()
{
    return LastPosition;
}

int FloorCatalog::positionCount()
{
    return FloorCount;
}

int FloorCatalog::numberFromPosition(int position)
{
    if (!isKnownPosition(position)) {
        return minPosition();
    }

    return FloorNumbers[position - FirstPosition];
}

int FloorCatalog::positionFromNumber(int floorNumber)
{
    for (int i = 0; i < FloorCount; ++i) {
        if (FloorNumbers[i] == floorNumber) {
            return i + FirstPosition;
        }
    }

    return minPosition();
}

bool FloorCatalog::isKnownPosition(int position)
{
    return position >= minPosition() && position <= maxPosition();
}

bool FloorCatalog::isKnownFloorNumber(int floorNumber)
{
    return numberFromPosition(positionFromNumber(floorNumber)) == floorNumber;
}
