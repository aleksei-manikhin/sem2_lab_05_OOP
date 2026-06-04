#ifndef FLOORCATALOG_H
#define FLOORCATALOG_H

class FloorCatalog
{
public:
    static int minPosition();
    static int maxPosition();
    static int numberFromPosition(int position);
    static int positionFromNumber(int floorNumber);
    static bool isKnownFloorNumber(int floorNumber);

private:
    static constexpr int FloorCount = 5;
    static constexpr int FloorNumbers[FloorCount] = {1, 2, 3, 4, 5};
};

#endif // FLOORCATALOG_H
