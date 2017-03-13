#ifndef ROUNDCOLLISION_H
#define ROUNDCOLLISION_H

#include "unit.h"


class RoundCollision : public Unit
{
protected:
    float R;
public:
    RoundCollision(QVector2D position, float R=0);
};

#endif // ROUNDCOLLISION_H
