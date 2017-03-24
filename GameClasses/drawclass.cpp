#include "drawclass.h"
#include "gamewidget.h"


void DrawClass::drawLine(QVector2D p1, QVector2D p2, GameWidget *w)
{
    QPainter pain(w);


    pain.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    pain.drawLine(QPointF(p1.x() + w->getTranslation().x(),p1.y()+ w->getTranslation().y()),
                  QPointF(p2.x()+ w->getTranslation().x(),p2.y()+ w->getTranslation().y()));
}

void DrawClass::drawPoint(QVector2D p, GameWidget *w)
{
    QPainter pain(w);
    pain.setPen(QPen(Qt::magenta, 4, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    pain.drawPoint(QPointF(p.x()+ w->getTranslation().x(),p.y()+ w->getTranslation().y()));
}
