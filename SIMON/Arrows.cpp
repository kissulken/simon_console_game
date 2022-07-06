#include "Arrows.h"

enum Arrows { LEFT_ARROW, RIGHT_ARROW, DOWN_ARROW, UP_ARROW, NUM_ZERO };

void Arrow::spawn() //Должен быть перенесен в Gameplay
{
    nav->setColor(White, Black);
    switch (view)
    {
    case LEFT_ARROW:
        nav->textThrower(x, y, "LEFT_ARROW");
        for (int j = 0; j < this->get_cols() + 1; j++)
        {
            nav->textThrower(x + j, y + this->get_rows() - 1, '>'); 
        }
        break;
    case RIGHT_ARROW:
        nav->textThrower(x, y, "RIGHT_ARROW");
        for (int j = 0; j < this->get_cols() + 1; j++)
        {
            nav->textThrower(x + j, y + this->get_rows() - 1, '<');
        }
        break;
    case DOWN_ARROW:
        nav->textThrower(x, y, "DOWN_ARROW");
        for (int j = 0; j < this->get_cols() + 1; j++)
        {
            nav->textThrower(x + j, y + this->get_rows() - 1, '*');
        }
        break;
    case UP_ARROW:
        nav->textThrower(x, y, "UP_ARROW");
        for (int j = 0; j < this->get_cols() + 1; j++)
        {
            nav->textThrower(x + j, y + this->get_rows() - 1, '^');
        }
        break;
    case NUM_ZERO:
        nav->textThrower(x, y, "NUM_ZERO");
        for (int j = 0; j < this->get_cols() + 1; j++)
        {
            nav->textThrower(x + j, y + this->get_rows() - 1, '0');
        }
        break;
    }
}

void Arrow::shine(bool correct)
{
    for (int i = 0; i < this->get_cols(); i++)
    {
        if (correct)
        {
            nav->setColor(Green);
        }     
        else
        {
            nav->setColor(Red);  
        }    
        nav->textThrower(this->get_x() + i, this->get_y() + this->get_rows(), ' ');
        nav->Do_Sleep(20);
    }
    for (int i = 0; i < this->get_cols(); i++)
    {
        nav->setColor(Black);
        nav->textThrower(this->get_x() + i, this->get_y() + this->get_rows(), ' ');
        nav->Do_Sleep(20);
    }
}