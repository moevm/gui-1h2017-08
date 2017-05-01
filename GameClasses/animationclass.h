#ifndef ANIMATIONCLASS_H
#define ANIMATIONCLASS_H

#include <QString>
#include <QVector>

class AnimationClass
{
    unsigned int curr_frame;
    unsigned int count_of_frames;
    unsigned int time_on_frame;
    QString way;
public:
    AnimationClass(QString w,unsigned int count_of_frames);
    QString getCurrFrame();
};

#endif // ANIMATIONCLASS_H
