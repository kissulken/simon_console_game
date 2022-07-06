#include "Counters.h"

void Counters::spawn() //move into Gameplay
{
    std::string s = this->get_text();
    nav->setColor(White, Red);
    nav->textThrower(this->get_x(), this->get_y(), s);
    s = std::to_string(this->get_points());
    nav->textThrower(this->get_x() + this->get_text().size(), this->get_y(), s);
}

void Counters::show_points() //move into Gameplay
{
    std::string s = std::to_string(this->get_points());
    nav->setColor(White, Red);
    nav->textThrower(this->get_x() + this->get_text().size(), this->get_y(), s);
}