#include "level.h"
#include "collision.h"



Level::Level(Player *pl)
{
    curr_map = new Map();
    //curr_map->addWall(Wall(QVector2D(240,140), 10,405));
    //curr_map->addWall(Wall(QVector2D(60,120), 20,400));
    curr_map->addWall(Wall(QVector2D(90,60), 250,20));
    this->pl=pl;
}

void Level::draw(GameWidget *obg)
{
    curr_map->draw(obg);
}

void Level::checkCollision(QWidget *paint)
{
    foreach (Wall curr_wall, curr_map->walls) {
        this->pl->setDirection(collisionCircleAndRectangle(&curr_wall, this->pl, paint));
    }
}
