#include "timer.h"

void Timer::setMax_time(unsigned int value)
{
    max_time = value;
}

Timer::Timer(unsigned int max_time)
{
    this->max_time=max_time;
    curr_time =0;

}

void Timer::start()
{
    curr_time=max_time;
}

void Timer::start(int max_time)
{
    this->max_time = max_time;
    curr_time=this->max_time;
}

bool Timer::isFinished()
{
    return curr_time <= 0;
}

void Timer::action()
{
    if(curr_time >0)
        curr_time--;
}
