#include "teleportermonster.h"

TeleporterMonster::TeleporterMonster(QVector2D position, float r)
    :Monster(position,r, new QString(":/img/img/teleporter.png"))
{

}

void TeleporterMonster::interact(Player *pl, QVector <Wall> cells){
    pl->getPosition();
    int targetCell =  rand() % (cells.length()-1);
    pl->setPosition(cells[targetCell].getPosition());
}

void TeleporterMonster::move(){

}

void TeleporterMonster::draw(){

}
