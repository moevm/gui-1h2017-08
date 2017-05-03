#include "animationclass.h"
#include <QtMath>

#include <QException>
#include <iostream>

using namespace std;

unsigned int AnimationClass::getCount_of_frames() const
{
    return count_of_frames;
}

unsigned int AnimationClass::getCurr_frame() const
{
    return curr_frame;
}

AnimationClass::AnimationClass(QString w, unsigned int count_of_frames, unsigned int time_of_frames, bool isRand)
{
    try {
        if(count_of_frames > 9)
        {
           // throw "Попытка создать анимацию с 10 или больше кадрами, пока что такой функции не предусмотрено.";
            throw new QException;
        }
    }
    catch(const QException* e)
    {

        cout << "Error:: count_of_frames > 10." << endl;
        exit(1);

    }

    time_on_frame=time_of_frames;
    curr_time_on_frame=time_of_frames;

    this->way = w;
    this->count_of_frames = count_of_frames;
    if(isRand)
        this->curr_frame=1 + (rand() %(count_of_frames-1)) ;
    else curr_frame=1;

}

QString AnimationClass::getCurrFrame()
{
    //":/img/teleportMonsterSprites/t0"



    QString curr_way = this->way + ('0'+curr_frame) + ".png";
    if(curr_time_on_frame==0)
    {
        curr_frame++;
        curr_time_on_frame=time_on_frame;
    }
    else curr_time_on_frame--;
    if(curr_frame == count_of_frames+1)
        curr_frame =1;
    return curr_way;
}
