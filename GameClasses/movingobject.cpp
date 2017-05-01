#include "MovingObject.h"
#include "iostream"

#include "math_function.h"
using std::cout;
float MovingObject::getSpeed() const
{
    return speed;
}

MovingObject::MovingObject(QVector2D position, float r):
    RoundCollision(position,r)
{
    this->direction = QVector2D(0,0);
    angle = 0;
    look=QVector2D(1,0);
}


QVector2D MovingObject::getDirection() const
{
    return direction;
}

void MovingObject::setDirection(const QVector2D &value)
{
    direction = value.normalized()* speed;
}

QVector2D MovingObject::getForce() const
{
    return force;
}

void MovingObject::setForce(const QVector2D &value)
{
    force = value;
}




void MovingObject::action()
{
    if(this->speed < this->maxSpeed && this->direction!=QVector2D(0,0))
        this->speed=this->speed+this->speed*0.05;
    this->position = this->position + this->direction+this->force;
}

void MovingObject::moveTo(QVector2D toPoint)
{
    angle = findAngle(look, (toPoint-getCentr()));

    this->direction = (toPoint - (this->position) ).normalized()* speed;

}

void MovingObject::stop()
{
    this->speed=5;
    this->direction = QVector2D(0,0);
}












