#include "Gameplay.h"

#define NUMBER_OF_LIGHTERS 5
#define START_AMOUNT_OF_LIGHTUPS 3

    void Gameplay::start()
    {
        std::vector<std::string> s = {"SIMON", "SAYS", "...."};
        for(int i = 0; i < s.size(); i++)
         nav->sayIt(s[i], 60, i + 1);
        for (int i = 0; i < NUMBER_OF_LIGHTERS; i++)
        {
            lig[i]->create();
            lig[i]->lightup();
        }
        for (int i = 0; i < NUMBER_OF_LIGHTERS; i++)
        {
            lig[i]->blackout();
        }
    }

    void Gameplay::createNewSeq() 
    {
        sequence.clear();
        for (int i = 0; i < START_AMOUNT_OF_LIGHTUPS; i++)
        {
            sequence.push_back(rand() % NUMBER_OF_LIGHTERS);
        }
    }

    void Gameplay::showSeq() 
    {
        for (std::vector<int>::iterator i = sequence.begin(); i != sequence.end(); i++) 
        {
            lig[*i]->lightup();
            lig[*i]->blackout();
        }
    }

    void Gameplay::gameplay()
    {
        createNewSeq();
        nav->Do_Sleep(500);
        while (true)
        {
            showSeq();
            while (true)
            {
                if (nav->buttonPressed())
                {
                    keyPressed();
                    trueFalseCheck();
                    if (endofSequence() == true)
                        break;
                }
            }
        }
        
    }

    void Gameplay::keyPressed()
    {
            int key = nav->whichButtonIsPressed();
            switch (key)
            {
                case RightB:
                    lig[0]->lightup();
                    userSequence.push_back(0);
                    chosen_arrow = 0;
                    lig[0]->blackout();
                    break;
                case LeftB:
                    lig[1]->lightup();
                    userSequence.push_back(1);
                    chosen_arrow = 1;
                    lig[1]->blackout();
                    break;
                case DownB:
                    lig[2]->lightup();
                    userSequence.push_back(2);
                    chosen_arrow = 2;
                    lig[2]->blackout();
                    break;
                case UpB:
                    lig[3]->lightup();
                    chosen_arrow = 3;
                    userSequence.push_back(3);
                    lig[3]->blackout();
                    break;
                case ZeroB:
                    lig[4]->lightup();
                    chosen_arrow = 4;
                    userSequence.push_back(4);
                    lig[4]->blackout();
                    break;
                default:
                    keyPressed();
            }
    }

    void Gameplay::trueFalseCheck()
    {
        std::string s;
        if (sequence[iteration] == userSequence[iteration])
        {
            iteration++;
            arrows[chosen_arrow]->shine(true);
        }
        else
        {
            arrows[chosen_arrow]->shine(false);
            counters[0]->set_points(-1);
            counters[0]->show_points();
            if (counters[0]->get_points() == 0)
            {
                s = "YOU LOSE!";
                nav->sayIt(s, 60, 10);
                nav->Do_Sleep(100000);
            }
            else
            {
                showSeq();
                userSequence.clear();
                iteration = 0;
                nav->Do_Sleep(1000);
            }
            if (counters[1]->get_points() == 20)
            {
                s = "YOU WIN!";
                nav->sayIt(s, 60, 10);
                nav->Do_Sleep(100000);
            }
        }
        
    }

    bool Gameplay::endofSequence()
    {
        if (iteration == sequence.size())
        {
            counters[1]->set_points(1);
            counters[1]->show_points();
            sequence.push_back(rand() % NUMBER_OF_LIGHTERS);
            userSequence.clear();
            iteration = 0;
            nav->Do_Sleep(1000);
            return true;
        }
    }


