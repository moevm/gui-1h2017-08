#ifndef TELEPORTERMONSTER_H
#define TELEPORTERMONSTER_H


#include "monster.h"
#include "movingobject.h"
#include "animationclass.h"
#include "map.h"
class Map;

class TeleporterMonster: public Monster, public AnimationClass//, public RoundCollision
{
    int Cooldown;
    int curr_Cooldown;
public:
    TeleporterMonster(QVector2D position, float r=25);

    void move();
    void draw(QWidget *obg, QPainter *p,QVector2D tr);
    void interact(RoundCollision *pl, QVector<RectangleCollision*> cells);

    void setCooldown(int value);
    bool canCastSpell();
    void castSpellTelleport(Unit *toPos, Map *m);
    void action();
};

#endif // TELEPORTERMONSTER_H
