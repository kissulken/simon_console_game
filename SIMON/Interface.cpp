#include "Interface.h"
#include "prFunctions.h"

Arrow::Arrow(int _x, int _y, int _view, int _block_cols, int _block_rows) : x(_x), y(_y), view(_view), block_cols(_block_cols), block_rows(_block_rows) {};
Counters::Counters(int _x, int _y, int _points, string _text) : x(_x), y(_y), points(_points), text(_text) {};

void spawnInterface(Arrow* arrows[], Counters* counters[]) {
    for (int i = 0; i < 5; i++)
    {
        arrows[i]->spawn();
        arrows[i]->shine(arrows[i]->get_x(), arrows[i]->get_y(), true);
    }
    for (int i = 0; i < 2; i++)
        counters[i]->spawn();
}

// СТРЕЛКИ 

#pragma region Arrows
    void Arrow::spawn()
    {
        setColor(White, Black);
        switch (view) {
        case 1: //влево
            SetCursor(x, y);
            cout << "LEFT_ARROW";
            for (int j = 0; j < this->get_cols() + 1; j++)
            {
                SetCursor(x + j, y + this->get_rows() - 1);
                wcout << L"→";
            }
            break;
        case 2: //направо
            SetCursor(x - 1, y);
            cout << "RIGHT_ARROW";
            for (int j = -1; j < this->get_cols() + 1; j++)
            {
                SetCursor(x + j, y + this->get_rows() - 1);
                wcout << L"←";
            }
            break;
        case 3: //вниз
            SetCursor(x, y);
            cout << "DOWN_ARROW";
            for (int j = 0; j < this->get_cols() + 1; j++)
            {
                SetCursor(x + j, y + this->get_rows() - 1);
                wcout << L"↓";
            }
            break;
        case 4: //вверх
            SetCursor(x, y);
            cout << "UP_ARROW";
            for (int j = 0; j < this->get_cols() + 1; j++)
            {
                SetCursor(x + j, y + this->get_rows() - 1);
                wcout << L"↑";
            }
            break;
        case 5: // zero
            SetCursor(x, y);
            cout << "NUM_ZERO";
            for (int j = 0; j < this->get_cols() + 1; j++)
            {
                SetCursor(x + j, y + this->get_rows() - 1);
                cout << '0';
            }
            break;
        }
    }

    void Arrow::shine(int x, int y, bool correct) {
        for (int i = 0; i < this->get_cols(); i++)
        {
            if (correct)
                setColor(Green);
            else
                setColor(Red);
            textThrower(x + i, y + this->get_rows() + 1, ' ');
            Sleep(20);
        }
        for (int i = 0; i < this->get_cols(); i++)
        {
            setColor(Black);
            textThrower(x + i, y + this->get_rows() + 1, ' ');
            Sleep(20);
        }
    }
#pragma endregion

//СЧЕТЧИКИ
#pragma region Counters
    void Counters::spawn() {
        setColor(White, Red);
        textThrower(this->get_x(), this->get_y(), this->get_text());
        textThrower(this->get_x() + this->get_text().size(), this->get_y(), to_string(this->get_points()));
    }

    void Counters::set_points(int _points) {
        setColor(White, Red);
        this->points += _points;
        textThrower(this->get_x() + this->get_text().size(), this->get_y(), to_string(this->get_points()));
    }
#pragma endregion

