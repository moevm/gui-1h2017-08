#ifndef RECTANGLECOLLISION_H
#define RECTANGLECOLLISION_H

#include "unit.h"



class RectangleCollision: public Unit
{
protected:
    float width, height;
public:
    RectangleCollision(QVector2D position, float h=0, float w=0 );

};

#endif // RECTANGLECOLLISION_H
