#ifndef FLOORCATALOG_H
#define FLOORCATALOG_H

class FloorCatalog
{
public:
    static constexpr int FirstPosition = 1;
    static constexpr int FirstFloorNumber = 1;
    static constexpr int FloorCount = 5;
    static constexpr int LastPosition = FirstPosition + FloorCount - 1;

    static int numberFromPosition(int position);
    static int positionFromNumber(int floorNumber);
};

#endif // FLOORCATALOG_H
