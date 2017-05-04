#include "wall.h"
#include "collision.h"


QString *Wall::getPath()
{
    return path;
}

Wall::~Wall()
{
    //delete path;
}

Wall::Wall(QVector2D position, float h, float w ):
    RectangleCollision(position,w,h)
{
    path = new QString(":/img/img/wall.png");
}

void Wall::draw(GameWidget *obg, QPainter *p)
{
    if(outsideWindow(this, obg))
    {
        return;
    }

    QPainter *pain =(p);
    float x = this->position.x() + obg->getTranslation().x();
    float y =  this->position.y() + obg->getTranslation().y();

    float h =  this->height;
    float w = this->width;
    pain->drawPixmap(QRect(QPoint(x,y),QSize(w, h)),QPixmap(*path));

}

void Wall::setPath(const QString &value)
{
   path = new QString(value);
}
