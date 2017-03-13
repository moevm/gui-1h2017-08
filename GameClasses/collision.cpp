#include "collision.h"




QVector2D collisionCircleAndRectangle(RectangleCollision *rect, RoundCollision *circle)
{
   /* QVector2D(rect->position.x, rect->position.x+ rect->width);
    QVector2D(circle->position.x, circle->position.x+ rect->width);*/
   // if(circle->position)


}

//дальше импорт функций из javascript кода

QVector2D pointProjectionOnLine(QVector2D point, float k, float b)  // проецируем точку point на прямую y=k*x+b
{
    if(k==0)return QVector2D(0,0);
    float x = (point.y()+((point.x())/(k))-b ) / (k+1/k);
    float y=k*x+b;
    return  QVector2D(x,y);

}

bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2,QVector2D proj3)
{
    return(	pointOnLine(point1,point2, proj1) ||
            pointOnLine(point1,point2, proj2) ||
            pointOnLine(point1,point2, proj3) ||// проверены все случаи ,когда хоть какой-то край проекцируемой прямой находился в (1,2)
            pointOnLine(proj1,proj2, point1)  ||
            pointOnLine(proj2,proj3, point1)  ||
            pointOnLine(proj3,proj2, point1)   );
}
bool pointOnLine (QVector2D p1,QVector2D p2,QVector2D point)
{
    return(((point.x() <= p1.x() && point.x() >= p2.x())  || (point.x() >= p1.x() && point.x() <= p2.x())) &&
        ((point.y() <= p1.y() && point.y() >= p2.y())  || (point.y() >= p1.y() && point.y() <= p2.y())));
}
