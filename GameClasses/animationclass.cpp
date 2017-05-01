#include "animationclass.h"
#include <QtMath>


AnimationClass::AnimationClass(QString w, unsigned int count_of_frames)
{
    time_on_frame=5;

    this->way = w;
    this->count_of_frames = count_of_frames;
    this->curr_frame=1 + (rand() %(count_of_frames-1)) ;

}

QString AnimationClass::getCurrFrame()
{
    //":/img/teleportMonsterSprites/t0"



    QString curr_way = this->way + ('0'+curr_frame) + ".png";
    if(time_on_frame==0)
    {
        curr_frame++;
        time_on_frame=5;
    }
    else time_on_frame--;
    if(curr_frame == count_of_frames+1)
        curr_frame =1;
    return curr_way;
}
