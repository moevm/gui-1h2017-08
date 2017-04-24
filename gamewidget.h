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
    QVector2D mouse_pos;
    //int x,y;
    Player *player;
    Level *level;
    QVector2D translation = QVector2D(0,0);
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent  * ev);
    void action();

    void drawLine(QVector2D p1, QVector2D p2 ); // для визуализации
    void drawPoint(QVector2D p); // для визуализации

    QVector2D getTranslation() const;
    void setTranslation(const QVector2D &value);

signals:

    void mousePressed();
    void mousePos();
    void mouseLeft();
    void keyEscapePressed();
    void openLevel();

public slots:
     void generateLevel(int h=3, int w=3);
     void getSettings();

     void resizeEvent(QResizeEvent * event);
};

#endif // GAMEWIDGET_H
