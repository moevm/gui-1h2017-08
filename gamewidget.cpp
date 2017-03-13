#include "gamewidget.h"


GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),m_lastRect(0,0,0,0)
{
    this->player = new Player(QVector2D(30,30),30);
    this->level = new Level();
    startTimer(50);
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    if(m_lastRect.height() < 10)
    {
        m_lastRect = event->rect();
    }
  /*  QPainter pain(this);
    QPen pen;
       pen.setStyle(Qt::NoPen);
       pain.setPen(pen);
        QImage image(":img/pict.png");
       // Указываем изображение в качестве паттерна
       QBrush brush(image);

       // Растягиваем изображение
      // brush.setTransform(QTransform().rotate(angle));
       brush.setTransform(QTransform().scale(0.2,0.2));
       pain.setBrush(brush);

       // Рисуем прямоугольник с закруглёнными краями
       qreal radius = 10;
       pain.drawRoundedRect(QRectF(0, 0, image.width(), image.height()), radius, radius);*/
      // pain.drawRoundedRect(QRectF(0, 0, 100, 100), radius, radius);
   /* Wall one(QVector2D(10,10), 20, 20);
    one.draw(this);*/
   // Player my_player(this->x,this->y, 30);

     level->draw(this);
     player->draw(this);


}

void GameWidget::timerEvent(QTimerEvent *event)
{
    //m_lastRect.setHeight(m_lastRect.height() -0.01*m_lastRect.height());
    //m_lastRect.setWidth(m_lastRect.width() -0.01*m_lastRect.width());
   /* angle++;
    if(angle == 360) angle =0;*/
    this->action();
    this->repaint();
}

void GameWidget::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    player->moveTo(QVector2D(this->x, this->y));
    emit mousePos();
}

void GameWidget::mousePressEvent(QMouseEvent *ev)
{

    emit mousePressed();
}

void GameWidget::leaveEvent(QEvent *ev)
{
    emit mouseLeft();
}

void GameWidget::mouseReleaseEvent(QMouseEvent *ev)
{
     player->stop();
}

void GameWidget::action()
{

    player->action();
}


