#include "player.h"


QVector2D Player::getDirection() const
{
    return direction;
}

void Player::setDirection(const QVector2D &value)
{
    direction = value;
}

Player::Player(QVector2D position, float r):
    RoundCollision(position,r)
{
    this->direction = QVector2D(0,0);
}



void Player::draw(GameWidget *obg)
{
    QPainter pain(obg);

    //QPen pen;
   // pen.setColor(Qt::black);
    //pain.setPen(pen);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    pain.drawEllipse(QRectF(this->position.x(), this->position.y(), this->R,  this->R));
    // pain.drawRect(QRectF(this->x, this->y, this->width,  this->height));
}

void Player::action()
{
    this->position = this->position + this->direction;
}

void Player::moveTo(QVector2D toPoint)
{
    //this->position = toPoint;
    this->direction = (toPoint - this->position).normalized()* speed;
}

void Player::stop()
{
    this->direction = QVector2D(0,0);
}
