#ifndef RECTANGLECOLLISION_H
#define RECTANGLECOLLISION_H

#include "unit.h"



class RectangleCollision: public Unit
{
protected:
    float width, height;
public:
    RectangleCollision(QVector2D position, float h=0, float w=0 );

    float getWidth() const;
    void setWidth(float value);
    float getHeight() const;
    void setHeight(float value);
    QVector2D getCentr();
};

#endif // RECTANGLECOLLISION_H
