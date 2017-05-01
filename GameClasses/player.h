#ifndef PLAYER_H
#define PLAYER_H

#include "roundcollision.h"
#include "gamewidget.h"
#include "movingobject.h"

class GameWidget;


class Player : public MovingObject// public RoundCollision
{
    /*QVector2D direction;
    QVector2D force;
    float speed = 5;
    const float maxSpeed = 10;
    float angle;
    QVector2D look;*/

public:
    Player(QVector2D position, float R=0);
    void draw(GameWidget *obg);
   /* void action();
    void moveTo(QVector2D toPoint);
    void stop();

    QVector2D getDirection() const;
    void setDirection(const QVector2D &value);
    QVector2D getForce() const;
    void setForce(const QVector2D &value);*/

};

#endif // PLAYER_H



