#include "player.h"


QVector2D Player::getDirection() const
{
    return direction;
}

void Player::setDirection(const QVector2D &value)
{
    direction = value.normalized()* speed;
}

QVector2D Player::getForce() const
{
    return force;
}

void Player::setForce(const QVector2D &value)
{
    if(value!=QVector2D(0,0))
        this->speed=5;
    force = value;
}

Player::Player(QVector2D position, float r):
    RoundCollision(position,r)
{
    this->direction = QVector2D(0,0);
}
void Player::draw(GameWidget *obg)
{
    QPainter pain(obg);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    pain.drawEllipse(QRectF(this->position.x(), this->position.y(), this->R*2,  this->R*2));
}

void Player::action()
{
    if(this->speed < this->maxSpeed && this->direction!=QVector2D(0,0))
        this->speed=this->speed+this->speed*0.05;
    this->position = this->position + this->direction+this->force;
}

void Player::moveTo(QVector2D toPoint)
{

    this->direction = (toPoint - (this->position) ).normalized()* speed;
}

void Player::stop()
{
    this->speed=5;
    this->direction = QVector2D(0,0);
}
