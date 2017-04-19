#include "player.h"
#include "iostream"

#include "math_function.h"
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
    float m=  (float)pic.width()/10.0;

<<<<<<< HEAD
    pain.drawPixmap(QRect(QPoint(x,y),QSize(d, d)),pic);

    //pain.drawPixmap(QRect(QPoint(x,y),QSize((float)pic.width()/10.0,(float)pic.height()/10.0)),pic);
=======
     pain.drawPixmap(QRect(QPoint(x,y),QSize(pic.width()/4,pic.height()/4)),pic);
>>>>>>> d308ea92dcccc3489fb83f1344e8f25edc0784ce

    #ifndef QT_NO_DEBUG
        pain.drawText(QRect(QPoint(0,0),QSize(100, 100)),
                  "x: " + QString().setNum((direction).x()) + '\n' +
                  "y: " + QString().setNum((direction).y()) + '\n' +
                  "angle: " + QString().setNum(angle));
    #endif
}



void Player::action()
{
    if(this->speed < this->maxSpeed && this->direction!=QVector2D(0,0))
        this->speed=this->speed+this->speed*0.05;
    this->position = this->position + this->direction+this->force;
}

void Player::moveTo(QVector2D toPoint)
{
    angle = findAngle(look, (toPoint-getCentr()));

    this->direction = (toPoint - (this->position) ).normalized()* speed;

}

void Player::stop()
{
    this->speed=5;
    this->direction = QVector2D(0,0);
}












