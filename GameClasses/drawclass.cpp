#include "drawclass.h"



void DrawClass::drawLine(QVector2D p1, QVector2D p2, QWidget *w)
{
    QPainter pain(w);

    //QPen pen;
   // pen.setColor(Qt::black);
    //pain.setPen(pen);
    pain.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
   // pain.drawEllipse(QRectF(this->x, this->y, this->width,  this->height));
   // pain.drawRect(QRectF(this->position.x(), this->position.y(), this->width,  this->height));
    pain.drawLine(QPointF(p1.x(),p1.y()), QPointF(p2.x(),p2.y()));
}

void DrawClass::drawPoint(QVector2D p, QWidget *w)
{
    QPainter pain(w);
    //QPen pen;
   // pen.setColor(Qt::black);
    //pain.setPen(pen);
    pain.setPen(QPen(Qt::magenta, 4, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
   // pain.drawEllipse(QRectF(this->x, this->y, this->width,  this->height));
   // pain.drawRect(QRectF(this->position.x(), this->position.y(), this->width,  this->height));
    pain.drawPoint(QPointF(p.x(),p.y()));
}
