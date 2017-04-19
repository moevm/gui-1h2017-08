#ifndef WALL_H
#define WALL_H

#include "rectanglecollision.h"
#include "gamewidget.h"


class GameWidget;


class Wall : public RectangleCollision
{
    QString *path;
public:
    ~Wall();
    Wall(QVector2D position= QVector2D(0,0), float h=0, float w=0 );
    void draw(GameWidget *obg);
    QString *getPath();
    void setPath(const QString &value);
};

#endif // WALL_H
