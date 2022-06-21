#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

void setColor(Color text, Color background);
void setColor(Color background);
void SetCursor(short x, short y);
void textThrower(int x, int y, string phrase);
void textThrower(int x, int y, char ch);
void sayIt(vector<string> s);