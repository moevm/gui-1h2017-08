#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "roundcollision.h"



class MovingObject: public RoundCollision
{
protected:
    QVector2D direction;
    QVector2D force;
    float speed = 5;
    const float maxSpeed = 10;
    float angle;
    QVector2D look;
public:
    MovingObject(QVector2D position, float R=0);
    void action();
    void moveTo(QVector2D toPoint);
    void stop();

    QVector2D getDirection() const;
    void setDirection(const QVector2D &value);
    QVector2D getForce() const;
    void setForce(const QVector2D &value);
    float getSpeed() const;
};

#endif // MOVINGOBJECT_H
