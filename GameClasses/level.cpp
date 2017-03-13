#include "level.h"

Level::Level()
{
 curr_map = new Map();
 curr_map->addWall(Wall(QVector2D(240,140), 10,405));
 curr_map->addWall(Wall(QVector2D(60,120), 20,400));
 curr_map->addWall(Wall(QVector2D(90,60), 250,20));

}

void Level::draw(GameWidget *obg)
{
    curr_map->draw(obg);
}
