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

void Wall::draw(GameWidget *obg)
{
    if(outsideWindow(this, obg))
    {
        return;
    }

    QPainter pain(obg);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    //pain.drawRect(QRectF(this->position.x() + obg->getTranslation().x(), this->position.y() + obg->getTranslation().y(), this->width,  this->height));
    float x = this->position.x() + obg->getTranslation().x();
    float y =  this->position.y() + obg->getTranslation().y();

    float h =  this->height;
    float w = this->width;
     // pain.drawRect(QRectF(x, y,w,  h));
   // pain.setViewport(0,0,1000,600);
 //   pain.setWindow(QRect(0,0,1000,600));
    pain.drawPixmap(QRect(QPoint(x,y),QSize(w, h)),QPixmap(*path));

}

void Wall::setPath(const QString &value)
{
   path = new QString(value);
}
