#include "Interface.h"

void ConsoleInterface::spawnInterface() 
{
    for (int i = 0; i < number_of_arrows; i++)
    {
        arrows[i]->spawn();
        arrows[i]->shine(true);
    }
    for (int i = 0; i < number_of_counters; i++)
        counters[i]->spawn();
}



