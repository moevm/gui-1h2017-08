#ifndef TELEPORT_H
#define TELEPORT_H

#include "animationclass.h"
#include "roundcollision.h"
#include <QPainter>
#include "wall.h"
class Wall;

class Teleport: public AnimationClass, public RoundCollision
{
    bool ready;
public:
    Teleport(QVector2D position, float R);
    void action();

    bool isReady() const;
    void draw(QWidget *obg, QPainter *p,QVector2D tr);
    void interact(RoundCollision *pl, QVector<Wall *> cells);
};

#endif // TELEPORT_H
