#ifndef PUSHMONSTER_H
#define PUSHMONSTER_H


#include "monster.h"
#include "movingobject.h"
#include "map.h"
class Map;
class Player;


class PushMonster : public Monster
{
    int push_distance;
public:
    PushMonster(QVector2D position, float r=25);

    void move();
    void draw(QWidget *obg, QPainter *p,QVector2D tr);
    void interact(Player *pl, QVector<RectangleCollision*> cells);
    void push (Player *pl);

    void action();
};

#endif // PUSHMONSTER_H
