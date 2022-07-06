#pragma once
#include "Console_Navigation.h"

enum Animations { AnimLeft, AnimRight, AnimDown, AnimUp };

class Lighter
{
private:
    const int x, y, ttl;
public:
    Lighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation>_nav) : x(_x), y(_y), ttl(_ttl), nav(_nav) {};
    virtual void lightup() = 0;
    virtual void blackout() = 0; 
    void create();
    int get_x() const { return x; };
    int get_y() const { return y; };
    int get_ttl() const { return ttl; };
protected:
    void cycl(Color col, int side);
    std::shared_ptr<Console_Navigation> nav;
};

class YellowLighter : public Lighter {
public:
    YellowLighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation> _nav) : Lighter(_x, _y, _ttl, _nav) {};
    void lightup();
    void blackout();
};

class GreenLighter : public Lighter {
public:
    GreenLighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation> _nav) : Lighter(_x, _y, _ttl, _nav) {};
    void lightup();
    void blackout();
};

class RedLighter : public Lighter {
public:
    RedLighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation> _nav) : Lighter(_x, _y, _ttl, _nav) {};
    void lightup();
    void blackout();
};

class BlueLighter : public Lighter {
public:
    BlueLighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation> _nav) : Lighter(_x, _y, _ttl, _nav) {};
    void lightup();
    void blackout();
};

class WhiteLighter : public Lighter {
public:
    WhiteLighter(int _x, int _y, int _ttl, std::shared_ptr<Console_Navigation> _nav) : Lighter(_x, _y, _ttl, _nav) {};
    void lightup();
    void blackout();
};
