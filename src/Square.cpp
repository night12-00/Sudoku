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

Square &Square::operator=(int value)
{
    this->value = value;
    return *this;
}
Square &Square::operator=(Square &square)
{
    this->value = square.value;
    return *this;
}

bool Square::operator==(const Square &square)
{

    return (this->value == square.value);
}
bool Square::operator==(int value)
{

    return (this->value == value);
}

bool Square::operator!=(const Square &square)
{
    return !(*this == square);
}
bool Square::operator!=(int value)
{
    return !(*this == value);
}
