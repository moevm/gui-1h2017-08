#ifndef UNIT_H
#define UNIT_H

#include <QVector2D>


class Unit
{
protected:
    QVector2D position;
public:

    Unit(QVector2D position);
   // virtual void draw(GameWidget *obg) =0;
};

#endif // UNIT_H
