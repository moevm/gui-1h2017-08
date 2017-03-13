#include "map.h"

Map::Map()
{

}

void Map::addWall(Wall w)
{
    walls.push_back(w);
}

void Map::draw(GameWidget *obg)
{
    foreach (Wall curr_wall, this->walls) {
        curr_wall.draw(obg);
    }
}
