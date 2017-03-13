#ifndef COLLISION_H
#define COLLISION_H

#include <QVector2D>
#include "rectanglecollision.h"
#include "roundcollision.h"


QVector2D collisionCircleAndRectangle( RectangleCollision * rect, RoundCollision *circle);
QVector2D pointProjectionOnLine(QVector2D point, float k, float b);  // проецируем точку point на прямую y=k*x+b
bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2,QVector2D proj3);
bool pointOnLine (QVector2D p1,QVector2D p2,QVector2D point);

#endif // COLLISION_H
