#pragma once
#include <string>
#include "Console_Navigation.h"

class Counters
{
private:
    const int x, y;
    int points;
    const std::string text;
public:
    Counters(int _x, int _y, int _points, const std::string _text) : x(_x), y(_y), points(_points), text(_text) {};
    int get_x() const { return x; };
    int get_y() const { return y; };
    std::string get_text() const { return text; };
    int get_points() const { return points; };
    void set_points(int _points) { points += _points; };
    
};
