#ifndef DRAWCLASS_H
#define DRAWCLASS_H

#include <QWidget>
#include <QVector2D>
#include <QPainter>
#include "gamewidget.h"

class DrawClass
{
public:
    static void drawLine(QVector2D p1, QVector2D p2 , GameWidget * w);
    static void drawPoint(QVector2D p , GameWidget * w);
};

#endif // DRAWCLASS_H
