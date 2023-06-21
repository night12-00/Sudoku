#include "TimePlay.h"

TimePlay::TimePlay()
{
}
TimePlay::~TimePlay()
{
}

void TimePlay::StartGame()
{
    start = clock();
}
void TimePlay::EndGame()
{
    timePlay = ((double)(end - start) / CLOCKS_PER_SEC) - pause;
}
void TimePlay::StartPause()
{
    pauseStart = clock();
}
void TimePlay::EndPause()
{
    pause += (double)(pauseEnd - pauseStart) / CLOCKS_PER_SEC;
}
