#include "collision.h"

#include "drawclass.h"

QVector2D collisionCircleAndRectangle(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if(     (circleInRectX(rect, circle, paint) && circleInRectY(rect, circle, paint)) ||
            ((!inLine(rect->getPosition().x(), rect->getPosition().x() + rect->getWidth(), circle->getCentr().x()) && !circleOutsideRectX(rect, circle, paint)) &&
            (!inLine(rect->getPosition().y(), rect->getPosition().y() + rect->getHeight(), circle->getCentr().y()) && !circleOutsideRectY(rect, circle, paint))))
    {
         return checkAreaFromTheCorner(rect, circle, paint);
    }
    else
    {
        if( (inLine(rect->getPosition().x(), rect->getPosition().x() + rect->getWidth(), circle->getCentr().x())) &&
            !circleOutsideRectY(rect, circle, paint))
        {
            if(rectUp(rect, circle, paint)) // значит круг снизу прямоугольника
            {
                if(paint!=nullptr)
                {
                    DrawClass::drawLine(circle->getCentr(), circle->getCentr() +QVector2D(0, -10), paint);
                }
                return QVector2D(0, -(circle->getCentr().y() + circle->getR() ) + (rect->getPosition().y()));
            }else
            {
                if(paint!=nullptr)
                {
                    DrawClass::drawLine(circle->getCentr(), circle->getCentr() +QVector2D(0, 10), paint);
                }
                return QVector2D(0, -(circle->getCentr().y() - circle->getR()) + (rect->getPosition().y()+rect->getHeight()));
            }
        }
        if(     (inLine(rect->getPosition().y(), rect->getPosition().y() + rect->getHeight(), circle->getCentr().y())) &&
                !circleOutsideRectX(rect, circle, paint))
        {
            if(rectRight(rect, circle, paint)/*rect->getPosition().x() > circle->getPosition().x()*/) // значит круг снизу прямоугольника
            {
                if(paint!=nullptr)
                {
                    DrawClass::drawLine(circle->getCentr(), circle->getCentr() +QVector2D(-10, 0), paint);
                }
                return QVector2D(-(circle->getCentr().x() + circle->getR() ) + (rect->getPosition().x()), 0);
            }else
            {
                if(paint!=nullptr)
                {
                    DrawClass::drawLine(circle->getCentr(), circle->getCentr() +QVector2D(10,0), paint);
                }
                return QVector2D( -(circle->getCentr().x() - circle->getR()) + (rect->getPosition().x()+rect->getWidth()), 0);
            }
        }
    }
     return (QVector2D(0, 0));
}
QVector2D checkAreaFromTheCorner(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    QVector2D centrRect = rect->getCentr();
    QVector2D centrCircle = circle->getCentr();
    if(paint!=nullptr)
    {
        DrawClass::drawLine(centrRect, centrCircle, paint);
    }
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
        if(paint!=nullptr)
        {
            DrawClass::drawLine(proection1, proection2, paint);
            DrawClass::drawPoint(proection1, paint);
            DrawClass::drawPoint(proection2, paint);
        }
        if(isCollisionLineWithLine( proection1,
                                    proection2,
                                    centrCircle+(centrCircle - centrRect).normalized()*circle->getR(),
                                    centrCircle+(centrRect - centrCircle).normalized()*circle->getR()))
        {
            if((centrCircle - proection1).length() < (centrCircle - proection2).length())
                return ( -(centrCircle-(centrCircle - centrRect).normalized()*circle->getR()) + proection1);
            else
                return ( -(centrCircle-(centrCircle - centrRect).normalized()*circle->getR()) + proection2);
        }
    } else {
        QVector2D proection1 = pointProjectionOnLine((rect->getPosition() + QVector2D(0,rect->getHeight())), k, b );
        QVector2D proection2 = pointProjectionOnLine((rect->getPosition() + QVector2D(rect->getWidth(), 0)), k, b );
        if(paint!=nullptr)
        {
            DrawClass::drawLine(proection1, proection2, paint);
            DrawClass::drawPoint(proection1, paint);
            DrawClass::drawPoint(proection2, paint);
        }
        if(isCollisionLineWithLine( proection1,
                                    proection2,
                                    centrCircle+(centrCircle - centrRect).normalized()*circle->getR(),
                                    centrCircle+(centrRect - centrCircle).normalized()*circle->getR()))
        {
            if((centrCircle - proection1).length() < (centrCircle - proection2).length())
                return ( -(centrCircle-(centrCircle - centrRect).normalized()*circle->getR()) + proection1);
            else
               return ( -(centrCircle-(centrCircle - centrRect).normalized()*circle->getR()) + proection2);
        }
    }
    return QVector2D(0,0);  // ну столкновения нет, значит и сила упругости нулевая.
}
bool circleInRectX(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if( inLine(rect->getPosition().x(),rect->getPosition().x() + rect->getWidth(), circle->getPosition().x()) &&
        inLine(rect->getPosition().x(),rect->getPosition().x() + rect->getWidth(), circle->getPosition().x() + circle->getR()*2)  )
    {
         return true;

    }
    return false;
}
bool circleInRectY(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if( inLine(rect->getPosition().y(),rect->getPosition().y() + rect->getHeight(), circle->getPosition().y()) &&
        inLine(rect->getPosition().y(),rect->getPosition().y() + rect->getHeight(), circle->getPosition().y() + circle->getR()*2)  )
    {
         return true;
    }
    return false;

}
bool circleOutsideRectX(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if( !inLine(rect->getPosition().x(),rect->getPosition().x() + rect->getWidth(), circle->getPosition().x()) &&
        !inLine(rect->getPosition().x(),rect->getPosition().x() + rect->getWidth(), circle->getPosition().x() + circle->getR()*2)  )
    {
         return true;

    }
    return false;
}
bool circleOutsideRectY(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if( !inLine(rect->getPosition().y(),rect->getPosition().y() + rect->getHeight(), circle->getPosition().y()) &&
        !inLine(rect->getPosition().y(),rect->getPosition().y() + rect->getHeight(), circle->getPosition().y() + circle->getR()*2)  )
    {
         return true;
    }
    return false;

}
bool rectUp(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if(rect->getPosition().y() > circle->getPosition().y()) // значит круг снизу прямоугольника
    {
        return true;
    }else
    {
        return false;
    }
}
bool rectRight(RectangleCollision *rect, RoundCollision *circle, GameWidget * paint)
{
    if(rect->getPosition().x() > circle->getPosition().x()) // значит круг снизу прямоугольника
    {
        return true;
    }else
    {
        return false;
    }
}
bool inLine(float line1, float line2, float point)
{
    if((line1 < point && line2 > point) || (line1 > point && line2 < point))
        return true;
    else return false;
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
bool pointOnLine (QVector2D p1,QVector2D p2,QVector2D point)
{
    return(((point.x() <= p1.x() && point.x() >= p2.x())  || (point.x() >= p1.x() && point.x() <= p2.x())) &&
        ((point.y() <= p1.y() && point.y() >= p2.y())  || (point.y() >= p1.y() && point.y() <= p2.y())));
}

bool collisionPointAndRectangle(QVector2D *p, RectangleCollision *rect, GameWidget * paint)
{
    if(paint!=nullptr)
    {
        DrawClass::drawPoint(*p,  paint);
        if((p->distanceToPoint(rect->getCentr()) < 100))
            DrawClass::drawLine(*p, rect->getCentr(), paint);
    }
    if(!((p->x() < rect->getPosition().x() && p->x() > rect->getPosition().x() + rect->getWidth()) ||   // проекция на x
        (p->x() > rect->getPosition().x() && p->x() < rect->getPosition().x() + rect->getWidth()))   )
    {
        return false;
    }
    if(!((p->y() < rect->getPosition().y() && p->y() > rect->getPosition().y() + rect->getHeight()) ||// проекция на y
        (p->y() > rect->getPosition().y() && p->y() < rect->getPosition().y() + rect->getHeight()))   )
    {
        return false;
    }

    return true;

}
bool collisionCircleAndCircle(RoundCollision *c1, RoundCollision *c2, GameWidget * paint)
{
    if(paint!=nullptr)
    {
        //DrawClass::drawPoint(*p,  paint);
        if((c1->getCentr().distanceToPoint(c2->getCentr()) < 100))
            DrawClass::drawLine(c1->getCentr(), c2->getCentr(), paint);
    }
    if((c1->getCentr().distanceToPoint(c2->getCentr()) < c1->getR() + c2->getR()))
    {
        return true;
    }

    return false;

}
bool outsideWindow(RoundCollision *circl, GameWidget * paint)
{

    if( paint->size().width() - paint->getTranslation().x() < circl->getPosition().x())
    {
        return true;
    }
    if(0 - paint->getTranslation().x() > circl->getPosition().x() + circl->getR()*2)
    {
        return true;
    }

    if(paint->size().height() - paint->getTranslation().y() < circl->getPosition().y())
    {
        return true;
    }
    if(0 - paint->getTranslation().y() > circl->getPosition().y() + circl->getR()*2)
    {
        return true;
    }
    return false;
}
bool outsideWindow(RectangleCollision *rect, GameWidget * paint)
{
    if( paint->size().width() -paint->getTranslation().x() < rect->getPosition().x())
    {
        return true;
    }
    if(0  -paint->getTranslation().x()> rect->getPosition().x() + rect->getWidth())
    {
        return true;
    }

    if(paint->size().height() -paint->getTranslation().y() < rect->getPosition().y())
    {
        return true;
    }
    if(0  -paint->getTranslation().y()> rect->getPosition().y() + rect->getHeight())
    {
        return true;
    }
    return false;
}



