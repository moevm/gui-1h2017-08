#include "gamewidget.h"
#include "GameClasses/collision.h"
#include "levelsetting.h"
#include "mainwindow.h"
#include <QtCore/qmath.h>

QVector2D GameWidget::getTranslation() const
{
    return translation;
}

void GameWidget::setTranslation(const QVector2D &value)
{
    translation = value;
}

void GameWidget::generateLevel(int h, int w)
{
  //  LevelSetting set;
   // set.show();


   // delete this->level;
    this->player = new Player(QVector2D(30,30),25);
    this->level = new Level(this->player,h,w);
    this->show();


}

void GameWidget::getSettings()
{
    LevelSetting *set = new LevelSetting(this);
    set->show();
    connect(set,SIGNAL(generateLevel(int,int)), this, SLOT(generateLevel(int,int)));
    emit openLevel();
}

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),m_lastRect(0,0,0,0)
{
    setFocusPolicy(Qt::StrongFocus);

    this->player = new Player(QVector2D(30,30),25);
    this->level = new Level(this->player);
    startTimer(1000/60);  // 60 fps
}

GameWidget::~GameWidget()
{
    delete player;
    delete level;
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    if(m_lastRect.height() < 10)
    {
        m_lastRect = event->rect();
    }


    //this->move(this->width()/2-player->getCentr().x(), this->height()/2-player->getCentr().y());
    //this->raise();
   // this->resize(this->width(), this->height());

    level->draw(this);
    player->draw(this);
    #ifndef QT_NO_DEBUG   // если Отладка, то рисуеются линии отвечающие за определение столкновения объектов. (а NDEBUG не объявлен, я думал это стандартная костанта для всех IDE, а вон оно как)
        this->level->checkCollision(this);
    #endif
   /* #ifndef QT_NO_DEBUG
        foreach (Wall curr_wall, this->level->getCurr_map()->walls) {
            if(collisionPointAndRectangle(&this->mouse_pos,&curr_wall, this))
            {
                curr_wall.setPath(":/img/img/cell.png");
            }
        }
    #endif*/
}

void GameWidget::timerEvent(QTimerEvent *event)
{
    this->action();
    this->setTranslation(QVector2D(this->width()/2-player->getCentr().x(), this->height()/2-player->getCentr().y()));
    this->repaint();
}

void GameWidget::mouseMoveEvent(QMouseEvent *ev)
{
//    this->x = ev->x();
   // this->y = ev->y();
    this->mouse_pos = QVector2D(ev->x()- this->getTranslation().x(), ev->y()- this->getTranslation().y());
    player->moveTo(QVector2D(ev->x()- this->getTranslation().x(), ev->y()- this->getTranslation().y()));
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

void GameWidget::keyPressEvent(QKeyEvent  *ev)
{
    if(ev->key() == Qt::Key_Escape  )
    {
        emit keyEscapePressed();
    }
}


void GameWidget::action()
{

    player->action();
    if(level->getFinised())
    {
        this->player = new Player(QVector2D(30,30),25);
        this->level = new Level(this->player,5,5);
        emit keyEscapePressed();  /// потом доделать
    }
    #ifdef QT_NO_DEBUG   // если не Отладка
        this->level->checkCollision(nullptr);
    #endif

   // this->level->checkCollision(nullptr);
}

void GameWidget::resizeEvent(QResizeEvent * event){
    QSize s = event->size();
    double px =  sqrt((s.width()*s.height())/60.0);
    level->resizeAll(px);
    level->draw(this);
}

