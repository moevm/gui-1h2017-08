#ifndef ANIMATIONCLASS_H
#define ANIMATIONCLASS_H

#include <QString>
#include <QVector>

class AnimationClass
{
    unsigned int curr_frame;
    unsigned int count_of_frames;
    unsigned int time_on_frame;
    unsigned int curr_time_on_frame;
    QString way;
public:
    AnimationClass(QString w, unsigned int count_of_frames, unsigned int time_of_frames=5, bool isRand=true);
    QString getCurrFrame();
    unsigned int getCount_of_frames() const;
    unsigned int getCurr_frame() const;
};

#endif // ANIMATIONCLASS_H
