#include "Gameplay.h"
#include "Lighters.h"
#include "Navigation.h"

#define LIGHTER_POSITION_Y 3
#define TIME_TO_SPAWN 50
#define ARROW_POSITION_Y 10
#define COUNTERS_POSITION_Y 15

std::vector<std::shared_ptr<Lighter>> lightersCreation(std::shared_ptr<Console_Navigation> nav) 
{
    auto yellow = std::make_shared<YellowLighter>(19, LIGHTER_POSITION_Y, TIME_TO_SPAWN, nav);
    auto green = std::make_shared<GreenLighter>(37, LIGHTER_POSITION_Y, TIME_TO_SPAWN, nav);
    auto red = std::make_shared<RedLighter>(55, LIGHTER_POSITION_Y, TIME_TO_SPAWN * 2, nav);
    auto blue = std::make_shared<BlueLighter>(73, LIGHTER_POSITION_Y, TIME_TO_SPAWN * 2, nav);
    auto white = std::make_shared<WhiteLighter>(91, LIGHTER_POSITION_Y, TIME_TO_SPAWN, nav);
        return { yellow, green, red, blue, white };
}

std::vector<std::shared_ptr<Arrow>> arrowsCreation(std::shared_ptr<Console_Navigation> nav) 
{
    auto strelaUp = std::make_shared<Arrow>(18, ARROW_POSITION_Y, 0, 9, 2, nav);
    auto strelaDown = std::make_shared<Arrow>(36, ARROW_POSITION_Y, 1, 9, 2, nav);
    auto strelaLeft = std::make_shared<Arrow>(54, ARROW_POSITION_Y, 2, 9, 2, nav);
    auto strelaRight = std::make_shared<Arrow>(72, ARROW_POSITION_Y, 3, 7, 2, nav);
    auto strelaZero = std::make_shared<Arrow>(90, ARROW_POSITION_Y, 4, 7, 2, nav);
        return { strelaUp, strelaDown, strelaLeft, strelaRight, strelaZero };
}

std::vector<std::shared_ptr<Counters>> countersCreation(std::shared_ptr<Console_Navigation> nav)
{
    auto health = std::make_shared<Counters>(19, COUNTERS_POSITION_Y, 3, "HP: ", nav);
    auto points = std::make_shared<Counters>(90, COUNTERS_POSITION_Y, 0, "POINTS: ", nav);
        return { health, points };
}

int main()
{
    srand(time(NULL));
    auto nav = std::make_shared<Console_Navigation>();
    std::vector<std::shared_ptr<Lighter>> lighters = lightersCreation(nav);
    std::vector<std::shared_ptr<Arrow>> arrows = arrowsCreation(nav);
    std::vector<std::shared_ptr<Counters>> counters = countersCreation(nav);

    Gameplay game(lighters, arrows, counters, nav);
    ConsoleInterface inter(arrows, counters, 5, 2);

    game.start();
    inter.spawnInterface();
    game.gameplay();
}

