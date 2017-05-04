#include "teleportermonster.h"
#include <QString>
#include <QVector>
#include <QPainter>
#include <QPixmap>
#include <qmath.h>
void TeleporterMonster::setCooldown(int value)
{
    Cooldown = value;
}

bool TeleporterMonster::canCastSpell()
{
    if(this->curr_Cooldown == 0)
        return true;
    else return false;
}

void TeleporterMonster::castSpellTelleport(Unit *toPos, Map *m)
{
    if(this->canCastSpell())
    {
        int count_of_spells = rand() % 3;
        for(int i=0; i<count_of_spells; i++ )
        {
            m->addTeleport(Teleport(QVector2D(toPos->getPosition().x() + (rand()%10 -5)*0.25*this->getR(),
                                              toPos->getPosition().y() + (rand()%10 -5)*0.25*this->getR()),  this->getR()));
        }
        this->curr_Cooldown=Cooldown;
    }
}

void TeleporterMonster::action()
{
    if(curr_Cooldown !=0) this->curr_Cooldown--;
    MovingObject::action();
}

TeleporterMonster::TeleporterMonster(QVector2D position, float r):
    Monster(position, r, new QString(":/img/teleportMonsterSprites/t01.png")),
    AnimationClass(QString(":/img/teleportMonsterSprites/t0"), 7,5,false)
{
    this->setMaxSpeed(7);
    this->curr_Cooldown=0;
    this->Cooldown =100;

}

void TeleporterMonster::interact(RoundCollision *pl, QVector <RectangleCollision*> cells){
    pl->getPosition();
    int targetCell =  rand() % (cells.length()-1);
    pl->setPosition(cells[targetCell]->getPosition());
}

void TeleporterMonster::move(){

}

void TeleporterMonster::draw(QWidget *obg, QPainter *p,QVector2D tr)
{
    QPainter *pain = (p);
    pain->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain->setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //pain.drawEllipse(QRectF(this->position.x() + tr.x(), this->position.y() + tr.y(), this->R*2,  this->R*2));

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
