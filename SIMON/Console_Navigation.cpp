#include "Console_Navigation.h"

void Console_Navigation::setColor(Constants::Color text, Constants::Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void Console_Navigation::setColor(Constants::Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4)));
}

void Console_Navigation::SetCursor(const Points p)
{
    COORD myCoords = { p.x,  p.y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoords);
}

void Console_Navigation::textThrower(const Points p, const std::string& phrase)
{
    SetCursor(p);
    std::cout << phrase << std::endl;
}
 
void Console_Navigation::textThrower(const Points p, const char ch)
{
    SetCursor(p);
    std::cout << ch << std::endl;
}

void Console_Navigation::sayIt(const std::string& s, Points p)
{
    setColor(Constants::Black);
    system("cls");
    setColor(Constants::White, Constants::Red);
    textThrower(p, s);
    Sleep(1000);
    setColor(Constants::White, Constants::Black);
    system("cls");
}

void Console_Navigation::Do_Sleep(const int time) 
{
    Sleep(time);
}

bool Console_Navigation::buttonPressed()
{
    return _kbhit();
}

Constants::Directions Console_Navigation::whichButtonIsPressed()
{
    int key = _getch();
    if (key == 0 || key == 0xE0)
    {
        key = whichButtonIsPressed();
    }
    switch (key)
    {
        case Constants::Direction::Up:
            return Constants::Directions::UpB;
            break;
        case Constants::Direction::Left:
            return Constants::Directions::LeftB;
            break;
        case Constants::Direction::Right:
            return Constants::Directions::RightB;
            break;
        case Constants::Direction::Down:
            return Constants::Directions::DownB;
            break;
        case Constants::Direction::zerobutton:
            return Constants::Directions::ZeroB;
            break;
    }
}

