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
    return "\033[1;" + to_string(color) + "m" + text + "\033[0m";
}

// Create longlong number
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) %
                   (h - l + 1);
}

// Random range [1 , num]
int RandomNumber(int num)
{
    long long maxRand = 10000000000000;
    // cout<< (int)floor((double)Rand(0,maxRand) / (double)maxRand * num + 1) <<" ";

    // return (int)floor((float)(rand() / double(RAND_MAX) * num + 1));
    return (int)floor((double)Rand(0, maxRand) / (double)maxRand * num + 1);
}