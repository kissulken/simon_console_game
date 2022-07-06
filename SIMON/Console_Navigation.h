#pragma once
#include "Navigation.h"
#include "Constants.h"
#include <vector>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

class Console_Navigation : public INavigation
{
    public:
        void setColor(Constants::Color text, Constants::Color background) override;
        void setColor(Constants::Color background) override;
        void textThrower(const Points p, const std::string& phrase) override;
        void textThrower(const Points p, const char ch) override;
        void sayIt(const std::string& s, Points p) override;
        void Do_Sleep(const int time) override;
        bool buttonPressed() override;
        Constants::Directions whichButtonIsPressed() override;
    protected:
        void SetCursor(const Points p);
};
