#ifndef TELEPORTERMONSTER_H
#define TELEPORTERMONSTER_H
#include "monster.h"
#include "player.h"
class Monster;
class Player;

class TeleporterMonster : public Monster
{
public:
    TeleporterMonster(QVector2D position, float r=25);
    void interact(Player* pl, QVector <Wall> cells);
    void move();
    void draw();
};

#endif // TELEPORTERMONSTER_H
