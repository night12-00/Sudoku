#include "Square.h"

Square::Square(char value)
{
    this->value = value;
}
Square::Square()
{
}
Square::~Square()
{
}
int Square::getValue()
{
    return this->value;
}

string Square::getValue(int color)
{
    return "\033[1;" + to_string(color) + "m" + to_string(this->value) + "\033[0m";
}
void Square::setvalue(int value)
{
    this->value = value;
}