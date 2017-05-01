#include "monster.h"

Monster::Monster(QVector2D position, float r, QString *path):
    RoundCollision(position,r)
{
    this->path=path;
}
