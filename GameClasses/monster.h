#ifndef MONSTER_H
#define MONSTER_H
#include "player.h"

class Monster : public RoundCollision
{


public:
   Monster(QVector2D position, float r);
   virtual void interact(Player *pl) = 0;
   virtual void move() = 0;
};

#endif // MONSTER_H
