#pragma once
#include "Console_Navigation.h"
#include "Lighters.h"
#include "Constants.h"
#include "Arrows.h"
#include "Counters.h"

    class Gameplay 
    {
        public:
            Gameplay(std::vector<std::shared_ptr<Lighter>>& _lig, std::vector<std::shared_ptr<Arrow>>& _arrows, std::vector<std::shared_ptr<Counters>>& _counters, std::shared_ptr<INavigation> _nav) : lig(_lig), arrows(_arrows), counters(_counters), nav(_nav) {};
            void start();
            void gameplay();
            
        protected:
            void createNewSeq();
            void showSeq();
        private:
            int iteration = 0, chosen_arrow = 0;
            std::vector<int> sequence, userSequence;
            std::vector<std::shared_ptr<Lighter>>& lig;
            std::vector<std::shared_ptr<Arrow>>& arrows;
            std::vector<std::shared_ptr<Counters>>& counters;
            std::shared_ptr<INavigation> nav;
            void arrowSpawn(std::shared_ptr<Arrow> arrow);
            void arrowShine(std::shared_ptr<Arrow> arrow, bool correct);
            void countersShowPoints(std::shared_ptr<Counters> counters);
            void countersSpawn(std::shared_ptr<Counters> counters);
            void spawnInterface();
            void keyPressed();
            void trueFalseCheck();
            bool endofSequence();
    };
    
   
    
    



