#include "roundcollision.h"



float RoundCollision::getR() const
{
    return R;
}

void RoundCollision::setR(float value)
{
    R = value;
}

QVector2D RoundCollision::getCentr()
{
     return QVector2D (this->position.x() + this->getR(), this->position.y() + this->getR());
}

RoundCollision::RoundCollision(QVector2D position, float R):
    Unit(position)
{
    this->R=R;
}
