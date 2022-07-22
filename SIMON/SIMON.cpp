#include "Gameplay.h"
#include "Lighters.h"
#include "Navigation.h"
#include "Constants.h"

std::vector<std::shared_ptr<Lighter>> lightersCreation(std::shared_ptr<Console_Navigation> nav) 
{
    auto yellow = std::make_shared<YellowLighter>(Constants::X_position_1, Constants::LIGHTER_POSITION_Y, Constants::TIME_TO_SPAWN, nav);
    auto green = std::make_shared<GreenLighter>(Constants::X_position_2, Constants::LIGHTER_POSITION_Y, Constants::TIME_TO_SPAWN, nav);
    auto red = std::make_shared<RedLighter>(Constants::X_position_3, Constants::LIGHTER_POSITION_Y, Constants::TIME_TO_SPAWN * 2, nav);
    auto blue = std::make_shared<BlueLighter>(Constants::X_position_4, Constants::LIGHTER_POSITION_Y, Constants::TIME_TO_SPAWN * 2, nav);
    auto white = std::make_shared<WhiteLighter>(Constants::X_position_5, Constants::LIGHTER_POSITION_Y, Constants::TIME_TO_SPAWN, nav);
        return { yellow, green, red, blue, white };
} 

std::vector<std::shared_ptr<Arrow>> arrowsCreation() 
{
    auto strelaUp = std::make_shared<Arrow>(Constants::X_position_1, Constants::ARROW_POSITION_Y, Constants::UpAnimation, Constants::ARROW_WIDTH, Constants::ARROW_HEIGHT);
    auto strelaDown = std::make_shared<Arrow>(Constants::X_position_2, Constants::ARROW_POSITION_Y, Constants::DownAnimation, Constants::ARROW_WIDTH, Constants::ARROW_HEIGHT);
    auto strelaLeft = std::make_shared<Arrow>(Constants::X_position_3, Constants::ARROW_POSITION_Y, Constants::LeftAnimation, Constants::ARROW_WIDTH, Constants::ARROW_HEIGHT);
    auto strelaRight = std::make_shared<Arrow>(Constants::X_position_4, Constants::ARROW_POSITION_Y, Constants::RightAnimation, Constants::ARROW_WIDTH, Constants::ARROW_HEIGHT);
    auto strelaZero = std::make_shared<Arrow>(Constants::X_position_5, Constants::ARROW_POSITION_Y, Constants::ZeroAnimation, Constants::ARROW_WIDTH, Constants::ARROW_HEIGHT);
        return { strelaUp, strelaDown, strelaLeft, strelaRight, strelaZero };
}

std::vector<std::shared_ptr<Counters>> countersCreation()
{
    auto health = std::make_shared<Counters>(19, Constants::COUNTERS_POSITION_Y, Constants::BASIC_HP, "HP: ");
    auto points = std::make_shared<Counters>(90, Constants::COUNTERS_POSITION_Y, Constants::BASIC_POINTS, "POINTS: ");
        return { health, points };
}

int main()
{
    srand(time(NULL));
    auto nav = std::make_shared<Console_Navigation>();
    std::vector<std::shared_ptr<Lighter>> lighters = lightersCreation(nav);
    std::vector<std::shared_ptr<Arrow>> arrows = arrowsCreation();
    std::vector<std::shared_ptr<Counters>> counters = countersCreation();

    Gameplay game(lighters, arrows, counters, nav);

    game.start();
    game.gameplay();
}

