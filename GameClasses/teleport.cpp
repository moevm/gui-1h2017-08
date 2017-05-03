#include "teleport.h"


Teleport::Teleport(QVector2D position, float R):
    AnimationClass(":/img/teleport/p0",7, 20),
    RoundCollision(position,R)
{
    this->ready=false;
}

void Teleport::action()
{
    if(this->getCurr_frame() == this->getCount_of_frames())
    {
       ready=true;
    }else ready =false;
}
bool Teleport::isReady() const
{
    return ready;
}
void Teleport::draw(QWidget *obg, QPainter *p,QVector2D tr)
{
    QPainter *pain = (p);
    pain->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain->setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //pain.drawEllipse(QRectF(this->position.x() + tr.x(), this->position.y() + tr.y(), this->R*2,  this->R*2));

    float x = this->position.x() + tr.x();
    float y =  this->position.y() + tr.y();
    float d =  this->R*2;

    QPixmap pic = QPixmap(this->getCurrFrame());
    pain->translate(x+this->R , y+this->R );
    pain->drawPixmap(QRect(QPoint(0-R,0-R),QSize(d, d)),pic);
    pain->translate(-(x+this->R) , -(y+this->R) );

}

void Teleport::interact(RoundCollision *pl, QVector <Wall*> cells){
    //pl->getPosition();
    int targetCell =  rand() % (cells.length()-1);
    pl->setPosition(cells[targetCell]->getPosition());
}
