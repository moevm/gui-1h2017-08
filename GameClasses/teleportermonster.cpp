#include "teleportermonster.h"

TeleporterMonster::TeleporterMonster(QVector2D position, float r)
    :Monster(position,r)
{

}

void TeleporterMonster::interact(Player *pl){
    pl->getPosition();

}

void TeleporterMonster::move(){

}
