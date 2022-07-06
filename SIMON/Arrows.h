#pragma once
#include "Console_Navigation.h"

class Arrow
{
private:
    const int x, y, view, block_cols, block_rows;
public:
    Arrow(int _x, int _y, int _view, int _block_cols, int _block_rows) : x(_x), y(_y), view(_view), block_cols(_block_cols), block_rows(_block_rows) {};
    int get_x() const { return x; };
    int get_y() const { return y; };
    int get_cols() const { return block_cols; };
    int get_rows() const { return block_rows; };
    int get_view() const { return view; };
};