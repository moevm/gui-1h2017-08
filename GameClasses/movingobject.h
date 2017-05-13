#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "roundcollision.h"
#include "timer.h"


class MovingObject: public RoundCollision
{
protected:
    QVector2D direction;
    QVector2D force;
    QVector2D pushForce;
    float speed = 3;
    float maxSpeed = 10;
    float angle;
    QVector2D look;
public:
    Timer deafen;

    MovingObject(QVector2D position, float R=0);
    virtual void action();
    void moveTo(QVector2D toPoint);
    void stop();

    QVector2D getDirection() const;
    void setDirection(const QVector2D &value);
    QVector2D getForce() const;
    void setForce(const QVector2D &value);
    float getSpeed() const;
    void setMaxSpeed(float value);

    QVector2D getPushForce() const;
    void setPushForce(const QVector2D &value);
};

#endif // MOVINGOBJECT_H
