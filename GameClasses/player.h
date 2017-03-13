#ifndef PLAYER_H
#define PLAYER_H

#include "roundcollision.h"
#include "gamewidget.h"


class GameWidget;


class Player : public RoundCollision
{
    QVector2D direction;
    float speed = 5;
public:
    Player(QVector2D position, float R=0);
    void draw(GameWidget *obg);
    void action();
    void moveTo(QVector2D toPoint);
    void stop();

    QVector2D getDirection() const;
    void setDirection(const QVector2D &value);
};

#endif // PLAYER_H



