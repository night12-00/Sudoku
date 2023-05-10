#pragma once
#include "include.h"
#include "Function.h"

class Square
{
private:
    int value = 0;

protected:
public:
    Square(char value);
    Square();
    ~Square();
    int getValue();
    void setvalue(int value);
};