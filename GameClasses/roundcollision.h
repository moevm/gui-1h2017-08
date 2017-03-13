#ifndef ROUNDCOLLISION_H
#define ROUNDCOLLISION_H

#include "unit.h"


class RoundCollision : public Unit
{
protected:
    float R;
public:
    RoundCollision(QVector2D position, float R=0);
    float getR() const;
    void setR(float value);
    QVector2D getCentr();
};

#endif // ROUNDCOLLISION_H
