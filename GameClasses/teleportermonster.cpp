#include "teleportermonster.h"
#include <QString>
#include <QVector>
#include <QPainter>
#include <QPixmap>
TeleporterMonster::TeleporterMonster(QVector2D position, float r):
    Monster(position, r, new QString(":/img/teleportMonsterSprites/t01.png")),
    AnimationClass(QString(":/img/teleportMonsterSprites/t0"), 7)
{

}

void TeleporterMonster::interact(RoundCollision *pl, QVector <RectangleCollision*> cells){
    pl->getPosition();
    int targetCell =  rand() % (cells.length()-1);
    pl->setPosition(cells[targetCell]->getPosition());
}

void TeleporterMonster::move(){

}

void TeleporterMonster::draw(QWidget *obg, QVector2D tr){
    QPainter pain(obg);
    pain.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    pain.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    //pain.drawEllipse(QRectF(this->position.x() + tr.x(), this->position.y() + tr.y(), this->R*2,  this->R*2));

    float x = this->position.x() + tr.x();
    float y =  this->position.y() + tr.y();
    float d =  this->R*2;


    //QPixmap pic = QPixmap (*this->path);
    QPixmap pic = QPixmap(this->getCurrFrame());
        QPixmap rotatePixmap(pic.size());
        rotatePixmap.fill(Qt::transparent);

        QPainter p(&rotatePixmap);
        pain.setRenderHint(QPainter::Antialiasing); // сглаживание
        pain.setRenderHint(QPainter::SmoothPixmapTransform);
        pain.setRenderHint(QPainter::HighQualityAntialiasing);
        pain.translate(x+this->R , y+this->R );
        pain.rotate(0-45); // градус

      // pain.setViewport(0,0,500,300);
      //  pain.setWindow(QRect(0,0,1000,600));
        pain.drawPixmap(QRect(QPoint(0-R,0-R),QSize(d, d)),pic);
        pain.translate(-(x+this->R) , -(y+this->R) );
        pain.end();
        pic = rotatePixmap;

}
