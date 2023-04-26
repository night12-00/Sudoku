#include "Function.h"

void clearSystem()
{
    if (PLATFORM_NAME == "windows")
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}

//          foreground background
// black        30         40
// red          31         41
// green        32         42
// yellow       33         43
// blue         34         44
// magenta      35         45
// cyan         36         46
// white        37         47
string printColor(string text, int color)
{
    return "\033[1;" + to_string(color) + "m" + text + "\033[0m\n";
}