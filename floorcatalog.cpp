#include "floorcatalog.h"

int FloorCatalog::minPosition()
{
    return 1;
}

int FloorCatalog::maxPosition()
{
    return FloorCount;
}

int FloorCatalog::numberFromPosition(int position)
{
    if (position < minPosition() || position > maxPosition()) {
        return minPosition();
    }

    return FloorNumbers[position - 1];
}

int FloorCatalog::positionFromNumber(int floorNumber)
{
    for (int i = 0; i < FloorCount; ++i) {
        if (FloorNumbers[i] == floorNumber) {
            return i + 1;
        }
    }

    return minPosition();
}

bool FloorCatalog::isKnownFloorNumber(int floorNumber)
{
    return numberFromPosition(positionFromNumber(floorNumber)) == floorNumber;
}
