#pragma once
#include "prFunctions.h"
#include "Interface.h"
#include <conio.h>

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, escape = 27, zerobutton = 48 };

// À¿——€ + Õ¿—À≈ƒÕ» »
#pragma region Classes
    class Lighter
    {
    public:
        virtual void lightup() = 0;
        virtual void blackout() = 0;
        void create(int x, int y, int tts);
    protected:
        void cycl(int x, int y, int ttl, Color col, int side);
    };

    class YellowLighter : public Lighter {
    private:
        int x, y, ttl;
    public:
        YellowLighter(int _x, int _y, int _ttl);
        void lightup();
        void blackout();
    };

    class GreenLighter : public Lighter {
    private:
        int x, y, ttl;
    public:
        GreenLighter(int _x, int _y, int _ttl);
        void lightup();
        void blackout();
    };

    class RedLighter : public Lighter {
    private:
        int x, y, ttl;
    public:
        RedLighter(int _x, int _y, int _ttl);
        void lightup();
        void blackout();
    };

    class BlueLighter : public Lighter {
    private:
        int x, y, ttl;
    public:
        BlueLighter(int _x, int _y, int _ttl);
        void lightup();
        void blackout();
    };

    class WhiteLighter : public Lighter {
    private:
        int x, y, ttl;
    public:
        WhiteLighter(int _x, int _y, int _ttl);
        void lightup();
        void blackout();
    };
#pragma endregion

//‘”Õ ÷»» Œ¡≈—œ≈◊»¬¿ﬁŸ»≈ –¿¡Œ“” ¡ÀŒ Œ¬
#pragma region Funcs
    void showSeq(Lighter* lig[]);
    void gameplay(Lighter* lig[], Arrow* arrs[], Counters* counters[]);
    void createNewSeq();
    void start(Lighter* lig[]);
#pragma endregion


