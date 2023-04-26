#pragma once
#include "include.h"

class Square
{
private:
    int row;
    int column;
    int value = 0;

protected:
public:
    Square(int value, int row, int column);
    Square();
    ~Square();
};