#include "ColorBlocks.h"

//œ≈–≈Ã≈ÕÕ€≈/œŒ—“ŒﬂÕÕ€≈
vector<int> sequence, userSequence;
// ŒÕ—“–” “Œ–¿

YellowLighter::YellowLighter(int _x, int _y, int _ttl) : x(_x), y(_y), ttl(_ttl) {};
GreenLighter::GreenLighter(int _x, int _y, int _ttl) : x(_x), y(_y), ttl(_ttl) {};
RedLighter::RedLighter(int _x, int _y, int _ttl) : x(_x), y(_y), ttl(_ttl) {};
BlueLighter::BlueLighter(int _x, int _y, int _ttl) : x(_x), y(_y), ttl(_ttl) {};
WhiteLighter::WhiteLighter(int _x, int _y, int _ttl) : x(_x), y(_y), ttl(_ttl) {};

// À¿——€ » »’ Ã≈“Œƒ€
#pragma region Classes
    void Lighter::create(int x, int y, int tts)
    {
        setColor(White, Black);
        for (int i = 0; i < 9; i++)
        {
            textThrower(x + i, y, '*');
        }
        for (int i = 1; i < 5; i++)
        {
            textThrower(x, y + i, '*');
            textThrower(x + 8, y + i, '*');
            Sleep(tts);
        }
        for (int i = 1; i < 9; i++)
        {
            textThrower(x + i, y + 4, '*');
        }
    }

    void Lighter::cycl(int x, int y, int ttl, Color col, int side) {
        setColor(col);
        switch (side) {
        case 1:
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    textThrower(x + i, y + j, ' ');
                }
                Sleep(ttl);
            }
            break;
        case 2:
            for (int i = 6; i >= 0; i--)
            {
                for (int j = 0; j < 3; j++)
                {
                    textThrower(x + i, y + j, ' ');
                }
                Sleep(ttl);
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    textThrower(x + j, y + i, ' ');
                }
                Sleep(ttl);
            }
            break;
        case 4:
            for (int i = 2; i >= 0; i--)
            {
                for (int j = 0; j < 7; j++)
                {
                    textThrower(x + j, y + i, ' ');
                }
                Sleep(ttl);
            }
            break;
        }
    }

    void YellowLighter::lightup() {
        cycl(x, y, ttl, Yellow, 1);
    }

    void YellowLighter::blackout() {
        cycl(x, y, ttl, Black, 1);
    }

    void GreenLighter::lightup() {
        cycl(x, y, ttl, Green, 2);
    }

    void GreenLighter::blackout() {
        cycl(x, y, ttl, Black, 2);
    }

    void RedLighter::lightup() {
        cycl(x, y, ttl, Red, 3);
    }

    void RedLighter::blackout() {
        cycl(x, y, ttl, Black, 3);
    }

    void BlueLighter::lightup() {
        cycl(x, y, ttl, Blue, 4);
    }

    void BlueLighter::blackout() {
        cycl(x, y, ttl, Black, 4);
    }

    void WhiteLighter::lightup() {
        cycl(x, y, ttl, White, 1);
    }

    void WhiteLighter::blackout() {
        cycl(x, y, ttl, Black, 1);
    }
#pragma endregion

//‘”Õ ÷»»
#pragma region Funcs
    void start(Lighter* lig[])
    {
        setlocale(LC_ALL, "Russian");
        sayIt({ "SIMON", "SAYS", "...." }); //from prFunctions.h
        for (int i = 0; i < 5; i++)
        {
            lig[i]->create(18 * (i + 1), 2, 100);
            lig[i]->lightup();
        }
        for (int i = 0; i < 5; i++)
        {
            lig[i]->blackout();
        }
    }
    void createNewSeq() {
        sequence.clear();
        srand(time(NULL));
        for (int i = 0; i < 3; i++)
        {
            sequence.push_back(rand() % 5);
        }
        Sleep(500);
    }

    void showSeq(Lighter* lig[]) {
        for (vector<int>::iterator i = sequence.begin(); i < sequence.end(); i++) {
            lig[*i]->lightup();
            lig[*i]->blackout();
        }
    }

    void gameplay(Lighter* lig[], Arrow* arrs[], Counters* counters[])
    {
        Arrow *a = arrs[0];
        createNewSeq();
        int key, iteration = 0;
        while (true)
        {
            showSeq(lig);
            while (true)
            {
                if (_kbhit())
                {
                    key = _getch();
                    if (key == 0 || key == 0xE0) key = _getch();
                    switch (key)
                    {
                    case Right:
                        lig[0]->lightup();
                        userSequence.push_back(0);
                        a = arrs[0];
                        lig[0]->blackout();
                        break;
                    case Left:
                        lig[1]->lightup();
                        userSequence.push_back(1);
                        a = arrs[1];
                        lig[1]->blackout();
                        break;
                    case Down:
                        lig[2]->lightup();
                        userSequence.push_back(2);
                        a = arrs[2];
                        lig[2]->blackout();
                        break;
                    case Up:
                        lig[3]->lightup();
                        a = arrs[3];
                        userSequence.push_back(3);
                        lig[3]->blackout();
                        break;
                    case zerobutton:
                        lig[4]->lightup();
                        a = arrs[4];
                        userSequence.push_back(4);
                        lig[4]->blackout();
                        break;
                    default:
                        break;
                    }
                    if (sequence[iteration] == userSequence[iteration])
                    {
                        iteration++;
                        a -> shine(a->get_x(), a->get_y(), true);
                    }
                    else
                    {
                        a->shine(a->get_x(), a->get_y(), false);
                        counters[0]->set_points(-1);
                        if (counters[0]->get_points() == 0)
                        {
                            sayIt({ "YOU LOSE!" });
                            Sleep(2000);
                            exit(0);
                        } 
                        else
                        {
                            showSeq(lig);
                            userSequence.clear();
                            iteration = 0;
                            Sleep(1000);
                        }
                        if (counters[0]->get_points() == 20)
                        {
                            sayIt({ "YOU WIN!" });
                            Sleep(2000);
                            exit(0);
                        }
                    }
                    if (iteration == sequence.size())
                    {
                        counters[1]->set_points(1);
                        sequence.push_back(rand() % 5);
                        userSequence.clear();
                        iteration = 0;
                        Sleep(1000);
                        break;
                    }
                }
            }
        }
    }
#pragma endregion

