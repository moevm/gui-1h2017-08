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
    int **map;
    int h, w;
    float block;
    int curLevel;
    int mapSizes[3][2];

    void setSizes();
public:
    int getLastLevel();
    int getLevel();
    Level(Player * pl, int mazeWidth=5, int mazeHeight=7, int stage = 0, int blockSize=100);
    ~Level();
    void draw(GameWidget *obg);
    void checkCollision(GameWidget *paint);
    Map *getCurr_map();
    bool getFinised() const;
    void resizeAll(int blockSize);


};

#endif // LEVEL_H
