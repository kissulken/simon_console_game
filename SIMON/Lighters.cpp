#include "Lighters.h"

#define LIGHTER_WIDTH 8
#define LIGHTER_HEIGHT 4

#define ANIMATION_BLOCK_WIDTH 6 //класс вместо кучи дефайнов
#define ANIMATION_BLOCK_HEIGHT 2
#define BORDER_SIZE 1
#define BORDER_MATERIAL '*'

void Lighter::create()
{

    nav->setColor(White, Black);
    for (int i = 0; i <= LIGHTER_WIDTH; i++)
    {
        nav->textThrower(this->get_x() - BORDER_SIZE + i, this->get_y() - BORDER_SIZE, BORDER_MATERIAL); //* тоже magic number
    }
    for (int i = 1; i <= LIGHTER_HEIGHT; i++)
    {
        nav->textThrower(this->get_x() - BORDER_SIZE, this->get_y() - BORDER_SIZE + i, BORDER_MATERIAL);
        nav->textThrower(this->get_x() - BORDER_SIZE + LIGHTER_WIDTH, this->get_y() - BORDER_SIZE + i, BORDER_MATERIAL);
        nav->Do_Sleep(this->get_ttl());
    }
    for (int i = 0; i <= LIGHTER_WIDTH; i++)
    {
        nav->textThrower(this->get_x() - BORDER_SIZE + i, this->get_y() - BORDER_SIZE + LIGHTER_HEIGHT, BORDER_MATERIAL);
    }
}

void Lighter::cycl(Color col, int side)
{
    nav->setColor(col);
    switch (side)
    {
    case AnimLeft:
        for (int i = 0; i <= ANIMATION_BLOCK_WIDTH; i++)
        {
            for (int j = 0; j <= ANIMATION_BLOCK_HEIGHT; j++)
            {
                nav->textThrower(this->get_x() + i, this->get_y() + j, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case AnimRight:
        for (int i = ANIMATION_BLOCK_WIDTH; i >= 0; i--)
        {
            for (int j = 0; j <= ANIMATION_BLOCK_HEIGHT; j++)
            {
                nav->textThrower(this->get_x() + i, this->get_y() + j, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case AnimDown:
        for (int i = 0; i <= ANIMATION_BLOCK_HEIGHT; i++)
        {
            for (int j = 0; j <= ANIMATION_BLOCK_WIDTH; j++)
            {
                nav->textThrower(this->get_x() + j, this->get_y() + i, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case AnimUp:
        for (int i = ANIMATION_BLOCK_HEIGHT; i >= 0; i--)
        {
            for (int j = 0; j <= ANIMATION_BLOCK_WIDTH; j++)
            {
                nav->textThrower(this->get_x() + j, this->get_y() + i, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    }
}

void YellowLighter::lightup() { cycl(Yellow, 0); }

void YellowLighter::blackout() { cycl(Black, 0); }

void GreenLighter::lightup() { cycl(Green, 1); }

void GreenLighter::blackout() { cycl(Black, 1); }

void RedLighter::lightup() { cycl(Red, 2); }

void RedLighter::blackout() { cycl(Black, 2); }

void BlueLighter::lightup() { cycl(Blue, 3); }

void BlueLighter::blackout() { cycl(Black, 3); }

void WhiteLighter::lightup() { cycl(White, 0); }

void WhiteLighter::blackout() { cycl(Black, 0); }