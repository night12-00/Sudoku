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

    Square &operator=(int value);
    Square &operator=(Square &square);
    bool operator==(const Square &square);
    bool operator==(int value);
    bool operator!=(const Square &square);
    bool operator!=(int value);
};