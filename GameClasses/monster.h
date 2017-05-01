#ifndef MONSTER_H
#define MONSTER_H
#include "player.h"
#include "wall.h"
class Wall;
class Player;

class Monster : public RoundCollision
{

    QString *path;
public:
   Monster(QVector2D position, float r, QString *path);
   virtual void interact(Player *pl, QVector <Wall> cells) = 0;
   virtual void move() = 0;
   virtual void draw() = 0;
};

#endif // MONSTER_H
