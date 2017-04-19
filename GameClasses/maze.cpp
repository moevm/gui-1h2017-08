#include "maze.h"


 Maze::Maze(int width, int height, bool braids, bool rooms, int roomNum){
    this->width = width;
    this->height=height;
    maze = new int *[width];

       for (int i = 0; i < width; i++) {
           maze[i] = new int [height];
       }

       for(int i = 0; i < width; i++){
               for(int j = 0; j < height; j++){
                   maze[i][j] = WALL;
               }
           }

           for(int i = 1; i < width-1; i+=2){ //инициализируем клетки.
               for(int j = 1; j < height-1; j+=2){
                   maze[i][j] = CELL;
               }
           }

           if (rooms){
               makeRooms(roomNum);
           }

       startPoint={0,0};
       exitPoint={width-1, height-1};
       unvisitedNum=unvisitedCount();
       haveBraids = braids;
       generate();

}

void Maze::makeRooms(int num){
     srand(time(0));
    if (num==0) return;
    int numOfRooms=num;

    if (num==-1){
        numOfRooms=(height*width)/2000;
    }

    while (numOfRooms){
        int x=randomRange(7, width-8);
        int y=randomRange(7, height-8);
        Cell room = {x,y};
        rooms.push_back(room);

        for (int i = x-2; i<x+2; i++){
            for (int j=y-2; j<y+2; j++){
                maze[i][j]=VISITED;
            }
        }

       numOfRooms--;
    }


}


void  Maze::generate (){
    srand(time(0));
    do    backtrackGeneration();
    while(unvisitedCount() > 0);
}

void Maze::backtrackGeneration(){

    unsigned int randNum;
        CellString cellStringUnvisited;
        CellString cellStringNeighbours = getNeighbours(startPoint, 2);

        if(cellStringNeighbours.size != 0){ //если у клетки есть непосещенные соседи
            randNum  = randomRange(0, cellStringNeighbours.size-1);
            cellNext = cellStringNeighbours.cells[randNum]; //выбираем случайного соседа

            stack.push_back(startPoint); //заносим текущую точку в стек
            removeWall(startPoint, cellNext); //убираем стену между текущей и соседней точками
            unvisitedNum--;
            startPoint = cellNext; //делаем соседнюю точку текущей и отмечаем ее посещенной
            setMode(startPoint,VISITED);
            delete cellStringNeighbours.cells;
        }
        else if(stack.size()){ //если нет соседей, возвращаемся на предыдущую точку
         if (haveBraids){
                makeBraid(startPoint);
            }
            setMode(startPoint,VISITED);
            startPoint = stack[stack.size()-1];
            stack.pop_back();

        }
        else{ //если нет соседей и точек в стеке, но не все точки посещены, выбираем случайную из непосещенных

            cellStringUnvisited = getUnvisitedCells();
            if (cellStringUnvisited.size>0){
                randNum  = randomRange(0, cellStringUnvisited.size-1);
                startPoint = cellStringUnvisited.cells[randNum];
            }
            delete cellStringUnvisited.cells;
        }

}

Maze::CellString Maze::getNeighbours(Cell c,int distance){
    int x = c.x;
    int y = c.y;
    Cell up = {x, y - distance};
    Cell rt = {x + distance, y};
    Cell dw = {x, y + distance};
    Cell lt = {x - distance, y};
    Cell d[4]  = {dw, rt, up, lt};
    int size = 0;

    CellString cells;
    cells.cells = new Cell[4];

    for(int i = 0; i < 4; i++){ //для каждого направдения
        if(d[i].x > 0 && d[i].x < width && d[i].y > 0 && d[i].y < height){ //если не выходит за границы лабиринта
            unsigned int mazeCellCurrent = maze[d[i].x][d[i].y];
            Cell cellCurrent  = d[i];
            if(mazeCellCurrent != WALL && mazeCellCurrent != VISITED){ //и не посещена\является стеной
                cells.cells[size] = cellCurrent; //записать в массив;
                size++;
            }
        }
    }
    cells.size = size;
    return cells;
}

void Maze::makeBraid(Cell c){
    int x = c.x;
    int y = c.y;
    int distance = 1;
    Cell up = {x, y - distance};
    Cell rt = {x + distance, y};
    Cell dw = {x, y + distance};
    Cell lt = {x - distance, y};
    Cell d[4]  = {dw, rt, up, lt};
    int size = 0;

    CellString cells;
    cells.cells = new Cell[4];

    for(int i = 0; i < 4; i++){ //для каждого направдения
        if(d[i].x > 3 && d[i].x < width-3 && d[i].y > 3 && d[i].y < height-3){ //если не выходит за границы лабиринта
            unsigned int mazeCellCurrent = maze[d[i].x][d[i].y];
            Cell cellCurrent  = d[i];
            if(mazeCellCurrent == WALL){
                cells.cells[size] = cellCurrent; //записать в массив;
                size++;
            }
        }
    }
    cells.size = size;

    if (size>0){
       for (int i =0; i<size; i++){

           int delx = cells.cells[i].x;
           int dely = cells.cells[i].y;

           if (maze[delx][dely-2]==VISITED ||   maze[delx][dely+2]==VISITED ){
                      continue;
              } else if (maze[delx-2][dely]==VISITED ||  maze[delx+2][dely]==VISITED  ){
                      continue;
              } else {
                     maze[delx][dely]=VISITED;
                }
      }
     }
       delete cells.cells;

}

void  Maze::removeWall(Cell first, Cell second){
    short int xDiff = second.x - first.x;
    short int yDiff = second.y - first.y;
    short int addX, addY;
    Cell target;

    addX = (xDiff != 0) ? (xDiff / abs(xDiff)) : 0;
    addY = (yDiff != 0) ? (yDiff / abs(yDiff)) : 0;

    target.x = first.x + addX; //координаты стенки
    target.y = first.y + addY;

    maze[target.x][target.y] = VISITED;
}

void  Maze::setMode(Cell c, int mode){
    int x = c.x;
    int y = c.y;
    maze[x][y] = mode;
}

int  Maze::randomRange(int low, int high){

    return rand() % (high - low + 1) + low;
}

Maze::CellString  Maze::getUnvisitedCells(){
    CellString cells;
    unsigned long long i, j, size = 0;

    cells.cells = new Cell[width*height];

    for(i = 0; i < width; i++){
        for(j = 0; j < height; j++){
            if((maze[i][j] != WALL) && (maze[i][j] != VISITED)){
                cells.cells[size].x = i;
                cells.cells[size].y = j;
                size++;
            }
        }
    }
    cells.size = size;
    return cells;
}

int  Maze::unvisitedCount(){
    unsigned int count = 0, i, j;
    for (i = 0; i < width; i++)
        for (j = 0; j < height; j++)
            if(maze[i][j] != WALL && maze[i][j] != VISITED) count++;
    return count;
}

int** Maze::getMap(){
    return maze;
}










