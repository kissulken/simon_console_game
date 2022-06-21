#include "ColorBlocks.h"
#include "prFunctions.h"
#define LIGHTER_POSITION_Y 3
#define TIME_TO_SPAWN 50
#define ARROW_POSITION_Y 10
#define COUNTERS_POSITION_Y 15
int main()
{
    YellowLighter y(19, LIGHTER_POSITION_Y, TIME_TO_SPAWN); GreenLighter g(37, LIGHTER_POSITION_Y, TIME_TO_SPAWN); RedLighter r(55, LIGHTER_POSITION_Y, TIME_TO_SPAWN*2); BlueLighter b(73, LIGHTER_POSITION_Y, TIME_TO_SPAWN*2); WhiteLighter w(91, LIGHTER_POSITION_Y, TIME_TO_SPAWN);
    Lighter* lighters[] = { &y, &g, &r, &b, &w };
    Arrow strelaUp(18, ARROW_POSITION_Y, 1, 9, 2), strelaDown(36, ARROW_POSITION_Y, 2, 9, 2), strelaLeft(54, ARROW_POSITION_Y, 3, 9, 2), strelaRight(72, ARROW_POSITION_Y, 4, 7, 2), strelaZero(90, ARROW_POSITION_Y, 5, 7, 2);
    Arrow* arrows[] = { &strelaUp, &strelaDown, &strelaLeft, &strelaRight, &strelaZero };
    Counters health(19, COUNTERS_POSITION_Y, 3, "HP: "), points(90, COUNTERS_POSITION_Y, 0, "POINTS: ");
    Counters* counters[] = {&health, &points};
    start(lighters);
    spawnInterface(arrows, counters);
    gameplay(lighters, arrows, counters);
}

