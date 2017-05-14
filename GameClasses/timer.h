#ifndef TIMER_H
#define TIMER_H


class Timer
{
    unsigned int max_time;
    unsigned int  curr_time;
public:
    Timer(unsigned int max_time=10);
    void start();
    void start(int max_time);
    bool isFinished();
    void action();

    void setMax_time(unsigned int value);
};

#endif // TIMER_H
