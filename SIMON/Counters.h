#pragma once
#include <string>
#include "Console_Navigation.h"

class Counters
{
private:
    const int x, y;
    int points;
    const std::string text; //const
    std::shared_ptr<Console_Navigation> nav;
public:
    Counters(int _x, int _y, int _points, const std::string _text, std::shared_ptr<Console_Navigation> _nav) : x(_x), y(_y), points(_points), text(_text), nav(_nav) {};
    int get_x() const { return x; };
    int get_y() const { return y; };
    std::string get_text() const { return text; };
    int get_points() const { return points; };
    void set_points(int _points) { points += _points; };
    void show_points();
    void spawn();
};
