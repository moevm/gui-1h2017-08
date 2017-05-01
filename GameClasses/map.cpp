#include "map.h"

Map::Map()
{

}

void Map::addWall(Wall w)
{
    walls.push_back(w);
}

void Map::addCell(Wall c)
{
    cells.push_back(c);
}

void Map::draw(GameWidget *obg)
{
    foreach (Wall curr_wall, this->walls) {
        curr_wall.draw(obg);
    }
    foreach (Wall curr_cell, this->cells) {
        curr_cell.draw(obg);
    }
}
void Map::addMonster(Monster *m)
{
   monsters.push_back(m);
}

void Map::genMonsters(){
    if (cells.size()<300 || !monsters.empty()) return;
    int amount = cells.size()/300;

    for (int i = 0; i<amount; i++){
        int targetCell =  rand() % (cells.length()-1);
        TeleporterMonster *t = new TeleporterMonster(cells[targetCell].getPosition());
        addMonster(t);
    }
}

Map::~Map(){
    foreach (Monster* m, this->monsters) {
        delete m;
    }
}

