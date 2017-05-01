#ifndef TELEPORTERMONSTER_H
#define TELEPORTERMONSTER_H
#include "monster.h"

class TeleporterMonster : public Monster
{
public:
    TeleporterMonster(QVector2D position, float r);
    void interact(Player* pl);
    void move();
};

#endif // TELEPORTERMONSTER_H
