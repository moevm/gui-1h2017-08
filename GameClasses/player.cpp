#include "player.h"
#include "iostream"
using std::cout;

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
   /* if(value!=QVector2D(0,0))
        this->speed=5;*/
    force = value;
}

Player::Player(QVector2D position, float r):
    RoundCollision(position,r)
{
    this->direction = QVector2D(0,0);
    angle = 0;
    look=QVector2D(1,0);
}
void Player::draw(GameWidget *obg)
{
    QPainter pain(obg);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //pain.drawEllipse(QRectF(this->position.x() + obg->getTranslation().x(), this->position.y() + obg->getTranslation().y(), this->R*2,  this->R*2));


    float x = this->position.x() + obg->getTranslation().x();
    float y =  this->position.y() + obg->getTranslation().y();
    float d =  this->R*2;

    QPixmap pic = QPixmap (":/img/img/player.png");
    QTransform transform;
    QTransform //trans = transform.scale(sqrt(pic.size().width()), sqrt(pic.size().height()));
        trans = transform.rotate(angle);
    pic = QPixmap(pic.transformed(trans));


     pain.drawPixmap(QRect(QPoint(x,y),QSize(pic.width()/4,pic.height()/4)),pic);
}



void Player::action()
{
    if(this->speed < this->maxSpeed && this->direction!=QVector2D(0,0))
        this->speed=this->speed+this->speed*0.05;
    this->position = this->position + this->direction+this->force;
}

void Player::moveTo(QVector2D toPoint)
{
    float ax = look.x(); //position.x();
    float ay = look.y(); //position.y();
    float bx = toPoint.x();
    float by = toPoint.y();

    angle = atan((ax*bx+ay*by)/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by)))*180.0;

    cout<<angle<<"\n";

    this->look = (toPoint - (this->position) ).normalized();
    this->direction = (toPoint - (this->position) ).normalized()* speed;

}

void Player::stop()
{
    this->speed=5;
    this->direction = QVector2D(0,0);
}












