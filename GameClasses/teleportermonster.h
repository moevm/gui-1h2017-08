#ifndef TELEPORTERMONSTER_H
#define TELEPORTERMONSTER_H


#include "monster.h"
#include "movingobject.h"
#include "animationclass.h"


class TeleporterMonster: public Monster, public AnimationClass//, public RoundCollision
{
public:
    TeleporterMonster(QVector2D position, float r=25);

    void move();
    void draw(QWidget *ob, QVector2D tr);
    void interact(RoundCollision *pl, QVector<RectangleCollision*> cells);

};

#endif // TELEPORTERMONSTER_H
