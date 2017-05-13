#ifndef MAP_H
#define MAP_H

#include "wall.h"
#include "monster.h"
#include "teleportermonster.h"
#include "pushmonster.h"
#include "teleport.h"

class TeleporterMonster;
class PushMonster;
class Wall;
class Teleport;

class Map
{

public:
    //QVector <Wall*> walls;
    QVector <QVector <Wall*>> walls;

    QVector <Wall*> cells;
    QVector <TeleporterMonster*> monsters;
    QVector <PushMonster*> push_monsters;
    QVector <Teleport*> teleports;
    Map();
    ~Map();
   // void addWall(Wall w);
    void addCell(Wall c);
    void addTeleportMonster(TeleporterMonster* m);
    void addTeleport(Teleport w);
    void draw(GameWidget *obg, QPainter *p);
    void genMonsters(int blockSize);
    void addPushMonster(PushMonster *m);
};

#endif // MAP_H
