#include "gamewidget.h"


GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),m_lastRect(0,0,0,0)
{
    this->player = new Player(QVector2D(30,30),15);
    this->level = new Level(this->player);
    startTimer(50);
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    if(m_lastRect.height() < 10)
    {
        m_lastRect = event->rect();
    }
     level->draw(this);
     player->draw(this);
    // this->level->checkCollision(this);  // потом вернуть



}

void GameWidget::timerEvent(QTimerEvent *event)
{
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
    this->level->checkCollision(nullptr);
}


