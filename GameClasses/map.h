#ifndef MAP_H
#define MAP_H

#include "wall.h"
#include "monster.h"
#include "teleportermonster.h"
class Monster;
class Wall;

class Map
{

public:
    QVector <Wall> walls;
    QVector <Wall> cells;
    QVector <Monster*> monsters;
    Map();
    ~Map();
    void addWall(Wall w);
    void addCell(Wall c);
    void addMonster(Monster* m);
    void draw(GameWidget *obg);
    void genMonsters();
};

#endif // MAP_H
