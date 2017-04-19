#include "map.h"

Map::Map()
{

}

void Map::addWall(Wall w)
{
    walls.push_back(w);
}

void Map::addCell(Wall c)
{
    cells.push_back(c);
}

void Map::draw(GameWidget *obg)
{
    foreach (Wall curr_wall, this->walls) {
        curr_wall.draw(obg);
    }
    foreach (Wall curr_cell, this->cells) {
        curr_cell.draw(obg);
    }
}
