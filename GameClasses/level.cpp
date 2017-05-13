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

    mapSizes[3][0] = 77;
    mapSizes[3][1] = 77;

    mapSizes[4][0] = 80;
    mapSizes[4][1] = 95;

    mapSizes[5][0] = 99;
    mapSizes[5][1] = 99;

    mapSizes[6][0] = 111;
    mapSizes[6][1] = 87;

    mapSizes[7][0] = 131;
    mapSizes[7][1] = 61;

    mapSizes[8][0] = 151;
    mapSizes[8][1] = 127;

    mapSizes[9][0] = 189;
    mapSizes[9][1] = 201;
}

int  Level::getLastLevel(){
    return 10;
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


    curr_map->genMonsters(blockSize);

}

Level::~Level()
{

}

void Level::resizeAll(int blockSize){

    int wallWidth = blockSize;
    int wallHeight = blockSize;
    //curr_map = new Map();  // Пусть останется как напоминание.
    bool done = false;

    int count_of_wall=0;
    int count_of_cell=0;
    for (int i=0; i<w; i++){
        count_of_wall=0;
        for (int j=0; j<h; j++){
            if(Maze::WALL == map[i][j])
            {
                Wall *m = curr_map->walls.at(i).at(count_of_wall);
                m->setPosition(QVector2D(wallWidth*j,wallHeight*i));
                m->setWidth(wallWidth);
                m->setHeight(wallHeight);
                count_of_wall++;
            }
            if(Maze::VISITED == map[i][j] )
            {
                Wall *c = curr_map->cells.at(count_of_cell);
                c->setPosition(QVector2D(wallWidth*j,wallHeight*i));
                c->setWidth(wallWidth);
                c->setHeight(wallHeight);
                count_of_cell++;

                 if (!done){
                     QVector2D pos = this->pl->getPosition();

                     this->pl->setPosition(QVector2D(pos.x()*blockSize/block,pos.y()*blockSize/block));
                     this->pl->setR(blockSize/4.0);
                     done=true;

                 }
            }
        }
    }
    foreach (Monster *m, curr_map->monsters) {
         QVector2D pos = m->getPosition();
         m->setPosition(QVector2D(pos.x()*blockSize/block,pos.y()*blockSize/block));
         m->setR(blockSize/4.0);
    }
    block = blockSize;
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
        QVector<Wall*> curr_walls;
        for (int j=0; j<h; j++)
        {
            if(Maze::WALL == map[i][j]){
             Wall wal = Wall(QVector2D(wallWidth*j,wallHeight*i), wallWidth,wallHeight);
                if (i==w-2 && j==h-1){

                     wal.setPath(QString(":/img/img/exit.png"));
                     curr_walls.push_back(new Wall(wal));
                } else {
                curr_walls.push_back(new Wall(wal));
                }
            }
                if(Maze::VISITED == map[i][j] ){
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
        this->curr_map->walls.push_back(curr_walls);
    }
}

QVector2D Level::wayToPlayer(QVector2D p) const
{
    return (p - this->pl->getCentr());
}

void Level::action()
{
    float vision= this->pl->getR() * 10;
    foreach (TeleporterMonster *curr_m, this->curr_map->monsters) {
        curr_m->action();
        if(this->wayToPlayer((curr_m->getCentr())).length() < vision &&
           this->wayToPlayer((curr_m->getCentr())).length() > vision*0.4  )
        {
            //curr_m->setDirection(-this->wayToPlayer(curr_m->getCentr()));
            curr_m->moveTo(this->pl->getCentr());
        }
        else curr_m->stop();
        if(this->wayToPlayer((curr_m->getCentr())).length() < vision*0.6)
        {
            curr_m->castSpellTelleport(pl, this->curr_map);
        }
    }
    foreach (Teleport *curr_t, this->curr_map->teleports) {
        if(this->wayToPlayer((curr_t->getCentr())).length() < curr_t->getR()*1.5 &&   // для игрока
           curr_t->isReady()  )
        {
            curr_t->interact(this->pl, this->curr_map->cells);
        }
        foreach (MovingObject *curr_m, this->curr_map->monsters) {                  // для монстров
            if(((curr_m->getCentr() - curr_t->getCentr())).length() < curr_t->getR()*1.5 &&
               curr_t->isReady()  )
            {
                curr_t->interact(curr_m, this->curr_map->cells);
            }
        }
        if(curr_t->isReady())
        {
            this->curr_map->teleports.remove(this->curr_map->teleports.lastIndexOf(curr_t));
        }
    }
}

void Level::draw(GameWidget *obg, QPainter *p)
{
    curr_map->draw(obg,p);
}

// позволяет увелчить скорость просчёта коллизий за счёт того, что проверяются не все стены, а только "находящиеся рядом":
QVector2D Level::checkroundCollisionWithVectorOfWall(RoundCollision * circle, GameWidget *paint)
{
    QVector2D save = QVector2D(0,0);
    float h = curr_map->walls.at(0).at(0)->getHeight();
    float from_y = 0;
    float to_y = 0;
    if(curr_map->walls.size() < 10)
    {
        from_y = circle->getPosition().y() / h -1;
        to_y = from_y+2;
    }else
    {
        from_y = 0;
        to_y = curr_map->walls.size()-1;
    }
    for (int i=from_y; i<=to_y; i++){
        float from_x = 0;
        float to_x = curr_map->walls.at(i).size()-1;
        while(true)
        {
            if(to_x - from_x < 4)
                break;
            float midle_elem = (from_x + to_x)/2;
            if(curr_map->walls.at(i).at(midle_elem)->getPosition().x() < circle->getPosition().x())
            {
                from_x = midle_elem;
            }
            else
            {
                to_x = midle_elem;
            }
        }
        for (int j=from_x; j<=to_x; j++){
             save +=collisionCircleAndRectangle(curr_map->walls.at(i).at(j), circle, paint);
        }

    }
    return save;
}

void Level::checkCollision(GameWidget *paint)
{
    QVector2D save = QVector2D(0,0);
    /*foreach (Wall *curr_wall, curr_map->walls) {
        save +=collisionCircleAndRectangle(curr_wall, this->pl, paint);
    }*/

    save += checkroundCollisionWithVectorOfWall(pl, paint);
    /*float w = curr_map->walls.at(0).at(0)->getWidth();
    float h = curr_map->walls.at(0).at(0)->getHeight();
    float from_y = 0;
    float to_y = 0;
    if(curr_map->walls.size() < 10)
    {
        from_y = this->pl->getPosition().y() / h -1;
        to_y = from_y+2;
    }else
    {
        from_y = 0;
        to_y = curr_map->walls.size()-1;
    }

    for (int i=from_y; i<=to_y; i++){
        float from_x = 0;
        float to_x = curr_map->walls.at(i).size()-1;
        while(true)
        {
            if(to_x - from_x < 4)
                break;
            float midle_elem = (from_x + to_x)/2;
            if(curr_map->walls.at(i).at(midle_elem)->getPosition().x() < this->pl->getPosition().x())
            {
                from_x = midle_elem;
            }
            else
            {
                to_x = midle_elem;
            }
        }
        for (int j=from_x; j<=to_x; j++){
             save +=collisionCircleAndRectangle(curr_map->walls.at(i).at(j), this->pl, paint);
        }
    }*/
    /*foreach (QVector <Wall*> curr_walls, curr_map->walls)
    {
        float save_distance =1000000;
        float curr_distance =1000000;
        for( int i=0; i< curr_walls.size(); i++)
        {

        }
        foreach (Wall *curr_wall, curr_walls)
        {
            save +=collisionCircleAndRectangle(curr_wall, this->pl, paint);
            curr_distance = (this->pl->getPosition() - curr_wall->getPosition()).length();
            if(curr_distance > save_distance)
            {
                break;
            }
            else
            {
                save_distance = curr_distance;
            }
        }
    }*/
    Wall * rect =  this->curr_map->cells[this->curr_map->cells.length()-1];
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
       /* foreach (Wall *curr_wall, curr_map->walls) {
            monsterForse +=collisionCircleAndRectangle(curr_wall, curr_m, paint);
        }*/
        monsterForse += checkroundCollisionWithVectorOfWall(curr_m, paint);
        /*foreach (QVector <Wall*> walls, curr_map->walls)
        {
            foreach (Wall *curr_wall, walls)
            {
                monsterForse +=collisionCircleAndRectangle(curr_wall, curr_m, paint);
            }
        }*/
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
