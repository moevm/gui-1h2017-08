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

void Level::setSizes(){
    mapSizes[0][0] = 15;
    mapSizes[0][1] = 15;

    mapSizes[1][0] = 27;
    mapSizes[1][1] = 31;

    mapSizes[2][0] = 59;
    mapSizes[2][1] = 73;
}

int  Level::getLastLevel(){
    return 3;
}

Level::Level(Player *pl, int mazeWidth, int mazeHeight, int stage, int blockSize)
{
    setSizes();
    curLevel = stage;

    curr_map = new Map();

    int wallWidth = blockSize;
    int wallHeight = blockSize;

    if (stage > 0){
       w = mapSizes[curLevel-1][0];
       h = mapSizes[curLevel-1][1];
     } else {
        h = mazeHeight;
        w = mazeWidth;
     }


    Maze maze (w,h);
    map = maze.getMap();
    this->pl=pl;
    bool done = false;
    block = blockSize;



    for (int i=0; i<w; i++){
        for (int j=0; j<h; j++){
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

Level::~Level()
{

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
        // уровень пройден
        this->finised = true;
        //emit levelFinished(curLevel);

    }

    this->pl->setForce(save);
}
int Level::getLevel(){
    return curLevel;
}
