#ifndef MONSTER_H
#define MONSTER_H

//#include "player.h"

#include "roundcollision.h"
#include "rectanglecollision.h"
#include <QWidget>
#include "movingobject.h"



class Monster: public MovingObject
{
protected:
    QString *path;
public:
   Monster(QVector2D position, float r, QString *path = nullptr);
   virtual void interact(RoundCollision *pl, QVector <RectangleCollision*> cells) = 0;
   virtual void move() = 0;
   virtual void draw(QWidget *ob, QVector2D tr) = 0;
};

#endif // MONSTER_H
