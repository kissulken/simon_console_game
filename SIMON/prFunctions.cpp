#include "prFunctions.h"

void setColor(Color text, Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void setColor(Color background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4)));
}

void SetCursor(short x, short y)
{
    COORD myCoords = { x,  y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoords);
}
void textThrower(int x, int y, string phrase)
{
    SetCursor(x, y);
    cout << phrase << endl;
}

void textThrower(int x, int y, char ch)
{
    SetCursor(x, y);
    cout << ch << endl;
}


void sayIt(vector<string> s) {
    setColor(Black);
    system("cls");
    setColor(White, Red);
    for (int i = 0; i < s.size(); i++)
    {
        textThrower(60, 10 + i, s[i]);
        Sleep(1000);
    }
    setColor(White, Black);
    system("cls");
}

