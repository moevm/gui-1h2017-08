#include "level.h"
#include "collision.h"
#include "maze.h"


Map *Level::getCurr_map()
{
    return curr_map;
}


bool Level::getFinised() const
{
    return finised;
}

Level::Level(Player *pl, int mazeWidth, int mazeHeight, int blockSize)
{
    curr_map = new Map();
  //  int mazeWidth = 41;
  // int mazeHeight = 71;
    int wallWidth = blockSize;
    int wallHeight = blockSize;
    h = mazeHeight;
    w = mazeWidth;
    Maze maze (mazeWidth,mazeHeight);
    map = maze.getMap();
    this->pl=pl;
    bool done = false;
    block = blockSize;

    for (int i=0; i<mazeWidth; i++){
        for (int j=0; j<mazeHeight; j++){
            if(Maze::WALL == map[i][j])
            {
                curr_map->addWall(Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight));
            }
            if(Maze::VISITED == map[i][j] )
            {
                Wall cell = (Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight));
                cell.setPath(QString(":/img/img/cell.png"));
                curr_map->addCell(cell);
                 if (!done){
                     this->pl->setPosition(QVector2D(wallWidth*j,wallHeight*i));
                     done=true;
                 }
            }
        }
     }
}

void Level::resizeAll(int blockSize){

    int wallWidth = blockSize;
    int wallHeight = blockSize;
    curr_map = new Map();
    bool done = false;
     int mazeHeight = h;
     int mazeWidth = w;


    for (int i=0; i<mazeWidth; i++){
        for (int j=0; j<mazeHeight; j++){
            if(Maze::WALL == map[i][j])
            {
                curr_map->addWall(Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight));
            }
            if(Maze::VISITED == map[i][j] )
            {
                Wall cell = (Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight));
                cell.setPath(QString(":/img/img/cell.png"));
                curr_map->addCell(cell);
                 if (!done){
                     QVector2D pos = this->pl->getPosition();

                     this->pl->setPosition(QVector2D(pos.x()*blockSize/block,pos.y()*blockSize/block));
                     this->pl->setR(blockSize/4.0);
                     done=true;
                     block = blockSize;
                 }
            }
        }
     }
}

void Level::draw(GameWidget *obg)
{
    curr_map->draw(obg);
}

void Level::checkCollision(GameWidget *paint)
{
    QVector2D save = QVector2D(0,0);
    foreach (Wall curr_wall, curr_map->walls) {
        save +=collisionCircleAndRectangle(&curr_wall, this->pl, paint);
    }
    Wall * rect =  &this->curr_map->cells[this->curr_map->cells.length()-1];
    if(collisionPointAndRectangle(new QVector2D(this->pl->getCentr()),//&*(this->curr_map->cells.end()),
                                  rect,
                                  paint))
    {
        // урвоень пройден
        this->finised = true;
    }

    this->pl->setForce(save);
}
