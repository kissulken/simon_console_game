#include "Console_Navigation.h"

void Console_Navigation::setColor(Color text, Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void Console_Navigation::setColor(Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4)));
}

void Console_Navigation::SetCursor(int x, int y)
{
    COORD myCoords = { x,  y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoords);
}

void Console_Navigation::textThrower(int x, int y, const std::string &phrase)
{
    SetCursor(x, y);
    std::cout << phrase << std::endl;
}
 
void Console_Navigation::textThrower(int x, int y, char ch)
{
    SetCursor(x, y);
    std::cout << ch << std::endl;
}

void Console_Navigation::sayIt(const std::string& s, int start_x, int start_y)
{
    setColor(Black);
    system("cls");
    setColor(White, Red);
    textThrower(start_x, 10 + start_y, s);
    Sleep(1000);
    setColor(White, Black);
    system("cls");
}

void Console_Navigation::Do_Sleep(int time) 
{
    Sleep(time);
}

bool Console_Navigation::buttonPressed()
{
    return _kbhit();
}

Directions Console_Navigation::whichButtonIsPressed()
{
    int key = _getch();
    if (key == 0 || key == 0xE0)
    {
        key = whichButtonIsPressed();
    }
    switch (key)
    {
        case Direction::Up:
            return Directions::UpB;
            break;
        case Direction::Left:
            return Directions::LeftB;
            break;
        case Direction::Right:
            return Directions::RightB;
            break;
        case Direction::Down:
            return Directions::DownB;
            break;
        case Direction::zerobutton:
            return Directions::ZeroB;
            break;
    }
}

