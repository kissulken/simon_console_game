#include "Lighters.h"

void Lighter::create()
{
    nav->setColor(Constants::White, Constants::Black);
    for (int i = 0; i <= Constants::LIGHTER_WIDTH; i++)
    {
        nav->textThrower({ this->get_x() - Constants::BORDER_SIZE + i, this->get_y() - Constants::BORDER_SIZE }, Constants::BORDER_MATERIAL);
    }
    for (int i = 1; i <= Constants::LIGHTER_HEIGHT; i++)
    {
        nav->textThrower({ this->get_x() - Constants::BORDER_SIZE, this->get_y() - Constants::BORDER_SIZE + i }, Constants::BORDER_MATERIAL);
        nav->textThrower({ this->get_x() - Constants::BORDER_SIZE + Constants::LIGHTER_WIDTH, this->get_y() - Constants::BORDER_SIZE + i }, Constants::BORDER_MATERIAL);
        nav->Do_Sleep(this->get_ttl());
    }
    for (int i = 0; i <= Constants::LIGHTER_WIDTH; i++)
    {
        nav->textThrower({ this->get_x() - Constants::BORDER_SIZE + i, this->get_y() - Constants::BORDER_SIZE + Constants::LIGHTER_HEIGHT }, Constants::BORDER_MATERIAL);
    }
}

void Lighter::cycl(Constants::Color col, int side)
{
    nav->setColor(col);
    switch (side)
    {
    case Constants::AnimLeft:
        for (int i = 0; i <= Constants::ANIMATION_BLOCK_WIDTH; i++)
        {
            for (int j = 0; j <= Constants::ANIMATION_BLOCK_HEIGHT; j++)
            {
                nav->textThrower({ this->get_x() + i, this->get_y() + j }, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case Constants::AnimRight:
        for (int i = Constants::ANIMATION_BLOCK_WIDTH; i >= 0; i--)
        {
            for (int j = 0; j <= Constants::ANIMATION_BLOCK_HEIGHT; j++)
            {
                nav->textThrower({ this->get_x() + i, this->get_y() + j }, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case Constants::AnimDown:
        for (int i = 0; i <= Constants::ANIMATION_BLOCK_HEIGHT; i++)
        {
            for (int j = 0; j <= Constants::ANIMATION_BLOCK_WIDTH; j++)
            {
                nav->textThrower({ this->get_x() + j, this->get_y() + i }, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    case Constants::AnimUp:
        for (int i = Constants::ANIMATION_BLOCK_HEIGHT; i >= 0; i--)
        {
            for (int j = 0; j <= Constants::ANIMATION_BLOCK_WIDTH; j++)
            {
                nav->textThrower({ this->get_x() + j, this->get_y() + i }, ' ');
            }
            nav->Do_Sleep(this->get_ttl());
        }
        break;
    }
}

void YellowLighter::lightup() { cycl(Constants::Yellow, 0); }

void YellowLighter::blackout() { cycl(Constants::Black, 0); }

void GreenLighter::lightup() { cycl(Constants::Green, 1); }

void GreenLighter::blackout() { cycl(Constants::Black, 1); }

void RedLighter::lightup() { cycl(Constants::Red, 2); }

void RedLighter::blackout() { cycl(Constants::Black, 2); }

void BlueLighter::lightup() { cycl(Constants::Blue, 3); }

void BlueLighter::blackout() { cycl(Constants::Black, 3); }

void WhiteLighter::lightup() { cycl(Constants::White, 0); }

void WhiteLighter::blackout() { cycl(Constants::Black, 0); }