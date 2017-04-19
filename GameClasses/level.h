#ifndef LEVEL_H
#define LEVEL_H

#include "map.h"

class Map;
class Player;

class Level
{
    Map *curr_map;
    Player * pl;
    bool finised = false;
public:
    Level(Player * pl, int mazeWidth=5, int mazeHeight=7);
    void draw(GameWidget *obg);
    void checkCollision(GameWidget *paint);
    Map *getCurr_map();
    bool getFinised() const;
};

#endif // LEVEL_H
