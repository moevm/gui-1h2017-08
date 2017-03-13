#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <QPixmap>

#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

#include <QVector2D>

#include "GameClasses/wall.h"
#include "GameClasses/player.h"
#include "GameClasses/level.h"

class Player;
class Level;

class GameWidget : public QWidget
{
    Q_OBJECT

    QRect m_lastRect;
    int angle=0;
    int x,y;
    Player *player;
    Level *level;
public:
    explicit GameWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    void action();
signals:

    void mousePressed();
    void mousePos();
    void mouseLeft();

public slots:
};

#endif // GAMEWIDGET_H
