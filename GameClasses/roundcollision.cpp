#include "roundcollision.h"



RoundCollision::RoundCollision(QVector2D position, float R):
    Unit(position)
{
    this->R=R;
}
