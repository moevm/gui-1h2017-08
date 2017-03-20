#include "maze.h"
#define CELL 0
#define WALL 1
#define VISITED -1

 Maze::Maze(int width, int height){
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

       startPoint={0,0};
       exitPoint={width-1, height-1};
       unvisitedNum=unvisitedCount();
       generate();
}

void  Maze::generate (){
    do    backtrackGeneration();
    while(unvisitedCount() > 0);
}

void Maze::backtrackGeneration(){
/*
    for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){

                if((i % 2 != 0  && j % 2 != 0) && //если ячейка нечетная по x и y,
                   (i < height-1 && j < width-1))   //и при этом находится в пределах стен лабиринта
                       maze[i][j] = CELL;       //то это КЛЕТКА
                else maze[i][j] = WALL;           //в остальных случаях это СТЕНА.
            }
        }
*/


    unsigned int randNum;
        CellString cellStringUnvisited;
        CellString cellStringNeighbours = getNeighbours(startPoint, 2);

        if(cellStringNeighbours.size != 0){ //если у клетки есть непосещенные соседи
            randNum  = randomRange(0, cellStringNeighbours.size-1);
            cellNext = cellStringNeighbours.cells[randNum]; //выбираем случайного соседа

            stack.push_back(startPoint); //заносим текущую точку в стек
            removeWall(startPoint, cellNext); //убираем стену между текущей и сосендней точками
            unvisitedNum--;
            startPoint = cellNext; //делаем соседнюю точку текущей и отмечаем ее посещенной
            setMode(startPoint,VISITED);
            delete cellStringNeighbours.cells;
        }
        else if(stack.size()){ //если нет соседей, возвращаемся на предыдущую точку
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
           // free(cellStringUnvisited.cells);
        }

}

Maze::CellString Maze::getNeighbours(Cell c,int distance){
    unsigned int i;
    unsigned int x = c.x;
    unsigned int y = c.y;
    Cell up = {x, y - distance};
    Cell rt = {x + distance, y};
    Cell dw = {x, y + distance};
    Cell lt = {x - distance, y};
    Cell d[4]  = {dw, rt, up, lt};
    unsigned int size = 0;

    CellString cells;
    cells.cells = new Cell[4];

    for(i = 0; i < 4; i++){ //для каждого направдения
        if(d[i].x > 0 && d[i].x < width && d[i].y > 0 && d[i].y < height){ //если не выходит за границы лабиринта
            unsigned int mazeCellCurrent = maze[d[i].y][d[i].x];
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


void  Maze::removeWall(Cell first, Cell second){
    short int xDiff = second.x - first.x;
    short int yDiff = second.y - first.y;
    short int addX, addY;
    Cell target;

    addX = (xDiff != 0) ? (xDiff / abs(xDiff)) : 0;
    addY = (yDiff != 0) ? (yDiff / abs(yDiff)) : 0;

    target.x = first.x + addX; //координаты стенки
    target.y = first.y + addY;

    maze[target.y][target.x] = VISITED;
}

void  Maze::setMode(Cell c, int mode){
    unsigned int x = c.x;
    unsigned int y = c.y;
    maze[y][x] = mode;
}

unsigned int  Maze::randomRange(unsigned int low, unsigned int high){

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

unsigned int  Maze::unvisitedCount(){
    unsigned int count = 0, i, j;
    for (i = 0; i < width; i++)
        for (j = 0; j < height; j++)
            if(maze[i][j] != WALL && maze[i][j] != VISITED) count++;
    return count;
}

int** Maze::getMap(){
    return maze;
}










