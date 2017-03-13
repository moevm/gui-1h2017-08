#ifndef LEVEL_H
#define LEVEL_H

#include "map.h"

class Map;

class Level
{
    Map *curr_map;
public:
    Level();
    void draw(GameWidget *obg);
};

#endif // LEVEL_H
