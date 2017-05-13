#include "player.h"
#include "iostream"

#include "math_function.h"
using std::cout;




Player::Player(QVector2D position, float r):
    MovingObject(position,r)
{
    this->direction = QVector2D(0,0);
    angle = 0;
    look=QVector2D(1,0);
}
void Player::draw(GameWidget *obg, QPainter *p)
{
    QPainter *pain=(p);
   // pain->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
   // pain->setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //pain->drawEllipse(QRectF(this->position.x() + obg->getTranslation().x(), this->position.y() + obg->getTranslation().y(), this->R*2,  this->R*2));


    float x = this->position.x() + obg->getTranslation().x();
    float y =  this->position.y() + obg->getTranslation().y();
    float d =  this->R*2;


    QPixmap pic = QPixmap (":/img/img/player.png");
        QPixmap rotatePixmap(pic.size());
        rotatePixmap.fill(Qt::transparent);

        //QPainter p(&rotatePixmap);
        pain->setRenderHint(QPainter::Antialiasing); // сглаживание
        pain->setRenderHint(QPainter::SmoothPixmapTransform);
        pain->setRenderHint(QPainter::HighQualityAntialiasing);
        pain->translate(x+this->R , y+this->R );
        pain->rotate(angle); // градус

      // pain->setViewport(0,0,500,300);
      //  pain->setWindow(QRect(0,0,1000,600));
        pain->drawPixmap(QRect(QPoint(0-R,0-R),QSize(d, d)),pic);
        pain->rotate(-angle);
        pain->translate(-(x+this->R) , -(y+this->R) );

       // pain->end();


    #ifndef QT_NO_DEBUG
        pain->drawText(QRect(QPoint(0,0),QSize(100, 100)),
                  "x: " + QString().setNum((direction).x()) + '\n' +
                  "y: " + QString().setNum((direction).y()) + '\n' +
                  "angle: " + QString().setNum(angle));
#endif
}

void Player::action()
{
    deafen.action();
    if(this->speed < this->maxSpeed && this->direction!=QVector2D(0,0))
        this->speed=this->speed+this->speed*0.05;
    //if(deafen.isFinished())
        this->position = this->position + this->direction+this->force + this->getPushForce();
    /*else
        this->position = this->position + this->getPushForce();*/
    this->setPushForce(this->getPushForce()*0.94);
}
