#pragma once
#include <string>

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
enum Directions {UpB, LeftB, RightB, DownB, ZeroB};

class INavigation 
{
    public:
        virtual void setColor(Color text, Color background) = 0;
        virtual void setColor(Color background) = 0;
        virtual void textThrower(int x, int y, const std::string& phrase) = 0;
        virtual void textThrower(int x, int y, char ch) = 0;
        virtual void sayIt(const std::string& s, int start_x, int start_y) = 0;
        virtual void Do_Sleep(int time) = 0;
        virtual bool buttonPressed() = 0;
        virtual Directions whichButtonIsPressed() = 0;
};