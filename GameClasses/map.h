#ifndef MAP_H
#define MAP_H

#include "wall.h"
#include "ground.h"

class Wall;

class Map
{

public:
    QVector <Wall> walls;
    QVector <Wall> cells;
    Map();
    void addWall(Wall w);
    void addCell(Wall c);
    void draw(GameWidget *obg);
};

#endif // MAP_H
