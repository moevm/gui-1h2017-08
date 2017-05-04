#include "map.h"
#include "collision.h"
#include <iostream>

using namespace std;
Map::Map()
{

}

/*void Map::addWall(Wall w)
{
    walls.push_back(new Wall(w));
}*/

void Map::addTeleport(Teleport w)
{
    teleports.push_back(new Teleport(w));
}
void Map::addCell(Wall c)
{
    cells.push_back(new Wall(c));
}

void Map::draw(GameWidget *obg, QPainter *p)
{

    foreach (Wall *curr_cell, this->cells) {
        curr_cell->draw(obg, p);
    }

    foreach (Teleport *curr_teleport, this->teleports) {
        curr_teleport->action();
        if(outsideWindow(curr_teleport, obg))
        {
            continue;
        }
        curr_teleport->draw(obg, p, obg->getTranslation());
    }
    foreach (Monster *curr_m, this->monsters) {
        //cout << "Window: x -" << obg->getTranslation().x() << ", y -" << obg->getTranslation().x() << endl;
        //cout << "Window: w -" << obg->size().width() << ", h -" << obg->size().height() << endl;
        if(outsideWindow(curr_m, obg))
        {
            //cout << "Not draw: " << curr_m->getPosition().x() << ", " << curr_m->getPosition().y() << endl;
            continue;
        }
        //cout << "Draw: " << curr_m->getPosition().x() << ", " << curr_m->getPosition().y() << endl;
        curr_m->draw(obg, p, obg->getTranslation());
    }
    /*foreach (Wall *curr_wall, this->walls) {
        curr_wall->draw(obg, p);
    }*/
    foreach (QVector <Wall*> curr_walls, this->walls)
    {
        foreach (Wall *curr_wall, curr_walls)
        {
            curr_wall->draw(obg, p);
        }
    }

}
void Map::addTeleportMonster(TeleporterMonster *m)
{
   monsters.push_back(m);
}

void Map::genMonsters(int blockSize){
    if (cells.size()<50 || !monsters.empty()) return;
    int amount = cells.size()/50;
    //if(amount > 40) amount =40;

    for (int i = 0; i<amount; i++){
        int targetCell =  rand() % (cells.length()-1);
        TeleporterMonster *t = new TeleporterMonster(cells[targetCell]->getPosition(), blockSize/4.0);
        addTeleportMonster(t);
        //
        //Teleport teleport(cells[targetCell]->getPosition(), blockSize/4.0);
        //addTeleport(teleport);
    }
}

Map::~Map(){
    foreach (TeleporterMonster* m, this->monsters) {
        delete m;
    }
}

