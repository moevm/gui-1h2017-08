#ifndef COLLISION_H
#define COLLISION_H

#include <QVector2D>
#include <QWidget>
#include "rectanglecollision.h"
#include "roundcollision.h"


QVector2D collisionCircleAndRectangle( RectangleCollision * rect, RoundCollision *circle, QWidget * paint);

bool collisionOnX(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool rectUp(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool collisionOnY(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool rectRight(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool circleOutsideRectX(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool circleOutsideRectY(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool circleInRectX(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
bool circleInRectY(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);
QVector2D checkAreaFromTheCorner(RectangleCollision *rect, RoundCollision *circle, QWidget * paint);

bool getLine(const QVector2D  p1 ,const QVector2D p2, float &k, float &b); //возвращает false, если эта линия имеет вид x=b
bool inLine(float line1, float line2, float point);

QVector2D pointProjectionOnLine(QVector2D point, float k, float b);  // проецируем точку point на прямую y=k*x+b
//bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2,QVector2D proj3);
bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2);
bool pointOnLine (QVector2D p1,QVector2D p2,QVector2D point);

#endif // COLLISION_H
