#ifndef DRAWCLASS_H
#define DRAWCLASS_H

#include <QWidget>
#include <QVector2D>
#include <QPainter>

class DrawClass
{
public:
    static void drawLine(QVector2D p1, QVector2D p2 , QWidget * w);
    static void drawPoint(QVector2D p , QWidget * w);
};

#endif // DRAWCLASS_H
