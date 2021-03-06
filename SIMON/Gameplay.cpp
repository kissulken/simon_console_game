#include "Gameplay.h"

    void Gameplay::start()
    {
        std::vector<std::string> s = {"SIMON", "SAYS", "...."};
        for(int i = 0; i < s.size(); i++)
            nav->sayIt(s[i], {60, i + 10});
        for (int i = 0; i < Constants::NUMBER_OF_LIGHTERS; i++)
        {
            lig[i]->create();
            lig[i]->lightup();
        }
        for (int i = 0; i < Constants::NUMBER_OF_LIGHTERS; i++)
        {
            lig[i]->blackout();
        }
        spawnInterface();
    }

    void Gameplay::createNewSeq() 
    {
        sequence.clear();
        for (int i = 0; i < Constants::START_AMOUNT_OF_LIGHTUPS; i++)
        {
            sequence.push_back(rand() % Constants::NUMBER_OF_LIGHTERS);
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
                case Constants::RightB:
                    lig[0]->lightup();
                    userSequence.push_back(0);
                    chosen_arrow = 0;
                    lig[0]->blackout();
                    break;
                case Constants::LeftB:
                    lig[1]->lightup();
                    userSequence.push_back(1);
                    chosen_arrow = 1;
                    lig[1]->blackout();
                    break;
                case Constants::DownB:
                    lig[2]->lightup();
                    userSequence.push_back(2);
                    chosen_arrow = 2;
                    lig[2]->blackout();
                    break;
                case Constants::UpB:
                    lig[3]->lightup();
                    chosen_arrow = 3;
                    userSequence.push_back(3);
                    lig[3]->blackout();
                    break;
                case Constants::ZeroB:
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
            arrowShine(arrows[chosen_arrow], true);
        }
        else
        {
            arrowShine(arrows[chosen_arrow], false);
            counters[0]->set_points(-1);
            countersShowPoints(counters[0]);
            if (counters[0]->get_points() == 0)
            {
                s = "YOU LOSE!";
                nav->sayIt(s, { 60, 10 });
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
                nav->sayIt(s, { 60, 10 });
                nav->Do_Sleep(100000);
            }
        }
        
    }

    bool Gameplay::endofSequence()
    {
        if (iteration == sequence.size())
        {
            counters[1]->set_points(1);
            countersShowPoints(counters[1]);
            sequence.push_back(rand() % Constants::NUMBER_OF_LIGHTERS);
            userSequence.clear();
            iteration = 0;
            nav->Do_Sleep(1000);
            return true;
        }
    }

    void Gameplay::spawnInterface() 
    {
        for (int i = 0; i < arrows.size(); i++)
        {
            arrowSpawn(arrows[i]);
            arrowShine(arrows[i],true);
        }
        for (int i = 0; i < counters.size(); i++)
            countersSpawn(counters[i]);
    }

    void Gameplay::arrowSpawn(std::shared_ptr<Arrow> arrow) 
    {
        nav->setColor(Constants::White, Constants::Black);
        switch (arrow->get_view())
        {
        case Constants::LEFT_ARROW:
            nav->textThrower({ arrow->get_x(), arrow->get_y() }, "LEFT_ARROW");
            for (int j = 0; j < arrow->get_cols() + 1; j++)
            {
                nav->textThrower({ arrow->get_x() + j, arrow->get_y() + arrow->get_rows() - 1 }, '>');
            }
            break;
        case Constants::RIGHT_ARROW:
            nav->textThrower({ arrow->get_x(), arrow->get_y() }, "RIGHT_ARROW");
            for (int j = 0; j < arrow->get_cols() + 1; j++)
            {
                nav->textThrower({ arrow->get_x() + j, arrow->get_y() + arrow->get_rows() - 1 }, '<');
            }
            break;
        case Constants::DOWN_ARROW:
            nav->textThrower({ arrow->get_x(), arrow->get_y() }, "DOWN_ARROW");
            for (int j = 0; j < arrow->get_cols() + 1; j++)
            {
                nav->textThrower({ arrow->get_x() + j, arrow->get_y() + arrow->get_rows() - 1 }, '*');
            }
            break;
        case Constants::UP_ARROW:
            nav->textThrower({ arrow->get_x(), arrow->get_y() }, "UP_ARROW");
            for (int j = 0; j < arrow->get_cols() + 1; j++)
            {
                nav->textThrower({ arrow->get_x() + j, arrow->get_y() + arrow->get_rows() - 1 }, '^');
            }
            break;
        case Constants::NUM_ZERO:
            nav->textThrower({ arrow->get_x(), arrow->get_y() }, "NUM_ZERO");
            for (int j = 0; j < arrow->get_cols() + 1; j++)
            {
                nav->textThrower({ arrow->get_x() + j, arrow->get_y() + arrow->get_rows() - 1 }, '0');
            }
            break;
        }
    }

    void Gameplay::arrowShine(std::shared_ptr<Arrow> arrow, bool correct)
    {
        for (int i = 0; i < arrow->get_cols(); i++)
        {
            if (correct)
            {
                nav->setColor(Constants::Green);
            }
            else
            {
                nav->setColor(Constants::Red);
            }
            nav->textThrower({ arrow->get_x() + i, arrow->get_y() + arrow->get_rows() }, ' ');
            nav->Do_Sleep(20);
        }
        for (int i = 0; i < arrow->get_cols(); i++)
        {
            nav->setColor(Constants::Black);
            nav->textThrower({ arrow->get_x() + i, arrow->get_y() + arrow->get_rows() }, ' ');
            nav->Do_Sleep(20);
        }
    }

    void Gameplay::countersShowPoints(std::shared_ptr<Counters> counters) 
    {
        std::string s = std::to_string(counters->get_points());
        nav->setColor(Constants::White, Constants::Red);
        nav->textThrower({ counters->get_x() + (int)counters->get_text().size(), counters->get_y() }, s);
    }

    void Gameplay::countersSpawn(std::shared_ptr<Counters> counters) 
    {
        std::string s = counters->get_text();
        nav->setColor(Constants::White, Constants::Red);
        nav->textThrower({ counters->get_x(), counters->get_y() }, s);
        s = std::to_string(counters->get_points());
        nav->textThrower({ counters->get_x() + (int)counters->get_text().size(), counters->get_y() }, s);
    }



