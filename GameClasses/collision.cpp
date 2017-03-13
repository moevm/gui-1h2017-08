#include "collision.h"

#include "drawclass.h"

QVector2D collisionCircleAndRectangle(RectangleCollision *rect, RoundCollision *circle, QWidget * paint)
{
    //QVector2D centRect(rect->getPosition().x() + rect->getWidth()/2, rect->getPosition().y() + rect->getHeight()/2);
    //QVector2D centCircle(circle->getPosition().x() + circle->getR(), circle->getPosition().y() + circle->getR());
    QVector2D centrRect = rect->getCentr();
    QVector2D centrCircle = circle->getCentr();
    DrawClass::drawLine(centrRect, centrCircle, paint);

    float k, b;
    getLine(centrRect, centrCircle, k, b);
    if( (rect->getPosition().distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->getWidth(),rect->getHeight())).distanceToPoint(centrCircle) &&
         rect->getPosition().distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(0,rect->getHeight())).distanceToPoint(centrCircle) &&
         rect->getPosition().distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->getWidth(),0)).distanceToPoint(centrCircle)) ||
        ((rect->getPosition() + QVector2D(rect->getWidth(),rect->getHeight())).distanceToPoint(centrCircle) < (rect->getPosition()).distanceToPoint(centrCircle) &&
         (rect->getPosition() + QVector2D(rect->getWidth(),rect->getHeight())).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(0,rect->getHeight())).distanceToPoint(centrCircle) &&
         (rect->getPosition() + QVector2D(rect->getWidth(),rect->getHeight())).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->getWidth(),0)).distanceToPoint(centrCircle)))
    {
        QVector2D proection1 = pointProjectionOnLine(rect->getPosition(), k, b );
        QVector2D proection2 = pointProjectionOnLine((rect->getPosition() + QVector2D(rect->getWidth(),rect->getHeight())), k, b );
        DrawClass::drawLine(proection1, proection2, paint);
        DrawClass::drawPoint(proection1, paint);
        DrawClass::drawPoint(proection2, paint);
        if(isCollisionLineWithLine( proection1,
                                    proection2,
                                    centrCircle+(centrCircle - centrRect).normalized()*circle->getR()/2,
                                    centrCircle+(centrRect - centrCircle).normalized()*circle->getR()/2))
        {
            return (centrCircle -centrRect).normalized(); // возвращаем вектор, который направлен в противоположную сторону от столкновения(но вообще нужно отражать на угол, наверное). Или мы просто гасим движение? Нужно, наверное, ещё подумать над механийкой столкновения.
        }
        // Вот вопрос, а следующий if вообще нужен? Наверное нет.
    } else /*if(  (rect->getPosition() + QVector2D(0,rect->height)).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->width,rect->height)).distanceToPoint(centrCircle) &&
                (rect->getPosition() + QVector2D(0,rect->height)).distanceToPoint(centrCircle) < (rect->getPosition()).distanceToPoint(centrCircle) &&
                (rect->getPosition() + QVector2D(0,rect->height)).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->width,0)).distanceToPoint(centrCircle) ||
                ((rect->getPosition() + QVector2D(rect->width,0)).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(rect->width,rect->height)).distanceToPoint(centrCircle) &&
                (rect->getPosition() + QVector2D(rect->width,0)).distanceToPoint(centrCircle) < (rect->getPosition() + QVector2D(0,rect->height)).distanceToPoint(centrCircle) &&
                (rect->getPosition() + QVector2D(rect->width,0)).distanceToPoint(centrCircle) < (rect->getPosition()).distanceToPoint(centrCircle)))*/
    {
        QVector2D proection1 = pointProjectionOnLine((rect->getPosition() + QVector2D(0,rect->getHeight())), k, b );
        QVector2D proection2 = pointProjectionOnLine((rect->getPosition() + QVector2D(rect->getWidth(), 0)), k, b );
        DrawClass::drawLine(proection1, proection2, paint);
        DrawClass::drawPoint(proection1, paint);
        DrawClass::drawPoint(proection2, paint);
        if(isCollisionLineWithLine( proection1,
                                    proection2,
                                    centrCircle+(centrCircle - centrRect).normalized()*circle->getR()/2,
                                    centrCircle+(centrRect - centrCircle).normalized()*circle->getR()/2))
        {
            return (centrCircle -centrRect).normalized(); // возвращаем вектор, который направлен в противоположную сторону от столкновения(но вообще нужно отражать на угол, наверное)
        }
    }
    return QVector2D(0,0);  // ну столкновения нет, значит и сила упругости нулевая.
}

bool getLine(const QVector2D  p1 ,const QVector2D p2, float &k, float &b) //возвращает false, если эта линия имеет вид x=b
{
    if(p1.x() - p2.x() == 0)  // то есть получится уравнение вида x=b
    {
        k=1;
        b=-p1.x();
        return false;
    }
    else
    {
        k = (p2.y() - p1.y())/(p2.x() - p1.x());
        b = p1.y() -k* p1.x();
        return true;
    }
}

//дальше импорт функций из javascript кода

QVector2D pointProjectionOnLine(QVector2D point, float k, float b)  // проецируем точку point на прямую y=k*x+b
{
    if(k==0)return QVector2D(0,0);
    float x = (point.y()+((point.x())/(k))-b ) / (k+1/k);
    float y=k*x+b;
    return  QVector2D(x,y);

}

bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2)   // вот эта функция вызывает сомнения в плане оптимизации
{
    return(	pointOnLine(point1,point2, proj1) ||
            pointOnLine(point1,point2, proj2) ||// проверены все случаи ,когда хоть какой-то край проекцируемой прямой находился в (1,2)
            pointOnLine(proj1,proj2, point1)  ||
            pointOnLine(proj1,proj2, point2)  );
}
/*
bool isCollisionLineWithLine(QVector2D point1,QVector2D point2,QVector2D proj1,QVector2D proj2,QVector2D proj3)
{
    return(	pointOnLine(point1,point2, proj1) ||
            pointOnLine(point1,point2, proj2) ||
            pointOnLine(point1,point2, proj3) ||// проверены все случаи ,когда хоть какой-то край проекцируемой прямой находился в (1,2)
            pointOnLine(proj1,proj2, point1)  ||
            pointOnLine(proj2,proj3, point1)  ||
            pointOnLine(proj3,proj2, point1)   );
}*/
bool pointOnLine (QVector2D p1,QVector2D p2,QVector2D point)
{
    return(((point.x() <= p1.x() && point.x() >= p2.x())  || (point.x() >= p1.x() && point.x() <= p2.x())) &&
        ((point.y() <= p1.y() && point.y() >= p2.y())  || (point.y() >= p1.y() && point.y() <= p2.y())));
}
