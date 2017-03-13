#include "rectanglecollision.h"


float RectangleCollision::getWidth() const
{
    return width;
}

void RectangleCollision::setWidth(float value)
{
    width = value;
}

float RectangleCollision::getHeight() const
{
    return height;
}

void RectangleCollision::setHeight(float value)
{
    height = value;
}

QVector2D RectangleCollision::getCentr()
{
     return QVector2D (this->position.x() + this->getWidth()/2, this->position.y() + this->getHeight()/2);
}

RectangleCollision::RectangleCollision(QVector2D position, float h, float w):
    Unit(position)
{
    this->height = h;
    this->width = w;
}
