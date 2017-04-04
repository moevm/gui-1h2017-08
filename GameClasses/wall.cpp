#include "wall.h"



Wall::Wall(QVector2D position, float h, float w ):
    RectangleCollision(position,w,h)
{

}

void Wall::draw(GameWidget *obg)
{

    QPainter pain(obg);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    //pain.drawRect(QRectF(this->position.x() + obg->getTranslation().x(), this->position.y() + obg->getTranslation().y(), this->width,  this->height));
    float x = this->position.x() + obg->getTranslation().x();
    float y =  this->position.y() + obg->getTranslation().y();

    float h =  this->height;
    float w = this->width;
     // pain.drawRect(QRectF(x, y,w,  h));
    pain.drawPixmap(QRect(QPoint(x,y),QSize(w, h)),QPixmap( ":/img/img/wall.png"));

}
