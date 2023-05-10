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
void Square::setvalue(int value)
{
    this->value = value;
}