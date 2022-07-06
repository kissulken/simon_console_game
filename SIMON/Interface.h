#pragma once
#include "Arrows.h"
#include "Counters.h"

class ConsoleInterface 
{
    public:
        ConsoleInterface(std::vector<std::shared_ptr<Arrow>>& _arrows, std::vector<std::shared_ptr<Counters>>& _counters, int _number_of_arrows, int _number_of_counters) : arrows(_arrows), counters(_counters), number_of_arrows(_number_of_arrows), number_of_counters(_number_of_counters) {};
        void spawnInterface();
    private:
        std::vector<std::shared_ptr<Arrow>>& arrows;
        std::vector<std::shared_ptr<Counters>>& counters;
        int number_of_arrows;
        int number_of_counters;
};
