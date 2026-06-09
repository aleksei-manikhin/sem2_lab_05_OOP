#include "floorcatalog.h"

int FloorCatalog::numberFromPosition(int position)
{
    int floorNumber = FirstFloorNumber + position - FirstPosition;
    if (FirstFloorNumber < 0 && floorNumber >= 0) {
        ++floorNumber;
    }

    if (position < FirstPosition || position > LastPosition) {
        floorNumber = FirstFloorNumber;
    }

    return floorNumber;
}

int FloorCatalog::positionFromNumber(int floorNumber)
{
    int position = floorNumber - FirstFloorNumber + FirstPosition;
    if (FirstFloorNumber < 0 && floorNumber > 0) {
        --position;
    }

    if (floorNumber == 0 || position < FirstPosition || position > LastPosition) {
        position = FirstPosition;
    }

    return position;
}
