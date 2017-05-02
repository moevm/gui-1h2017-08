#include "map.h"
#include "collision.h"
Map::Map()
{

}

void Map::addWall(Wall w)
{
    walls.push_back(new Wall(w));
}

void Map::addCell(Wall c)
{
    cells.push_back(new Wall(c));
}

void Map::draw(GameWidget *obg, QPainter *p)
{
    foreach (Wall *curr_wall, this->walls) {
        curr_wall->draw(obg, p);
    }
    foreach (Wall *curr_cell, this->cells) {
        curr_cell->draw(obg, p);
    }
    foreach (Monster *curr_m, this->monsters) {
        if(outsideWindow(curr_m, obg))
        {
            break;
        }
        curr_m->draw(*&obg, p, obg->getTranslation());
    }

}
void Map::addMonster(Monster *m)
{
   monsters.push_back(m);
}

void Map::genMonsters(){
    if (cells.size()<30 || !monsters.empty()) return;
    int amount = cells.size()/30;

    for (int i = 0; i<amount; i++){
        int targetCell =  rand() % (cells.length()-1);
        TeleporterMonster *t = new TeleporterMonster(cells[targetCell]->getPosition());
        addMonster(t);
    }
}

Map::~Map(){
    foreach (Monster* m, this->monsters) {
        delete m;
    }
}

