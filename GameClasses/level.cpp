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

Level::Level(Player *pl, int mazeWidth, int mazeHeight)
{
    curr_map = new Map();
  //  int mazeWidth = 41;
  // int mazeHeight = 71;
    int wallWidth = 100;
    int wallHeight = 100;

    Maze maze (mazeWidth,mazeHeight);
    int **map = maze.getMap();
    this->pl=pl;
    bool done = false;
    for (int i=0; i<mazeWidth; i++){
        for (int j=0; j<mazeHeight; j++){
            if(maze.WALL == map[i][j])
            {
                curr_map->addWall(Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight));
            }
            if(maze.VISITED == map[i][j] )
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
