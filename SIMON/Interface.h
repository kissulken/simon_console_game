#pragma once
#include <string>
using namespace std;

class Arrow
{
    private:
        int x, y, view, block_cols, block_rows;
    public:
        Arrow(int _x, int _y, int _view, int _block_cols, int _block_rows);
        int get_x() const { return x; };
        int get_y() const { return y; };
        int get_cols() const { return block_cols; };
        int get_rows() const { return block_rows; };
        void spawn();
        void shine(int x, int y, bool correct);
};

class Counters
{
    private:
        int x, y, points;
        string text;
    public:
        Counters(int _x, int _y, int _points, string _text);
        int get_x() const { return x; };
        int get_y() const { return y; };
        string get_text() const { return text; };
        int get_points() const { return points; };
        void set_points(int _points);
        void spawn();

};

void spawnInterface(Arrow* arrows[], Counters* counters[]);