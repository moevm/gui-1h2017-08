#include "math_function.h"
#include <QtMath>

float findAngle(QVector2D v1, QVector2D v2)
{
    float angle = qAcos((v1.x()*v2.x()+v1.y()*v2.y())/(sqrt(v1.x()*v1.x()+v1.y()*v1.y())*sqrt(v2.x()*v2.x()+v2.y()*v2.y())))*180/3.14;

    if(v2.x() > 0 && v2.y() >0)
    {
         return angle;
    }
    if(v2.x() < 0 && v2.y() >0)
    {
        return angle;
    }
    if(v2.x() < 0 && v2.y() <0)
    {
        return -angle;
    }
    if(v2.x() > 0 && v2.y() <0)
    {
        return -angle;
    }
    if(v2.y() ==0)
    {
       if(v2.x() >0)
           return 0;
       else
           return 180;
    }
    if(v2.x() ==0)
    {
       if(v2.y() >0)
           return 90;
       else
           return 90;
    }
    return angle;
}
