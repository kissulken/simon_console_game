#pragma once
#include "Navigation.h"
#include <vector>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, zerobutton = 48 };

class Console_Navigation : public INavigation
{
    public:
        void setColor(Color text, Color background) override;
        void setColor(Color background) override;
        void textThrower(int x, int y, const std::string& phrase) override;
        void textThrower(int x, int y, char ch) override;
        void sayIt(const std::string& s, int start_x, int start_y) override;
        void Do_Sleep(int time) override;
        bool buttonPressed() override;
        Directions whichButtonIsPressed() override;
    protected:
        void SetCursor(int x, int y);
};
