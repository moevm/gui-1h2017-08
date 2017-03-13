#include "rectanglecollision.h"


RectangleCollision::RectangleCollision(QVector2D position, float h, float w):
    Unit(position)
{
    this->height = h;
    this->width = w;
}
