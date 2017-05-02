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
    curr_map = nullptr;

    if (stage > 0){
       w = mapSizes[curLevel-1][0];
       h = mapSizes[curLevel-1][1];
     } else {
        h = mazeHeight;
        w = mazeWidth;
     }

    this->pl=pl;
    block = blockSize;

    this->createMap(w,h,blockSize,blockSize);


    curr_map->genMonsters();

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

    foreach (Monster *m, curr_map->monsters) {
         QVector2D pos = m->getPosition();
         m->setPosition(QVector2D(pos.x()*blockSize/block,pos.y()*blockSize/block));
         m->setR(blockSize/4.0);
    }
}

bool Level::createMap(int w, int h, int wallWidth, int wallHeight)
{
    if(curr_map)
        delete curr_map;
    curr_map = new Map();
    Maze maze (w,h);
    map = maze.getMap();

    bool done = false;

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
                      this->pl->setR(wallWidth/4.0);
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
        // уровень пройден
        this->finised = true;
        //emit levelFinished(curLevel);

    }

    foreach (Monster *curr_m, this->getCurr_map()->monsters) {
        QVector2D monsterForse = QVector2D(0,0);
        if(collisionCircleAndCircle(curr_m, this->pl, paint))
        {
            save +=(this->pl->getCentr() - curr_m->getCentr()).normalized()*this->pl->getSpeed();
            monsterForse +=(-this->pl->getCentr() + curr_m->getCentr()).normalized()*curr_m->getSpeed();
            //curr_m->setForce((-this->pl->getCentr() + curr_m->getCentr())/2);
        }
        foreach (Wall curr_wall, curr_map->walls) {
            monsterForse +=collisionCircleAndRectangle(&curr_wall, curr_m, paint);
        }
        foreach (Monster *curr_m_next, this->getCurr_map()->monsters) {
            if(curr_m_next != curr_m)
            {
                if(collisionCircleAndCircle(curr_m, curr_m_next, paint))
                {
                    monsterForse +=(curr_m->getCentr() - curr_m_next->getCentr()).normalized()*curr_m->getSpeed();
                }
            }
        }
        curr_m->setForce(monsterForse);
    }
    this->pl->setForce(save);
}
int Level::getLevel(){
    return curLevel;
}
