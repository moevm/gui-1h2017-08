#include "pushmonster.h"
#include <QString>
#include <QVector>
#include <QPainter>
#include <QPixmap>
#include <qmath.h>


void PushMonster::action()
{
    MovingObject::action();
}

PushMonster::PushMonster(QVector2D position, float r):
    Monster(position, r, new QString(":/img/teleportMonsterSprites/t01.png")),
    AnimationClass(QString(":/img/teleportMonsterSprites/t0"), 7,5,false)
{
    this->setMaxSpeed(7);
    this->deafen.setMax_time(100);
}

void PushMonster::interact(Player *pl, QVector <RectangleCollision*> cells){
    /*pl->getPosition();
    int targetCell =  rand() % (cells.length()-1);
    pl->setPosition(cells[targetCell]->getPosition());*/
    pl->setForce(this->getCentr() - pl->getCentr());

}

void PushMonster::push(Player *pl)
{
    float push_len =10;
    pl->setPushForce((-this->getCentr() + pl->getCentr()).normalized() * push_len);
    pl->deafen.start();
    this->stop();
    //this->setPushForce((this->getCentr() - pl->getCentr()).normalized() * push_len);
    this->deafen.start();

}

void PushMonster::move(){

}

void PushMonster::draw(QWidget *obg, QPainter *p,QVector2D tr)
{
    QPainter *pain = (p);
    pain->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain->setBrush(QBrush(Qt::green, Qt::SolidPattern));

    pain->drawEllipse(QRectF(this->position.x() + tr.x(), this->position.y() + tr.y(), this->R*2,  this->R*2));

    float x = this->position.x() + tr.x();
    float y =  this->position.y() + tr.y();
    float d =  this->R*2;


    //QPixmap pic = QPixmap (*this->path);
    QPixmap pic = QPixmap(this->getCurrFrame());

          pain->translate(x+this->R , y+this->R );
          pain->rotate(angle-45); // градус
          pain->drawPixmap(QRect(QPoint(0-R,0-R),QSize(d, d)),pic);
          pain->rotate(-angle+45);
          pain->translate(-(x+this->R) , -(y+this->R) );

      //  pain->end();


}
