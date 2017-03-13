#include "unit.h"


QVector2D Unit::getPosition() const
{
    return position;
}

void Unit::setPosition(const QVector2D &value)
{
    position = value;
}

Unit::Unit(QVector2D position)
{
    this->position=position;
}
